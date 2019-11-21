#include<bits/stdc++.h>
#define mii map<int, map<int, int> > 
using namespace std;

void kutil(mii adj, set<int>& vis, stack<int>& st, int vertex, int v){
    vis.insert(vertex);
    map<int, int> :: iterator it;
    for(it = adj[vertex].begin(); it!= adj[vertex].end(); it++){
        if(vis.find(it->first) == vis.end()){
            kutil(adj, vis, st, it->first, v);
        }
    }
    st.push(vertex);
}

void krutil(mii reverse, set<int>& vis, stack<int>& st, int vertex){
    vis.insert(vertex);
    cout<<vertex<<" ";
    map<int, int> :: iterator it;
    for(it = reverse[vertex].begin(); it!= reverse[vertex].end(); it++){
        if(vis.find(it->first) == vis.end()){
            krutil(reverse, vis, st, it->first);
        }
    }
}

void kosaraju(mii adj, mii reverse, int v){
    set<int> vis;
    stack<int> st;
    for(int i=0;i<v;i++){
        if(vis.find(i) == vis.end()){
            kutil(adj, vis, st, i, v);
        }
    }
    vis.clear();
    while(!st.empty()){
        int temp = st.top();
        st.pop();
        if(vis.find(temp) == vis.end()){
            krutil(reverse, vis, st, temp);
            cout<<endl;
        }
    }
}

int main(){
    int v, e;
    cin>>v>>e;
    map<int, map<int, int> > adj;
    map<int, map<int, int> > reverse;
    for(int i=0;i<e;i++){
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        reverse[v][u] = 1;
    }
    kosaraju(adj, reverse, v);
    return 0;
}