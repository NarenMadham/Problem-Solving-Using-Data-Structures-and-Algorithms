#include<bits/stdc++.h>
using namespace std;

int min(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

int main(){
    int n;
    cin>>n;
    int adj[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>adj[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==k || j == k || i==k){
                    continue;
                }else{
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adj[i][j] <<" ";
        }
        cout<<endl;
    }
}