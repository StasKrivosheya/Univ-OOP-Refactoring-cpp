// Lab_5_1_9(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

class Person{
public:
	string name;
	string color_eye;
	string favorit_tv_series;
	int age;	
};

void print(Person* person){
	cout << person->name << " is " << person->age << " years old.\n" << "He has a " << person->color_eye << " eye color. " 
		<< person->name << " likes to watch TV series \"" << person->favorit_tv_series << "\"." << endl;
}
 
int main(){  
	
	Person person;  
	person.name = "Harry";  
	person.age  = 23;
	person.color_eye = "green";
	person.favorit_tv_series = "Black Mirror";
	cout << "Meet " << person.name << "!" << endl;
	print(&person);
	
	Person friend_;
	friend_.name = "Tim";
	friend_.age = 26;
	friend_.color_eye = "blue";
	friend_.favorit_tv_series = "Mr. Robot";
	cout << "Meet " << friend_.name << "!" << endl;
	print(&friend_);

	system("pause");
	return 0;
}
