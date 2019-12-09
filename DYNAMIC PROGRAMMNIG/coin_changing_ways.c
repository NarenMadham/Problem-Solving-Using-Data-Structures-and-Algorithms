#include<stdio.h>
#include<stdlib.h>

long long int coin_change_ways(int arr[], int n, int s);

int main(){
    int n, s;
    scanf("%d %d", &s, &n);
    
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    } 
    printf("%lld\n", coin_change_ways(arr, n, s));
    return 0;
}

long long int coin_change_ways(int arr[], int n, int s){
    if(n == 0){
        return 0;
    }
    long long int dp[n][s+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<=s;j++){
            dp[i][j] = 1;
        }
    }
    for(int i=0;i<n;i++){
        dp[0][i] = 1;
    }
    for(int i=0;i<=s;i++){
        if(i % arr[0] == 0){
            dp[0][i] = 1;
        }else{
            dp[0][i] = 0;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<=s;j++){
            if(j - arr[i] >= 0){
                dp[i][j] = dp[i-1][j] + dp[i][j-arr[i]];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    /*for(int i=0;i<n;i++){
        for(int j=0;j<=s;j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }*/
    return dp[n-1][s];
}