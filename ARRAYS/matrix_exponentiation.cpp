#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

void multiply(ll a[2][2], ll b[2][2]){
    ll w = ((a[0][0] * b[0][0]) % MOD + (a[0][1] * b[1][0]) % MOD ) % MOD; 
    ll x = ((a[0][0] * b[0][1]) % MOD + (a[0][1] * b[1][1]) % MOD ) % MOD; 
    ll y = ((a[1][0] * b[0][0]) % MOD + (a[1][1] * b[0][1]) % MOD ) % MOD; 
    ll z = ((a[1][0] * b[0][1]) % MOD + (a[1][1] * b[1][1]) % MOD ) % MOD; 
    
    a[0][0] = w;
    a[0][1] = x;
    a[1][0] = y;
    a[1][1] = z;
}

ll fib(ll n){
    if(n == 0 || n == 1) return 1;
    n--;
    ll f[2][2] = {{1, 1}, {1, 0}};
    ll res[2][2] = {{1, 0}, {0, 1}};
    while(n != 0){
        if(n % 2 != 0){
            multiply(res, f);
        }
        multiply(f, f);
        n >>= 1;
    }
    return (res[0][0] + res[0][1]) % MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        cout<<fib(n)<<"\n";
    }
    return 0;
}