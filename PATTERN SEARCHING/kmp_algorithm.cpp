#include<bits/stdc++.h>
using namespace std;

int main(){
    string t;
    string p;
    cin>>t;
    cin>>p;
    int lt = t.length();
    int lp = p.length();
    int pre[lp];
    int i=1, j=0;
    pre[0] = 0;
    while(i < lp){
        if(p[i] == p[j]){
            j++;
            pre[i] = j;
            i++;
            continue;
        }
        while(j != 0 && p[j] != p[i]){
            j = pre[j-1];
        }
        if(j == 0){
            pre[i] = 0;
            i++;
        }
        else{
            pre[i] = j + 1;
            j++;
            i++;
        }
    }
    i = 0;
    j = 0;
    int c = 0;
    while(i < lt){
        if(j < lp && t[i] == p[j]){
            i++;
            j++;
            if(j == lp){
                c += 1;
            }
            continue;
        }
        while(j != 0 && t[i] != p[j]){
            j = pre[j-1];
        }
        if(p[j] == t[i]){
            j++;
            i++;
        }
        else
            i++;
    }
    cout<<c<<endl;
    return 0;
}


/*

abcxabcdabxabcdabcdabcyabcdabcy
abcdabcy

abcxabcdabxabcdabcdabcy
acacabacacabacacac


*/