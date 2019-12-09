#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int min_edit_distance(char a[], char b[]);
int min(int a, int b, int c);

int main() {
    int t;
    scanf("%d", &t);
    for(int x=0;x<t;x++){
        char a[100000] = {'\0'}, b[100000] = {'\0'};
        scanf("%s", a);
        scanf("%s", b);
        
        printf("%d\n", min_edit_distance(a, b));
    }
    return 0;
}

int min_edit_distance(char a[], char b[]){
    int n = strlen(a);
    int m = strlen(b);
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            dp[i][j] = 0;
        }
    }
    for(int i=0;i<=n;i++){
        dp[i][0] = i;
    }
    for(int j=0;j<=m;j++){
        dp[0][j] = j;
    }
    dp[0][0] = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }else{
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]) + 1;
            }
        }
    }
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }*/
    return dp[n][m];
}

int min(int a, int b, int c){
    if(a < b){
        if(a < c){
            return a;
        }else{
            return c;
        }
    }else{
        if(b < c){
            return b;
        }else{
            return c;
        }
    }
}