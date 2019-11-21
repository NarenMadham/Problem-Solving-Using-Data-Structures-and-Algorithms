#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n;
        cin>>m;
        int a[n], b[m], res[m+n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int j=0;j<m;j++){
            cin>>b[j];
        }
        int i=0,j=0, k = 0;
        while(i < n && j < m){
            if(a[i] < b[j]){
                res[k] = a[i];
                i++;
                k++;
            }else{
                res[k] = b[j];
                j++;
                k++;
            }
        }
        while(i < n){
            res[k]  = a[i];
            i++;
            k++;
        }
        while(j < m){
            res[k] = b[j];
            j++;
            k++;
        }
        for(int i=0;i<m+n;i++){
            cout<<res[i]<<" ";
        }
    }
}