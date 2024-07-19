#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int binarySearchRec(int arr[],int right,int num,int left=0)
{
	int mid = (left + right) / 2;
	if (left > right)
		return -1;
	if (arr[mid] > num)
		binarySearchRec(arr, mid - 1, num, left);
	else if (arr[mid] < num)
		binarySearchRec(arr, right, num, mid + 1);
	else
		return mid;
}

int main()
{
	int arr[] = { 1,4,7,10,15,19,20,25,29,30,55 };

	int Size = sizeof(arr) / sizeof(arr[0]);

	for (int i = 0; i < Size; i++)
	{
		cout << binarySearchRec(arr, Size, arr[i]) << " "; // 0 1 2 3 4 5 6 .... Size-1
	}

	cout << endl;
	return 0;
}