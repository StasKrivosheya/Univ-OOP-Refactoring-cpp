#include<iostream>
#include<string>

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool is_valid(std::string input) = 0;
};

class PatternValidator : public StringValidator
{
private:
	std::string val;
public:
	PatternValidator(std::string val) : val(val) {}
	bool is_valid(std::string input) override;
};

bool PatternValidator::is_valid(std::string input)
{
	std::string tmp_str;
	bool is_pattern = true;

	for (int i = 0; i < input.size(); i++)
	{
		if (input.size() - i < val.size())
			break;

		tmp_str = input.substr(i, val.size());

		const char ANY_SYMBOL = '?';
		const char DIGIT = 'D';
		const char ALPHA = 'A';

		for (int j = 0; j < tmp_str.size(); j++)
		{
			switch (val[j])
			{
			case ANY_SYMBOL:
				continue;
				break;
			case DIGIT:
				if (isdigit(tmp_str[j]))
					continue;
				else
				{
					is_pattern = false;
					break;
				}
				break;
			case ALPHA:
				if (isalpha(tmp_str[j]))
					continue;
				else
				{
					is_pattern = false;
					break;
				}
			default:
				if (isalpha(val[j]))
				{
					if (tolower(val[j]) != tolower(tmp_str[j]))
					{
						is_pattern = false;
						break;
					}
					else
						continue;
				}
				else
				{
					if (val[j] != tmp_str[j])
					{
						is_pattern = false;
						break;
					}
				}
				break;
			}

		}
		if (is_pattern)
		{
			return true;
		}
		is_pattern = true;
	}
	return !is_pattern;
}

class MaxLengthValidator : public StringValidator
{
private:
	int max_length;
public:
	MaxLengthValidator(int num) : max_length(num) { }

	bool is_valid(std::string input) override;
};

bool MaxLengthValidator::is_valid(std::string input)
{
	return input.length() <= max_length;
}

class MinLengthValidator : public StringValidator
{
private:
	int min_length;
public:
	MinLengthValidator(int num) : min_length(num) { }

	bool is_valid(std::string input) override;
};

bool MinLengthValidator::is_valid(std::string input)
{
	return input.length() >= min_length;
}

void print_valid(StringValidator& validator, std::string input)
{
	std::cout << "The string '" << input << "' is "
		<< (validator.is_valid(input) ? "valid" : "invalid") << std::endl;
}

void test_validators()
{
	std::cout << "MinLengthValidator" << std::endl;
	MinLengthValidator min(6);
	print_valid(min, "hello");
	print_valid(min, "welcome");
	std::cout << std::endl;

	std::cout << "MaxLengthValidator" << std::endl;
	MaxLengthValidator max(6);
	print_valid(max, "hello");
	print_valid(max, "welcome");
	std::cout << std::endl;

	std::cout << "PatternValidator" << std::endl;
	PatternValidator digit("D");
	print_valid(digit, "there are 2 types of sentences in the world");
	print_valid(digit, "valid and invalid ones");
	std::cout << std::endl;
}

int main()
{
	test_validators();

	system("pause");
	return 0;
}