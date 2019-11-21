#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    for(int i=0;i<n;i++){
        dp[i][i] = ((i-1 >= 0)? arr[i-1] : 1) * arr[i] * ((i+1 < n) ? arr[i+1] : 1);
    }
    for(int l=2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j = i + l - 1;
            int M = INT_MIN;
            for(int k=i;k<=j;k++){
                int a = (k-1 >= i)? dp[i][k-1] : 0;
                int b = (k+1 <= j)? dp[k+1][j] : 0;
                int c = ((i-1 >= 0) ? arr[i-1] : 1) * arr[k] * ((j+1 < n) ? arr[j+1] : 1);
                int temp = c + a + b;
                if(temp > M){
                    M = temp;
                }
            }
            dp[i][j] = M;
        }
    }
    cout<<dp[0][n-1]<<endl;
}



/*

4
3 1 5 8

*/
