#pragma once

const int baseSize = 100;
const int nameLength = 30;
const int numberLength = 15;

struct record
{
	char name[nameLength];
	char number[numberLength];
};

void deleteBase(record *currentBase);
int readFile(record *currentBase);
void printBase(int recordAmount, record *currentBase);
void interface(int recordAmount, record *currentBase);
int createRecord(int recordAmount, record *currentBase);
int writeFile(int writePosition, int recordAmount, record *currentBase);
int searchName(int recordAmount, record *currentBase);
int searchNumber(int recordAmount, record *currentBase);
