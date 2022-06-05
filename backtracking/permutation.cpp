#include <bits/stdc++.h>
using namespace std;

void permutation(vector<int> &arr, int i, int n)
{
    if (i == n)
    {
        for (auto it : arr)
            cout << it << " ";
        cout << endl;
    }

    for (int j = i; j < n; j++)
    {
        swap(arr[i], arr[j]);
        permutation(arr, i + 1, n);
        swap(arr[i], arr[j]);
    }

    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (auto &it : arr)
        cin >> it;

    permutation(arr, 0, n);

    return 0;
}