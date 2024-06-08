#include <iostream>
#include <ctime>
#include <time.h>
#include <random>
using namespace std;

#define minNumberRange 1
#define maxNumberRange 1000000

void swapTwoNumbers(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}
int findMin(int *arr, int size, int startSearching)
{
	int minIndex = startSearching;
	for (int index = startSearching; index < size; index++)
	{
		if (arr[minIndex] > arr[index])
			minIndex = index;
	}
	return minIndex;
}
void selectionSort(int* arr, int size)
{
	int index = 0;
	for (int i = 0; i < size - 1; i++)
	{
		index = findMin(arr, size, i);
		swapTwoNumbers(arr[i], arr[index]);
	}
}
int main()
{
	const int size = 100000;
	int* arr = new int[size];
	srand(unsigned int(time(NULL)));
	for (int i = 0; i < size; i++)
	{
		arr[i] = minNumberRange + rand() % (maxNumberRange - minNumberRange + 1);
		//cout << arr[i] << " ";
	}
	//cout << endl << endl << endl;
	clock_t start = clock();
	selectionSort(arr, size);
	clock_t end = clock();

	double executionTime = double(end - start) / CLOCKS_PER_SEC * 1000;
	/*for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}*/
	cout << endl;

	cout << "Execution Time is " << executionTime << endl;
	delete[] arr;
	return 0;
}