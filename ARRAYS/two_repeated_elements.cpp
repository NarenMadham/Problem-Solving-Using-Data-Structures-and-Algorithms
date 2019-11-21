#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t-- ){
	    int n;
	    cin>>n;
	    int arr[n+2];
	    for(int i=0;i<n+2;i++){
	        cin>>arr[i];
	    }
	    vector<int> mp(n+2, 0);
	    for(int i=0;i<n+2;i++){
	        mp[arr[i]] += 1;
	        if(mp[arr[i]] > 1){
	            cout<<arr[i]<<" "; 
	        }
	    }
	    cout<<endl;
	}
	return 0;
}