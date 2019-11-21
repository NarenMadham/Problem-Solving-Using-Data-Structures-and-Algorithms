#include<bits/stdc++.h>
using namespace std;

int util(int arr[], int l, int m, int r){
    int inv_count = 0;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++){
        L[i] = arr[l + i];
    }
    for(int j=0;j<n2;j++){
        R[j] = arr[m + j + 1];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
            k++;
        }else{
            inv_count += n1 - i;
            arr[k] = R[j];
            j++;
            k++;
        }
    }
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    return inv_count;
}

int inversion(int arr[], int l, int h){
    int inv_count = 0;
    if(l < h){
        int m = (l + h)/2;
        inv_count += inversion(arr, l, m);
        inv_count += inversion(arr, m+1, h);
        inv_count += util(arr, l, m, h);
        return inv_count;
    }else{
        return 0;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<inversion(arr, 0, n-1)<<endl;
        
    }
}