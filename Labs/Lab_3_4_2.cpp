// Lab_3_4_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

bool isLeap(int year) { 
	if (((year % 4 == 0) and (year % 100 != 0)) or (year % 400 == 0)) {
		return true;
	}
	else {
		return false;
	}
}

int monthLength(int year, int month){
	int Lengths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	
	if (month == 2 && isLeap(year)) {
		return 29;
	}
	else {
		return *(Lengths + (month - 1));
	}
}

int main(void){
	for(int yr = 2000; yr < 2002; yr++) {
		for(int mo = 1; mo <= 12; mo++)
			cout << monthLength(yr,mo) << " ";
		cout << endl; 
	}
	system("pause");
	return 0;
}