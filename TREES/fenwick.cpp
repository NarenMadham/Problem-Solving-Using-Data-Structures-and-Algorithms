#include<bits/stdc++.h>
using namespace std;

int getSum(int ftree[], int index){
    index += 1;
    int sum = 0;
    while(index > 0){
        sum += ftree[index];
        index -= (index & -index);
    }
    return sum;
}

void updateTree(int ftree[], int index, int val, int n){
    index += 1;
    while(index <= n){
        ftree[index] += val;
        index += (index & -index);
    }
}

int * constructTree(int arr[], int n){
    int * ftree = new int[n+1];
    for(int i=0;i<=n;i++){
        ftree[i] = 0;
    }
    for(int i=0;i<n;i++){
        updateTree(ftree, i, arr[i], n);
    }
    return ftree;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int n = 7;
    int * ftree = constructTree(arr, n);
    for(int i=0;i<8;i++){
        cout<<ftree[i]<<" ";
    }
}