r : q1

q1 : RecordStore.o main-1-1.cpp
	g++ -o r main-1-1.cpp RecordStore.o

RecordStore.o: RecordStore.cpp RecordStore.h
	g++ -c RecordStore.cpp

a : q2

q2 : RecordStore.o main-2-1.cpp Amoeba.o
	g++ -o a main-2-1.cpp RecordStore.o Amoeba.o

Amoeba.o: Amoeba.cpp Amoeba.h
	g++ -c Amoeba.cpp

t : q3

q3 : RecordStore.o main-2-2.cpp Amoeba.o AmoebaTickets.o
	g++ -o t main-2-2.cpp RecordStore.o Amoeba.o AmoebaTickets.o

AmoebaTickets.o: AmoebaTickets.cpp AmoebaTickets.h
	g++ -c AmoebaTickets.cpp

c : q4

q4 : RecordStore.o main-3-1.cpp Amoeba.o AmoebaTickets.o StoreChain.o
	g++ -o c main-3-1.cpp RecordStore.o Amoeba.o AmoebaTickets.o StoreChain.o

StoreChain.o: StoreChain.h StoreChain.cpp
	g++ -c StoreChain.cpp

s : q2

q2 : RecordStores.o main-4-1.cpp Amoeba.o
	g++ -o s main-4-1.cpp RecordStores.o Amoeba.o

RecordStores.o: RecordStores.cpp RecordStores.h
	g++ -c RecordStores.cpp
