#include<bits/stdc++.h>
using namespace std;

void calculateZvalues(string s, vector<int>& z, int n){
    int l = 0, r = 0;
    for(int k=1;k<n;k++){
        if(k > r){
            l = r = k;
            while(r < n && s[r] == s[r - l])
                r++;
            z[k] = r - l;
            r--;
        }else{
            int k1 = k - l;
            if(z[k1] < r - k + 1){
                z[k] = z[k1];
            }else{
                l = k;
                while(r < n && s[r] == s[r-l])
                    r++;
                z[k] = r - l;
                r--;
            }
        }
    }
}

int main(){
    string t, p;
    cin>>t>>p;
    string cmb = p + '$' + t;
    int n = cmb.length();
    vector<int> z(n, 0);
    calculateZvalues(cmb, z, n);
    int lp = p.length();
    int c = 0;
    for(int i=0;i<n;i++){
        //cout<<z[i]<<" ";
        if(z[i] == lp){
            c += 1;
            cout<<(i - 1 - lp)<<" ";
        }
    }
    cout<<endl;
    cout<<c<<endl;
    return 0;
}

/*

abaxabcabcdbacbcabc
abc


*/