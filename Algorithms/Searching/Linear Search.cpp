#include <iostream>
#include <ctime>
#include <time.h>
#include <random>
using namespace std;

#define minNumberRange 1
#define maxNumberRange 100000000000

int linearSearch(int* arr, int size,int num)
{
	for (int index = 0; index < size; index++)
	{
		if (arr[index] == num)
			return index;
	}
	return -1;
}
int main()
{
	const int size = 1000000;
	int* arr = new int[size];
	srand(unsigned int(time(NULL)));
	for (int i = 0; i < size; i++)
	{
		arr[i] = minNumberRange + rand() % (maxNumberRange - minNumberRange + 1);
		//cout << arr[i] << " ";
	}
	//cout << endl << endl << endl;
	int num = minNumberRange + rand() % (maxNumberRange - minNumberRange + 1);
	clock_t start = clock();
	int index = linearSearch(arr, size, num);
	
	clock_t end = clock();

	double executionTime = double(end - start) / CLOCKS_PER_SEC * 1000;
	if (index == -1)
		cout << "The number " << num << "doesn't exist." << endl;
	else
		cout << "The number " << num << " is at index " << index << endl;

	cout << "Execution Time is " << executionTime << endl;
	delete[] arr;
	return 0;
}