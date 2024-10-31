operations: main.o
	g++ main.o -o operations

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o operations