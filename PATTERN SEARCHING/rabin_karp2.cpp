#include<bits/stdc++.h>
#define M 1000000007
#define p1 17
#define p2 19
using namespace std;

int rabin_karp(string t, string p){
    int lt = t.length();
    int lp = p.length();
    int c = 0;
    long long int pw1[lp+1];
    long long int pw2[lp+1];
    pw1[0] = 1;
    pw2[0] = 1;
    for(int i=0;i<=lp;i++){
        pw1[i] = (pw1[i-1] * p1) % M;
    }
    for(int i=0;i<=lp;i++){
        pw2[i] = (pw2[i-1] * p2) % M;
    }
    long long int ha1=0, ha2=0, hb1=0, hb2=0;
    for(int i=0;i<lp;i++){
        ha1 = (ha1 + p[i] * pw1[lp-i]) % M;
        hb1 = (hb1 + t[i] * pw1[lp-i]) % M;
        ha2 = (ha2 + p[i] * pw2[lp-i]) % M;
        hb2 = (hb2 + t[i] * pw2[lp-i]) % M;
    }
    if(ha1 == hb1 && ha2 == hb2)
        c += 1;
    
    for(int i=lp;i<lt;i++){
        hb1 = (((hb1 - t[i-lp]*pw1[lp]) * p1 + t[i]) + M) % M;
        hb2 = (((hb2 - t[i-lp]*pw2[lp]) * p2 + t[i]) + M) % M;
        if(hb1 == ha1 && hb2 == ha2){
            c += 1;
        }
    }
    return c;   
}

int main(){
    string t;
    string p;
    cin>>t;
    cin>>p;
    cout<<rabin_karp(t, p);
}

/*

abcxabcdabxabcdabcdabcyabcdabcy
abcdabcy


*/