#include<bits/stdc++.h>
using namespace std;

void max_min(int arr[], int l, int h, int& m, int& M){
    if(l > h){
        return;
    }
    if(l==h){
        if(arr[l] < m){
            m = arr[l];
        }
        if(arr[h] > M){
            M = arr[h];
        }
        return;
    }
    int mid = (l + h) / 2;
    max_min(arr, l, mid, m, M);
    max_min(arr, mid+1, h, m, M);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int m = INT_MAX, M = INT_MIN;
    max_min(arr, 0, n-1, m, M);
    cout<<m<<endl;
    cout<<M<<endl;
}