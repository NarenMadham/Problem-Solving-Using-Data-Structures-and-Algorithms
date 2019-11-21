#include<bits/stdc++.h>
using namespace std;
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
	    vector<int> dp(n, 1);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[j] < arr[i]){
	                dp[i] = max(dp[i], dp[j]+1);
	            }
	        }
	    }
	    int M = 0;
	    for(int i=0;i<n;i++){
	        if(dp[i] > M)
	            M = dp[i];
	    }
	    cout<<M<<endl;
	}
	return 0;
}