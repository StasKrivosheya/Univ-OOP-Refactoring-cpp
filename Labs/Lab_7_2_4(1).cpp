#include <iostream>
#include <string>

struct NegativeException
{
	std::string msg;

	NegativeException(const std::string& msg) : msg(msg) { }
};

float square_area(float a)
{
	if (a <= 0)
		throw NegativeException("Your input is not valid. The area can't be negative.");
	return a * a;
}

float rectangle_area(float a, float b)
{
	float c = 0.0f;
	if (a <= 0 && b <= 0)
		throw NegativeException("Your input is not valid. The area can't be negative.");
	return a * b;
}

int main(void)
{
	float a, b;
	std::cin >> a >> b;
	try
	{
		float rsquare = square_area(a);
		float rrectangle = rectangle_area(a, b);
		std::cout << rsquare << std::endl << rrectangle << std::endl;
	}
	catch (NegativeException& e)
	{
		std::cout << e.msg << "\n";
	}

	system("pause");
	return 0;
}