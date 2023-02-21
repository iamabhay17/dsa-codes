#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;

        arr[index] = val;

        while (index > 1)
        {
            if (arr[index] > arr[index / 2])
            {
                swap(arr[index], arr[index / 2]);
                index = index / 2;
            }
            else
            {
                return;
            }
        }
    }

    // delete

    void deleteFrom()
    {
        if (size == 0)
        {
            cout << "cannot delete : " << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i < size)
        {
            int leftInd = 2 * i;
            int rightInd = 2 * i + 1;

            if (leftInd < size && arr[leftInd] > arr[i])
            {
                swap(arr[i], arr[leftInd]);
                i = leftInd;
            }
            else if (rightInd < size && arr[rightInd] > arr[i])
            {
                swap(arr[i], arr[rightInd]);
                i = rightInd;
            }
            else
            {
                return;
            }
        }
    }

    // print

    void print()
    {
        for (int i = 1; i < size + 1; i++)
        {
            cout << arr[i] << " ";
        }
    }
};

void heapify(vector<int> &arr, int i, int n)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left < n && arr[largest] < arr[left])
    {
        largest = left;
    }
    if (right < n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// int main

int main()
{
    heap h;

    vector<int> arr = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (auto i : arr)
    {
        cout << i << " ";
    }
    return 0;
}