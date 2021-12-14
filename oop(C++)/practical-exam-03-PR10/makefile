L : q1

q1 : Lightbox.o main-1-1.cpp
	g++ -o l main-1-1.cpp Lightbox.o

Lightbox.o: Lightbox.h Lightbox.cpp
	g++ -c Lightbox.cpp

s : q2

q2 : Shelf.o main-1-2.cpp Lightbox.o
	g++ -o s main-1-2.cpp Shelf.o Lightbox.o

Shelf.o: Shelf.h Shelf.cpp
	g++ -c Shelf.cpp