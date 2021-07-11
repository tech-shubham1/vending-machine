#ifndef __Vending
#define __Vending

#include <string>
#include "Drink.h"
#include <vector>

using namespace std;
class Vending
{
public:
	Vending();
	void debt(double);
	void change();
	void printBal();
	void printMenu();
	int getInput(int);
	void refund();
	void machineRun(); // runs vending
	void consumerMode(); // enters consumer mode
	void maintnanceMode(); // enters maintnance moe
	void credit();
	void printDrink(int);
	void purchase();
	void editDrink();
	void restock();
	void newDrink();
	void printProfit();
	void printStatus();
	~Vending();
private:
	vector<Drink> menu;
	vector<int>inv;
	unsigned int input;
	double balance;
	double profit;
	string name;
	
};
#endif
