#pragma once

const int baseSize = 100;
const int nameLength = 30;
const int numberLength = 15;
const char baseFileName[] = "base.txt";
const char testBaseFileName[] = "test.txt";

struct record
{
	char name[nameLength];
	char number[numberLength];
};

int readFile(record *currentBase, const char *fileName);
void printBase(int recordAmount, record *currentBase);
int interface(int recordAmount, record *currentBase);
int createRecord(int recordAmount, record *currentBase);
int writeFile(int writePosition, int recordAmount, record *currentBase);
int searchName(int recordAmount, record *currentBase);
int searchNumber(int recordAmount, record *currentBase);
