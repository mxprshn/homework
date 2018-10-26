#pragma once

const int bitNumberLength = 32;
void createBinary(int decimal, bool *binary);
void printBinary(bool *binary);
void sumBinary(bool *summand1, bool *summand2, bool *result);
int createDecimal(bool *binary);