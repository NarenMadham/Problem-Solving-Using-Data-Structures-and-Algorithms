#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

int mcm(int arr[], int n);

int main(){
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d", &n);
        int *arr = malloc(sizeof(arr) * n);
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }
        printf("%d\n", mcm(arr, n));
    }
}

int mcm(int arr[], int n){
    int dp[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            dp[i][j] = 0;
        }
    }
    for(int l = 2;l<n;l++){
        for(int i=1;i<n-l+1;i++){
            int j = i + l - 1;
            dp[i][j] = 1000000007;
            
            for(int k=i-1;k<j;k++){
                int temp = dp[i][k] + dp[k+1][j] + (arr[i-1] * arr[k] * arr[j]);
                if(temp < dp[i][j]){
                    dp[i][j] = temp;
                }
            }
            
        }
    }
    /*for(int i=1;i<n;i++){
        for(int j=1;j<n;j++){
            printf("%10d ", dp[i][j]);       
        }
        printf("\n");
    }*/
    return dp[1][n-1];
}