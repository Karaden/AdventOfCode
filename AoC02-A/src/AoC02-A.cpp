//============================================================================
// Name        : AoC02-A.cpp
// Author      : KateT
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string>

using namespace std;

vector<vector<int> > data;

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
	std::istringstream ss(s);
	while (!ss.eof()) {
		typename Container::value_type field;
		getline(ss, field, delimiter);
		if ((empties == splitter::no_empties) && field.empty())
			continue;
		result.push_back(field);
	}
	return result;
}



void readFile()
{
	ifstream myfile;
	string line;

	myfile.open("src/input.txt");

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';

			string sline = line;
			vector<string> srow;
			vector<int> irow;

			// tokenise the line and store it in row
			// split on tab character
			split(srow, sline, '\t');

			//convert to int and copy to int vector
			for (unsigned int i = 0; i < srow.size(); i++)
			{
				const char* c = srow.at(i).c_str();
				int num = atoi(c);
				irow.push_back(num);
			}

			// create the row
			data.push_back(irow);
		}
		myfile.close();
	}

	else
	{
		cout << "Unable to open file";
	}

}

int main()
{
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	readFile();

	cout << "no. of rows in data: " << data.size() << "\n";

	return 0;

}

