#include<bits/stdc++.h>

#define sint set<int> 

using namespace std;

set<int> white;
set<int> gray;
set<int> black;

bool cycle = false;

void isCycle(int ele, sint gray, sint black, map<int, vector<int> > adj, int u, int v){
    gray.insert(ele);
    vector<int> :: iterator it;
    for(it = adj[ele].begin(); it != adj[ele].end(); it++){
        if(black.find(*it) == black.end()){
            if(gray.find(*it) == gray.end()){
                isCycle(*it, gray, black, adj, u, v);
            }else{
                if(cycle == false){
                    cycle = true;
                    u = ele;
                    v = *it;
                    cout<<"There is a cycle in the graph"<<endl;
                    cout<<"The edge that forms the cycle is : "<<u<<"->"<<v<<endl;
                    return;
                }else{
                    break;
                }
            }
        }
    }
    gray.erase(ele);
    black.insert(ele);
}

int main(){
    int ver, e;
    cin>>ver>>e;
    map<int, vector<int> > adj;
    for(int i=0;i<e;i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    for(int i=1;i<=ver;i++){
        white.insert(i);
    }
    set<int> :: iterator wit;
    int u = -1, v = -1;
    for(wit = white.begin(); wit != white.end(); wit++){
        if(black.find(*wit) == black.end() && gray.find(*wit) == gray.end()){
            isCycle(*wit, gray, black, adj, u, v);
        }
        else{
            continue;
        }
    }
    if(cycle == false){
        cout<<"There is no cycle in the graph!"<<endl;
    }
    return 0;
}



/*

6 7
1 2
2 3
1 3
4 1
4 5
5 6
6 4

6 6
1 2
2 3
1 3
4 1
4 5
5 6

*/