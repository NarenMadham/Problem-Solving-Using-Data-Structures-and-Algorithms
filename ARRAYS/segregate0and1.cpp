#include<bits/stdc++.h>
using namespace std;
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
	    int p1 = 0;
	    int p2 = n-1;
	    while(p1 <= p2){
	        while(arr[p1] == 0){
	            p1++;
	        }
	        while(arr[p2] == 1){
	            p2--;
	        }
	        if(p1 > p2) break;
	        int temp = arr[p1];
	        arr[p1] = arr[p2];
	        arr[p2] = temp;
	        p1++;
	        p2--;
	    }
	    for(int i=0;i<n;i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}