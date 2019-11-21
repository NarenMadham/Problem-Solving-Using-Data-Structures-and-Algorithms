#include<bits/stdc++.h>
using namespace std;

queue<int> q;
map<int, int> parent;
set<int> vis;
bool term = false;
map<int, map<int, int> > adj;

void adjust_paths(int src,int curr, int m, int sink){
    int t = sink;
    adj[parent[t]][t] -= m;
    adj[t][parent[t]] += m;
    while(t != src){
        cout<<t<<"<-";
        t = parent[t];
        adj[parent[t]][t] -= m;
        adj[t][parent[t]] += m;    
    }
    cout<<t<<endl;
}

int minimum(vector<int> v){
    int m = INT_MAX;
    vector<int> :: iterator it;
    for(it = v.begin(); it!= v.end(); it++){
        //cout<<*it<<" ";
        if(*it < m){
            m = *it;
        }
    }
    //cout<<endl;
    return m;
}

int bfs(int src, int sink){
    vector<int> residues;
    q.push(src);
    while(!q.empty()){
        map<int, int> :: iterator it;
        int temp = q.front();
        q.pop();
        vis.insert(temp);
        for(it = adj[temp].begin(); it!= adj[temp].end(); it++){
            if(it->second > 0){
                if(vis.find(it->first) != vis.end()){
                    continue;
                }else{
                    residues.push_back(it->second);
                    q.push(it->first);
                    parent[it->first] = temp;
                    if(it->first == sink){
                        int transfered = minimum(residues);
                        adjust_paths(src, temp, transfered, sink);
                        //cout<<transfered<<endl;
                        return transfered;
                    }
                }
            }
        }
    }
    term = true;
    return 0;
}

int ford_fulkerson(int src, int sink){
    map<int, int> :: iterator it;
    int max_transfer = 0;
    while(true){
        if(term == true){
            break;
        }
        max_transfer += bfs(src, sink);
        while(!q.empty()){
            q.pop();
        }
        parent.clear();
        vis.clear();
    }
    return max_transfer;
}

int main(){
    int v, e;
    cin>>v>>e;
    for(int i=0;i<e;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u][v] = w;
        adj[v][u] = 0;
    }
    cout<<"MAXIMUM UNITS TRANSFERED THROUGH THE NETWORK: " << endl;
    cout<<ford_fulkerson(0, v-1);
}


/*

7 11
0 1 3
0 3 3
2 0 3
2 3 1
1 2 4
4 1 1
2 4 2
3 4 2
3 5 6
5 6 9
4 6 1


*/