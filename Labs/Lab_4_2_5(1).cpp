// Lab_4_2_5(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "N: ";
	cin >> n;
	cout << n * (n + 1) / 2;
	system("pause");
	return 0;
}

