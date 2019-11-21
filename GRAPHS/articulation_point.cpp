/*

WE HAVE TO PRACTICE THIS AGAIN!!!!

*/

#include<bits/stdc++.h>
using namespace std;

int min(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

void aputil(map<int, map<int, int> > adj, int vertex, bool vis[], int low[], int disc[], int parent[], bool ap[]){
    static int time = 0;
    int c = 0;
    map<int, int> :: iterator it;
    vis[vertex] = true;
    int temp = ++time;
    disc[vertex] = temp;
    low[vertex] = temp;
    for(it = adj[vertex].begin(); it != adj[vertex].end(); it++){
        if(vis[it->first] == false){
            c++;
            parent[it->first] = vertex;
            aputil(adj, it->first, vis, low, disc, parent, ap);
            low[vertex] = min(low[vertex], low[it->first]);
            if(parent[vertex] == -1 && c > 1){
                ap[vertex] = true;
            }
            
            if(parent[vertex] != -1 && low[it->first] >= disc[vertex]){
                ap[vertex] = true;
            }
        }
        else if(it->first != parent[vertex]){
            low[vertex] = min(low[vertex], disc[it->first]);
        }
    }
}

void articulation_points(map<int, map<int, int> > adj, int V){
    int *low = new int[V];
    int *disc = new int[V];
    bool *vis = new bool[V];
    bool *ap = new bool[V];
    int *parent = new int[V];
    for(int i=0;i<V;i++){
        low[i] = 0;
        disc[i] = 0;
        ap[i] = false;
        parent[i] = -1;
        vis[i] = false;
    }
    
    for(int i=0;i<V;i++){
        if(!vis[i])
            aputil(adj,i, vis, low, disc, parent, ap);
    }
    
    for(int i=0;i<V;i++){
        if(ap[i] == true){
            cout<<i<<" is an ARTICULATION POINT"<<endl;
        }
    }
}

int main(){
    int v, e;
    cin>>v>>e;
    map<int, map<int, int> > adj;
    for(int i=0;i<e;i++){
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    articulation_points(adj, v);
}



/*

8 9
0 2
1 2
0 1
2 3
3 4
4 6
4 5
6 5
5 7


*/