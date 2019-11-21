#include<bits/stdc++.h>
using namespace std;

int main(){
    char a[1005] = {'\0'};
    scanf("%s", a);
    int i = 0;
    set<int> s;
    while(a[i] != '\0'){
        if(s.find(a[i]) == s.end()){
            cout<<a[i];
            s.insert(a[i]);
        }
        i += 1;
    }
}