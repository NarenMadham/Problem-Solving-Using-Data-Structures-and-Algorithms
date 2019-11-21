#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n = s.length();
    int dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        dp[i][i] = 1;
    }
    for(int l = 2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j = l + i - 1;
            if(s[i] == s[j]){
                dp[i][j] = dp[i+1][j-1] + 2;
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
            }
        }
    }
    cout<<dp[0][n-1]<<endl;
}


/*

caadbeaaf   

*/