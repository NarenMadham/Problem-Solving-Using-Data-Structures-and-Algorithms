#include<bits/stdc++.h>
using namespace std;

void reverse(int arr[], int s, int e){
    int p1 = s;
    int p2 = e;
    while(p1 < p2){
        int temp = arr[p1];
        arr[p1] = arr[p2];
        arr[p2] = temp;
        p1++;
        p2--;
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    reverse(arr, 0, n-1);
    reverse(arr, 0, n-1-k);
    reverse(arr, n-k, n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}