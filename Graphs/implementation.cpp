#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m; // n= nodes ,m=edges
    vector<int> arr[n + 1];
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b; // a and b are two connected nodes
        arr[a].push_back(b);
        arr[b].push_back(a); // in case of directed graph remove this line
    }
    return 0;
}