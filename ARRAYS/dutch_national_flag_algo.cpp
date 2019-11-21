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
	    int c0=0, c1=0, c2=0;
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        if(arr[i] == 0){
	            c0 += 1;
	        }else if(arr[i] == 1){
	            c1 += 1;
	        }else if(arr[i] == 2){
	            c2 += 1;
	        }
	    }
	    for(int i=0;i<c0;i++){
	        cout<<0<<" ";
	    }
	    for(int i=0;i<c1;i++){
	        cout<<1<<" ";
	    }
	    for(int i=0;i<c2;i++){
	        cout<<2<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}