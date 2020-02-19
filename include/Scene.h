#ifndef SCENE_H
#define SCENE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <memory>
#include <vector>
#include <string>
#include <fstream>
#include <thread>

#include "actors/VisualElement.h"
#include "actors/Actor.h"
#include "actors/HeadOfSnake.h"
#include "actors/BodyOfSnake.h"
#include "actors/Apple.h"
#include "Command.h"
#include "Geometry.h"


using namespace std;

typedef vector<shared_ptr<Actor> > Objects;

class Scene
{
	public:
		Scene();
		~Scene();

		void draw(SDL_Renderer* ren);

		void tick();

		void load(const string& filename, SDL_Renderer* ren);
	
	private:

		void addSnake(SDL_Texture* tex, const Rectangle& rect);
		void addElementOfBody(SDL_Texture* tex, const Rectangle& rect, const shared_ptr<Actor>& target);

		void addApple(SDL_Texture* tex, const Rectangle& rect);

		void runFuncById(int id);

		void snakeEatApple();

	public:

		bool running;

	private:
		Objects objects;


		vector<string> readFile(fstream& file);
		vector<Command> parse(const vector<string>& linesOfFile);
		void runCommand(const vector<Command>& commands, SDL_Renderer* ren);

		void createNewActor(const Command& command, SDL_Renderer* ren);

		///////////////////////////////////
		
		void checkTouchs();
		bool circleVsCircle(shared_ptr<Actor> circle1, shared_ptr<Actor> circle2);
		
		///////////////////////////////////
		
		thread controlThread;
	public:
		void startController();

	private:
		void eventListener();
		shared_ptr<HeadOfSnake> hero;
		void controlHero(const SDL_Event& event);


		shared_ptr<Apple> apple;
		void createAppleAtRandom();

		///////////////////////////////////
};

#endif
