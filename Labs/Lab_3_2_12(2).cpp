#include <iostream>

int main()
{
	const int M = 10;
	const int N = 10;
	int matrix[M][N] = {};

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			*(*(matrix + i) + j) = (i + 1) * (j + 1); //через указатели!

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout.width(4);
			std::cout << matrix[i][j];
		}
		std::cout << std::endl;
	}

	system("pause");
	return 0;
}