// Lab_7_1_3(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;

int main(void) {
	int a = 0, b = 0, c = 0;
	
	cin >> b;
	cin >> a;

	try {
		
		if ((b == 0) and (a == 0)) {
			throw exception("There is no need for expression.\n");
		}

		if (b == 0) throw exception("Your input is not valid, you can't divide by zero.\n");
		
		c = a / b;
	}
	catch (exception&e) {
		cout << e.what();
	}

	cout << c << endl;
	system("pause");
	return 0;
}

