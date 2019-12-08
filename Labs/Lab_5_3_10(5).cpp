// Lab_5_3_10(5).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include<string>
#include <cmath>

using namespace std;

class Fraction { 
public:  
	Fraction(int numerator, int denominator); 
	string toString(); 
	double toDouble(); 
private:
	int numerator; 
	int denominator; 
};

Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
}

double Fraction::toDouble()
{
	double one = 1, answer;

	one *= this->numerator;

	answer = one / this->denominator;

	return answer;
}
string Fraction::toString()
{
	string data, input;
	int num, den, whole, remain;
	double answer, one = 1;
	num = this->numerator;
	den = this->denominator;
	whole = num / den;
	remain = whole * den;
	num -= remain;
	input = to_string(whole);
	data += input;
	data += " ";
	input = to_string(num);
	data += input;
	data += "/";
	input = to_string(den);
	data += input;
	return data;
}


int main()
{
	int num, den; 
	string input = ""; 
	getline(cin, input);
		
	if (input.find("/") != -1) {
		int x = input.find("/");
		string a = input.substr(0, x);
		string b = input.substr(x + 1, input.length());
		num = stoi(a, 0, 10);
		den = stoi(b, 0, 10);
	}
			
	Fraction fraction(num, den);
	cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;
	
	system("pause");
	return 0;
}

