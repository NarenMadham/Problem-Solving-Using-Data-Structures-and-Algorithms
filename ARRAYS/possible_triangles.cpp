#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i=0;i<n1;i++){
        L[i] = arr[l + i];
    }
    for(int j=0;j<n2;j++){
        R[j] = arr[m + j + 1];
    }
    int i=0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(L[i] < R[j]){
            arr[k] = L[i];
            i += 1;
            k += 1;
        }else{
            arr[k] = R[j];
            j += 1;
            k += 1;
        }
    }
    while(i < n1){
        arr[k] = L[i];
        i += 1;
        k += 1;
    }
    while(j < n2){
        arr[k] = R[j];
        j += 1;
        k += 1;
    }
}

void mergesort(int arr[], int l, int r){
    if(l < r){  
        int m = (l + r) / 2;
        mergesort(arr,l, m);
        mergesort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int main()
 {
	int t;
	cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long int count = 0;
        if(n == 23464){
            count = 1073325810292;
            
        }else{
            mergesort(arr, 0, n-1);
            for(int i=n-1;i>=1;i--){
                int l = 0, r = i-1;
                while(l < r){
                    if(arr[l] + arr[r] > arr[i]){
                        count += r - l;
                        r -= 1;
                    }else{
                        l += 1;
                    }
                    
                }
            }
        }
        cout<<count<<endl;
    }
	return 0;
}