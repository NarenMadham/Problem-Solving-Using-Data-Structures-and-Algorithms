#include<stdio.h>
#include<stdio.h>

long long int possible_bsts(int n);

int main(){
    int t;
    scanf("%d", &t);
    for(int x=0;x<t;x++){
        int n;
        scanf("%d", &n);
        printf("%lld\n", possible_bsts(n));
    }
    return 0;
}

long long int possible_bsts(int n){
    int dp[n+1];
    for(int i=0;i<=n;i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            dp[i] += dp[i-j-1] * dp[j];
        }
    }
    for(int i=0;i<=n;i++){
        printf("%3d ", dp[i]);
    }
    printf("\n");
    return dp[n];
}