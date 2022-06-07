#include <bits/stdc++.h>
using namespace std;

int partition(int low,int high,vector<int> &arr){
    int pi = arr[high];

    int i = low - 1;

    for(int j = low;j<high;j++){
        if(arr[j]<pi){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);

    return i+1;
}

void  QuickSort(int high,int low,vector<int> &arr){
    if(high>low){
        int pi = partition(low,high,arr);
        QuickSort(pi-1,low,arr);
        QuickSort(high,pi+1,arr);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);

    for (auto &it : arr)
        cin >> it;

    QuickSort(n - 1, 0, arr);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}