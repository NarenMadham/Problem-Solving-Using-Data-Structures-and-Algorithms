using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int e, n;
	    cin>>e>>n;
	    int dp[e+1][n+1];
	    memset(dp, 0, sizeof(dp));
	    for(int i=0;i<=n;i++){
	        dp[1][i] = i;
	    }
	    for(int i=2;i<=e;i++){
	        for(int j=1;j<=n;j++){
	            if(i > j){
	                dp[i][j] = dp[i-1][j];
	                continue;
	            }
	            int m = INT_MAX;
	            for(int k=1;k<=j;k++){
	                m = min(m, 1+max(dp[i-1][k-1], dp[i][j-k]));
	            }
	            dp[i][j] = m;
	        }
	    }
	    cout<<dp[e][n]<<endl;
	}
	return 0;
}