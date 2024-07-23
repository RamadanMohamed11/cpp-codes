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
#define sizeOfArray 100000

void swapTwoNumbers(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

int partition(int* arr, int start, int end)
{
	int pivot = arr[end];
	int i = start - 1;

	for (int j = start; j < end; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			swapTwoNumbers(arr[i], arr[j]);
		}
	}
	swapTwoNumbers(arr[i + 1], arr[end]);
	return (i + 1);
}
void quickSort(int* arr, int start, int end)
{
	if (start >= end)
		return;
	int partitionIndex = partition(arr, start, end);

	quickSort(arr, start, partitionIndex - 1);

	quickSort(arr, partitionIndex + 1, end);
}
int main()
{
	int* arr = new int[sizeOfArray];
	srand(unsigned int(time(NULL)));
	for (int i = 0; i < sizeOfArray; i++)
	{
		arr[i] = minNumberRange + rand() % (maxNumberRange - minNumberRange + 1);
		//cout << arr[i] << " ";
	}
	//cout << endl << endl << endl;
	clock_t start = clock();
	quickSort(arr, 0, sizeOfArray - 1);
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