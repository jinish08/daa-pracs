#include <bits/stdc++.h>
using namespace std;

struct Job
{
    char id;
    int t1;
    int t2;
};

bool cmp1(Job a, Job b){
    return a.t1 < b.t1;
}

bool cmp2(Job a, Job b){
    return a.t2 < b.t2;
}

int main()
{

    int n;
    cin >> n;
    vector<Job> arr(n);
    for (auto &it : arr)
    {
        cout << "Enter the job id,t1 and the t2 of the job : ";
        cin >> it.id >> it.t1 >> it.t2;
    }

    vector<Job> one;

    for (int i = 0; i < n; i++)
        if (arr[i].t1 <= arr[i].t2)
            one.push_back(arr[i]);

    sort(one.begin(), one.end(), cmp1);

    vector<Job> two;

    for (int i = 0; i < n; i++)
        if (arr[i].t1 >= arr[i].t2)
            two.push_back(arr[i]);

    sort(two.begin(), two.end(), cmp2);

    vector<Job> ans;
    for (auto it : one)
        ans.push_back(it);

    for (int i = two.size() - 1; i >= 0; i--)
        ans.push_back(two[i]);

    cout << "The final sequence in which the tasks are going to take place is ";

    for (auto it : ans)
        cout << it.id << " ";
    cout << endl;

    return 0;
}