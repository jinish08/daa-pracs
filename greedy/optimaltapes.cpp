#include <bits/stdc++.h>
using namespace std;

void optimalStorageTapes(vector<int> arr, int n)
{
    sort(arr.begin(), arr.end());
    int meanTime = 0;
    int i = n;
    for (auto it : arr)
    {
        meanTime += it * i;
        i--;
    }
    cout << "The optimal way to store the tapes are in the order :";
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    float ans = meanTime / float(n);
    cout << "The mean time they take will be " << ans << endl;
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
    optimalStorageTapes(arr, n);
    return 0;
}