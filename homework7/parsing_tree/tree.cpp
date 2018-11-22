#include <fstream>
#include <iostream>
#include <string>

struct Node
{
	int value = 0;
	Node *left = nullptr;
	Node *right = nullptr;
};

struct Tree
{
	Node *root = nullptr;
};

Node *createNode(std::ifstream &input)
{
	const char current = input.peek();
	Node *newNode = new Node{};

	if (current == '(')
	{
		input.get();
		newNode->value = input.get();
		input.get();
		newNode->left = createNode(input);
		input.get();
		newNode->right = createNode(input);
		input.get();
	}
	else if (isdigit(current))
	{
		input >> newNode->value;
	}

	return newNode;
}

Tree *createTree(std::ifstream &input)
{
	return new Tree{ createNode(input) };
}

bool isEmpty(Tree *tree)
{
	return (tree->root == nullptr);
}

void deleteTraversal(Node *current)
{
	if (current->left != nullptr)
	{
		deleteTraversal(current->left);
	}

	if (current->right != nullptr)
	{
		deleteTraversal(current->right);
	}

	delete current;
}

void deleteTree(Tree *&tree)
{
	if (!isEmpty(tree))
	{
		deleteTraversal(tree->root);
	}
	delete tree;
	tree = nullptr;
}

int evaluationByNode(Node *current)
{
	if (current->value == '*')
	{
		return evaluationByNode(current->left) * evaluationByNode(current->right);
	}
	else if (current->value == '/')
	{
		return evaluationByNode(current->left) / evaluationByNode(current->right);
	}
	else if (current->value == '+')
	{
		return evaluationByNode(current->left) + evaluationByNode(current->right);
	}
	else if (current->value == '-')
	{
		return evaluationByNode(current->left) - evaluationByNode(current->right);
	}
	
	return current->value;
}

int treeEvaluation(Tree *tree)
{
	if (isEmpty(tree))
	{
		return 0;
	}

	return evaluationByNode(tree->root);
}

void printNode(Node *current)
{
	if (current->value == '*')
	{
		std::cout << "(* ";
	}
	else if (current->value == '/')
	{
		std::cout << "(/ ";
	}
	else if (current->value == '+')
	{
		std::cout << "(+ ";
	}
	else if (current->value == '-')
	{
		std::cout << "(- ";
	}
	else
	{
		std::cout << current->value;
		return;
	}	

	printNode(current->left);
	std::cout << ' ';
	printNode(current->right);
	std::cout << ')';
}

void printTree(Tree *tree)
{
	if (isEmpty(tree))
	{
		std::cout << "The tree is empty" << std::endl;
		return;
	}

	printNode(tree->root);
}


