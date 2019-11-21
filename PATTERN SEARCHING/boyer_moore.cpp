#include<bits/stdc++.h>
using namespace std;

void computebad(string p, int m, int badchar[256]){
    for(int i=0;i<m;i++){
        badchar[i] = -1;
    }
    for(int i=0;i<m;i++){
        badchar[p[i]] = i;
    }
}

int main(){
    string t, p;
    cin>>t>>p;
    int badchar[256];
    int m = p.length();
    int n = t.length();
    computebad(p, m, badchar);
    int s = 0;
    while(s <= n-m){
        int j = m-1;//has to be inside the loop!
        while(j >= 0 && t[s+j] == p[j])//>=
            j--;
        if(j < 0){
            cout<<s<<" ";
            s += (s+m < n) ? badchar[t[s+m]] : 1;
        }else{
            s += max(1, j - badchar[t[s+j]]);
        }
    }
}


/*

abcxabcdabxabcdabcdabcyabcdabcy
abcdabcy

*/