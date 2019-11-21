#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    string a;
	    cin>>a;
	    int n = a.length();
	    int arr[n];
	    for(int i=0;i<n;i++){
	        arr[i] = (int) a[i] - 48;
	    }
	    int dp[n][n];
	    for(int i=0;i<n;i++){
	        dp[i][i] = arr[i];
	    }
	    int max_len = 0;
	    for(int l=2;l<=n;l++){
	        for(int i=0;i<n-l+1; i++){
	            int j = i + l - 1;
	            int k = l / 2;
	            dp[i][j] = dp[i][j-k] + dp[j-k+1][j];
	            if(dp[i][j-k] == dp[j-k+1][j] && l%2 == 0){
	                max_len = l;
	            }
	        }
	    }
	    cout<<max_len<<endl;
	}
	return 0;
}