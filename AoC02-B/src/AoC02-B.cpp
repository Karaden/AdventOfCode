//============================================================================
// Name        : AoC02-B.cpp
// Author      : KateT
// Version     :
// Copyright   : Your copyright notice
// Description : the goal is to find the only two numbers in each row where
//				 one evenly divides the other - that is, where the result
//				 of the division operation is a whole number. They would
//				 like you to find those numbers on each line, divide them,
//				 and add up each line's result.
//
//
//    In the first row, the only two numbers that evenly divide are 8 and 2; the result of this division is 4.
//    In the second row, the two numbers are 9 and 3; the result is 3.
//    In the third row, the result is 2.
//
//In this example, the sum of the results would be 4 + 3 + 2 = 9.

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
vector<vector<int> > sampleData;
int sampleSolution = 9;

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

vector<vector<int> > readFile(const char * filepath, char token)
		{
	ifstream myfile;
	string line;
	vector<vector<int> > target;

	myfile.open(filepath);

	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';

			string sline = line;
			vector<string> srow;
			vector<int> irow;

			// tokenise the line and store it in row
			split(srow, sline, token);

			//convert to int and copy to int vector
			for (unsigned int i = 0; i < srow.size(); i++)
			{
				const char* c = srow.at(i).c_str();
				int num = atoi(c);
				irow.push_back(num);
			}

			// create the row
			target.push_back(irow);
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

bool test(int actual, int expected)
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

// Solution A: brute force it
int calculate(vector<vector<int> > dataArray)
{

	int totalSum = 0;

	//iterate through every row
	for (unsigned int i = 0; i < dataArray.size(); ++i)
	{


		// iterate through the row
		for(unsigned int j = 0; j < dataArray[i].size(); ++j)
		{

			for (unsigned int k = j+1; k < dataArray[i].size(); ++k)
			{
				if ((dataArray[i][j] % dataArray[i][k]) == 0)
				{
					totalSum += dataArray[i][j] / dataArray[i][k];
				}
				else if ((dataArray[i][k] % dataArray[i][j]) == 0)
				{
					totalSum += dataArray[i][k] / dataArray[i][j];
				}
			}

		}

	}

	return totalSum;
}

//
//// Solution A: brute force it
//int calculate2(vector<vector<int> > dataArray)
//{
//
//	int totalSum = 0;
//
//	//iterate through every row
//	for (unsigned int i = 0; i < dataArray.size(); ++i)
//	{
//
//
//		// iterate through the row
//		for(unsigned int j = 0; j < dataArray[i].size(); ++j)
//		{
//
//
//
//
//
//
//
//
//
//		}
//
//
//
//
//
//	}
//
//	return totalSum;
//}

void initialise()
{
	sampleData = readFile("src/sampleInput.txt", '\t');
	data = readFile("src/input.txt", '\t');
}

int main()
{
	int result = -1;

	cout << "AoC02-B:" << endl; // prints AoC02-B:

	initialise();
	cout << "no. of rows in sampleData: " << sampleData.size() << "\n";
	cout << "no. of rows in data: " << data.size() << "\n";

	if (test( calculate(sampleData), sampleSolution))
	{
		result = calculate(data);
		cout << "Final result is: " << result << endl;
	}

	return 0;
}
