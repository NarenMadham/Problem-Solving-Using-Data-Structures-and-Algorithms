#include<bits/stdc++.h>
using namespace std;

bool check(char a[], char b[], int it){
    int i = 0;
    int j = it;
    int n = strlen(a);
    int m = strlen(b);
    while(i < n){
        if(a[i] == b[j]){
            i++;
            j++;
            if(j == m){
                j = 0;
            }
            continue;
        }else{
            return false;
        }
    }
    return true;
}

bool isRotation(char a[], char b[]){
    if(strlen(a) != strlen(b)){
        return false;
    }
    set<int> st;
    int i = 1;
    int c = 1;
    st.insert(0);
    while(a[i] != '\0'){
        if(a[i] == a[0]){
            st.insert(i);
        }
        i += 1;
    }
    set<int> :: iterator it;
    for(it = st.begin(); it != st.end(); it++){
        bool ans = check(a, b, *it);
        if(ans){
            return true;
        }
    }
    return false;
}

int main(){
    char a[1000] = {'0'};
    char b[1000] = {'0'};
    scanf("%s", a);
    scanf("%s", b);
    bool res = isRotation(a, b);
    if(res){
        cout<<"Yes!"<<endl;
    }else{
        cout<<"No!"<<endl;
    }
}


/*

ABACD
CDABA

ABACD
CDABV

*/