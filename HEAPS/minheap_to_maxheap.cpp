#include<bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxheapify(int arr[], int i, int n){
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int s = i;
    if(left < n && arr[left] > arr[i]){
        s = left;
    }
    if(right < n && arr[right] > arr[s]){
        s = right;
    }
    if(s != i){
        swap(&arr[i], &arr[s]);
        maxheapify(arr, s, n);
    }
}

void convert(int arr[], int n){
    for(int i=(n-2)/2; i>=0;i--){
        maxheapify(arr, i, n);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    convert(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


/*

10
3 5 9 6 8 20 10 12 18 9

*/