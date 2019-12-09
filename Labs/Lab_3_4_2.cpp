#include <iostream>

bool is_leap(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return true;
	return false;
}

int monthLength(int year, int month)
{
	const int LENGTHS[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	if (month == 2 && is_leap(year)) {
		return 29;
	}
	else {
		return *(LENGTHS + (month - 1));
	}
}

int main(void)
{
	const int year1 = 2000;
	const int year2 = 2002;
	const int month_amount = 12;

	for (int yr = year1; yr < year2; yr++) {
		for (int mo = 1; mo <= month_amount; mo++)
			std::cout << monthLength(yr, mo) << " ";
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}