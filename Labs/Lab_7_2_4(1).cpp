// Lab_7_2_4(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;


struct NegativeException
{
	string msg;

	NegativeException(const string& msg) :
		msg(msg)
	{}
};


float square_area(float a) {
	float c = 0;
	try {
		if (a <= 0) {
			throw NegativeException("Your input is not valid. The area can't be negative.");
		}

		c = a * a;
		
	}
	catch (NegativeException& e) {
		cout << e.msg << "\n";
	}

	return c;
}

float rectangle_area(float a, float b) {
	float c = 0;

	try {
		if ((a > 0) and (b > 0)){
			c = a * b;
		} else {
			throw NegativeException("Your input is not valid. The area can't be negative.");
		}

	}
	catch (NegativeException& e) {
		cout << e.msg << "\n";
	}

	return c;

}


int main(void) {
	float a, b;
	cin >> a;
	cin >> b;

	float rsquare = square_area(a);
	float rrectangle = rectangle_area(a, b);
	cout << rsquare << endl << rrectangle << endl;
	system("pause");
	return 0;
}
