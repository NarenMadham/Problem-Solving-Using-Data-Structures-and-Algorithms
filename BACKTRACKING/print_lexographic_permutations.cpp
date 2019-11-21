#include<bits/stdc++.h>
using namespace std;

void putil(char str[], char temp[], set<char>& s, int index, int n){
    if(index == n){
        cout<<temp<<endl;
    }
    for(int i=0;i<n;i++){
        temp[index] = str[i];
        if(s.find(str[i]) == s.end()){
            s.insert(str[i]);
            putil(str, temp, s, index+1, n);
        }
        s.erase(str[i]);
    }
}

void print_perm(char str[]){
    char temp[10] = {'\0'};
    set<char> s;
    int n = strlen(str);
    putil(str, temp, s, 0, n);
}

int main(){
    char str[10] = {'\0'};
    cin>>str;
    print_perm(str);
}