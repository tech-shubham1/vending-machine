#include "Vending.h"
#include <iostream>
#include <time.h>
#include <iomanip>

using namespace std;

Vending::Vending()
{
	balance = 0.00;
	profit = 0.00;
	Drink Default1("Sprite", 50.00, 100);
	Drink Default2("Coke", 40.00, 100);
	Drink Default3("Water", 20.00, 0);
	menu.push_back(Default1);
	menu.push_back(Default2);
	menu.push_back(Default3);
}
void Vending::machineRun()
{
	int choice;
	cout << "ROOT MENU" << endl<<endl;
	while (1)
	{
		cout << "Please make a selection" << endl;
		cout << "1 = Consumer mode" << endl;
		cout << "2 = Maintenance mode" << endl;
		cout << "0 = Quit" << endl<<endl;
		cout << "User Input: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			consumerMode();
			break;
		case 2:
			maintnanceMode();
			break;
		case 0:
			break;
		default:
			cout << "Error, Please chek you input" << endl;
			break;
		}
		if (choice == 0)
		{
			cout << "Exiting Run mode" << endl;
			break;
		}
	}
}
void Vending::maintnanceMode()
{
	int choice;
	cout << "MAINTENANCE MODE" << endl << endl;
	while (1)
	{
		cout << "Please select an option: " << endl << endl;
		cout << "1 ----- Add new drink type" << endl;
		cout << "2 ----- Restock drink" << endl;
		cout << "3 ----- Edit existing Drink" << endl;
		cout << "4 ----- Print machine status" << endl;
		cout << "0 ----- Quit Maintenance mode" << endl << endl;
		cout << "User Input: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			newDrink();
			break;
		case 2:
			restock();
			break;
		case 3:
			editDrink();
			break;
		case 4:
			printStatus();
			break;
		case 0:
			break;
		default:
			cout << "Please check your input" << endl;
			break;
		}
		if (choice == 0)
		{
			cout << "Exiting Maintenance Mode..." << endl << endl;
			break;
		}
	}
}
void Vending::consumerMode()
{
	int choice;
	cout << "CONSUMER MODE" << endl << endl;
	while (1)
	{
		printBal();
		cout << "What would u like to do? " << endl;
		cout << "1 = Add credit" << endl;
		cout << "2 = Show Drink data" << endl;
		cout << "3 = Purcahse" << endl;
		cout << "4 = Refund" << endl;
		cout << "0 = Quit Consumer Mode" << endl<<endl;
		cout << "User Input: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			credit();
			break;
		case 2:
			printDrink(choice);
			break;
		case 3:
			purchase();
			break;
		case 4:
			refund();
			break;
		case 0:
			break;
		default:
			cout << "Error, Please check you input" << endl;
			break;
		}
		if (choice == 0)
		{
			cout << "Exiting consumer mode" << endl<<endl;
			break;
		}
	}
	cout << "Thanks for the purchase" << endl << endl;
}
void Vending::refund()
{
	if (balance == 0)
	{
		cout << "Balance is empty" << endl<<endl;
	}
	else
		cout << "Refunding Rs." << setprecision(2) << fixed << balance << "." << endl << endl;
	balance = 0;
}
void Vending::credit()
{
	int choice;
	while (1)
	{
		printBal();
		cout << "What would u like to add? " << endl;
		cout << "1 = 5 Rupees" << endl;
		cout << "2 = 10 Rupees" << endl;
		cout << "3 = 50 Rupees" << endl;
		cout << "0 = Back" << endl;
		cout << "User Input: ";
		cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
			balance += 5.00;
			break;
		case 2:
			balance += 10.00;
			break;
		case 3:
			balance += 50.00;
			break;
		case 0:
			break;
		default:
			cout << "Error, Please check you input" << endl<<endl;
			break;
		}
		if (choice == 0)
		{
			cout << "Exiting credit mode" << endl<<endl;
			break;
		}
	}
}
void Vending::editDrink()
{
	int choice1, choice2;
	string tempName;
	double tempPrice;
	int tempCal;
	cout << "NEW DRINK MODE" << endl << endl;
	while (1)
	{
		cout << "Select drink to edit:" << endl << endl;
		for (int i = 0; i < menu.size(); i++)
		{
			cout << i+1<< ": " << menu[i].getName() << endl;
		}
		cout << "0: Back" << endl << endl;

		cout << "User Input: ";

		cin >> choice1;
		cout << endl;

		if (choice1 <= menu.size() && choice1 > 0)
		{
			choice1 -= 1;
			while (1)
			{
				cout << "Choose a field to edit" << endl;
				cout << "1: Name" << endl;
				cout << "2: Price" << endl;
				cout << "3: Calories" << endl;
				cout << "0: Back" << endl<<endl;
				cout << "User Input: ";
				cin >> choice2;
				cout << endl;
				switch (choice2)
				{
				case 1:
					cout << "Enter new name: ";
					cin >> tempName;
					cout << endl;
					menu[choice1].setName(tempName);
					break;
				case 2:
					cout << "Enter new price: ";
					cin >> tempPrice;
					cout << endl;
					menu[choice1].setPrice(tempPrice);
					break;
				case 3:
					cout << "Emter new calorie count: ";
					cin >> tempCal;
					cout << endl;
					menu[choice1].setCal(tempCal);
					break;
				case 0:
					break;
				default:
					cout << "Please check your input" << endl;
					break;
				}
				if (choice2 == 0)
				{
					break;
				}
			}
		}
		else if (0 == choice1)
		{
			cout << "Exiting drink editing mode..." << endl;
			break;
		}
	}
}
void Vending::newDrink()
{
	string drinkName;
	double drinkPrice;
	int drinkCal;
	Drink tempDrink("null", 0,0);
	int choice;
	cout << "NEW DRINK MODE" << endl << endl;
	while (1)
	{
		cout << "Name: ";
		cin >> drinkName;
		cout << "Price: ";
		cin >> drinkPrice;
		cout << "Calories: ";
		cin >> drinkCal;
		tempDrink.setName(drinkName);
		tempDrink.setPrice(drinkPrice);
		tempDrink.setCal(drinkCal);
		menu.push_back(tempDrink);
		cout << "Drink Created. Enter 1 to create another or anything else to quit" << endl<<endl;
		cout << "User Input: ";
		cin >> choice;
		cout << endl;
		if (choice != 1)
		{
			cout << "Exiting Drink creator" << endl << endl;
			break;
		}
	}
}
void Vending::purchase()
{
	int choice;
	cout << "PURCHASE MODE" << endl << endl;
	while (1)
	{
		cout << "Please make a selection: " << endl << endl;
		printMenu();
		cout << "0: Back" << endl << endl;
		cout << "User Input: ";
		cin >> choice;
		cout << endl;
		if (choice < menu.size() && choice > 0)
		{
			choice -= 1;
			if (menu[choice].getPrice() > balance)
			{
				cout << "Insufficient Funds. Please make another selection." << endl;
			}
			else if (menu[choice].getCount() == 0)
			{
				cout << "Out of Stock" << endl;
			}
			else
			{
				debt(menu[choice].getPrice());
				profit += menu[choice].getPrice();
				menu[choice].minusCount();
			}
		}
		else if (choice == 0)
		{
			cout << "Exiting Purchase mode..." << endl;
			break;
		}
	}
}
void Vending::printStatus()
{
	int total = 0;
	cout << "VENDING MACHINE STATUS: " << endl << endl;
	cout << "Drink Name      Price          Stock" << endl;
	for (int i = 0; i < menu.size(); i++)
	{
		cout << menu[i].getName() << " ";
		for (int j = 0; j < 15; j++)
		{
			if (j > menu[i].getName().length())
				cout << " ";
		}
		cout << " Rs." << setprecision(2) << fixed << menu[i].getPrice();
		for (int j = 0; j < 12; j++)
		{
			cout << " ";
		}
		cout << menu[i].getCount() << endl;
		total += menu[i].getCount();
	}
	cout << "Profit: Rs." << profit << endl;
	cout << "Total Drinks: " << total << endl << endl;
}
int Vending::getInput(int num)
{
	while (1)
	{
		cin >> input;
		if (input <= num)
			return input;
		else
			cout << "Please check your input" << endl;
	}
}
void Vending::debt(double d)
{
		balance -= d;
}
void Vending::printMenu()
{
	cout << "Current Menu:" << endl << endl;
	for (int i = 0; i < menu.size(); i++)
	{
		cout << i + 1 << ": "<< menu[i].getName() <<" ";
		for (int j = 0; j < 20 ; j++)
		{
			if (j > menu[i].getName().length())
				cout << "-";
		}
		if (menu[i].getCount() != 0)
		{
			cout << " Rs." << setprecision(2) << fixed << menu[i].getPrice() << endl;
		}
		else
			cout << " SOLD OUT" << endl;
	}
}
void Vending::change()
{
	cout << "Dispensing " << balance / .25 << " quarters" << endl;
	balance = 0;
}
//restock mode starts
void Vending::restock()
{
	int choice1; //choice1 is drink at menu[choice1]
	int choice2; //coice 2 is amount to add to restock
	int choice3;
	int max = 20;
	cout << "RESTOCKING MODE" << endl;
	while (1)
	{
		cout << "What would you like to restock" << endl;
		printMenu();
		cout << "0: Back" << endl;
		cin >> choice1;
		if (choice1 <= menu.size() && choice1 > 0)
		{
			choice1 -= 1;
			cout << choice1 << ": " << menu[choice1].getName() << "(" << menu[choice1].getCount() << ")" << endl << endl << endl;
			while (1)
			{
				cout << "How much do you want to add" << endl;
				cin >> choice2;
				if (menu[choice1].getCount() + choice2 > max || menu[choice1].getCount() + choice2 < 0)
				{
					cout << "Error: Too much drinks in machine, enter smaller amount";
				}
				else
				{
					menu[choice1].setCount(menu[choice1].getCount() + choice2);
					cout << "Successfully Restocked. Current stock of " << menu[choice1].getName() << ": " << menu[choice1].getCount() << endl;
				}
				cout << "Enter 1 to create another or anything else to quit" << endl;
				cin >> choice3;
				if (choice3 != 1)
				{
					break;
				}
			}
		}
		else
		{
			cout << "Exiting restocking mode..." << endl << endl;
			break;
		}
	}
}
void Vending::printBal()
{
	cout << "Current Balance: Rs." << setprecision(2) << fixed << balance << endl;
}
void Vending::printDrink(int n)
{
	cout << "Drink:" << menu[n].getName() << endl;
	cout << "Price: Rs." << menu[n].getPrice() << endl;
	cout << "Calories:" << menu[n].getCal() << endl;
}
void Vending::printProfit()
{
	cout << profit << endl;
}
Vending::~Vending()
{
}
