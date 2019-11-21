#include<bits/stdc++.h>
using namespace std;

void consecutive(char a[]){
    int n = strlen(a);
    if(n == 0) return;
    if(a[0] == '\0') return;
    bool res = false;
    int i = 0;
    char temp[1003] = {'\0'};
    int pos = 0;
    while(i < n){
        bool f = false;
        while((i+1 < n) && a[i] == a[i+1]){
            f = true;
            res = true;
            i += 1;
        }
        if(f){
            i += 1;
        }
        if(a[i] != a[i+1]){
            temp[pos] =  a[i];
            pos += 1;
        }else{
            continue;
        }
        i += 1;
    }
    if(res){
        consecutive(temp);
    }else{
        cout<<temp;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        char a[1003] = {'\0'};
        scanf("%s", a);
        int n = strlen(a);
        consecutive(a);
        cout<<endl;
    }
}
