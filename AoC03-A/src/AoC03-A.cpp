//============================================================================
// Name        : AoC03-A.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description :
//
//Each square on the grid is allocated in a spiral pattern starting at a location marked 1 and
//then counting up while spiraling outward. For example, the first few squares are allocated like this:
//
//17  16  15  14  13
//18   5   4   3  12
//19   6   1   2  11
//20   7   8   9  10
//21  22  23---> ...
//While this is very space-efficient (no squares are skipped), requested data must be carried
//back to square 1 (the location of the only access port for this memory system) by programs
//that can only move up, down, left, or right. They always take the shortest path: the
//Manhattan Distance between the location of the data and square 1.
//
//For example:
//
//Data from square 1 is carried 0 steps, since it's at the access port.
//Data from square 12 is carried 3 steps, such as: down, left, left.
//Data from square 23 is carried only 2 steps: up twice.
//Data from square 1024 must be carried 31 steps.
//
//How many steps are required to carry the data from the square identified in your puzzle
//input all the way to the access port?
//
//Your puzzle input is 289326.


// My thoughts:
// Lower right corners are odd squares: 1x1 = 1, 3x3 = 9, 5x5 = 25 etc
// The number of values in each 'ring' of the spiral is 4 (sides of a square) multiplied by
// the even number below the corner square


// e.g.
// 3x3 square has corner value of  9. The ring value is 4x(3-1) =  8. The side length is 2
// 5x5 square has corner value of 25. The ring value is 4x(5-1) = 16.                    4
// 7x7                            49.					4x(7-1) = 24.                    6


// Manhattan distance is at most Side length for any number on that ring
// and Side length/2 is at minimum for any number on that ring.



	// Take an input
	// Find next largest square number with odd root
	// Find root
	// work out x, y coords

//============================================================================

#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const unsigned int UPPER_LIMIT = 5000;
const unsigned int sampleDataSize = 4;
//input, number of steps
unsigned int sampleData[sampleDataSize][2] = {{1,0},{12,3},{23,2},{1024,31}};
unsigned int data = 289326;


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

int calculateCornerRoot(unsigned int target)
{

	for (unsigned int root = 1; root < UPPER_LIMIT; root= root+2)
		{
			if ((root*root) >= target)
				return root;
		}

	return -1;
}

int calculate(int target)
{
	int result = -1;

	int cornerRoot = calculateCornerRoot(target);
	cout << "Corner value: " << (cornerRoot*cornerRoot) << endl;
	cout << "Corner root: " << cornerRoot << endl;

	int sideLength = cornerRoot - 1;
	int minMD = sideLength / 2;
	cout << "Side length: " << sideLength << endl;
	cout << "Minimum Manhattan Distance: " << minMD << endl;

	if (sideLength == 0)
	{
		result = 0;
	}
	else
	{

		//get previous ring corner value
		int previousCornerValue = (cornerRoot-2)*(cornerRoot-2);


		//subtract prevCornVal from target to get position on ring perimeter
		int ringPerimeterPosition = target - previousCornerValue;


		//modulo sideLength to get position on ring side
		int ringSidePosition = ringPerimeterPosition % sideLength;


		//difference between ringSidePos and minMD
		int difference = ringSidePosition - minMD;

		// make sure difference is always a positive number
		int absdiff = abs(difference);


		// abs(ringsidePos - (minMD)) + (minMD)
		result = absdiff + minMD;





	}


	return result;
}

bool calculateAllTestData()
{

	for(unsigned int i = 0; i < sampleDataSize; i++)
	{
		if (!test(calculate(sampleData[i][0]), sampleData[i][1]))
		{
			return false;
		}
	}

	return true;
}


int main() {
	int result = -1;
	cout << "This is AoC03-A." << endl;


	if ((calculateAllTestData()))
	{
		result = calculate(data);
		cout << "Final result is: " << result << endl;
	}

	return 0;
}
