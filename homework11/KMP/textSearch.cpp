#include <string>
#include <vector>
#include <fstream>

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

int textSearch(std::ifstream &file, const std::string &pattern)
{
	std::vector<int> patternPrefixes = prefix(pattern);

	char fileCompared = file.get();
	int patternCompared = 0;
	int position = 0;

	while (!file.eof())
	{
		if (fileCompared == '\n')
		{
			fileCompared = ' ';
		}

		if (fileCompared == pattern[patternCompared])
		{
			if (patternCompared == pattern.length() - 1)
			{
				file.seekg(0, file.beg);
				return position - pattern.length() + 1;
			}

			file.get(fileCompared);
			++patternCompared;
			++position;
		}
		else
		{
			if (patternCompared == 0)
			{
				file.get(fileCompared);
				++position;
			}
			else
			{
				patternCompared = patternPrefixes[patternCompared - 1];
			}
		}
	}

	file.clear();
	file.seekg(0, file.beg);

	return -1;
}

