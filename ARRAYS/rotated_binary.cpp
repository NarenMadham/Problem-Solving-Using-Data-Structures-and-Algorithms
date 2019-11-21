/*
if(a[l] < a[m]){
    if(k >= a[l] && k <= a[m]){
        return left
    }
    return right
}

if(k >= a[m] && k <= a[h]){
    return right;
}

return left

*/

#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int l, int h, int k){
    if(l > h){
        return -1;
    }
    
    if(h == l){
        if(arr[l] == k) return l;
        return -1;
    }
    
    int m = (h+l) / 2;
    if(arr[m] == k){
        return m;
    }
    
    if(arr[l] <= arr[m]){
        
        if(k >= arr[l] && k <= arr[m])
            return search(arr, l, m-1, k);
            
        return search(arr, m+1, h, k);
    }
    if(k >= arr[m] && k <= arr[h])
        return search(arr, m+1, h, k);
    
    return search(arr, l, m-1, k);
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
	    int k;
	    cin>>k;
	    cout<<search(arr, 0, n-1, k)<<endl;
	    
	}
	return 0;
}