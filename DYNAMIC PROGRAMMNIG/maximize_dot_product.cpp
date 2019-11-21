#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int m, n;
	    cin>>m>>n;
	    long long int a[m], b[n];
	    for(int i=0;i<m;i++){
	        cin>>a[i];
	    }
	    for(int j=0;j<n;j++){
	        cin>>b[j];
	    }
	    long long int dp[n+1][m+1];
	    memset(dp, 0, sizeof(dp));
	    for(int i=1;i<=n;i++){
	        for(int j=i;j<=m;j++){
	            dp[i][j] = max(dp[i-1][j-1] + (a[j-1] * b[i-1]), dp[i][j-1]);
	        }
	    }
	    cout<<dp[n][m]<<endl;
	}
	return 0;
}