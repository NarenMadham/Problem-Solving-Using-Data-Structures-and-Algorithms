#include<bits/stdc++.h>
#define prime 347
using namespace std;

int main(){
    string t,p;
    cin>>t;
    cin>>p;
    int lt = t.length();
    int lp = p.length();
    int powers[lp];
    powers[0] = 1;
    powers[1] = prime;
    long long int pat_hash = 0;
    for(int i=2;i<lp;i++){
        powers[i] = prime * powers[i-1];
    }
    for(int i=0;i<lp;i++){
        pat_hash += (p[i] * powers[i]);
    }
    long long int h = 0;
    int idx = 0;
    int c = 0;
    for(int i=0;i<lp;i++){
        h += t[i] * powers[i];
    }
    if(h == pat_hash){
        c += 1;
    }
    for(int i = lp; i<lt; i++){
        long long int temp = h - t[idx];
        temp /= prime;
        temp += (t[i] * powers[lp-1]);
        if(temp == pat_hash){
            c += 1;
        }
        h = temp;
        idx += 1;
    }
    cout<<c<<endl;
}


/*

abfghabca
abc

*/