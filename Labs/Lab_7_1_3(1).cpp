#include <iostream>
#include <string>

int main()
{
	int a = 0, b = 0, c = 0;

	std::cout << "Input a and b:\n";
	std::cin >> a >> b;

	try
	{
		if (b == 0)
			throw std::exception("Your input is not valid, you can't divide by zero.\n");
		else if (a == 0)
			throw std::exception("There is no need for expression.\n");
		else
		{
			c = a / b;
			std::cout << "The integer part of division is: " << c << std::endl;
		}

	}
	catch (std::exception & e)
	{
		std::cout << e.what();
	}

	system("pause");
	return 0;
}