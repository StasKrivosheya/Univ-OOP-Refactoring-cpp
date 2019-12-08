// Lab_8_1_2(1).cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;

/*

Напишите простой класс контейнера, который содержит элементы стека 
(тип элемента зависит от вас, он может быть целым или двойным, или
все что пожелаете). Стек представляет собой простую структуру данных с 
двумя операциями: push, которая добавляет элемент в коллекцию и pop,
который удаляет последний добавленный элемент, который еще не удален. 
Порядок, в котором элементы выходят из стека, дает
перейти к его альтернативному названию, LIFO (последний раз, первый раз). 
Эти два метода (push и pop) изменяют содержимое стека. Помимо двух
методы, добавьте метод, чтобы получить доступ к вершине без изменения стека 
(имя сверху). Если стек пуст, добавьте исключение
(как в главе 7). Ваша основная задача в этой лаборатории - написать 
операторские функции (т. Е. << и >>), чтобы нажать значение и получить (вверху
и pop) - значение из стека. В основном коде добавьте свой код для обработки 
этих особых исключений. Кроме того, в основном коде,
добавьте некоторый код для ввода данных в стек. Спросите пользователя, 
сколько предметов нужно вставить в стек, спросите пользователя об этих элементах,
и спросите снова, сколько предметов ваша программа должна распечатать и выскочить из стека. 
Затем распечатайте стек - если возникает исключение, распечатайте
адекватное сообщение. Используйте операторы, определенные в вашей программе.

*/

class Stack
{
private:
	int* arr;
	int* top;
	int size;
public:
	Stack(int s)
	{
		if (s < 0) throw new exception("Negative_Value");
		size = s;
		arr = new int[size];
		top = arr;
	}
	
	~Stack() 
	{
		delete arr;
	}

	bool IsEmpty()
	{
		if (top > arr) return false;
		else return true;
	}
	bool IsFull()
	{
		if (top - arr < size) return false;
		else return true;
	}

	bool Push(int val)
	{
		bool res = !IsFull();
		if (res)
		{
			*top = val;
			top++;
		}
		return res;
	}
	bool Pop()
	{
		bool res = !IsEmpty();
		if (res) top--;
		return res;
	}
	bool Pop(int *ret)
	{
		bool res = !IsEmpty();
		if (res)
		{
			top--;
			*ret = *top;
		}
		return res;
	}			
};

int main()
{
	int n;
	cout << "Count push: ";
	cin >> n;
	
	Stack s(n);
	int number;

	for (int i = 0; i <= n; i++) {
		cin >> number;
		s.Push(number);		
		cout << endl;
	}

	cout << "Count pop: ";
	cin >> n;

	for (int i = 0; i <= n; i++) {
		if (s.Pop(&number)) cout << number << endl;
		else cout << "Exception: stack is empty." << endl;
	}

	system("pause");
	return 0;
}
