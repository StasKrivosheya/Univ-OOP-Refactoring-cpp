// Lab_8_3_4(1).cpp: определяет точку входа для консольного приложения.
//
/*

Подготовьте класс контейнера для двоичной древовидной структуры. 
Двоичное дерево представляет собой структуру данных дерева, где каждый узел имеет нуль, один или два дочерних
узлы. 
Эти дочерние узлы упоминаются как левый ребенок и правый ребенок. 
Этот класс состоит из трех полей:
поле со значением;
указатель на левый ребенок;
указатель на правильный ребенок.
Внедрите метод добавления значения в дерево, проверьте его с некоторыми значениями 
(вы можете жестко закодировать значения - тестирование должно быть проще и
Быстрее). Перегрузите оператор <<, чтобы распечатать все узлы inorder 
(inorder - метод обхода дерева, где вы сначала проходите левое дочернее
inorder, затем распечатать значение текущего узла, а затем пересечь правый дочерний регистр).

*/

#include "stdafx.h"
#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct node
{
	int value;                        
	node *left, *right;
};

void push(int a, node *&t)
{
	if (!t)                   
	{
		t = new node;                
		t->value = a;                
		t->left = t->right = 0;       
		return;                         
	}

	if (t->value > a) {
		push(a, t->left);
	} else {
		push(a, t->right);
	}
}

void clear(node *root) {
	if (!root) return;
	clear(root->left);
	clear(root->right);
	delete root;
	return;
}

ostream& inorder_recursive(ostream &out, node *current)
{	
	if (current == nullptr) return out;	
	inorder_recursive(out, current->left);
	out << current->value << '\n';	
	return inorder_recursive(out, current->right);
}

ostream &operator << (ostream &ostr, node *bs)
{
	return inorder_recursive(ostr, bs);
}


int main()
{	

	node *root = 0;
	int n;                              
	int s;                              	
	cin >> n;

	for(int i = 0; i<n; ++i)
	{
		cin >> s;                       
		push(s, root);                
	}
	
	cout << root;
	clear(root);
	system("pause");
    return 0;
}

