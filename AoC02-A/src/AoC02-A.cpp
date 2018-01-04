//============================================================================
// Name        : AoC02-A.cpp
// Author      : KateT
// Version     :
// Copyright   : Your copyright notice
// Description : calculate the spreadsheet's checksum. For each row, determine
//				 the difference between the largest value and the smallest
//				 value; the checksum is the sum of all of these differences.
//
//    The first row's largest and smallest values are 9 and 1, and their difference is 8.
//    The second row's largest and smallest values are 7 and 3, and their difference is 4.
//    The third row's difference is 6.
//
//	In this example, the spreadsheet's checksum would be 8 + 4 + 6 = 18.
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
int sampleSolution = 18;

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
		}
		else
		{
			cout << "Looks good. Result is: " << actual << endl;
			result = true;
		}

	return result;

}

int calculate(vector<vector<int> > dataArray)
{

	int totalSum = 0;

		//iterate through every row
		for (unsigned int i = 0; i < dataArray.size(); ++i)
		{
			int largest = -1;
			int smallest = -1;

			// find largest and smallest item in row
			for(unsigned int j = 0; j < dataArray[i].size(); ++j)
			{
				if (dataArray[i][j] < smallest || smallest == -1)
				{
					smallest = dataArray[i][j];
				}

				if (dataArray[i][j] > largest || largest == -1)
				{
					largest = dataArray[i][j];
				}
			}


			// find their difference
			// add the difference to totalSum
			cout << "largest on row:  " << largest << endl;
			cout << "smallest on row: " << smallest << endl;
			cout << "diff:            " << largest - smallest << endl;

			totalSum += (largest - smallest);

			cout << "total sum so far: " << totalSum << endl;

		}

	return totalSum;
}

void initialise()
{
	sampleData = readFile("src/sampleInput.txt", '\t');
	data = readFile("src/input.txt", '\t');
}

int main()
{
	int result = -1;

	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
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

