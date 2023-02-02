// Implementing bubble sort
// Time Complexity	O(n2)

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // bubble sort
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    // printing
    for (auto i : arr)
        cout << i << " ";

    return 0;
}
