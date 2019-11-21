#include<bits/stdc++.h>
using namespace std;

void sutil(int arr[], int temp[], int index, int pos, int sum, int k, int n){
    if(sum > k || index == n){
        return;
    }
    if(sum == k){
        for(int i=0;i<pos;i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return;
    }
    sutil(arr, temp, index+1, pos, sum, k, n);
    temp[pos] = arr[index];
    if(sum + arr[index] <= k)
        sutil(arr, temp, index+1, pos+1, sum+arr[index], k, n);
    return;
}

void subset_sum(int arr[], int k, int n){
    int temp[n];
    sutil(arr, temp, 0, 0, 0, k, n);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    subset_sum(arr, k, n);
    return 0;
}


/*

5
2 4 6 8 10
14

10
1 2 3 4 5 6 7 8 9 10
16

*/