#include "set.h"
#include <iostream>
#include <vector>

struct Node
{
	int value = 0;
	int amount = 0;
	Node *left = nullptr;
	Node *right = nullptr;
};

struct Set
{
	Node *root = nullptr;
};

Set *createSet()
{
	return new Set{};
}

bool isEmpty(Set *set)
{
	return (set->root == nullptr);
}

void add(Set *set, const int newValue)
{
	if (isEmpty(set))
	{
		set->root = new Node{ newValue, 1, nullptr, nullptr };
		return;
	}

	Node *newParent = set->root;

	bool isLeft = (newValue < newParent->value);

	while (((isLeft) && (newParent->left != nullptr)) || ((!isLeft) && (newParent->right != nullptr)))
	{
		if (newValue == newParent->value)
		{
			++newParent->amount;
			return;
		}

		if (isLeft)
		{
			newParent = newParent->left;
		}
		else
		{
			newParent = newParent->right;
		}

		isLeft = (newValue < newParent->value);
	}

	if (newValue == newParent->value)
	{
		++newParent->amount;
		return;
	}

	if (isLeft)
	{
		newParent->left = new Node{ newValue, 1, nullptr, nullptr };
	}
	else
	{
		newParent->right = new Node{ newValue, 1, nullptr, nullptr };
	}
}

void leftTraversal(Node *current, std::vector<std::pair<int, int>> &values)
{
	if (current->left != nullptr)
	{
		leftTraversal(current->left, values);
	}

	values.push_back({current->value, current->amount});

	if (current->right != nullptr)
	{
		leftTraversal(current->right, values);
	}
}

std::vector<std::pair<int, int>> ascendingOrder(Set *set)
{
	std::vector<std::pair<int, int>> values;

	if (isEmpty(set))
	{
		return values;
	}

	leftTraversal(set->root, values);

	return values;
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

void deleteSet(Set *&set)
{
	if (!isEmpty(set))
	{
		deleteTraversal(set->root);
	}

	delete set;
	set = nullptr;
}