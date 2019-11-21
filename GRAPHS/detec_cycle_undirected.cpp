#include<bits/stdc++.h>
using namespace std;

class Node{
public: 
    int data;
    int rank;
    Node * parent;
};

map<int, Node*> mp;

void makeset(int i){
    Node * n = (Node *)malloc(sizeof(Node));
    n->data = i;
    n->parent = n;
    n->rank = 0;
    mp[i] = n;
}

void unionset(int u, int v){
    Node * p1 = mp[u]->parent;
    Node * p2 = mp[v]->parent;
    if(p1->data == p2->data){
        return;
    }
    if(p1->rank >= p2->rank){
        if(p1->rank == p2->rank){
            p1->rank += 1;
        }
        p2->parent = p1;
    }else{
        p1->parent = p2;   
    }
}

Node* findset(Node * node){
    if(node->parent == node){
        return node->parent;
    }
    node->parent = findset(node->parent);
    return node->parent;
}

int main(){
    int v, e;
    cin>>v>>e;
    map<int, map<int, int> > adj;
    for(int i=0;i<e;i++){
        int u, v;
        cin>>u>>v;
        adj[u][v] = 1;
        //adj[v][u] = 1;
    }
    for(int i=0;i<v;i++){
        makeset(i);    
    }
    bool isCycle = false;
    map<int, map<int, int> > :: iterator it;
    for(it = adj.begin(); it != adj.end(); it++){
        map<int, int> :: iterator mit;
        for(mit = it->second.begin(); mit != it->second.end(); mit++){
            if(findset(mp[it->first]) != findset(mp[mit->first])){
                unionset(it->first, mit->first);
            }else{
                isCycle = true;
                cout<<"There is a cycle in the graph"<<endl;
                cout<<"The edge that forms the cycle is : "<<it->first <<" -> "<<mit->first;
                break;
            }
        }
        if(isCycle == true){
            break;
        }
    }
    
    if(isCycle == false){
        cout<<"There is no cycle in the graph";
    }
    return 0;   
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





















