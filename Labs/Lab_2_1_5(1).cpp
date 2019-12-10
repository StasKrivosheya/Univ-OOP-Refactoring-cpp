#include <iostream>
#include <string>

std::string year_info(int year)
{
	bool is_leap = ((year % 4 == 0) && (year % 100 != 0)) || year % 400 == 0;
	std::string info;

	if (is_leap)
		info = "Leap year\n";
	else
		info = "Common year\n";

	return info;
}

void print_year_info(int year)
{
	std::cout << year << " == Expected value == Leap year => Function Value == "
						<< year_info(year);
}

int main(int year)
{

	print_year_info(2000);
	print_year_info(2015);
	print_year_info(1999);
	print_year_info(1996);
	print_year_info(1900);

	system("pause");

	return 0;
}
