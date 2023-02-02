// selection sort
// n2

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // selection sort
    for (int i = 0; i < size - 1; i++)
    {
        int minInd = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minInd])
            {
                minInd = j;
            }
            // swap
            swap(arr[minInd], arr[i]);
        }
    }

    for (auto x : arr)
    {
        cout << x << " ";
    }

    return 0;
}