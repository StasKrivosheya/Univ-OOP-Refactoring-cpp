// Lab_5_1_9(4).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;


class ShopItemOrder {

	/* The item order shall store the following information : 
		-item name; 
		-item unit price; 
		-number of items ordered. */

private:
	string name; 
	float unit_price; 
	int number_ordered;

/* There will be access methods allowing to:
		-get and set all of the above information;
		-get the total price for the order; */

public:
	void set(string name_, double unit_price_, int number_ordered_){
		name = name_;
		unit_price = unit_price_;
		number_ordered = number_ordered_;
	}
	string NameItem() {
		return name;
	}
	float PriceItem() {
		return unit_price;
	}
	int NumberItem() {
		return number_ordered;
	}
	double GetTotalPrice() {
		return number_ordered * unit_price;
	}
	
	/* Print the order in a user-friendly way. */
	
	void Print()
	{
		cout << "Ordered: " << name << endl << "Number: " << number_ordered << endl << "Price: " << unit_price << endl;;
	}
};

int main()
{	
	ShopItemOrder item_1;
	item_1.set("MacBook", 2000., 2);
	item_1.Print();
	cout << "===========" << endl;
	cout << "Total price: " << item_1.GetTotalPrice() << endl;

	system("pause");
    return 0;
}
