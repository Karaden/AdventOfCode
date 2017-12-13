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

int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!


	int result = calculate(sample1, 4);

	if (result != solution1)
	{
		cout << "Wrong result: " << result << endl;
	}

	return 0;

}


int calculate(int* data, int arrayLength)
{

	int total = -1;
	// loop for array.length

	// if i == last item in array then 2ndComparator == 0
	// else 2ndComparator == i+1

	//if array[i] == array[2ndComparator] then add array[i] to int Total



	return total;
}


