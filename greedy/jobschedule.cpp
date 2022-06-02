#include <bits/stdc++.h>
using namespace std;

struct Job
{
    char id;
    int profit;
    int deadline;
};

bool cmp(Job a, Job b)
{
    return a.profit > b.profit;
}

void jobSchedule(vector<Job> arr, int n)
{
    vector<char> job(n);
    vector<bool> slot(n, false);

    sort(arr.begin(), arr.end(), cmp);

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].deadline) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                slot[j] = true;
                job[j] = arr[i].id;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (slot[i] == true)
            cout << job[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    vector<Job> arr(n);
    for (auto &it : arr)
    {
        cout << "Enter the job id,profit and the deadline of the job : ";
        cin >> it.id >> it.profit >> it.deadline;
    }
    jobSchedule(arr, n);
    return 0;
}