#include<bits/stdc++.h>
using namespace std;

int futil(int arr[], int l, int h, int diff, int n){
    if(l <= h){
        int m = (l + h)/2;
        if(m-1 >= 0 && arr[m-1] != (arr[m] - diff)){
            return (arr[m] - diff);
        }
        if(m+1 < n && arr[m+1] != (arr[m] + diff)){
            return (arr[m] + diff);
        }
        if(arr[m] == arr[0] + (m * diff))//OPTIMIZATION STEP!!!!
            return futil(arr, m+1, h, diff, n);
        return futil(arr, l, m-1, diff, n);
    }
}

int find_missing(int arr[], int n){
    int diff = (arr[n-1] - arr[0]) / n;
    return futil(arr, 0, n-1, diff, n); 
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<find_missing(arr, n)<<endl;
}


/*

8
2 4 6 8 12 14 16 18

*/