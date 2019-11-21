#include<bits/stdc++.h>

void addEdge(map<int, map<int , int> >adj, int u, int v){
    adj[u][v] = 1;
    adj[v][u] = 1;
}

void printGraph(map<int, map<int, int> > adj){
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
        map<int, map<int, int> > adj;
        int v, e;
        cin>>v>>e;
        for(int i=0;i<e;i++){
            int u, v;
            cin>>u>>v;
            addEdge(adj, u, v);
        }
        printGraph(adj);
    }
    
}