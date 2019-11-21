#include<bits/stdc++.h>
using namespace std;

class Job{
public:
    int s, f, p;
};

bool mycomparator(Job a, Job b){
    return (a.f < b.f);
}

int main(){
    int n;
    cin>>n;
    Job jobs[n];
    for(int i=0;i<n;i++){
        cin>>jobs[i].s;
        cin>>jobs[i].f;
        cin>>jobs[i].p;
    }
    sort(jobs, jobs+n, mycomparator);
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i] = jobs[i].p;
    }
    for(int i=1;i<n;i++){
        int j = -1;
        for(j = i-1;j>=0;j--){
            if(jobs[i].s >= jobs[j].f){
                break;
            }
        }
        int temp = 0;
        if(j != -1){
            temp = dp[j] + jobs[i].p;
        }
        dp[i] = max(dp[i], temp);
    }
    int M = INT_MIN;
    for(int i=0;i<n;i++){
        M = max(M, dp[i]);
    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl<<M<<endl;
}