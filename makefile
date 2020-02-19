all: snake

FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer -lpthread

snake: main.o game.o VisualElement.o Scene.o Command.o Geometry.o PhysicsElement.o Actor.o HeadOfSnake.o BodyOfSnake.o Apple.o
	g++ -fno-stack-protector -OO -g main.o game.o VisualElement.o Scene.o Command.o Geometry.o PhysicsElement.o Actor.o HeadOfSnake.o BodyOfSnake.o Apple.o -o snake $(FLAGS)

main.o: main.cpp
	g++ -g -c main.cpp

game.o: src/game.cpp
	g++ -g -c src/game.cpp 

VisualElement.o: src/actors/VisualElement.cpp
	g++ -g -c src/actors/VisualElement.cpp

Scene.o: src/Scene.cpp
	g++ -g -c src/Scene.cpp

Command.o: src/Command.cpp
	g++ -g -c src/Command.cpp

Geometry.o: src/Geometry.cpp
	g++ -g -c src/Geometry.cpp

PhysicsElement.o: src/actors/PhysicsElement.cpp
	g++ -g -c src/actors/PhysicsElement.cpp

Actor.o: src/actors/Actor.cpp
	g++ -g -c src/actors/Actor.cpp

HeadOfSnake.o: src/actors/HeadOfSnake.cpp
	g++ -g -c src/actors/HeadOfSnake.cpp

BodyOfSnake.o: src/actors/BodyOfSnake.cpp
	g++ -g -c src/actors/BodyOfSnake.cpp

Apple.o: src/actors/Apple.cpp
	g++ -g -c src/actors/Apple.cpp

clear: 
	rm snake *.o
