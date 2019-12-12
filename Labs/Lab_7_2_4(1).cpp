#include <iostream>
#include <string>

class NegativeException : public std::exception
{
private:
	std::string m_error;

public:
	NegativeException(std::string error)
		: m_error(error) { }

	const char* what() const noexcept { return m_error.c_str(); }
};

class GeometryValidator
{
public:

	static void validate_rectangle_side(float side1, float side2)
	{
		if ((side1 <= 0) && (side2 <= 0)) {
			throw NegativeException("Your input is not valid. The area can't be negative.");
		}
	}

	static void validate_square_side(float side)
	{
		validate_rectangle_side(side, side);
	}
};

float square_area(float a)
{
	GeometryValidator::validate_square_side(a);

	return a * a;
}

float rectangle_area(float a, float b)
{
	GeometryValidator::validate_rectangle_side(a, b);

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
	catch (NegativeException & e)
	{
		std::cout << e.what() << "\n";
	}

	system("pause");
	return 0;
}