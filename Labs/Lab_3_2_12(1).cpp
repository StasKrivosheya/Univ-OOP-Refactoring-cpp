#include <iostream>

int* find_min_place(int* vector)
{
	const int N = sizeof(vector) / sizeof(vector[0]);

	int* arr_min_pointer = vector;

	for (int i = 0; i < N; i++)
	{
		if (vector[i] < *arr_min_pointer)
		{
			arr_min_pointer = &vector[i];
		}
	}
	return arr_min_pointer;
}

int main()
{
	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	
	int* arr_min_pointer = find_min_place(vector);

	std::cout << "Min: " << *arr_min_pointer << "\tplace: " << arr_min_pointer << std::endl;

	system("pause");
	return 0;
}