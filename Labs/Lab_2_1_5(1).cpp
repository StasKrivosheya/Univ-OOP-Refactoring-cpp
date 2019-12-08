#include <iostream>
#include <string>

std::string yearInfo(int year)
{
	bool isLeap = ((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0;
	std::string info;

	if (isLeap)
		info = "Leap year\n";
	else
		info = "Common year\n";

	return info;
}

void printYearInfo(int year)
{
	std::cout << year << " == Expected value == Leap year => Function Value == "
						<< yearInfo(year);
}

int main(int year)
{

	printYearInfo(2000);
	printYearInfo(2015);
	printYearInfo(1999);
	printYearInfo(1996);
	printYearInfo(1900);

	system("pause");

	return 0;
}
