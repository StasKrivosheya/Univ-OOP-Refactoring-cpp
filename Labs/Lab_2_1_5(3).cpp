// Lab_2_1_5(3).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


void measurement_systems() {
	
	int sys;
	float m, ft, in;
	
	cout << "For Metric, enter 0. For Imperial, enter 1." << endl;
	cin >> sys;

	
	if (sys == 0) {
		cout << "Metric method. How many Meters?" << endl;
		cin >> m;
		float tf = 3.2808 * m;
		ft = floor(tf);
		in = ((tf - ft) * 12);
		cout << ft << "'" << in << "''" << endl;			
	}
	else if (sys == 1) {
		cout << "Imperial method. How many Feet?" << endl;
		cin >> ft;
		cout << "How many Inches?" << endl;
		cin >> in;
		m = ((ft * 12) + in) * 0.0254;
		cout << m << "m" << endl;
	}
}

int main(void) {
	
	measurement_systems();
	system("pause");
	return 0;
}

