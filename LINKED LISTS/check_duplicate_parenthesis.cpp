#include<bits/stdc++.h>
using namespace std;

int main(){
    char str[51] = {'\0'};
    scanf("%s", str);
    int n = strlen(str);
    stack<char> st;
    int f = 0;
    for(int i=0;i<n;i++){
        if(str[i] == ')'){
            int temp = 0;
            while(st.top() != '('){
                temp += 1;
                st.pop();
            }
            if(temp < 1){
                f = 1;
                cout<<"Yes"<<endl;
            }
        }else{
            st.push(str[i]);
        }
    }
    if(f == 0){
        cout<<"Nope"<<endl;
    }
    return 0;
}

/*

((a+b)+((c+d)))

*/