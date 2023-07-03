#include<iostream>
using namespace std;
int partition(int arr[], int low,int high)
{
    int key = arr[low];
    while (low < high)
    {
        while (low < high && arr[high] >= key)
        {
            high--;
        }
        arr[low] = arr[high];
        while (low < high && arr[low] <= key)
        {
            low++;
        }
        arr[high] = arr[low];
    }
    arr[low] = key;
    return low;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
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