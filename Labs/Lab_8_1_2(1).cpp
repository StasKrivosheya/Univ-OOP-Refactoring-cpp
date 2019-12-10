#include <iostream>

class Stack
{
private:
	int* arr;
	int* top;
	int size;
public:
	Stack(int s)
	{
		if (s < 0)
			throw std::exception("Negative_Value");
		size = s;
		arr = new int[size];
		top = arr;
	}

	~Stack()
	{
		delete arr;
	}

	bool is_empty()
	{
		return top <= arr;
	}

	bool is_full()
	{
		return top - arr >= size;
	}

	bool push(int val)
	{
		bool res = !is_full();
		if (res)
		{
			*top = val;
			top++;
		}
		return res;
	}

	int pop()
	{
		bool res = !is_empty();
		if (res)
		{
			top--;
			return *top;
		}
		throw std::exception("Stack is empty!");
	}
};

int main()
{
	int pushes_amount;
	std::cout << "Count push: ";
	std::cin >> pushes_amount;

	Stack s(pushes_amount);

	int number;

	for (int i = 0; i < pushes_amount; i++)
	{
		std::cin >> number;
		s.push(number);
	}

	int pops_amount;
	std::cout << "Count pop: ";
	std::cin >> pops_amount;

	try
	{
		for (int i = 0; i <= pops_amount; i++)
		{
			std::cout << s.pop() << std::endl;
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << "\n";
	}
	system("pause");
	return 0;
}