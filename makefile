all: VendingMachine

VendingMachine: main.cpp Drink.h Drink.cpp Vending.h Vending.cpp
	g++ -o VendingMachine main.cpp Drink.h Drink.cpp Vending.h Vending.cpp

clean:
	rm -f VendingMachine 
