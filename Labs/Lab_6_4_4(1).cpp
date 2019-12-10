#include <iostream>
#include <string>

class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool is_valid(std::string input) = 0;
};

class ExactValidator : public StringValidator
{
private:
	std::string password;
public:
	ExactValidator(std::string input)
	{
		password = input;
	}
	bool is_valid(std::string input);
};

bool ExactValidator::is_valid(std::string input)
{
	return input == password;
}

class DummyValidator : public StringValidator
{
public:
	bool is_valid(std::string input);
};

bool DummyValidator::is_valid(std::string input)
{
	return true;
}


void print_valid(StringValidator& validator, std::string input) {
	std::cout << "The string '" << input << "' is "
		<< (validator.is_valid(input) ? "valid" : "invalid");
}

int main() {
	DummyValidator dummy;
	print_valid(dummy, "hello");
	std::cout << std::endl;

	ExactValidator exact("secret");
	print_valid(exact, "hello");
	std::cout << std::endl;

	print_valid(exact, "secret");
	std::cout << std::endl << std::endl;

	system("pause");
	return 0;
}