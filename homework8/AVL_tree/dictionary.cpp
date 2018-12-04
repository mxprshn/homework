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

//void removeByNode(Node *&currentNode, int targetValue);

Dictionary *createDictionary()
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

//int minimum(Node *currentNode)
//{
//	if (currentNode->left != nullptr)
//	{
//		return minimum(currentNode->left);
//	}
//	else
//	{
//		return currentNode->value;
//	}
//}

//void removeNoChildren(Node *&targetNode)
//{
//	Node *temp = targetNode;
//	targetNode = nullptr;
//	delete temp;
//}
//
//void removeOneChild(Node *targetNode)
//{
//	Node *temp = (targetNode->left != nullptr) ? targetNode->left : targetNode->right;
//
//	targetNode->value = temp->value;	
//	targetNode->left = temp->left;
//	targetNode->right = temp->right;
//	delete temp;
//}
//
//void removeTwoChildren(Node *&targetNode)
//{
//	const int rightMinimum = minimum(targetNode->right);
//	removeByNode(targetNode, rightMinimum);
//	targetNode->value = rightMinimum;
//}
//
//
//void removeByNode(Node *&currentNode, const int targetValue)
//{
//	if (targetValue < currentNode->value)
//	{
//		removeByNode(currentNode->left, targetValue);
//	}
//	else if (targetValue > currentNode->value)
//	{
//		removeByNode(currentNode->right, targetValue);
//	}
//	else
//	{
//		if ((currentNode->left == nullptr) && (currentNode->right == nullptr))
//		{
//			removeNoChildren(currentNode);
//		}
//		else if ((currentNode->left != nullptr) && (currentNode->right != nullptr))
//		{
//			removeTwoChildren(currentNode);
//		}
//		else
//		{
//			removeOneChild(currentNode);
//		}
//	}
//}
//
//bool remove(Set *set, const int targetValue)
//{
//	if (!exists(set, targetValue))
//	{
//		return false;
//	}
//
//	removeByNode(set->root, targetValue);
//
//	return true;
//}
//
//void leftTraversal(Node *current, std::vector<int> &values)
//{
//	if (current->left != nullptr)
//	{
//		leftTraversal(current->left, values);
//	}
//
//	values.push_back(current->value);
//
//	if (current->right != nullptr)
//	{
//		leftTraversal(current->right, values);
//	}
//}
//
//void rightTraversal(Node *current, std::vector<int> &values)
//{
//	if (current->right != nullptr)
//	{
//		rightTraversal(current->right, values);
//	}
//
//	values.push_back(current->value);
//
//	if (current->left != nullptr)
//	{
//		rightTraversal(current->left, values);
//	}
//}
//
//std::vector<int> ascendingOrder(Set *set)
//{
//	std::vector<int> values;
//
//	if (isEmpty(set))
//	{
//		return values;
//	}
//
//	leftTraversal(set->root, values);
//
//	return values;
//}
//
//std::vector<int> descendingOrder(Set *set)
//{
//	std::vector<int> values;
//
//	if (isEmpty(set))
//	{
//		return values;
//	}
//
//	rightTraversal(set->root, values);
//
//	return values;
//}
//
//void deleteTraversal(Node *current)
//{
//	if (current->left != nullptr)
//	{
//		deleteTraversal(current->left);
//	}
//
//	if (current->right != nullptr)
//	{
//		deleteTraversal(current->right);
//	}
//
//	delete current;
//}
//
//void deleteSet(Set *&set)
//{
//	if (!isEmpty(set))
//	{
//		deleteTraversal(set->root);
//	}
//
//	delete set;
//	set = nullptr;
//}

int main()
{
	Dictionary *dict = createDictionary();
	add(dict, "a", "5");
	add(dict, "b", "5");
	add(dict, "c", "5");
	add(dict, "d", "5");
	add(dict, "e", "5");
	add(dict, "ttt", "5");
	add(dict, "wwww", "5");
	add(dict, "wwwww", "5");

	return 0;
}