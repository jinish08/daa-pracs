#include <bits/stdc++.h>
using namespace std;

int main()
{

    string a, b;
    cout << "Enter the first string" << endl;
    cin >> a;
    cout << "Enter the second string" << endl;
    cin >> b;

    int l1 = a.size();
    int l2 = b.size();

    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[l1][l2] << endl;

    return 0;
}