output: main.o Character.o Player.o Monster.o Item.o Bag.o Room.o function.cpp testmain
	g++ main.o Character.o Player.o Monster.o Item.o Bag.o Room.o function.cpp -o main
	bash testmain

main.o: main.cpp 
	g++ -c main.cpp 

Character.o: Character.cpp Character.h action.h
	g++ -c Character.cpp

Room.o: Room.h Character.h Room.cpp Item.h
	g++ -c Room.cpp


Player.o: Player.cpp Player.h Character.h Item.h Bag.h
	g++ -c Player.cpp

Monster.o: Monster.cpp Monster.h Character.h Item.h
	g++ -c Monster.cpp

Item.o: Item.cpp Item.h 
	g++ -c Item.cpp

Bag.o: Bag.cpp Bag.h Item.h
	g++ -c Bag.cpp

clean:
	rm *.o main
    




