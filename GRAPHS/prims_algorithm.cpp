#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int main(){
    int v, e;
    cin>>v>>e;
    map<int, map<int, int> > adj;
    for(int i=0;i<e;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u][v] = w;
        adj[v][u] = w;
    }
    priority_queue<pii, vector<pii >, greater<pii > > pq;
    vector<int> key(v, INT_MAX);
    vector<bool> vis(v, false);
    vector<int> parent(v, -1);
    pq.push(make_pair(0,0));
    key[0] = 0;
    while(!pq.empty()){
        pair<int, int> temp = pq.top();
        pq.pop();
        int vertex = temp.second;
        int weight = temp.first;
        vis[vertex] = true;
        map<int, int> :: iterator it;
        map<int, int> mp = adj[vertex];
        for(it = mp.begin(); it != mp.end(); it++){
            if(vis[it->first] == false && key[it->first] > adj[vertex][it->first]){
                key[it->first] = adj[vertex][it->first];
                parent[it->first] = vertex;
                pq.push(make_pair(key[it->first], it->first));
            }
        }
    }
    for(int i=1 ;i<v;i++){
        cout<<i<<"->"<<parent[i]<<endl; 
    }
    return 0;
}

/*
6 9
0 2 1 
0 1 3
2 3 1
2 1 3
1 3 1
2 4 6
3 4 5
3 5 4
5 4 2


*/