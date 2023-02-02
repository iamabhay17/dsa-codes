// quick sort

#include <iostream>
using namespace std;

// partition
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    // placing pivot at right location
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // handling left and right
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIndex;
}

// quick sort
void quickSort(int arr[], int s, int e)
{
    // base case
    if (s >= e)
        return;

    // partition
    int p = partition(arr, s, e);

    // left part
    quickSort(arr, s, p - 1);
    // right part
    quickSort(arr, p + 1, e);
}

int main()
{
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    quickSort(arr, 0, size - 1);

    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}