#include<bits/stdc++.h>
using namespace std;

int max(int a, int b, int c){
    if(a > b){
        if(a > c){
            return a;
        }else{
            return c;
        }
    }else{
        if(b > c)
            return b;
        else
            return c;
    }
}

void nullify(int m, int n, vector<vector<int> > dp, vector<vector<int> >&arr){
    int i = m-1;
    int j = 0;
    while(i!=0){
        int temp = dp[i][j] - arr[i][j];
        if(i-1 >= 0 && j-1 >= 0 && (temp == dp[i-1][j-1])){
            arr[i][j] = 0;
            i = i-1;
            j = j-1;
        }else if(i-1 >= 0 && j >= 0 && (temp == dp[i-1][j])){
            arr[i][j] = 0;
            i = i-1;
        }else if((i-1) >= 0 && (j+1) < n && (temp == dp[i-1][j+1])){
            arr[i][j] = 0;
            i = i-1;
            j = j+1;
        }
    }
}

int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<int> > arr;
    for(int i=0;i<m;i++){
        vector<int> temp;
        for(int j=0;j<n;j++){
            int t;
            cin>>t;
            temp.push_back(t);
        }
        arr.push_back(temp);
    }
    vector<vector<int> > dp(m, vector<int>(n, 0));
    dp[0][0] = arr[0][0];
    int c = 2;
    for(int i=1;i<m;i++){
        for(int j=0;j<c;j++){
            int a = ((i-1) >= 0 && (j-1) >= 0) ? dp[i-1][j-1] : 0;
            int b = ((i-1) >= 0) ? dp[i-1][j] : 0;
            int c = ((i-1) >= 0 && (j+1) <n) ? dp[i-1][j+1] : 0;
            dp[i][j] = max(a, b, c) + arr[i][j];
        }
        c++;
    }
    cout<<"First Traversal : "<<dp[m-1][0]<<endl;
    nullify(m, n, dp, arr);
    vector<vector<int> > dp2(m, vector<int>(n, 0));
    c = 2;
    dp2[0][n-1] = arr[0][n-1];
    for(int i = 1;i<m;i++){
        int j = n-1;
        for(int k = 0;k<c;k++,j--){
            int a = ((i-1) >= 0 && (j-1) >= 0) ? dp2[i-1][j-1] : 0;
            int b = ((i-1) >= 0) ? dp2[i-1][j] : 0;
            int c = ((i-1) >= 0 && (j+1) < n) ? dp2[i-1][j+1] : 0;
            dp2[i][j] = max(a, b, c) + arr[i][j];
        }
        c++;
    }
    cout<<"Second Traversal : "<<dp2[m-1][n-1]<<endl;
    return 0;
}

/*

5 4
3 6 8 2
5 2 4 3
1 1 20 10
1 1 20 10
1 1 20 10

*/