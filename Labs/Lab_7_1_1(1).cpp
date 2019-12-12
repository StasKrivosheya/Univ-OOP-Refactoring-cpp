#include <iostream>
#include <string>

void calculate_division(int numerator, int denominator)
{
	try
	{
		if (denominator == 0)
			throw std::exception("Your input is not valid, you can't divide by zero.\n");
		int result = numerator / denominator;
		std::cout << result << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}
}

int main()
{
	const int NUMERATOR = 8;
	int denominator = 0;

	std::cout << "Value b : ";
	std::cin >> denominator;

	calculate_division(NUMERATOR, denominator);

	system("pause");
	return 0;
}