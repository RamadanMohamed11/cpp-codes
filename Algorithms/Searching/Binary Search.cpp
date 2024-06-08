#include <iostream>
#include <ctime>
#include <time.h>
#include <random>
#include <algorithm>
using namespace std;

#define minNumberRange 1
#define maxNumberRange 10000000

int binarySearch(int* arr, int size,int num)
{
	int l = 0, h = size - 1, m = 0;
	while (l <= h)
	{
		m = (l + h) / 2;
		if (arr[m] > num)
			h = m - 1;
		else if (arr[m] < num)
			l = m + 1;
		else
			return m;
	}
	return -1;
}
int main()
{
	const int size = 1000000;
	int* arr = new int[size];
	srand(unsigned int(time(NULL)));
	//cout << "The numbers before sorting ..." << endl;
	for (int i = 0; i < size; i++)
	{
		arr[i] = minNumberRange + rand() % (maxNumberRange - minNumberRange + 1);
		//cout << arr[i] << " ";
	}
	//cout << endl << endl << endl;

	int num = arr[size - 1];

	clock_t start1 = clock();
	sort(arr, arr + size);
	clock_t end1 = clock();
	double executionTime1 = double(end1 - start1) / CLOCKS_PER_SEC * 1000;

	/*cout << "The numbers after sorting ..." << endl;
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}*/


	clock_t start2 = clock();
	int index = binarySearch(arr, size, num);
	clock_t end2 = clock();
	cout << endl;
	double executionTime2 = double(end2 - start2) / CLOCKS_PER_SEC * 1000;

	if (index == -1)
		cout << "The number " << num << " doesn't exist." << endl;
	else
		cout << "The number " << num << " is at index " << index << endl;

	cout << endl << endl << endl;

	cout << "Execution Time without considering the sort time = " << executionTime2 << endl;
	cout << "Execution Time with considering the sort time = " << executionTime1+ executionTime2 << endl;
	delete[] arr;
	return 0;
}