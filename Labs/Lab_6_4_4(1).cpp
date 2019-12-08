// Lab_6_4_4(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>

using namespace std;

class StringValidator{
public:
	virtual ~StringValidator() {};
	virtual bool isValid(string input)= 0;
};

class ExactValidator : public StringValidator
{
private:
	string password;

public:
	ExactValidator(string input) {this->password = input;}
	bool isValid(string input);
};

bool ExactValidator::isValid(string input)
{
	cout << input << endl;
	if (input.compare(this->password) == 0)
		return true;
	else
		return false;
}

class DummyValidator : public StringValidator {
public:
	bool isValid(string input);
};

bool DummyValidator::isValid(string input){
	return true;
}


void printValid(StringValidator &validator, string input){  
	cout << "The string '" << input << "' is "       
		<< (validator.isValid(input) ? "valid" : "invalid");
}

int main(){  
	DummyValidator dummy;  
	printValid(dummy, "hello");  
	cout << endl;  
	ExactValidator exact("secret");  
	printValid(exact, "hello");
	cout << endl;
	printValid(exact, "secret");
	cout << endl;
	cout << endl;
	system("pause");
	return 0;
}
