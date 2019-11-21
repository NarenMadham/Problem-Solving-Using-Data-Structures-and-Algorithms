#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int l;
        cin>>l;
        string s;
        cin>>s;
        int n, o;
        n = (l/2) + 1;
        o = l/2;
        
        char b[n];
        char op[o];
        int idx = 0;
        for(int i=0;i<l;i+=2, idx++){
            b[idx] = s[i];
            //cout<<b[idx]<<" ";
        }
        //cout<<endl;
        idx = 0;
        for(int i=1;i<l;i+=2, idx++){
            op[idx] = s[i];
            //cout<<op[idx]<<" ";
        }
        //cout<<endl;
        long long int t[n][n], f[n][n];
        memset(t, 0, sizeof(t));
        memset(f, 0, sizeof(f));
        for(int i=0;i<n;i++){
            if(b[i] == 'T'){
                t[i][i] = 1;
            }else{
                f[i][i] = 1;
            }
        }
        for(int l=2;l<=n;l++){
            for(int i=0;i<n-l+1;i++){
                int j = i + l - 1;
                for(int k=0;k<j;k++){
                    int tik = t[i][k] + f[i][k];
                    int tkj = t[k+1][j] + f[k+1][j];
                    if(op[k] == '&'){
                        t[i][j] += (t[i][k] * t[k+1][j]);
                        f[i][j] += ((tik*tkj) - (t[i][k] * t[k+1][j]));
                    }else if(op[k] == '|'){
                        f[i][j] += (f[i][k] * f[k+1][j]);
                        t[i][j] += ((tik * tkj) - (f[i][k] * f[k+1][j]));
                    }else if(op[k] == '^'){
                        t[i][j] += ((t[i][k] * f[k+1][j]) + (f[i][k] * t[k+1][j]));
                        f[i][j] += ((t[i][k] * t[k+1][j]) + (f[i][k] * f[k+1][j]));
                    }
                }
            }
        }
        /*for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<t[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<f[i][j]<<" ";
            }
            cout<<endl;
        }*/
        cout<<(t[0][n-1] % 1003)<<endl;
    }
    return 0;
}