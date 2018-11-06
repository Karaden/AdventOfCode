//============================================================================
// Name        : Aoc04-A.cpp
// Author      : Kate
// Version     :
// Copyright   : Your copyright notice
// Description :
//
//
//A passphrase consists of a series of words (lowercase letters) separated by spaces.
//
//To ensure security, a valid passphrase must contain no duplicate words.
//
//For example:
//
//aa bb cc dd ee is valid.
//aa bb cc dd aa is not valid - the word aa appears more than once.
//aa bb cc dd aaa is valid - aa and aaa count as different words.
//The system's full passphrase list is available as your puzzle input. How many passphrases are valid?
//


// ===========My thoughts:=================
//
// Ingest data - tokenise each line into words
// For each line:
//		For each word, do string compare
//			If valid, increment validity count


//Using C++11
//============================================================================

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<string> > data;

map< vector<string>, bool> sampleData {
	{ {"aa", "bb", "cc", "dd", "ee"}, true},
	{ {"aa", "bb", "cc", "dd", "aa"}, false},
	{ {"aa", "bb", "cc", "dd", "aaa"}, true}
};

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

bool test(unsigned int actual, unsigned int expected)
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

int calculate(int target)
{
	return -1;
}

bool calculateAllTestData()
{
	return false;
}


void initialise()
{
	data = readFile("src/input.txt", ' ');
}

int main() {
	int result = -1;
	cout << "AoC04-A begin:" << endl; // prints AoC04-A begin:
	initialise();
	cout << "no. of rows in sampleData: " << sampleData.size() << "\n";
	cout << "no. of rows in data: " << data.size() << "\n";

	if ((calculateAllTestData()))
		{
			cout << "===================PASSED ALL TESTS=================" << endl;
			//result = calculate(data);
			cout << "Final result is: " << result << endl;
		}
	else
	{
		cout << "Tests failed." << endl;
	}

		return 0;
}
