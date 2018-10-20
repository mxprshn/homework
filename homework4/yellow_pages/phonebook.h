#pragma once

const int baseSize = 100;
const int nameLength = 30;
const int numberLength = 15;
const char baseFileName[] = "base.txt";
const char testBaseFileName[] = "test.txt";

struct Record
{
	char name[nameLength];
	char number[numberLength];
};

int readFile(Record *currentBase, const char *fileName);
void printBase(int recordAmount, Record *currentBase);
int interface(int recordAmount, Record *currentBase);
int createRecord(int recordAmount, Record *currentBase, char *newName, char *newNumber);
int writeFile(int writePosition, int recordAmount, Record *currentBase);
int searchName(int recordAmount, Record *currentBase, char *targetNumber);
int searchNumber(int recordAmount, Record *currentBase, char *targetName);
bool programTest();
