#include<bits/stdc++.h>

#define pii pair<int, int>
using namespace std;

int main(){
    int v = 6;
    priority_queue< pii, vector<pii >, greater<pii > > pq;
    for(int i=0;i<v;i++){
        pq.push(make_pair(INT_MAX , i));
    }
    pair<int, int> temp = pq.top();
    pq.pop();
    cout<<temp.first<<endl;
    cout<<temp.second<<endl;
}