#pragma once

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
