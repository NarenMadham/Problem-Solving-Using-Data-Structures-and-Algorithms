#include<bits/stdc++.h>
using namespace std;

stack<int> s;
set<int> vis;
int l = 0;
void kosaraju(map<int, map<int, int> > radj, int i){
    vis.insert(i);
    cout<<i<<" ";
    map<int, int> :: iterator it;
    for(it = radj[i].begin(); it !=  radj[i].end(); it++){
        if(vis.find(it->first) == vis.end())
            kosaraju(radj, it->first);
    }
    
}

void fill_stack(map<int, map<int, int> > adj, int i){
    vis.insert(i);
    map<int, int> :: iterator it;
    for(it = adj[i].begin(); it != adj[i].end(); it++){
        if(vis.find(it->first) == vis.end())
            fill_stack(adj, it->first);
    }
    s.push(i);
}

int main(){
    int v, e;
    cin>>v>>e;
    map<int, map<int, int> > adj;
    map<int, map<int, int> > radj;
    for(int i=0;i<e;i++){
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        radj[v][u] = 1;
    }
    
    for(int i=0;i<v;i++){
        if(vis.find(i) == vis.end()){
            fill_stack(adj, i);
        }else{
            continue;
        }
    }
    
    for(int i=0;i<v;i++){
        vis.erase(i);
    }
    
    cout<<"STRONGLY CONNECTED COMPONENTS : "<<endl;
    
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        if(vis.find(temp) == vis.end()){
            cout<<l<<" : ";
            kosaraju(radj, temp);
            cout<<endl;
            l += 1;
        }else{
            continue;
        }
        
    }
}

/*

11 13
0 1
1 2
2 0
1 3
3 4
4 5
5 3
6 5
6 7
7 8
8 9
9 6
9 10


*/














