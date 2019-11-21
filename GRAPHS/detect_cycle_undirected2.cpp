#include<bits/stdc++.h>
using namespace std;

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
    stack<int> s;
    set<int> vis;
    s.push(0);
    vis.insert(0);
    vector<int> parent(v, -1);
    bool cycle = false;
    while(!s.empty()){
        int temp = s.top();
        s.pop();
        map<int, int > :: iterator it;
        for(it = adj[temp].begin(); it!= adj[temp].end();it++){
            if(it->first == parent[temp]){
                continue;
            }
            if(vis.find(it->first) == vis.end()){
                s.push(it->first);
                vis.insert(it->first);
                parent[it->first] = temp;
            }else{
                cycle = true;
                cout<<"There is a cycle in the graph!"<<endl;
                cout<<"The edge that forms a cycle is : "<<temp<<"->"<<it->first<<endl;
                break;
            }
        }
        if(cycle==true){
            break;
        }
    }
    if(cycle == false){
        cout<<"There is no cycle in the graph!"<<endl;
    }
}


/*
6 6
0 5
0 1
1 4
1 2
4 3
2 3

6 5
0 5
0 1
1 4
1 2
4 3


*/