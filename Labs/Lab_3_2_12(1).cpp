// Lab_3_2_12(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{	
	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 }; 
	int n = sizeof(vector) / sizeof(vector[0]);
	
	int* pArrMin = vector;
	
	for (int i = 1; i < n; i++)
	{
		if (vector[i] < *pArrMin)
		{
			pArrMin = &vector[i];
		}
	}
	cout << "Min: " << *pArrMin << "\tplace: " << pArrMin << std::endl;
	system("pause");
    return 0;
}
