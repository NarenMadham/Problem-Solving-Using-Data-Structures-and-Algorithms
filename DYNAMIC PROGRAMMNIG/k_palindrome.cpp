#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n, k;
	    cin>>n>>k;
	    string a;
	    cin>>a;
	    int dp[n][n];
	    memset(dp, 0, sizeof(dp));
	    for(int i=0;i<n;i++){
	        dp[i][i] = 1;
	    }
	    for(int l=2;l<=n;l++){
	        for(int i=0;i<n-l+1; i++){
	            int j = i + l - 1;
	            if(a[i] == a[j]){
	                dp[i][j] = dp[i+1][j-1] + 2;   
	            }else{
	                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
	            }
	        }
	    }
	    if(n - dp[0][n-1] <= k){
	        cout<<1<<endl;
	    }else{
	        cout<<0<<endl;
	    }
	}
	
	return 0;
}