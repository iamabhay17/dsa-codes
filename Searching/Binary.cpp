// implementing binary search
// o(log n)

#include <iostream>
using namespace std;

int binary(int arr[], int size, int target)
{
    int low = 0;
    int high = size - 1;

    while (low < high)
    {
        int mid = (high - low) + low / 2;

        if (arr[mid] == target)
            return mid;

        if (arr[mid] < target)
        {
            low = mid + 1;
        }
        if (arr[mid] > target)
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {4, 2, 5, 1, 7, 9, 11, 13, 41};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    cin >> target;

    cout << "Present at : " << binary(arr, size, target);

    return 0;
}
