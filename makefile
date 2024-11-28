instructions: main.o
	g++ main.o -o instructions

main.o: main.cpp
	g++ -c main.cpp

clean:
	rm *.o instructions