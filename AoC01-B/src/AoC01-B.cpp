//============================================================================
// Name        : AoC01-B.cpp
// Author      : KateT
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// Commas added to raw string via python: ",".join((x for x in rawString))
int puzzleInput[] = {3,1,8,1,3,1,7,4,3,4,9,2,3,5,9,7,2,1,5,9,8,1,1,8,6,9,7,5,5,1,6,6,3,4,3,8,8,2,9,5,8,3,7,6,4,7,4,2,7,8,4,3,7,6,8,
		1,6,3,2,4,9,5,2,2,2,4,9,9,2,1,1,4,8,8,6,4,9,5,4,3,7,5,5,6,5,5,1,3,8,8,4,2,5,5,3,8,6,7,2,4,6,1,3,1,2,4,5,4,6,2,8,8,1,7,5,6,
		8,6,2,7,3,6,9,2,2,9,2,5,7,5,2,6,4,7,3,4,1,6,7,3,3,4,2,7,5,6,5,1,4,8,5,6,6,6,3,9,7,9,4,9,6,7,4,7,1,5,8,2,4,1,7,9,2,8,5,7,6,
		2,5,4,7,1,3,2,3,5,3,5,1,8,3,2,2,2,4,9,7,9,4,9,7,5,1,6,4,4,4,8,8,2,7,7,3,1,7,1,7,3,4,9,6,1,2,4,4,7,3,8,9,3,4,5,2,4,2,5,1,1,
		8,1,3,3,6,4,5,9,8,4,4,8,8,7,5,9,1,2,8,8,9,7,1,4,6,4,9,8,8,3,1,3,7,3,7,9,5,7,2,1,6,6,1,6,9,6,4,9,2,6,2,2,2,7,6,2,8,2,8,8,1,
		2,1,8,3,7,1,2,7,3,9,7,3,5,3,8,1,6,3,7,7,9,7,8,2,4,3,5,2,1,1,4,9,1,1,9,6,6,1,6,3,7,5,1,3,5,4,7,2,5,1,7,9,3,5,4,8,1,9,6,4,4,
		3,9,9,5,6,8,4,4,5,3,6,1,3,6,8,2,3,7,5,7,7,6,4,4,9,4,9,6,7,2,9,7,2,5,1,5,4,5,3,8,9,4,6,4,4,7,2,7,9,4,4,7,4,4,4,7,9,4,1,5,6,
		4,7,7,8,7,3,3,9,2,6,5,3,2,7,4,1,7,5,2,7,5,7,8,6,5,2,4,3,9,4,6,9,7,6,2,6,6,4,2,6,5,4,8,3,4,1,8,8,9,8,7,3,5,1,4,3,8,3,4,6,4,
		1,4,2,6,5,9,4,2,5,1,2,2,7,8,6,6,6,7,3,9,9,1,4,3,3,3,5,7,7,2,1,7,4,9,7,3,1,2,8,3,8,3,8,6,9,8,9,3,3,2,5,9,7,7,3,1,9,6,5,1,8,
		3,9,5,1,6,6,9,4,2,9,5,5,3,4,1,4,6,6,6,8,7,2,8,8,2,2,3,9,3,4,5,2,6,2,6,3,2,1,8,9,2,3,5,7,1,9,2,5,7,4,4,4,4,8,5,6,2,6,4,7,2,
		1,5,8,5,3,6,5,1,6,4,9,4,5,6,4,7,2,5,4,6,4,5,2,6,4,6,9,3,9,5,7,8,9,8,3,7,3,2,1,4,8,9,7,8,4,8,4,2,4,9,6,6,2,6,6,5,8,2,9,9,1,
		2,7,2,4,9,6,7,7,1,1,5,9,5,8,3,7,1,5,4,5,6,7,1,4,6,4,5,5,8,5,5,7,6,6,4,1,4,5,8,3,5,8,3,2,6,5,2,1,8,5,8,5,1,8,3,1,9,3,1,5,2,
		3,3,8,5,7,4,7,3,6,9,5,7,1,2,2,3,8,3,2,3,7,8,7,2,5,4,5,5,6,5,9,7,5,6,6,4,6,1,1,8,8,4,5,2,2,7,9,8,5,3,7,6,6,1,8,4,3,3,3,6,9,
		6,3,4,4,3,9,5,8,1,8,6,1,5,2,1,5,8,4,6,3,4,8,5,8,6,5,4,1,1,6,4,1,9,4,6,2,4,3,7,1,3,5,3,5,5,6,8,1,2,5,4,8,9,4,5,4,4,7,4,3,2,
		7,8,7,7,9,5,4,8,9,4,4,3,3,1,2,9,4,1,6,8,7,2,2,1,3,1,4,4,3,2,6,9,4,1,1,5,8,4,7,8,6,3,1,2,9,8,2,6,5,3,2,6,2,8,2,2,8,3,8,6,8,
		9,4,6,8,3,3,9,2,3,5,2,7,9,9,5,1,4,9,4,2,6,6,5,3,9,6,2,7,3,7,2,6,8,2,1,9,3,6,3,4,6,6,6,3,4,8,5,4,9,9,1,5,9,1,4,1,3,6,8,4,4,
		3,7,8,2,4,7,5,7,1,4,6,7,9,9,5,3,2,1,3,3,8,8,3,7,5,9,3,9,5,1,9,7,1,1,5,9,1,2,6,2,4,8,9,8,6,9,3,2,6,1,4,5,4,7,6,9,5,8,3,7,8,
		4,6,4,6,5,2,4,5,1,4,4,1,4,3,4,8,4,6,3,8,2,4,7,4,5,7,8,5,3,5,4,6,8,4,3,3,5,1,4,1,2,1,3,3,6,8,4,4,7,2,7,9,8,8,1,2,8,9,9,8,5,
		4,3,9,7,5,1,4,7,6,4,9,8,2,3,2,1,5,3,3,2,9,2,9,6,2,3,5,7,4,2,3,1,7,3,8,4,4,2,2,8,1,1,6,1,2,9,4,8,3,8,4,9,9,4,4,1,7,9,9,9,9,
		6,8,5,7,7,4,6,5,4,9,4,4,1,1,4,2,8,5,9,1,9,9,7,9,9,1,2,5,5,9,5,7,6,1,7,2,4,7,8,2,2,2,5,4,5,2,3,9,4,5,9,3,5,1,4,3,8,8,5,7,1,
		1,8,7,2,7,9,2,6,6,2,9,1,3,6,4,2,7,8,1,8,4,7,6,1,8,3,3,3,2,4,4,7,6,8,3,8,9,3,9,8,9,8,2,5,8,2,2,5,7,4,8,5,6,2,3,4,5,8,5,3,6,
		3,3,3,6,4,3,1,4,9,2,3,1,8,6,6,8,5,5,3,4,8,6,4,1,7,8,6,6,5,2,1,4,1,3,5,6,3,1,4,9,4,8,7,6,4,7,4,1,8,6,8,3,3,3,9,2,9,2,9,1,2,
		4,3,3,7,1,6,1,2,2,2,9,5,9,4,5,9,1,1,7,5,5,4,2,3,8,4,2,9,2,1,6,9,1,6,5,3,2,1,7,5,2,4,7,3,2,6,3,9,1,3,2,1,5,2,5,8,3,2,3,6,2,
		2,7,4,6,8,3,7,6,3,4,8,8,3,4,7,6,5,4,4,9,7,8,8,9,2,6,1,5,4,3,9,5,9,5,9,1,2,1,2,5,3,9,8,5,1,8,3,5,3,5,4,3,3,5,5,9,8,8,4,4,6,
		6,9,6,1,8,3,9,1,8,7,6,6,2,3,6,3,8,1,3,7,9,2,6,8,9,3,5,8,2,1,3,1,9,4,5,3,6,1,2,6,4,8,4,1,7,3,3,3,4,1,2,4,7,6,4,6,1,2,5,2,7,
		8,4,8,9,9,9,5,8,3,8,3,6,9,1,2,7,5,8,2,4,3,8,4,1,9,8,8,9,9,2,2,3,6,5,5,9,6,5,5,4,2,3,7,1,5,3,4,1,2,3,9,4,4,9,4,9,3,2,5,8,2,
		4,2,4,2,2,2,4,7,9,7,9,8,3,8,2,9,3,2,3,3,5,2,3,9,2,7,4,2,9,7,6,6,3,3,6,5,1,6,4,9,1,2,9,5,3,3,6,4,7,7,7,8,7,6,1,8,7,5,2,2,3,
		2,4,9,9,1,8,3,7,7,7,5,4,9,2,6,2,1,6,7,5,9,5,3,3,9,7,8,4,3,8,3,3,2,4,7,5,2,5,5,9,9,7,7,1,9,7,4,5,5,5,5,4,5,3,4,8,3,8,8,8,7,
		1,5,7,8,3,4,7,3,3,2,4,5,6,5,8,6,9,4,9,2,8,3,6,5,7,6,1,3,8,4,1,4,1,4,5,7,6,9,7,6,5,4,2,3,4,3,9,3,4,9,1,1,4,2,4,7,1,6,6,1,3,
		4,7,9,2,4,9,8,9,3,1,1,3,9,6,1,9,2,5,7,1,3,3,1,7,6,4,4,3,4,9,9,4,6,4,4,4,2,7,1,9,5,9,3,7,5,9,8,1,1,5,8,4,4,5,1,5,1,6,5,9,4,
		3,1,8,4,4,1,4,2,2,4,2,5,4,7,1,9,1,1,8,1,9,4,4,3,9,5,8,9,7,9,6,3,1,4,6,9,4,7,9,3,5,4,6,3,7,1,8,1,4,5,1,6,9,2,6,6,1,2,9,1,1,
		8,4,1,3,5,2,3,5,4,1,2,2,2,4,4,4,9,9,7,6,7,8,7,2,6,6,4,4,6,1,5,1,8,5,3,2,4,4,6,1,2,9,3,2,2,8,1,2,4,4,5,6,1,1,8,8,5,3,8,8,5,
		5,5,2,2,7,9,8,4,9,9,1,7,3,4,2,4,7,4,7,9,2,9,8,4,4,2,5,6,2,9,2,4,8,4,9,2,8,4,7,8,2,7,6,5,3,1,3,3,5,8,3,2,1,5,5,3,9,3,2,5,8,
		6,6,8,8,1,6,6,2,1,5,9,4,2,1,9,8,7,3,1,5,1,8,6,9,1,4,7,6,9,4,7,8,9,4,7,3,8,9,1,8,8,3,8,2,3,8,3,5,4,6,8,8,1,6,2,2,2,4,6,7,9,
		3,7,8,1,8,4,6,2,5,4,2,5,3,7,5,9,7,1,4,5,7,3,3,5,4,5,4,4,9,9,7,8,5,3,1,5,3,7,9,8,8,6,2,4,3,6,8,8,7,8,8,9,3,1,8,6,4,6,6,4,3,
		3,5,9,5,5,5,6,6,3,1,3,5,4,7,6,2,6,1,8,6,3};


int sample1[] = {1,2,1,2};
int sample2[] = {1,2,2,1};
int sample3[] = {1,2,3,4,2,5};
int sample4[] = {1,2,3,1,2,3};
int sample5[] = {1,2,1,3,1,4,1,5};

int solution1 = 6;
int solution2 = 0;
int solution3 = 4;
int solution4 = 12;
int solution5 = 4;


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

/*
 * Now, instead of considering the next digit, it wants you to consider the digit halfway around
   the circular list. That is, if your list contains 10 items, only include a digit in your sum
   if the digit 10/2 = 5 steps forward matches it. Fortunately, your list has an even number of
   elements.

For example:

    1212 produces 6: the list contains 4 items, and all four digits match the digit 2 items ahead.
    1221 produces 0, because every comparison is between a 1 and a 2.
    123425 produces 4, because both 2s match each other, but no other digit has a match.
    123123 produces 12.
    12131415 produces 4.
 *
 */
int calculate(int* data, int arrayLength)
{

	int total = -1;
	int comp = 0;

	if ((data != NULL) && (arrayLength > 0))
	{
		total = 0;
		// loop for array.length1
		for(int i = 0; i < arrayLength; i++)
		{
			/*
			 if length is 10:
			 i = 0, comp = 5
			 i = 4, comp = 9
			 i = 5, comp = 0 -> wraparound!

			 */

			comp = (i + (arrayLength/2)) % arrayLength;


			//if array[i] == array[2ndComparator] then add array[i] to int Total
			if (data[i] == data[comp])
			{
				total += data[i];
			}

		}
	}

	return total;
}



int main() {

	int result = 0;
	cout << "AoC01-B" << endl; // prints !!!Hello World!!!


	 if (
	(test(calculate(sample1, (sizeof(sample1)/sizeof(*sample1))), solution1)) &&
	(test(calculate(sample2, (sizeof(sample2)/sizeof(*sample2))), solution2)) &&
	(test(calculate(sample3, (sizeof(sample3)/sizeof(*sample3))), solution3)) &&
	(test(calculate(sample4, (sizeof(sample4)/sizeof(*sample4))), solution4)) &&
	(test(calculate(sample5, (sizeof(sample5)/sizeof(*sample5))), solution5)))
	 {
		 result = calculate(puzzleInput, (sizeof(puzzleInput)/sizeof(*puzzleInput)));
		 	cout << "Final result is: " << result << endl;
	 }



	return 0;
}




