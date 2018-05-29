a.out: game.o bet.o player.o main.o
	g++ game.o bet.o player.o main.o
main.o: main.cpp
	g++ -c main.cpp
game.o: game.cpp game.h
	g++ -c game.cpp
bet.o: bet.cpp bet.h
	g++ -c bet.cpp
player.o: player.cpp
	g++ -c player.cpp

