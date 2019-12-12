#include <iostream>

class Stack
{
private:
	int* array;
	int* top;
	int size;
public:
	Stack(int size)
	{
		if (size < 0)
			throw std::exception("Negative_Value");
		this->size = size;
		array = new int[size];
		top = array;
	}

	~Stack()
	{
		delete[] array;
	}

	bool is_empty()
	{
		return top <= array;
	}

	bool is_full()
	{
		return top - array >= size;
	}

	bool push(int val)
	{
		bool is_stack_empty = !is_full();
		if (is_stack_empty)
		{
			*top = val;
			top++;
		}
		return is_stack_empty;
	}

	int pop()
	{
		bool stack_is_empty = is_empty();
		if (!stack_is_empty)
		{
			top--;
			return *top;
		}
		throw std::exception("Stack is empty!");
	}
};

void initialize_stack(Stack& stack, int pushes_amount)
{
	int number;

	for (int i = 0; i < pushes_amount; i++)
	{
		std::cin >> number;
		stack.push(number);
		std::cout << std::endl;
	}
}

void pop_stack(Stack& stack, int pops_amount)
{
	try
	{
		for (int i = 0; i <= pops_amount; i++)
		{
			std::cout << stack.pop() << std::endl;
		}
	}
	catch (std::exception e)
	{
		std::cout << e.what() << "\n";
	}
}

void run_test_stack()
{
	int pushes_amount;
	std::cout << "Count push: ";
	std::cin >> pushes_amount;

	Stack stack(pushes_amount);
	initialize_stack(stack, pushes_amount);

	int pops_amount;
	std::cout << "Count pop: ";
	std::cin >> pops_amount;

	pop_stack(stack, pops_amount);
}

int main()
{
	run_test_stack();

	system("pause");
	return 0;
}