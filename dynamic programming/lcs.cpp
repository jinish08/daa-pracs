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

    int i = l1, j = l2;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (a[i - 1] == b[j - 1])
        {
            ans.push_back(a[i - 1]);
            i--;
            j--;
        }
        else
        {
            if (dp[i][j - 1] > dp[i - 1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;

    return 0;
}