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

Dictionary *newDictionary()
{
	return new Dictionary;
}

bool isEmpty(Dictionary *dictionary)
{
	return (dictionary->root == nullptr);
}

int height(Node *node)
{
	return (node == nullptr) ? 0 : node->height;
}

void correctHeight(Node *node)
{
	node->height = ((height(node->right) > height(node->left)) ? height(node->right) : height(node->left)) + 1;
}

int balanceFactor(Node *node)
{
	return (node == nullptr) ? 0 : height(node->right) - height(node->left);
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

void leftRotation(Node *&root)
{
	Node *temp = root->right;
	root->right = temp->left;
	temp->left = root;
	correctHeight(root);
	root = temp;
}

void rightRotation(Node *&root)
{
	Node *temp = root->left;
	root->left = temp->right;
	temp->right = root;
	correctHeight(root);
	root = temp;
}

void balance(Node *&root)
{
	if (balanceFactor(root) == -2)
	{
		if (balanceFactor(root->left) <= 0)
		{
			leftRotation(root->left);
		}

		rightRotation(root);
	}
	else
	{
		if (balanceFactor(root->right) <= 0)
		{
			rightRotation(root->right);
		}
		
		leftRotation(root);
	}
}

std::string value(Dictionary *dictionary, const std::string &targetKey)
{
	if (isEmpty(dictionary))
	{
		return "";
	}

	Node *temp = dictionary->root;

	while ((temp != nullptr) && (temp->key != targetKey))
	{
		temp = (targetKey < temp->key) ? temp->left : temp->right;
	}

	return (temp != nullptr) ? temp->value : "";
}

void addByNode(Node *&root, Node *parent, const std::string &key, const std::string &newValue)
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
		root->value = newValue;
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

std::string minimum(Node *currentNode)
{
	if (currentNode->left != nullptr)
	{
		return minimum(currentNode->left);
	}
	else
	{
		return currentNode->key;
	}
}

void removeByNode(Node *&currentNode, const std::string &targetKey);

void removeNoChildren(Node *&targetNode)
{
	Node *temp = targetNode;
	targetNode = nullptr;
	delete temp;
}

void removeOneChild(Node *targetNode)
{
	Node *temp = (targetNode->left != nullptr) ? targetNode->left : targetNode->right;
	targetNode->key = temp->key;
	targetNode->value = temp->value;
	targetNode->left = temp->left;
	targetNode->right = temp->right;
	targetNode->height = temp->height;
	delete temp;
}

void removeTwoChildren(Node *&targetNode)
{
	const std::string rightMinimum = minimum(targetNode->right);
	removeByNode(targetNode, rightMinimum);
	targetNode->key = rightMinimum;
}


void removeByNode(Node *&currentNode, const std::string &targetKey)
{
	if (targetKey < currentNode->key)
	{
		removeByNode(currentNode->left, targetKey);
	}
	else if (targetKey > currentNode->key)
	{
		removeByNode(currentNode->right, targetKey);
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

		return;
	}

	if (abs(balanceFactor(currentNode)) > 1)
	{
		balance(currentNode);
	}

	correctHeight(currentNode);
}

bool remove(Dictionary *dictionary, const std::string &targetKey)
{
	if (!exists(dictionary, targetKey))
	{
		return false;
	}

	removeByNode(dictionary->root, targetKey);

	return true;
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

void deleteDictionary(Dictionary *&dictionary)
{
	if (!isEmpty(dictionary))
	{
		deleteTraversal(dictionary->root);
	}

	delete dictionary;
	dictionary = nullptr;
}