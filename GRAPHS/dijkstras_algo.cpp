#include<bits/stdc++.h>
#define mii map<int, map<int, int> >
#define pii pair<int, int>
using namespace std;

void dijkstra(mii adj, int v, vector<int>& distances){
    priority_queue<pii, vector<pii >, greater<pii > > pq;
    set<int> vis;
    pq.push({0,0});
    distances[0] = 0;
    while(!pq.empty()){
        pair<int, int> temp = pq.top();
        pq.pop();
        int dist = temp.first;
        int vertex = temp.second;
        vis.insert(vertex);
        map<int, int> :: iterator it;
        for(it = adj[vertex].begin(); it!= adj[vertex].end(); it++){
            if(vis.find(it->second) == vis.end()){
                pq.push(make_pair(dist + it->second, it->first));
                distances[it->first] = min(distances[it->first], dist + it->second);
            }
            else if(!pq.empty())
                pq.pop();
        }
    }
}

int main(){
    int v, e;
    cin>>v>>e;
    mii adj;
    for(int i=0;i<e;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u][v] = w;
    }
    vector<int> distances(v, INT_MAX);
    dijkstra(adj, v, distances);
    for(int i=0;i<v;i++){
        cout<<i<<" : "<<distances[i]<<endl;
    }
    return 0;
}

/*

6 7
0 1 5
0 4 2
0 3 9
1 2 2
4 5 3
2 3 3
3 5 2

*/