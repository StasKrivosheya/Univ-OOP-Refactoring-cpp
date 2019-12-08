// Lab_2_1_5(2).cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
using namespace std;


void tax_calculate(float grossprice, float taxrate) {
	

	cout << "grossprice = " << grossprice << " taxrate = " << taxrate << endl;

	float netprice, taxvalue;
	
	if (grossprice > 0) {
		if ((taxrate > 0) and (taxrate <= 100)) {
			netprice = grossprice / (1 + (taxrate / 100));
			taxvalue = netprice * (taxrate / 100);
		}
	}

	cout << "Net price: " << netprice << endl;
	cout << "Tax value: " << taxvalue << endl;
	cout << endl;
}

int main(void){
	
	
	
	// cout << "Enter a gross price: ";
	// cin >> grossprice;
	// cout << "Enter a tax rate: ";
	// cin >> taxrate;
	
	tax_calculate(123, 23);
	tax_calculate(123, 50);
	tax_calculate(123, 98);
	tax_calculate(11, 10);
	

	system("pause");

	return 0;
}
