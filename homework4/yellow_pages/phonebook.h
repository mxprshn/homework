#pragma once

const int baseSize = 100;

struct Record;
int readFile(Record *currentBase, const char *fileName);
void printBase(int recordAmount, Record *currentBase);
void createRecord(int &recordAmount, Record *currentBase, char *newName, char *newNumber);
int writeFile(int writePosition, int recordAmount, Record *currentBase);
int searchName(int recordAmount, Record *currentBase, char *targetNumber);
int searchNumber(int recordAmount, Record *currentBase, char *targetName);
Record *createBase();
void deleteBase(Record *currentBase);


