#include <bits/stdc++.h>
using namespace std;

int maxProfit(int W, int n, vector<int> &wt, vector<int> &val)
{
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            int notTake = dp[i - 1][j];
            int take = -1e9;
            if (j >= wt[i - 1])
                take = val[i - 1] + dp[i - 1][j - wt[i - 1]];
            dp[i][j] = max(notTake, take);
        }
    }
    return dp[n][W];
}

int main()
{
    int W = 50;
    int n = 3;
    vector<int> val(n);
    vector<int> wt(n);
    for (auto &it : val)
    {
        cin >> it;
    }
    for (auto &it : wt)
    {
        cin >> it;
    }
    cout
        << maxProfit(W, n, wt, val);

    return 0;
}