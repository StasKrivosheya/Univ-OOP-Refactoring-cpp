// Lab_4_5_6(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include<string>
#include<iostream>
#include <sstream>
using namespace std;

int main() {
	string sentence, line;

	while (getline(cin, sentence)) {
		istringstream tr(sentence);
		while (tr >> line)
			cout << line << ' ';
		cout << endl;
	}

	cout << sentence << "\n";

	return 0;
}


