#include <iostream>
#include <string>

int main()
{
	const int numerator = 8;
	int denominator = 0, result = 0;

	std::cout << "Value b : ";
	std::cin >> denominator;

	try
	{
		if (denominator == 0)
			throw std::exception("Your input is not valid, you can't divide by zero.\n");
		result = numerator / denominator;
		std::cout << result << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what();
	}

	system("pause");
	return 0;
}