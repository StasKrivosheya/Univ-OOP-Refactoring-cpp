#include <iostream>
#include <string>

struct Node
{
	int value_;
	Node* left_;
	Node* right_;
	Node(int value, Node* left = nullptr, Node* right = nullptr)
	{
		value_ = value;
		left_ = left;
		right_ = right;
	}
};

void push(int a, Node*& t)
{
	if (t == nullptr)
	{
		t = new Node(a);
		return;
	}

	if (t->value_ > a)
		push(a, t->left_);
	else
		push(a, t->right_);
}

void clear(Node* root)
{
	if (root == nullptr)
		return;

	clear(root->left_);
	clear(root->right_);
	delete root;
	return;
}

void inorder_recursive(std::ostream& out, Node* current)
{
	if (current == nullptr)
		return;

	inorder_recursive(out, current->left_);
	out << current->value_ << '\t';
	inorder_recursive(out, current->right_);
}

std::ostream& operator<<(std::ostream& ostr, Node* bs)
{
	inorder_recursive(ostr, bs);
	return ostr;
}


int main()
{
	Node* root = 0;
	int nodes_to_push, value;
	std::cout << "Input the amount of nodes to push: ";
	std::cin >> nodes_to_push;

	for (int i = 0; i < nodes_to_push; ++i)
	{
		std::cin >> value;
		push(value, root);
	}

	std::cout << std::endl << "Tree is:\n" << root << std::endl;
	clear(root);

	system("pause");
	return 0;
}