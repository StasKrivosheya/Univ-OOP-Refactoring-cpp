// Lab_6_5_8(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

class IPAdress {
protected:
	string value;
public:
	IPAdress(const string &value) : value(value) {}
	IPAdress(const IPAdress &other) {
		this->value = other.value;
	}

	IPAdress() {}

	~IPAdress() {
		value = "";
	}
	void print() {
		cout << value << endl;
	}
};

class IPAs {
private:
	IPAdress * items;
	int n;
	int iter = 0;
public:
	IPAs(int n) : n(n) {
		items = new IPAdress[n];
	}

	IPAs() {
		items = new IPAdress[10000];
	}

	void AddtoArray(IPAdress ipAdress);
	void show(int n) {
		cout << "Network " << n << endl;
		for (int i = 0; i < iter; i++) {
			items[i].print();
		}
	}
};

void IPAs::AddtoArray(IPAdress ipAdress) {
	items[iter] = ipAdress;
	iter++;

}

int main(void) {
	string str, string1, string2;
	cout << "Enter text:" << endl;
	IPAs *ipAs1 = new IPAs();
	IPAs *ipAs2 = new IPAs();
	for (int i = 0; i < 5; i++) {
		getline(cin, str);
		IPAdress *ipAdress = new IPAdress(str);
		if (i < 2) {
			ipAs1->AddtoArray(*ipAdress);
		}
		else if (i == 2) {
			ipAs1->AddtoArray(*ipAdress);
			ipAs2->AddtoArray(*ipAdress);
		}
		else {
			ipAs2->AddtoArray(*ipAdress);
		}

	}

	ipAs1->show(1);
	ipAs2->show(2);
	system("pause");
	return 0;
}
