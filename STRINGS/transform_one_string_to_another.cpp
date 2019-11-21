#include<bits/stdc++.h>
using namespace std;

int main(){
    char a[100] = {'\0'};
    char b[100] = {'\0'};
    scanf("%s", a);
    scanf("%s", b);
    int n = strlen(a);
    int m = strlen(b);
    if(n != m){
        cout<<"Not possible to transform!"<<endl;
    }
    vector<int> count(256, 0);
    for(int i=0;i<n;i++){
        count[a[i]] += 1;
    }
    for(int i=0;i<m;i++){
        count[b[i]] -= 1;
    }
    for(int i=0;i<256;i++){
        if(count[i] != 0){
            cout<<"Not possible to transform!"<<endl;
        }
    }
    int i = n-1, j = n-1, res = 0;
    while(i >= 0){
        while(i >= 0 && a[i] != b[j]){
            i -= 1;
            res += 1;
        }
        i--;
        j--;
    }
    cout<<res;
}


/*

EACBD
EABCD

*/