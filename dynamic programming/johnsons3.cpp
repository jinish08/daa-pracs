#include<bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int t1;
    int t2;
};

bool cmp1(Job a, Job b){
    return a.t1 < b.t1;
}

bool cmp2(Job a, Job b){
    return a.t2 < b.t2;
}

int main(){
    int n;cin>>n;
    vector<vector<int>> inp(3,vector<int> (n));

    for(auto &it:inp){
        cout<<"Enter proccessing time of the machine ";
        for(auto &jt:it){
            cin>>jt;
        }
    }

    int min1 = *min_element(inp[0].begin(),inp[0].end());
    int max2 = *max_element(inp[1].begin(),inp[1].end());
    int min3 = *min_element(inp[2].begin(),inp[2].end());

    if(min1>=max2 || min3>=max2){
        vector<Job> arr(n);

        for(int i = 0;i<n;i++){
            arr[i].id = i+1;
            arr[i].t1 = inp[0][i] + inp[1][i];
            arr[i].t2 = inp[2][i] + inp[1][i];
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
    }
    else{
        cout<<"Constrains not matched "<<endl;
    }
    

    return 0;
}