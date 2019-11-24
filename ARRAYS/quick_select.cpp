#include<bits/stdc++.h>
using namespace std;

int partition(int ar[], int l, int r){
    int x = ar[r], i = l;
    for(int j=l;j<=r-1;j++){
        if(ar[j] <= x){
            int t = ar[j];
            ar[j] = ar[i];
            ar[i] = t;
            i++;
        }
    }
    int temp = ar[r];
    ar[r] = ar[i];
    ar[i] = temp;
    return i;
}

int kth_smallest(int ar[], int l, int r, int k){
    
    if(k > 0 && k <= r - l + 1){
    
        int ind = partition(ar, l, r);
        if(ind - l == k-1) return ar[ind];

        if(ind - l > k-1){
            return kth_smallest(ar, l, ind-1, k);
        }

        return kth_smallest(ar, ind+1, r, k - ind - 1 + l);
    }
    return INT_MAX;
}

int main(){
    int n, k; 
    cin>>n>>k;
    int ar[n];
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    
    cout<<kth_smallest(ar, 0, n-1, k);
    
    return 0;
}


/*

7 3
10 4 8 6 11 26 5


*/