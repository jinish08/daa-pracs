#include <bits/stdc++.h>
using namespace std;

void minmax(vector<int> &arr, int low, int high, int &mini, int &maxi)
{
    if (low == high)
        return;
    else if (high - low == 1)
    {
        if (arr[low] > arr[high])
        {
            mini = min(mini, arr[high]);
            maxi = max(maxi, arr[low]);
        }
        else
        {
            mini = min(mini, arr[low]);
            maxi = max(maxi, arr[high]);
        }
    }
    else
    {
        int mid = (low + high) / 2;
        minmax(arr, low, mid, mini, maxi);
        minmax(arr, mid + 1, high, mini, maxi);
    }
    return;
}

int main()
{

    int n;
    cin >> n;
    vector<int> arr(n);

    for (auto &it : arr)
    {
        cin >> it;
    }

    int mini = 1e9;
    int maxi = -1e9;

    int low = 0;
    int high = n - 1;

    minmax(arr, low, high, mini, maxi);

    cout << mini << " " << maxi << endl;

    return 0;
}