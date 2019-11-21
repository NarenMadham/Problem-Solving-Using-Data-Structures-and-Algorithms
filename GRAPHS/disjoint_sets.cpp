#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node * parent;
    int rank;
};

map<int, Node*> mp;

void makeset(int u){
    Node * node = (Node *) malloc(sizeof(Node));
    node->data = u;
    node->rank = 0;
    node->parent = node;
    mp[u] = node;
}

Node * findset(Node * u){
    if(u->parent == u) return u->parent;
    u->parent = findset(u->parent);
    return u->parent;
}

void unionset(int u, int v){
    Node * p1 = findset(mp[u]);
    Node * p2 = findset(mp[v]);
    
    if(p1->data == p2->data) return;
    
    if(p1->rank >= p2->rank){
        if(p1->rank == p2->rank){
            p1->rank += 1;
        }
        p2->parent = p1;
    }else{
        p1->parent = p2;
    }
}

int main(){
    int n, q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        makeset(i);
    }
    for(int i=0;i<q;i++){
        int u, v;
        cin>>u>>v;
        unionset(u, v);
    }
    for(int i=1;i<=n;i++){
        cout<<findset(mp[i])->data<<endl;
    }
}

/*
7 6
1 2
2 3
4 5
6 7
5 6
3 7
*/