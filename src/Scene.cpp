#include "../include/Scene.h"

/////////////////////////////////////////////////////////

Scene::Scene():running(true)
{}

Scene::~Scene()
{
	controlThread.join();
}

//////////////////////////////////////////////////////////

void Scene::load(const string& filename, SDL_Renderer* ren)
{
	fstream file(filename);

	runCommand(
		parse(
			readFile(
				file
				)
			),
		ren
	);

	file.close();
}

vector<string> Scene::readFile(fstream& file)
{
	vector<string> linesOfFile;

	string line;
	while(getline(file, line)){
		linesOfFile.push_back(line);
	}

	return linesOfFile;
}

vector<Command> Scene::parse(const vector<string>& linesOfFile)
{
	//warning!!! very long function
	//this function is a parser for file like json,
	//but basicaly
	//
	//for example:
	//title{
	//	key: value,
	//	you: aresmart
	//}

	vector<Command> commands;

	//buffers
	Command command;

	string key = "";

	string valueBuffer = "";
	string keyBuffer = "";
	string titleBuffer = "";
	//

	for(auto i = linesOfFile.begin(); i != linesOfFile.end(); i++)
	{

		//check all char of lines
		for(int j(0); j!=i->length(); j++)
		{
			//first need to take title of command
			if(command.title == "")
			{

				//search the special symbol
				//of end of a title, and start
				//to take a key - {
				if((*i)[j] == '{')
				{
					if(titleBuffer == "")
					{
						//log it later
					}
					
					//take a title
					command.title = titleBuffer;

					//clear buffers
					titleBuffer = "";
				}else
				{
					//ignore space and tab
					if(!((*i)[j] == ' ' || (*i)[j] == '	'))
					{
						//if current char is not 
						//special symbol,
						//append it to buffer
						titleBuffer += (*i)[j];
					}
				}

			//second to take key
			}else if(key == "")
			{
				if((*i)[j] == ':')
				{
					if(keyBuffer == "")
					{
						//log this shit later
					}
					key = keyBuffer;
					keyBuffer = "";
				}else if((*i)[j] == '}')
				{
					if(key == "")
					{
						//Error, log this shit
					}

					valueBuffer = "";
					key = "";
					commands.push_back(command);
					command = Command();
				}else
				{
					//ignore space and tab
					if(!((*i)[j] == ' ' || (*i)[j] == '	'))
					{
						keyBuffer += (*i)[j];
					}
				}

			//thirst to take value
			}else
			{
				if((*i)[j] == ',')
				{
					command[key] = valueBuffer;
					valueBuffer = "";
					key = "";
				}else if((*i)[j] == '}')
				{
					command[key] = valueBuffer;
					valueBuffer = "";
					key = "";
					commands.push_back(command);
					command = Command();
				}else
				{
					//ignore space and tab
					if(!((*i)[j] == ' ' || (*i)[j] == '	'))
					{
						valueBuffer += (*i)[j];
					}
				}
			}
		}
	}

	return commands;
}

void Scene::runCommand(const vector<Command>& commands, SDL_Renderer* ren)
{
	for(auto i = commands.begin(); i != commands.end(); i++)
	{
		createNewActor(*i, ren);
	}
}

void Scene::createNewActor(const Command& command, SDL_Renderer* ren)
{
	Rectangle rect(
			atoi(command["x_position"].c_str()),
			atoi(command["y_position"].c_str()),
			atoi(command["width"].c_str()),
			atoi(command["height"].c_str())
			);

	if(command.title == "Snake")
	{
		addSnake(IMG_LoadTexture(ren, command["texture"].c_str()), rect);
	}
	else if(command.title == "SnakeBody")
	{
		addElementOfBody(IMG_LoadTexture(ren, command["texture"].c_str()), rect, hero);
	}
	else if(command.title == "Apple")
	{
		addApple(IMG_LoadTexture(ren, command["texture"].c_str()), rect);
	}
}

//////////////////////////////////////////////////////////

void Scene::draw(SDL_Renderer* ren)
{
	SDL_RenderClear(ren);

	for(int i(objects.size()-1); i>=0; i--)
	{
		objects[i]->draw(ren);
	}

	SDL_RenderPresent(ren);
}

//////////////////////////////////////////////////////////

void Scene::tick()
{
	for(auto i = objects.begin(); i != objects.end(); i++)
	{
		(*i)->tick();
	}

	if(hero->checkElementsInTurn())
	{
		objects.push_back(hero->getElementFromTurn());
	}

	checkTouchs();
}

void Scene::checkTouchs()
{
	PhysicsObjects objsWhoTuchSubj;

	for(auto i = objects.begin(); i != objects.end(); i++)
	{

		for(auto j = objects.begin(); j != objects.end(); j++)
		{
			if(i!=j){

				if(circleVsCircle(*i, *j)) objsWhoTuchSubj.push_back(*j);
			}
		}

		runFuncById((*i)->touchBy(objsWhoTuchSubj));

		objsWhoTuchSubj.clear();
	}
}

void Scene::runFuncById(int id)
{
	switch(id){
	case 1:
		snakeEatApple();	

		break;
	}
}

void Scene::snakeEatApple()
{
	hero->createNewElement();

	createAppleAtRandom();
}

void Scene::createAppleAtRandom()
{
	float x_pos = 20.0f;
	float y_pos = 20.0f;

	apple->rect.move(Vec(x_pos, y_pos));
}


bool Scene::circleVsCircle(shared_ptr<Actor> circle1, shared_ptr<Actor> circle2)
{
	float lengthDifferentOfPos = 
		abs(
			(circle1->getCenter()- circle2->getCenter()).getLength()
		);
	
	if(lengthDifferentOfPos <= (circle1->getRadius()+circle2->getRadius()))
		return true;
	
	return false;
	
}

//////////////////////////////////////////////////////////

void Scene::addSnake(SDL_Texture* tex, const Rectangle& rect)
{
	HeadOfSnake* el = new HeadOfSnake(rect, tex);

	hero = shared_ptr<HeadOfSnake>(el);

	objects.push_back(hero);

}

void Scene::addElementOfBody(SDL_Texture* tex, const Rectangle& rect, const shared_ptr<Actor>& target)
{
	shared_ptr<BodyOfSnake> el(new BodyOfSnake(rect, tex, target));

	hero->addFirstElement(el);

	objects.push_back(el);
}

void Scene::addApple(SDL_Texture* tex, const Rectangle& rect)
{
	shared_ptr<Apple> el(new Apple(rect, tex));

	apple = el;

	objects.push_back(el);
	
}

/////////////////////////////////////////////////////////

void Scene::startController()
{
	controlThread = thread(&Scene::eventListener, this);
}

void Scene::eventListener()
{
	SDL_Event event;

	while(running)
	{
		SDL_WaitEvent(&event);

		if(event.type == SDL_QUIT)
		{
			running = false;
		}

		controlHero(event);

	}
}

void Scene::controlHero(const SDL_Event& event)
{
	if(event.key.keysym.sym == 'a')
	{
		hero->moveIn(Vec(-1.0f, 0.0f));
	}
	else if(event.key.keysym.sym == 'd')
	{
		hero->moveIn(Vec(1.0f, 0.0f));
	}
	else if(event.key.keysym.sym == 'w')
	{
		hero->moveIn(Vec(0.0f, -1.0f));
	}
	else if(event.key.keysym.sym == 's')
	{
		hero->moveIn(Vec(0.0f, 1.0f));
	}
}

/////////////////////////////////////////////////////////
