// implemeting linear search
//  o(n)

#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target, i;
    cin >> target;

    for (i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            cout << "Element present in array at :" << i;
        }
    }
    if (i != size - 1)
    {
        cout << "Target not present in array";
    }

    return 0;
}