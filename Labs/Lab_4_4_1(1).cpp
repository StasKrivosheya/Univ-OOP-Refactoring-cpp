// Lab_4_4_1(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string inputString;
	getline(cin, inputString);
	int alphabetTab = 0;
	int alphabet[26];	
	int flag = 0;
	
	for (int i = 0; i < 26; i++) {
		alphabet[i] = 0;
	}

	for (int i = 0; i < inputString.length(); i++) {
		int insertNum = (tolower(inputString[i]) - 'a');
		if (insertNum < 0 || insertNum > 25) {
			continue;
		}
		if (alphabet[insertNum] == 0) {
			alphabetTab++;
		}
		if (alphabetTab >= 26) {
			flag = 1;
			break;
		}
		else {
			alphabet[insertNum]++;
		}
	}
	
	for(int i = 0; i < 26; i++){
		cout << (char)(i + 97) << " - " << alphabet[i] << endl;
	}

	if (flag) {
		cout << "Pangram" << endl;
	}
	else {
		cout << "Not pangram" << endl;
	}

	system("pause");
	return 0;
}

