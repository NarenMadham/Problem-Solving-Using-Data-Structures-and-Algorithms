#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int bitonic(int arr[], int n);
int max(int a, int b);

int main() {
    int t;
    scanf("%d", &t);
    for(int x=0;x<t;x++){
        int n;
        scanf("%d", &n);
        int *arr = malloc(sizeof(int) * n);
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        //    printf("%d ", arr[i]);
        }
        //printf("\n");
        printf("%d\n", bitonic(arr, n));
    }

    return 0;
}

int bitonic(int arr[], int n){
    int dp[n], dpr[n];
    for(int i=0;i<n;i++){
        dp[i] = 1;
        dpr[i] = 1;
    }
    //dp[0] ;
    for(int i=1;i<n;i++){
        for(int j=0;j<=i-1;j++){
            dp[i] = max(dp[i], dp[j] + 1); 
        }
    }
    
    //dpr[n-1] = arr[n-1];
    
    for(int i = n-2;i>=0;i--){
        for(int j=n-1;j >= i+1;j--){
            dpr[i] = max(dpr[i], dpr[j] + 1);
        }
    }
    
    for(int i=0;i<n;i++){
        printf("%d ", dp[i]);
    }
    printf("\n");
    for(int i=0;i<n;i++){
        printf("%d ", dpr[i]);
    }
    printf("\n");
    int res[n];
    int max = 0;
    for(int i=0;i<n;i++){
        res[i] = dp[i] + dpr[i] -1;
        if(max < res[i]){
            max = res[i];
        }
    }
    return max;
}

int max(int a, int b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}