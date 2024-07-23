/*
*  _____                   ____                           _               __  __       _                              _
* | ____|_ __   __ _   _  |  _ \ __ _ _ __ ___   __ _  __| | __ _ _ __   |  \/  | ___ | |__   __ _ _ __ ___   ___  __| |
* |  _| | '_ \ / _` | (_) | |_) / _` | '_ ` _ \ / _` |/ _` |/ _` | '_ \  | |\/| |/ _ \| '_ \ / _` | '_ ` _ \ / _ \/ _` |
* | |___| | | | (_| |  _  |  _ < (_| | | | | | | (_| | (_| | (_| | | | | | |  | | (_) | | | | (_| | | | | | |  __/ (_| |
* |_____|_| |_|\__, | (_) |_| \_\__,_|_| |_| |_|\__,_|\__,_|\__,_|_| |_| |_|  |_|\___/|_| |_|\__,_|_| |_| |_|\___|\__,_|
*              |___/
*/

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
void bubbleSort(int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		for (int j = 0; j < size - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swapTwoNumbers(arr[j], arr[j + 1]);
		}
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
	bubbleSort(arr, size);
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
