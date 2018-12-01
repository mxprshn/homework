#include <iostream>
#include <vector>
#include <string>
#include <cmath>

struct Node
{
	std::string key;
	std::string value;
	int height = 0;
	Node *left = nullptr;
	Node *right = nullptr;
};

struct Dictionary
{
	Node *root = nullptr;
};

void removeByNode(Node *&currentNode, int targetValue);

Dictionary *createDictionary()
{
	return new Dictionary;
}

bool isEmpty(Dictionary *dictionary)
{
	return (dictionary->root == nullptr);
}

void correctHeight(Node *node)
{
	node->height = ((node->right->height > node->left->height) ? node->right->height : node->left->height) + 1;
}

int balanceFactor(Node *node)
{
	return node->right->height - node->left->height;
}

bool exists(Dictionary *dictionary, const std::string &targetKey)
{
	if (isEmpty(dictionary))
	{
		return false;
	}

	Node *temp = dictionary->root;

	while ((temp != nullptr) && (temp->key != targetKey))
	{
		temp = (targetKey < temp->key) ? temp->left : temp->right;
	}

	return temp != nullptr;
}

void addByNode(Node *root, Node *parent, const std::string &key, const std::string &newValue)
{
	if (root == nullptr)
	{
		if (key < parent->key)
		{
			parent->left = new Node{ key, newValue, 1, nullptr, nullptr };
		}
		else
		{
			parent->right = new Node{ key, newValue, 1, nullptr, nullptr };
		}

		return;
	}

	if (root->key == key)
	{
		root->key = key;
		return;
	}

	if (key < root->key)
	{
		addByNode(root->left, root, key, newValue);
	}
	else
	{
		addByNode(root->right, root, key, newValue);
	}

	if (abs(balanceFactor(root)) > 1)
	{
		balance(root);
	}

	correctHeight(root);
}

void add(Dictionary *dictionary, const std::string &key, const std::string &newValue)
{
	if (isEmpty(dictionary))
	{
		dictionary->root = new Node{ key, newValue, 1, nullptr, nullptr };
		return;
	}

	addByNode(dictionary->root, nullptr, key, newValue);
}

Node *leftRotation(Node *current)
{

}

Node *balance(Node *root)
{

}

//void ascent(Node *current)
//{
//	if (abs(current->balanceFactor) > 1)
//	{
//		balance(current);
//	}
//
//	if ((current->balanceFactor != 0) && (current->parent != nullptr))
//	{
//		current->parent->balanceFactor += (current->parent->key < current->key) ? -1 : 1;
//		ascent(current->parent);
//	}
//}
//
//void add(Dictionary *dictionary, const std::string &key, const std::string &newValue)
//{
//	if (isEmpty(dictionary))
//	{
//		dictionary->root = new Node{ key, newValue, 0, nullptr, nullptr, nullptr };
//		return;
//	}
//
//	Node *newParent = dictionary->root;
//	bool isLeft = (newValue < newParent->value);
//
//	while (((isLeft) && (newParent->left != nullptr)) || ((!isLeft) && (newParent->right != nullptr)))
//	{
//		if (newParent->key == key)
//		{
//			newParent->value = newValue;
//			return;
//		}
//
//		newParent = isLeft ? newParent->left : newParent->right;
//		isLeft = (newValue < newParent->value);
//	}
//
//	if (isLeft)
//	{
//		newParent->left = new Node{ key, newValue, 0, nullptr, nullptr, newParent };
//		++newParent->balanceFactor;
//	}
//	else
//	{
//		newParent->right = new Node{ key, newValue, 0, nullptr, nullptr, newParent };
//		--newParent->balanceFactor;
//	}
//
//	ascent(newParent);
//}

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