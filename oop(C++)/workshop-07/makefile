m : q1

q1 : Musician.o main-1-1.cpp
	g++ -o m main-1-1.cpp Musician.o

Musician.o: Musician.h Musician.cpp
	g++ -c Musician.cpp

o : q2

q2 : Orchestra.o main-2-2.cpp Musician.o
	g++ -o o main-2-2.cpp Orchestra.o Musician.o

Orchestra.o: Orchestra.h Orchestra.cpp
	g++ -c Orchestra.cpp