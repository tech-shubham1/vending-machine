#ifndef __Drink
#define __Drink

//#pragma once
#include <string>
using namespace std;
class Drink
{ 
public: 
	Drink();
	Drink(string, double, int);
	string getName(); 
	double getPrice(); 
	int getCal(); 
	void setName(string);
	void setPrice(double);
	void setCal(int);
	int getCount();
	void setCount(int);
	void minusCount();
	~Drink();
private: 
	string name; 
	double price;
	int cal;
	int count; 
};


#endif