#include<bits/stdc++.h>
using namespace std;

set<int> s;
stack<int> st;

void topo(map<int, map<int, int> > mp, int start){
    set<int> :: iterator it = s.find(start);
    if(it == s.end()){
        return;
    }else{
        s.erase(start);
        //cout<<start<<endl;
        map<int, int> :: iterator it;
        for(it = mp[start].begin();it != mp[start].end(); it++){
            topo(mp, it->first);
        }
        st.push(start);
    }
    return;
}

void topologicalSort(map<int, map<int ,int> > mp, int v){
    //cout<<"a";
    set<int> :: iterator it;
    while(!s.empty()){
        it = s.begin();
        topo(mp, *it);
    }
    cout<<"Topological sort"<<endl;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

void printGraph(map<int, map<int, int> > mp){
    map<int, map<int, int> > :: iterator it;
    for(it = mp.begin();it != mp.end();it++){
        cout<<it->first;
        map<int, int> :: iterator itr;
        for(itr = it->second.begin();itr != it->second.end();itr++){
            cout<<"-> "<<itr->first;
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int v,e ;
        cin>> v>> e;
        map<int, map<int, int> > adj;
        for(int i=0;i<e;i++){
            int u, v;
            cin>> u>> v;
            adj[u][v] = 1;            
        }
        for(int i=0;i<v;i++){
            s.insert(i);
        }
        topologicalSort(adj, v);
        //printGraph(adj);
    }
}

/*
1
8 8
0 2
1 2
2 3
3 4
3 5
1 6
6 5
5 7
*/