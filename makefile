addition: main.o
	g++ main.o -o addition

main.o: main.cpp
	g++ -c main.cpp