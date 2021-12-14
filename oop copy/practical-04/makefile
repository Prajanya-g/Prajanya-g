m : q1

q1 : meerkat.o main-1-1.cpp
	g++ -o m main-1-1.cpp meerkat.o

meerkat.o: meerkat.cpp meerkat.h
	g++ -c meerkat.cpp

p : q2

q2 : person.o main-1-2.cpp
	g++ -o p main-1-2.cpp person.o

person.o: person.cpp person.h
	g++ -c person.cpp

c : q3

q3 : cart.o meerkat.o main-2-1.cpp
	g++ -o c cart.o meerkat.o main-2-1.cpp

cart.o: cart.cpp cart.h
	g++ -c cart.cpp

a : q4

q4 : person.o main-2-2.cpp aircraft.o
	g++ -o a main-2-2.cpp person.o aircraft.o

aircraft.o: aircraft.cpp aircraft.h
	g++ -c aircraft.cpp