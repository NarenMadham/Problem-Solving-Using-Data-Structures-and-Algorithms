#include<bits/stdc++.h>
#define mii map<int, map<int, int> >
#define vpii vector<pair<int, int> >
using namespace std;

void butil(mii adj, int low[], int disc[], int parent[], bool vis[], vpii& bri, int vertex){
    static int time = 0;
    int c = 0;
    int temp = ++time;
    vis[vertex] = true;
    low[vertex] = disc[vertex] = temp;
    map<int, int> :: iterator it;
    for(it = adj[vertex].begin(); it!= adj[vertex].end(); it++){
        int i = it->first;
        if(vis[i] == false){
            c++;
            parent[i] = vertex;
            butil(adj, low, disc, parent, vis, bri, i);
            
            low[vertex] = min(low[vertex], low[i]);
            
            if(low[i] > disc[vertex]){
                bri.push_back({vertex, i});
            }
        }else if(i != parent[vertex]){ //MOST IMPORTANT!!!
            low[vertex] = min(low[vertex], disc[i]);
        }
    }
}

void bridges(mii adj, int v){
    int *low = new int[v];
    int *disc = new int[v];
    int *parent = new int[v];
    bool *vis = new bool[v];
    vpii bri;
    for(int i=0;i<v;i++){
        vis[i] = false;
        disc[i] = 0;
        low[i] = 0;
        parent[i] = -1;
    }
    for(int i=0;i<v;i++){
        if(vis[i] == false){
            butil(adj, low, disc, parent, vis, bri, i);
        }
    }
    vpii :: iterator it;
    cout<<"BRIDGES!"<<endl;
    for(it = bri.begin(); it!= bri.end(); it++){
        cout<<(*it).first<<" "<<(*it).second<<endl;
    }
}

int main(){
    int v, e;
    cin>>v>>e;
    mii adj;
    for(int i=0;i<e;i++){
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    bridges(adj, v);
    return 0;
}