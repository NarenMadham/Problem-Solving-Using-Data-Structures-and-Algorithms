#include<bits/stdc++.h>
using namespace std;

int main(){
    int v, e;
    cin>>v>>e;
    map<int, map<int , int> > adj;
    for(int i=0;i<e;i++){
        int u, v, w;
        cin>>u>>v>>w;
        adj[u][v] = w;
    }
    vector<int> dist(v, 10000);
    dist[0] = 0;
    vector<int> parent(v, -1);
    parent[0] = 0;
    for(int i=0;i<v-1;i++){
        map<int, map<int, int> > :: iterator it;
        for(it = adj.begin(); it!= adj.end(); it++){
            map<int, int> :: iterator mit;
            for(mit = it->second.begin(); mit != it->second.end(); mit++){
                if(dist[mit->first] > dist[it->first] + mit->second){
                    dist[mit->first] = dist[it->first] + mit->second;
                    parent[mit->first] = it->first;
                }
            }
        }
    }
    cout<<"DISTANCES : "<<endl;
    for(int i=1;i<v;i++){
        cout<<i<<" : "<<dist[i]<<endl;
    }
    cout<<"PATHS : "<<endl;
    for(int i=1;i<v;i++){
        cout<<i;
        int temp = parent[i];
        while(temp != parent[temp]){
            cout<<"<-"<<temp;
            temp = parent[temp];
        }
        cout<<"<-0"<<endl;
    }
}


/*

5 7
0 3 8
3 4 2
4 3 1
2 4 4
0 2 5
0 1 4
1 2 -3

*/