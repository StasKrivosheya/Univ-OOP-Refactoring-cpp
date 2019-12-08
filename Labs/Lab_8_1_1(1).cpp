// Lab_8_1_1(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

class Matrix {
public:	
	friend ostream& operator<<(ostream &out, Matrix &x);
	friend istream& operator>>(istream &in, Matrix &x);
private:
	vector< vector<int> > arr;
	int n;
};

ostream& operator<<(ostream &out, Matrix &x) {
	for (int i = 0; i<x.n; i++) {
		for (int j = 0; j<x.n; j++)
			out << x.arr[i][j] << " ";
		out << endl;
	}
	out << x.n << " " << x.n;
	return out;
}

istream& operator>>(istream &in, Matrix &x) {
	in >> x.n;
	int a;
	for (int i = 0; i<x.n; i++) {
		vector<int> row;
		for (int j = 0; j<x.n; j++) {
			in >> a;
			row.push_back(a);
		}
		x.arr.push_back(row);
	}
	return in;
}

int main()
{
	Matrix a;
	cin >> a;
	cout << a;
	system("Pause");
    return 0;
}

