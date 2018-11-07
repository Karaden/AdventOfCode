//============================================================================
// Name        : AoC04-B.cpp
// Author      : Kate
// Version     :
// Copyright   : Your copyright notice
// Description :

//a valid passphrase must contain no two words that are anagrams of each other - that is, a passphrase is invalid if any word's letters can be rearranged to form any other word in the passphrase.
//
//For example:
//
//abcde fghij is a valid passphrase.
//abcde xyz ecdab is not valid - the letters from the third word can be rearranged to form the first word.
//a ab abc abd abf abj is a valid passphrase, because all letters need to be used when forming another word.
//iiii oiii ooii oooi oooo is valid.
//oiii ioii iioi iiio is not valid - any of these words can be rearranged to form any other word.
//Under this new system policy, how many passphrases are valid?
//
//

//Using C++11 for nicer vector/map initialisation
//============================================================================

#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<vector<string> > data;
vector<pair< vector<string>, bool> > sampleData;

set<string> wordList;

void init_sampleData()
{
	sampleData.push_back(make_pair(vector<string> {"aa", "bb", "cc", "dd", "ee"}, true));
	sampleData.push_back(make_pair(vector<string> {"aa", "bb", "cc", "dd", "aa"}, false));
	sampleData.push_back(make_pair(vector<string>  {"aa", "bb", "cc", "dd", "aaa"}, true));

	sampleData.push_back(make_pair(vector<string>  {"abcde", "fghij"}, true));
	sampleData.push_back(make_pair(vector<string>  {"abcde", "xyz", "ecdab"} ,false)); //is not valid - the letters from the third word can be rearranged to form the first word.
	sampleData.push_back(make_pair(vector<string>  {"a", "ab", "abc", "abd,", "abf", "abj"}, true)); // is a valid passphrase, because all letters need to be used when forming another word.
	sampleData.push_back(make_pair(vector<string>  {"iiii", "oiii", "ooii", "oooi", "oooo"}, true));
	sampleData.push_back(make_pair(vector<string>  {"oiii", "ioii", "iioi", "iiio"}, false)); // is not valid - any of these words can be rearranged to form any other word.
}

struct splitter
{
	enum empties_t
	{
		empties_ok, no_empties
	};
};

template<typename Container>
Container& split(Container& result,
				const typename Container::value_type& s,
				typename Container::value_type::value_type delimiter,
				splitter::empties_t empties = splitter::empties_ok)
{
	result.clear();
	istringstream ss(s);
	while (!ss.eof()) {
		typename Container::value_type field;
		getline(ss, field, delimiter);
		if ((empties == splitter::no_empties) && field.empty())
			continue;
		result.push_back(field);
	}
	return result;
}

vector<vector<string> > readFile(const char * filepath, char token)
{
	ifstream myfile;
	string line;
	vector<vector<string> > target;

	myfile.open(filepath);

		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				cout << line << '\n';

				string sline = line;
				vector<string> srow;

				// tokenise the line and store it in row
				split(srow, sline, token);

				// create the row
				target.push_back(srow);
			}
			myfile.close();
			cout << "no. of rows in target vector: " << target.size() << "\n";
		}

		else
		{
			cout << "Unable to open file";
		}

	return target;
}

bool test(bool actual, bool expected)
{
	bool result = false;

	if (actual != expected)
	{
		cout << "Wrong result: " << actual << endl;
		cout << "Expected: " << expected << endl;
	}
	else
	{
		cout << "Looks good. Result is: " << actual << endl;
		result = true;
	}

	return result;

}

bool lineContainsValidPassphrase(vector<string> target)
{
	//Make sure dictionary is empty
	wordList.clear();

	//Container::const_iterator it;
    set<string>::iterator it;
    string word;

	//For each string in the vector (word in the passphrase)
	for (unsigned int i = 0; i < target.size(); ++i)
	{
		//Sort the characters of the word alphabetically
		 word = target[i];
		 sort(word.begin(), word.end());

		//Check to see if the word has already been used in the passphrase
		it = wordList.find(word);

		if (it != wordList.end())
		{
			// the word exists in the set - the passphrase is not valid
			return false;
		}
		else
		{
			// the word is not in the set - add it
			wordList.insert(word);
		}
	}

	return true;
}

int calculate(vector<vector<string> > target)
{
	int totalValid = 0;

	for (auto const& x : target)
		{
		   if (lineContainsValidPassphrase(x))
		   {
			   totalValid++;
		   }
		}

	return totalValid;
}

bool calculateAllTestData()
{
	cout << "===================COMMENCING TESTS=================" << endl;


	for (unsigned int i = 0; i < sampleData.size(); ++i)
	{
		if (!test(lineContainsValidPassphrase(sampleData[i].first), sampleData[i].second))
		{
			return false;
		}
	}

	return true;
}


void initialise()
{
	init_sampleData();
	data = readFile("src/input.txt", ' ');
}

int main() {
	int result = -1;
	cout << "AoC04-B begin:" << endl;
	initialise();

	cout << "no. of rows in sampleData: " << sampleData.size() << "\n";
	cout << "no. of rows in data: " << data.size() << "\n";

	if ((calculateAllTestData()))
	{
			cout << "===================PASSED ALL TESTS=================" << endl;
			result = calculate(data);
			cout << "Final result is: " << result << endl;
	}
	else
	{
		cout << "Tests failed." << endl;
	}

	return 0;
}
