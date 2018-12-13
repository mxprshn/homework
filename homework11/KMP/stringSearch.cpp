#include <string>
#include <vector>
#include <iostream>

std::vector<int> prefix(const std::string &source)
{
	std::vector<int> prefixes;
	prefixes.push_back(0);
	
	for (int i = 1; i < source.length(); ++i)
	{
		int longestPrefix = prefixes[i - 1];

		while ((longestPrefix != 0) && (source[longestPrefix] != source[i]))
		{
			longestPrefix = prefixes[longestPrefix - 1];
		}

		prefixes.push_back(source[longestPrefix] == source[i] ? ++longestPrefix : 0);
	}

	return prefixes;
}

std::vector<int> stringSearch(const std::string &string, const std::string &word)
{
	std::vector<int> wordPrefixes = prefix(word);

	for (char current : string)
	{

	}
}

int main()
{
	std::string text;
	std::cin >> text;

	for (char i : text)
	{
		std::cout << i << ' ';
	}

	std::cout << std::endl;

	for (int i : prefix(text))
	{
		std::cout << i << ' ';
	}
	return 0;
}