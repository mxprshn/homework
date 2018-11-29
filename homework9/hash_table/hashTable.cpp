#include <string>
#include <vector>
#include <algorithm>
#include "list.h"

struct HashTable
{
	int elementsAmount = 0;
	std::vector<List*> buckets;
};

HashTable *newTable()
{
	const int baseSize = 50;
	HashTable *newHashTable = new HashTable;
	newHashTable->buckets.resize(baseSize);

	for (List *&current : newHashTable->buckets)
	{
		current = createList();
	}

	return newHashTable;
}

float averageLength(const HashTable *table)
{
	int sum = 0;
	int notEmptyAmount = 0;

	for (List *current : table->buckets)
	{
		if (!isEmpty(current))
		{
			sum += listLength(current);
			++notEmptyAmount;
		}
	}

	return (float)sum / (float)notEmptyAmount;
}

float loadFactor(const HashTable *table)
{
	return (float)table->elementsAmount / (float)table->buckets.size();
}

int maxLength(const HashTable *table)
{
	int result = 0;

	for (List *current : table->buckets)
	{
		result = std::max(listLength(current), result);
	}

	return result;
}

unsigned long long int hash(const std::string &word)
{
	unsigned long long int hashSum = 0;
	int base = 1;

	for (int i : word)
	{
		hashSum += base * i;
		base *= 53;
	}

	return hashSum;
}

void rehash(Node *source, const HashTable *hashTable)
{
	const int wordHash = hash(word(source)) % hashTable->buckets.size();
	addNew(hashTable->buckets[wordHash], word(source), amount(source));
	markRehashed(source, true);
}

void expand(HashTable *hashTable)
{
	hashTable->buckets.resize(hashTable->buckets.size() * 2);

	for (int i = hashTable->buckets.size() / 2; i < hashTable->buckets.size(); ++i)
	{
		hashTable->buckets[i] = createList();
	}

	for (int i = 0; i < (hashTable->buckets.size() / 2); ++i)
	{
		Node *current = head(hashTable->buckets[i]);

		while (current != nullptr)
		{
			if (isRehashed(current))
			{
				markRehashed(current, false);
				continue;
			}

			rehash(current, hashTable);
			Node *temp = current;
			current = next(current);
			removeNode(hashTable->buckets[i], temp);
		}
	}
}

void add(HashTable *hashTable, const std::string &word)
{
	if (((float)hashTable->elementsAmount / (float)hashTable->buckets.size()) > 1.0)
	{
		expand(hashTable);
	}

	const int wordHash = hash(word) % hashTable->buckets.size();
	Node *wordNode = exists(hashTable->buckets[wordHash], word);

	if (wordNode != nullptr)
	{
		addExisting(wordNode);
	}
	else
	{
		addNew(hashTable->buckets[wordHash], word, 1);
		++hashTable->elementsAmount;
	}
}

void deleteTable(HashTable *&table)
{
	for (List *current : table->buckets)
	{
		deleteList(current);
	}

	delete table;
	table = nullptr;
}

bool wordExists(const HashTable *table, const std::string &word)
{
	const int wordHash = hash(word) % table->buckets.size();
	Node *wordNode = exists(table->buckets[wordHash], word);

	return (wordNode != nullptr);
}

int amountByWord(const HashTable *table, const std::string &word)
{
	const int wordHash = hash(word) % table->buckets.size();
	Node *wordNode = exists(table->buckets[wordHash], word);

	if (wordNode == nullptr)
	{
		return 0;
	}
	else
	{
		return amount(wordNode);
	}
}






