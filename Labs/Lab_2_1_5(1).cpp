// Lab_2_1_5(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


void year_(int year) {
	
	if (((year % 4 == 0) and (year % 100 != 0)) or (year % 400 == 0)) {
		cout << "Leap year\n";
	}
	else {
		cout << "Common year\n";
	}
}

int main(int year) {
		
	cout << "2000 == Expected value == Leap year => Function Value == " ;
	year_(2000);
	cout << "2015 == Expected value == Common year => Function Value == ";
	year_(2015);
	cout << "1999 == Expected value == Common year => Function Value == ";
	year_(1999);
	cout << "1996 == Expected value == Leap year => Function Value == ";
	year_(1996);
	cout << "1900 == Expected value == Common year => Function Value == ";
	year_(1900);
	
	system("pause");

	return 0;
}

