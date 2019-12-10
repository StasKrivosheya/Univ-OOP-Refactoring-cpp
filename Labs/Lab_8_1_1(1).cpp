#include <iostream>
#include <vector>

class Matrix
{
private:
	std::vector<std::vector<int>> arr;
	int size_;
public:
	Matrix(int size) : size_(size) { }
	friend std::ostream& operator<<(std::ostream& out, const Matrix& x);
	friend std::istream& operator>>(std::istream& in, Matrix& x);
};

std::ostream& operator<<(std::ostream& out, const Matrix& x)
{
	for (int i = 0; i < x.size_; i++)
	{
		for (int j = 0; j < x.size_; j++)
			out << x.arr[i][j] << " ";
		out << std::endl;
	}
	return out;
}

std::istream& operator>>(std::istream& in, Matrix& x)
{
	int a;
	for (int i = 0; i < x.size_; i++)
	{
		std::vector<int> row;
		for (int j = 0; j < x.size_; j++)
		{
			in >> a;
			row.push_back(a);
		}
		x.arr.push_back(row);
	}
	return in;
}

int main()
{
	Matrix a(3);
	std::cin >> a;
	std::cout << a;

	system("pause");
	return 0;
}