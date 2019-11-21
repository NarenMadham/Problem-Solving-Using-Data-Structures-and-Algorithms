#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    stack<int> st;
    for(int i=0;i<9;i++){
        st.push(arr[i]);
    }
    cout<<endl;
    queue<int> q;
    while(!st.empty()){
        q.push(st.top());
        st.pop();
    }
    while(!q.empty()){
        st.push(q.front());
        q.pop();
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    return 0;
}