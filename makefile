all: snake

FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer 

snake: main.o game.o Visual.o VisualElement.o
	g++ -OO -g main.o game.o Visual.o VisualElement.o -o snake $(FLAGS)

main.o: main.cpp
	g++ -g -c main.cpp

game.o: src/game.cpp
	g++ -g -c src/game.cpp $(FLAGS)

Visual.o: src/Visual.cpp
	g++ -g -c src/Visual.cpp $(FLAGS)

VisualElement.o: src/actors/VisualElement.cpp
	g++ -g -c src/actors/VisualElement.cpp
