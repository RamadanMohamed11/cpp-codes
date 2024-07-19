#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int sumRec(int arr[], int Size, int index = 0)
{
	if (index == Size - 1)
		return arr[index];
	return arr[index] + sumRec(arr, Size, index + 1);
}

int main()
{
	int arr[] = { 44,5,8,9,33,56,78,96,47 };
	int Size = sizeof(arr) / sizeof(arr[0]);

	cout << sumRec(arr, Size) << endl;	// 

	cout << endl;
	return 0;
}