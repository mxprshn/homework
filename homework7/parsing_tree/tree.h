#pragma once
#include <fstream>

struct Tree;

Tree *createTree(std::ifstream &input);
bool isEmpty(Tree *tree);
void deleteTree(Tree *&tree);
int treeEvaluation(Tree *tree);
void printTree(Tree *tree);

