#include<bits/stdc++.h>
using namespace std;

long long int max(long long int a, long long int b){
    if( a > b ){
        return a;
    }else{
        return b;
    }
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    long long int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    long long int dp[n];
	    dp[0] = arr[0];
	    for(int i=1;i<n;i++){
	        dp[i] = max(dp[i-1] + arr[i], arr[i]);
	    }
	    long long int s = INT_MIN;
	    for(int i=0;i<n;i++){
	        if(s < dp[i]){
	            s = dp[i];   
	        }
	    }
	    cout<<s<<endl;
	}
	return 0;
}