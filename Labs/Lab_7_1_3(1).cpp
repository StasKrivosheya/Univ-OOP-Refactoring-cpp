#include <iostream>
#include <string>

void validate_division_operands(int numerator, int denominator)
{
	if ((denominator == 0) && (numerator == 0))
	{
		throw std::exception("There is no need for expression.\n");
	}

	if (denominator == 0)
	{
		throw std::exception("Your input is not valid, you can't divide by zero.\n");
	}
}

int calculate_division(int numerator, int denominator)
{
	try
	{
		validate_division_operands(numerator, denominator);

		return numerator / denominator;
	}
	catch (std::exception e)
	{
		std::cout << e.what();
	}
}

int main()
{
	int numerator = 0, denominator = 0, result = 0;

	std::cout << "Input a and b:\n";
	std::cin >> numerator >> denominator;

	result = calculate_division(numerator, denominator);

	std::cout << result << std::endl;

	system("pause");
	return 0;
}