#include<bits/stdc++.h>
using namespace std;

void computeTF(string pat, int m, int tf[][256]){
    int lps = 0;
    for(int i=0;i<256;i++){
        tf[0][i] = 0;
    }
    tf[0][pat[0]] = 1;
    for(int i=1;i<=m;i++){
        for(int x=0;x<256;x++){
            tf[i][x] = tf[lps][x];
        }
        tf[i][pat[i]] = i + 1;
        if(i < m)
            lps = tf[lps][pat[i]];
    }
}

int main(){
    string t, p;
    cin>>t>>p;
    int n = t.length();
    int m = p.length();
    int tf[m+1][256];
    computeTF(p, m, tf);
    int temp = 0;
    for(int i=0;i<n;i++){
        temp = tf[temp][t[i]];
        if(temp== m){
            cout<<i-m+1<<" ";
        }
    }
    cout<<endl;
    return 0;
}

/*

abcxabcdabxabcdabcdabcyabcdabcy
abcdabcy

*/