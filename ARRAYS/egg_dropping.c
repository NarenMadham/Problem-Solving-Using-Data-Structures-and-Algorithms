/* 

        NOT WORKING

*/

#include <stdio.h>
#include <limits.h>
int egg_dropping(int e, int f);
int max(int a, int b);
int main() {
    int t;
    scanf("%d", &t);
    for(int x=0;x<t;x++){
        int e, f;
        scanf("%d %d", &e, &f);
        printf("%d\n", egg_dropping(e, f));
    }
	return 0;
}

int egg_dropping(int e, int f){
    int dp[e][f+1];
    for(int i=0;i<e;i++){
        for(int j=0;j<f;j++){
            dp[i][j] = 0;
        }
    }
    for(int i=1;i<=f;i++){
        dp[0][i] = i;
    }
    for(int i=1;i<e;i++){
        for(int j=1;j<=f;j++){
            if(i > j){
                dp[i][j] = dp[i-1][j];
            }
            else{
                int m = INT_MAX;
                for(int k=i;k<=j;k++){
                    int temp = max(dp[i][j-1], dp[i-1][j-1]);
                    if(m > temp)
                        m = temp;
                }
            }
        }
    }
    for(int i=0;i<e;i++){
        for(int j=1;j<=f;j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    return dp[e-1][f];
}

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}