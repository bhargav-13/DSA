#include <bits/stdc++.h>
using namespace std;

int arrSum(int array[], int size, int sum = 0)
{
	if (size == 0)
		return sum;

	return arrSum(array, size - 1, sum + array[size - 1]);
}

int main()
{
	int array[] = { 2, 55, 1, 7 };
	int size = sizeof(array) / sizeof(array[0]);
	cout << arrSum(array, size) << endl;
	return 0;
}
