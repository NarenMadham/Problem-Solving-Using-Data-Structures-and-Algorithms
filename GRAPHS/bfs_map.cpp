#include<bits/stdc++.h>
#include<map>
using namespace std;
class Graph{
public:
    int v;
    int e;
    map<int, map<int , int> > adj;
public:
    void setve(int v, int e){
        this->v = v;
        this->e = e;
    }
    void addEdge(int u, int v){
        this->adj[u][v] = 1;
        //cout<<"adj["<< u <<"]["<<v<<"] : "<< adj[u][v]<<endl;
        this->adj[v][u] = 1;
        //cout<<"adj["<< v <<"]["<<u<<"] : "<< adj[u][v]<<endl;
    }
    void printGraph(){
        map<int, map<int, int> > :: iterator it;
        for(it = this->adj.begin(); it != this->adj.end(); it++){
            cout<<it->first;
            map<int, int> :: iterator i;
            for(i = it->second.begin();i != it->second.end(); i++){
                cout<<"-> "<<i->first;
            }
            cout<<"\n";
        }
    }
    void bfs(int s, vector<bool> vis){
        queue<int> q;
        q.push(s);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            cout<<temp<<" ";
            vis[temp] = true;
            map<int, int> :: iterator it;
            map<int, int> edges = this->adj[temp];
            for(it = edges.begin(); it != edges.end(); it++){
                if(!vis[it->first]){
                    q.push(it->first);
                    vis[it->first] = true;
                }
            }
        }
    }
};

int main(){
    int t;
    cin>>t;
    for(int x=0;x<t;x++){
        int v, e;
        cin>>v>>e;
        Graph g;
        g.setve(v, e);
        for(int i=0;i<e;i++){
            int u, v;
            cin>>u>>v;
            g.addEdge(u, v);
        }
        //g.printGraph();
        vector<bool> vis(v, false);
        g.bfs(0, vis);
    }
}

/*1
7 8
0 1
0 2
0 3
2 4
2 5
1 6
3 4
5 6
*/