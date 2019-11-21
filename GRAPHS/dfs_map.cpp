#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int v, e;
        cin>>v>>e;
        map<int, map<int, int> > adj;
        for(int i=0;i<e;i++){
            int u, v;
            cin>>u>>v;
            adj[u][v] = 1;
            adj[v][u] = 1;
        }
        stack<int> s;
        s.push(0);
        vector<bool> vis(v, false);
        while(! s.empty()){
            int temp = s.top();
            s.pop();
            vis[temp] = true;
            cout<<temp<<" ";
            map<int, int> e = adj[temp];
            map<int, int> :: iterator it;
            for(it = e.begin(); it != e.end(); it++){
                if(!vis[it->first]){
                    vis[it->first] = true;
                    s.push(it->first);
                }
            }
        }
    }
}

/*
1
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