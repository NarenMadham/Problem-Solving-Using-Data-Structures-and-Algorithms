#include<bits/stdc++.h>
using namespace std;

long long int find_rank(vector<char>& ar, int n, vector<char>& q, int index, vector<long long int>& fact, vector<int>& count, vector<bool>& vis){
    if(index == n){
        return 1;
    }
    
    long long int r = 0;
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        if(ar[i] == q[index]){
            vis[i] = true;
            count[ar[i]]--;
            return r + find_rank(ar, n, q, index+1, fact, count, vis);
        }else{
            long long int sum = 1;
            for(int j=0;j<256;j++){
                sum *= fact[count[j]];
            }
            // cout<<sum<<endl;
            r += fact[n - index - 1] / sum;
            
        }
    }
    return r;
}

int main(){
    int n;
    cin>>n;
    vector<char> ar;
    vector<char> q;
    vector<int> count(256, 0);
    for(int i=0;i<n;i++){
        char temp;
        cin>>temp;
        ar.push_back(temp);
        q.push_back(temp);
        count[temp]++;
    }
    sort(ar.begin(), ar.end());
    vector<long long int> fact(n+1, 1);
    for(int i=2;i<=n;i++){
        fact[i] = fact[i-1] * i;
    }
    int index = 0;
    vector<bool> vis(n, false);
    cout<<find_rank(ar, n, q, index, fact, count, vis)<<endl;
    return 0;
}

/*

4
R A N K

*/