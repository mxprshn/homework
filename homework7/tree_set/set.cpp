#include <iostream>
#include <vector>

struct Node
{
	int value = 0;
	Node *left = nullptr;
	Node *right = nullptr;
	Node *parent = nullptr;
};

struct Set
{
	Node *root = nullptr;
};

void removeByNode(Node *&currentNode, int targetValue);

Set *createSet()
{
	return new Set{};
}

bool isEmpty(Set *set)
{
	return (set->root == nullptr);
}

bool exists(Set *set, const int targetValue)
{
	if (isEmpty(set))
	{
		return false;
	}

	Node *temp = set->root;

	while ((temp != nullptr) && (temp->value != targetValue))
	{
		if (targetValue < temp->value)
		{
			temp = temp->left;
		}
		else if (targetValue > temp->value)
		{
			temp = temp->right;
		}
	}

	return (temp != nullptr);
}

bool add(Set *set, const int newValue)
{
	if (exists(set, newValue))
	{
		return false;
	}

	if (isEmpty(set))
	{
		set->root = new Node{ newValue, nullptr, nullptr, nullptr };
		return true;
	}

	Node *newParent = set->root;
	bool isLeft = (newValue < newParent->value);

	while (((isLeft) && (newParent->left != nullptr)) || ((!isLeft) && (newParent->right != nullptr)))
	{
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

	if (isLeft)
	{
		newParent->left = new Node{ newValue, nullptr, nullptr, newParent };
	}
	else
	{
		newParent->right = new Node{ newValue, nullptr, nullptr, newParent };
	}

	return true;
}

int minimum(Node *currentNode)
{
	if (currentNode->left != nullptr)
	{
		return minimum(currentNode->left);
	}
	else
	{
		return currentNode->value;
	}
}

void removeNoChildren(Node *&targetNode)
{
	Node *temp = targetNode;
	targetNode = nullptr;
	delete temp;
}

void removeOneChild(Node *targetNode)
{
	Node *temp = (targetNode->left != nullptr) ? targetNode->left : targetNode->right;

	targetNode->value = temp->value;	
	targetNode->left = temp->left;
	targetNode->right = temp->right;
	delete temp;
}

void removeTwoChildren(Node *&targetNode)
{
	const int rightMinimum = minimum(targetNode->right);
	removeByNode(targetNode, rightMinimum);
	targetNode->value = rightMinimum;
}


void removeByNode(Node *&currentNode, const int targetValue)
{
	if (targetValue < currentNode->value)
	{
		removeByNode(currentNode->left, targetValue);
	}
	else if (targetValue > currentNode->value)
	{
		removeByNode(currentNode->right, targetValue);
	}
	else
	{
		if ((currentNode->left == nullptr) && (currentNode->right == nullptr))
		{
			removeNoChildren(currentNode);
		}
		else if ((currentNode->left != nullptr) && (currentNode->right != nullptr))
		{
			removeTwoChildren(currentNode);
		}
		else
		{
			removeOneChild(currentNode);
		}
	}
}

bool remove(Set *set, const int targetValue)
{
	if (!exists(set, targetValue))
	{
		return false;
	}

	removeByNode(set->root, targetValue);

	return true;
}

void leftTraversal(Node *current, std::vector<int> &values)
{
	if (current->left != nullptr)
	{
		leftTraversal(current->left, values);
	}

	values.push_back(current->value);

	if (current->right != nullptr)
	{
		leftTraversal(current->right, values);
	}
}

void rightTraversal(Node *current, std::vector<int> &values)
{
	if (current->right != nullptr)
	{
		rightTraversal(current->right, values);
	}

	values.push_back(current->value);

	if (current->left != nullptr)
	{
		rightTraversal(current->left, values);
	}
}

std::vector<int> ascendingOrder(Set *set)
{
	std::vector<int> values;

	if (isEmpty(set))
	{
		return values;
	}

	leftTraversal(set->root, values);

	return values;
}

std::vector<int> descendingOrder(Set *set)
{
	std::vector<int> values;

	if (isEmpty(set))
	{
		return values;
	}

	rightTraversal(set->root, values);

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