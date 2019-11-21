#include<bits/stdc++.h>
using namespace std;

int main(){
    deque<int> dq;
    dq.push_front(10);
    dq.push_front(30);
    dq.push_front(50);
    dq.push_front(20);
    dq.push_front(60);
    dq.erase(20);
    deque<int> :: iterator it;
    for(it = dq.begin(); it != end(); it++){
        cout<<*it<<" ";
    }
}