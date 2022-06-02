#include <bits/stdc++.h>
using namespace std;

// int minimumCoins(int i, int sum, vector<int> a)
// {
//     if (i == 0)
//     {
//         if (sum % a[i] == 0)
//             return sum / a[i];
//         else
//             return 1e9;
//     }

//     int nottake = minimumCoins(i - 1, sum, a);
//     int take = 1e9;
//     if (a[i] <= sum)
//         take = 1 + minimumCoins(i, sum - a[i], a);

//     return min(take, nottake);
// }

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a)
    {
        cin >> it;
    }
    int sum;
    cin >> sum;
    // cout << minimumCoins(n - 1, sum, a);

    vector<vector<int>> dp(n, vector<int>(sum + 1));

    for (int i = 0; i <= sum; i++)
    {
        if (i % a[0] == 0)
            dp[0][i] = i / a[0];
        else
            dp[0][i] = 1e9;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int nottake = dp[i - 1][j];
            int take = 1e9;
            if (a[i] <= j)
                take = 1 + dp[i][j - a[i]];
            dp[i][j] = min(take, nottake);
        }
    }

    cout << dp[n - 1][sum] << endl;

    return 0;
}