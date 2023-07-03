#include<iostream>
using namespace std;

int quicksort(int arr[], int low, int high)
{
	if (low > high)
		return -1;
	int key = arr[low];
	int i = low;
	int j = high;
	while (i < j)
	{
		while (i < j && arr[j] >= key)
			j--;

		arr[i] = arr[j];

		while (i < j && arr[i] <= key)
			i++;

		arr[j] = arr[i];
	}
	arr[i] = key;

	if (i - 1 > low)
	{
		quicksort(arr, low, i - 1);
	}
	if (i + 1 < high)
	{
		quicksort(arr, i + 1, high);
	}
	return 0;
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
	int a[] = { 1,4,6,3,2,7,8,6,5 };
	int low = 0;
	int high = sizeof(a) / sizeof(a[0]);
	quicksort(a, low, high-1);
	print(a, high);

	return 0;
}