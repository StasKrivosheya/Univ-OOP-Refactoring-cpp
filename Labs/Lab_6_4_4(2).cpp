// Lab_6_4_4(2).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;


class StringValidator
{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(std::string input) = 0;
};

class PatternValidator : public StringValidator {
public:
	string val;

	PatternValidator(string val) : val(val) {}

	bool isValid(std::string input) override;

};

bool PatternValidator::isValid(std::string input) {
	string tmpStr;
	bool isPattern = true;
	for (int i = 0; i < input.size(); i++) {
		if (input.size() - i < val.size()) {
			break;
		}
		tmpStr = input.substr(i, val.size());
		for (int j = 0; j < tmpStr.size(); j++) {
			if (val[j] == '?') continue;
			if (val[j] == 'D') {
				if (isdigit(tmpStr[j])) {
					continue;
				}
				else {
					isPattern = false;
					break;
				}
			}
			if (val[j] == 'A') {
				if (isalpha(tmpStr[j])) {
					continue;
				}
				else {
					isPattern = false;
					break;
				}
			}
			if (isalpha(val[j])) {
				if (tolower(val[j]) != tolower(tmpStr[j])) {
					isPattern = false;
					break;
				}
				else {
					continue;
				}
			}
			else {
				if (val[j] != tmpStr[j]) {
					isPattern = false;
					break;
				}
			}
		}
		if (isPattern) {
			return isPattern;
		}
		isPattern = true;
	}
	return !isPattern;
}

class MaxLengthValidator :public StringValidator {
private:
	int num;
public:
	MaxLengthValidator(int num) : num(num) {}

	bool isValid(std::string input) override;
};

bool MaxLengthValidator::isValid(std::string input) {
	if (input.length() > num) {
		return false;
	}
	else {
		return true;
	}
}

class MinLengthValidator : public StringValidator {
private:
	int num;
public:
	MinLengthValidator(int num) : num(num) {}

	bool isValid(std::string input) override;
};



bool MinLengthValidator::isValid(std::string input) {
	if (input.length() < num) {
		return false;
	}
	else {
		return true;
	}
}

void printValid(StringValidator &validator, string input)
{
	cout << "The string '" << input << "' is "
		<< (validator.isValid(input) ? "valid" : "invalid") << endl;
}
int main()
{
	cout << "MinLengthValidator" << endl;
	MinLengthValidator min(6);
	printValid(min, "hello");
	printValid(min, "welcome");
	cout << endl;
	cout << "MaxLengthValidator" << endl;
	MaxLengthValidator max(6);
	printValid(max, "hello");
	printValid(max, "welcome");
	cout << endl;
	cout << "PatternValidator" << endl;
	PatternValidator digit("D");
	printValid(digit, "there are 2 types of sentences in the world");
	printValid(digit, "valid and invalid ones");
	cout << endl;
	system("pause");
	return 0;
}
