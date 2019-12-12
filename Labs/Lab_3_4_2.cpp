#include <iostream>

const int MONTH_AMOUNT = 12;

bool is_leap(int year)
{
	bool is_leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
	return is_leap;
}

int monthLength(int year, int month)
{
	const int LENGTHS[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	const int FEBRUARY = 2;
	if (month == FEBRUARY && is_leap(year)) {
		return 29;
	}
	else {
		return *(LENGTHS + (month - 1));
	}
}

void print(int year1, int year2)
{
	for (int yr = year1; yr < year2; yr++) {
		for (int mo = 1; mo <= MONTH_AMOUNT; mo++)
			std::cout << monthLength(yr, mo) << " ";
		std::cout << std::endl;
	}
}

int main(void)
{
	print(2000, 2002);

	system("pause");
	return 0;
}