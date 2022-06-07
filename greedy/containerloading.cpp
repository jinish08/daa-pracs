#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int n, int W)
{
    int pointer = 0;
    sort(arr.begin(), arr.end());
    cout << "The containers included in the ship are ";
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= W)
        {
            cout << arr[i] << " ";
            pointer++;
            W -= arr[i];
        }
        else break;
    }
    cout << endl;
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
    int W;
    cout << "Enter the max capacity ";
    cin >> W;
    solve(arr, n, W);
    return 0;
}