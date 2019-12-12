#include <iostream>
#include <string>

class Fraction
{
private:
	int numerator_;
	int denominator_;
public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction(std::string input)
	{
		const int found = input.find("/");
		if (found != -1)
		{
			std::string a = input.substr(0, found);
			std::string b = input.substr(found + 1, input.length());
			numerator_ = stoi(a, 0, 10);
			denominator_ = stoi(b, 0, 10);
		}
		else
			throw std::exception("Wrong input");
	}

	int get_numerator()
	{
		return numerator_;
	}
	void set_numerator(int numerator)
	{
		numerator_ = numerator;
	}

	int get_denominator()
	{
		return denominator_;
	}
	void set_denominator(int denominator)
	{
		denominator_ = denominator;
	}
	std::string to_string();
	float decimalize();
};

float Fraction::decimalize()
{
	return (float)numerator_ / denominator_;
}

std::string Fraction::to_string()
{
	std::string data;
	int num, den, integer_part, remainder;

	num = numerator_;
	den = denominator_;

	integer_part = num / den;
	remainder = integer_part * den;
	num -= remainder;

	data += "Integer part:\t";
	data += std::to_string(integer_part);
	data += "\nFraction:\t";
	data += std::to_string(num);;
	data += "/";
	data += std::to_string(den);;

	return data;
}


int main()
{
	std::string input = "";
	getline(std::cin, input);

	try
	{
		Fraction fr(input);
	}
	catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}

	system("pause");
	return 0;
}