//============================================================================
// Name        : AoC05-A.cpp
// Author      : Kate
// Version     :
// Copyright   : Your copyright notice
// Description :

// a maze of jump instructions - find the exit.
//
// The message includes a list of the offsets for each jump. Jumps are relative:
// -1 moves to the previous instruction, and 2 skips the next one.
// Start at the first instruction in the list. The goal is to follow the jumps
// until one leads outside the list.
//
// In addition, these instructions are a little strange; after each jump,
// the offset of that instruction increases by 1. So, if you come across
// an offset of 3, you would move three instructions forward, but change
// it to a 4 for the next time it is encountered.
//
// For example, consider the following list of jump offsets:
//
// 0
// 3
// 0
// 1
// -3
//
// Positive jumps ("forward") move downward; negative jumps move upward.
// For legibility in this example, these offset values will be written all on one
// line, with the current instruction marked in parentheses. The following steps
// would be taken before an exit is found:
//
// (0) 3  0  1  -3  - before we have taken any steps.
// (1) 3  0  1  -3  - jump with offset 0 (that is, don't jump at all). Fortunately,
//					  the instruction is then incremented to 1.
//  2 (3) 0  1  -3  - step forward because of the instruction we just modified.
//					  The first instruction is incremented again, now to 2.
//  2  4  0  1 (-3) - jump all the way to the end; leave a 4 behind.
//  2 (4) 0  1  -2  - go back to where we just were; increment -3 to -2.
//  2  5  0  1  -2  - jump 4 steps forward, escaping the maze.
// In this example, the exit is reached in 5 steps.
//


//Thoughts:

// Index (pointer?) arithmetic in an array until an overflow is reached.


// Using C++11 for nicer vector initialisation
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>
using namespace std;

const unsigned int LOOP_BREAKER =  UINT_MAX;

vector<int> sampleData = {0, 3,	0, 1,-3};
int sampleSolution = 5;
vector<int> data;


vector<int> readFile(const char * filepath, char token)
{

	ifstream myfile;
	string line;
	vector<int> target;

	myfile.open(filepath);

		if (myfile.is_open())
		{
			while (getline(myfile, line))
			{
				cout << line << '\n';

				const char* c = line.c_str();
				int num = atoi(c);
				target.push_back(num);
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

int calculate(vector<int> dataArray)
{
	unsigned int stepCount = 0;
	const unsigned int MAX_ARRAY_INDEX = dataArray.size();
	unsigned int arrayIndex = 0;
	int arrayContents = 0;


	// Any underflow on a UINT will be a massive number - larger than the MAX_ARRAY_INDEX!
	while ((arrayIndex < MAX_ARRAY_INDEX) && (stepCount < LOOP_BREAKER))
	{
		cout << "===Step #" << stepCount << "===" << endl;

		arrayContents = dataArray[arrayIndex];
		dataArray[arrayIndex]++;
		arrayIndex = arrayIndex + arrayContents;

		cout << "dataArray[" << arrayIndex << "] : " << dataArray[arrayIndex] << endl;

		stepCount++;
	}

	return stepCount;
}


bool calculateAllTestData()
{
	return test(calculate(sampleData), sampleSolution);
}

void initialise()
{
	data = readFile("src/input.txt", '\n');
}

int main()
{
	int result = -1;
	cout << "AoC05-A begin:" << endl; // prints AoC05-A begin:

	initialise();
	cout << "no. of rows in sampleData: " << sampleData.size() << endl;
	cout << "no. of rows in data: " << data.size() << endl;

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
