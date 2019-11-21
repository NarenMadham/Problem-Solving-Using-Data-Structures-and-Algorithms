#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n][n];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>arr[i][j];
	        }
	    }
	    int dp[n][n];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            dp[i][j] = INT_MIN;
	        }
	    }
	    for(int i=0;i<n;i++){
	        dp[0][i] = arr[0][i];
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if((i+1) < n)
	                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + arr[i+1][j]);
	            if((j-1) >= 0)
	                dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j] + arr[i+1][j-1]);
	            if((j+1) < n && (i+1) < n)
	                dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + arr[i+1][j+1]);
	        }
	    }
	    int M = INT_MIN;
	    for(int i=0;i<n;i++){
	        if(M < dp[n-1][i]){
	            M = dp[n-1][i];
	        }
	    }
	    cout<<M<<endl;
	}
	return 0;
}