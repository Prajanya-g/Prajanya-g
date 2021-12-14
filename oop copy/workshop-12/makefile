a : q1

q1 : Animal.o main-1-1.cpp
	g++ -o a main-1-1.cpp Animal.o

Animal.o: Animal.cpp Animal.h
	g++ -c Animal.cpp

h : q2

q2 : animal.o main-2-1.cpp Hunter.o
	g++ -o h main-2-1.cpp Animal.o Hunter.o

Hunter.o: Hunter.cpp Hunter.h
	g++ -c Hunter.cpp

v : q3

q3 : animal.o main-2-2.cpp Vegie.o
	g++ -o v main-2-2.cpp Animal.o Vegie.o

Vegie.o: Vegie.cpp Vegie.h
	g++ -c Vegie.cpp

z : q4

q4 : animal.o main-3-1.cpp Zoo.o Vegie.o Hunter.o
	g++ -o z main-3-1.cpp Animal.o Zoo.o Vegie.o Hunter.o

Zoo.o: Zoo.cpp Zoo.h
	g++ -c Zoo.cpp