#include <bits/stdc++.h>
using namespace std;

void minimumCoins(int amt, vector<int> deno, int n)
{
    // sort(deno.begin(),deno.end());

    vector<int> ans;
    int totalCoins = 0;
    int i = n - 1;
    while (amt > 0)
    {
        if (amt < deno[i])
            i--;
        else
        {
            ans.push_back(deno[i]);
            totalCoins++;
            amt -= deno[i];
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    cout << "Minimum coins required are " << totalCoins << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<int> deno(n);
    for (auto &it : deno)
    {
        cin >> it;
    }
    cout << "Enter the total amount ";
    int amt;
    cin >> amt;
    minimumCoins(amt, deno, n);
    return 0;
}