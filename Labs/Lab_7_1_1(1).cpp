// Lab_7_1_1(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int a = 8, b = 0, c = 0;
	cout << "Value b : ";
	cin >> b;
	
	try {

		if (b == 0) throw exception("Your input is not valid, you can't divide by zero.\n");
		c = a / b;
	
	}
	catch (exception&e)
	{
		cout << e.what();
	}
	
	cout << c << endl;
	system("pause");
	return 0;
}