#include<bits/stdc++.h>
using namespace std;

long long int find_rank(vector<char>& ar, int n, vector<char>& q, int index, vector<long long int>& fact, vector<bool>& vis){
    if(index == n){
        return 1;
    }
    
    long long int r = 0;
    for(int i=0;i<n;i++){
        if(vis[i]) continue;
        if(ar[i] == q[index]){
            vis[i] = true;
            return r + find_rank(ar, n, q, index+1, fact, vis);
        }else{
            r += fact[n - index - 1];
        }
    }
    return r;
}

int main(){
    int n;
    cin>>n;
    vector<char> ar;
    for(int i=0;i<n;i++){
        char temp;
        cin>>temp;
        ar.push_back(temp);
    }
    sort(ar.begin(), ar.end());
    vector<char> q;
    for(int i=0;i<n;i++){
        char temp;
        cin>>temp;
        q.push_back(temp);
    }
    vector<long long int> fact(n+1, 1);
    for(int i=2;i<=n;i++){
        fact[i] = fact[i-1] * i;
    }
    int index = 0;
    vector<bool> vis(n, false);
    cout<<find_rank(ar, n, q, index, fact, vis)<<endl;
    return 0;
}

/*

3
A R M
R A M

*/