#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return (double)a.first / (double)a.second > (double)b.first / (double)b.second;
}

int fractionalKnapsack(int W, vector<pair<int, int>> arr, int n)
{
    sort(arr.begin(), arr.end(), cmp);
    int totalProfit = 0;
    for (auto it : arr)
    {
        if (W > 0)
        {
            if (W >= it.second)
            {
                totalProfit += it.first;
                W -= it.second;
            }
            else
            {
                totalProfit += (it.first * W) / it.second;
                W = 0;
            }
        }
        else
            break;
    }
    return totalProfit;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cout << "Enter profit and weight of item number " << i + 1 << " : ";
        int p, w;
        cin >> p;
        cin >> w;
        arr[i].first = p;
        arr[i].second = w;
    }
    cout << "Enter the maximum weight bag can hold ";
    int W;
    cin >> W;
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n);
}