#include <iostream>
#include <ctime>
#include <time.h>
#include <random>
using namespace std;

#define minNumberRange 1
#define maxNumberRange 1000000

void insertionSort(int* arr, int size)
{
	for (int i = 1; i < size; i++)
	{
		int cur = arr[i];
		int j = i - 1;
		while (j >= 0 && (arr[j] > cur))
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = cur;
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
	insertionSort(arr, size);
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