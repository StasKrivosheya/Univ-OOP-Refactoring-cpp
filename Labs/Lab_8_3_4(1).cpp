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

	static void push(int value, Node*& node)
	{
		if (node == nullptr)
		{
			node = new Node(value);
			return;
		}

		if (node->value_ > value)
			push(value, node->left_);
		else
			push(value, node->right_);
	}

	static void clear(Node* root)
	{
		if (root == nullptr)
			return;

		clear(root->left_);
		clear(root->right_);
		delete root;
		return;
	}

	static void inorder_recursive(std::ostream& out, Node* current)
	{
		if (current == nullptr)
			return;

		inorder_recursive(out, current->left_);
		out << current->value_ << '\t';
		inorder_recursive(out, current->right_);
	}

	friend std::ostream& operator<<(std::ostream& ostr, Node* node);
};

std::ostream& operator<<(std::ostream& ostr, Node* node)
{
	Node::inorder_recursive(ostr, node);
	return ostr;
}

void initialize_tree(Node** root, int count)
{
	int value;
	for (int i = 0; i < count; ++i)
	{
		std::cin >> value;
		Node::push(value, *root);
	}
}

int main()
{
	Node* root = 0;
	int nodes_to_push;
	std::cout << "Input the amount of nodes to push: ";
	std::cin >> nodes_to_push;

	initialize_tree(&root, nodes_to_push);

	std::cout << std::endl << "Tree is:\n" << root << std::endl;

	Node::clear(root);

	system("pause");
	return 0;
}