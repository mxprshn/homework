#pragma once

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
