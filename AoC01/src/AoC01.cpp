//============================================================================
// Name        : AoC01.cpp
// Author      : KateT
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int sample1[] = {1,1,2,2};
int sample2[] = {1,1,1,1};
int sample3[] = {1,2,3,4};
int sample4[] = {9,1,2,1,2,1,2,9};

int solution1 = 3;
int solution2 = 4;
int solution3 = 0;
int solution4 = 9;

int calculate(int* data, int arrayLength);

int main()
{

	int result = calculate(sample4, (sizeof(sample4)/sizeof(*sample4)));

	if (result != solution4)
	{
		cout << "Wrong result: " << result << endl;
	}
	else
	{
		cout << "Looks good. Result is: " << result << endl;
	}

	return 0;

}


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
		// if i == last item in array then 2ndComparator == 0
			if (i == (arrayLength - 1))
			{
				comp = 0;
			}
			else //2ndComparator == i+1
			{
				comp = i + 1;
			}

			//if array[i] == array[2ndComparator] then add array[i] to int Total
			if (data[i] == data[comp])
			{
				total += data[i];
			}
		}
	}

	return total;
}


