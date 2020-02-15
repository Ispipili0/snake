all: snake

FLAGS = -lSDL2 -lSDL2_image -lSDL2_mixer 

snake: main.o game.o
	g++ -OO -g main.o game.o -o snake $(FLAGS)

main.o: main.cpp
	g++ -g -c main.cpp

game.o: src/game.cpp
	g++ -g -c src/game.cpp $(FLAGS)
