#include<bits/stdc++.h>
using namespace std;

class Edge{
public: 
    int u;
    int v;
    int w;
};

class Node{
public: 
    int rank;
    int data;
    Node * parent;
};

map<int, Node*> mp;



void makeset(int u){
    Node * node = (Node *)malloc(sizeof(Node));
    node->rank = 0;
    node->data =u;
    node->parent = node;
    mp[u] = node;
}

Node* findset(Node * node){
    if(node == node->parent) return node->parent;
    
    node->parent = findset(node->parent);
    return node->parent;
}

void unionset(int u, int v){
    Node * p1 = mp[u]->parent;
    Node * p2 = mp[v]->parent;
    if(p1->data == p2->data){
        return;
    }
    if(p1->rank <= p2->rank){
        if(p1->rank == p2->rank){
            p1->rank += 1;
        }
        p2->parent = p1;
    }else{
        p1->parent = p2;
    }
}

void merge(vector<Edge *> arr, int l, int m, int r){
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<Edge *> L;
    vector<Edge *> R;
    for(int i=0;i<n1;i++){
        L.push_back(arr[l + i]);
    }
    for(int j=0;j<n2;j++){
        R.push_back(arr[m + j + 1]);
    }
    int i=0, j=0, k = l;
    while(i < n1 && j < n2){
        if(L[i]->w < R[j]->w){
            arr[k] = L[i];
            i++;
            k++;
        }else{
            arr[k] = R[j];
            k++;
            j++;
        }
    }
    while(i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(vector<Edge *> arr, int l, int h){
    if(l < h){
        int m = l + (h-l)/2;
        mergesort(arr, l, m);
        mergesort(arr, m+1, h);
        merge(arr, l, m, h);
    }
}

int main(){
    int v, e;
    cin>>v>>e;
    vector<Edge *> adj;
    for(int i=0;i<e;i++){
        int a, b, weight;
        cin>>a>>b>>weight;
        Edge *e = (Edge *)malloc(sizeof(Edge));
        e->u = a;
        e->v = b;
        e->w = weight;
        adj.push_back(e);
    }  
    for(int i=0;i<v;i++){
        makeset(i);
    }
    
    mergesort(adj, 0, e-1);
    /*for(int i=0;i<e-1;i++){
        for(int j=0;j<e-i-1;j++){
            if(adj[j]->w > adj[j+1]->w){
                Edge * temp = adj[j];
                adj[j] = adj[j+1];
                adj[j+1] = temp;
            }
        }
    }
    */
    for(int i=0;i<e;i++){
        cout<<adj[i]->w<<endl;;
    }
    
    for(int i=0;i<e;i++){
        if(findset(mp[adj[i]->u]) == findset(mp[adj[i]->v])){
            continue;
        }else{
            unionset(adj[i]->u, adj[i]->v);
            cout<<adj[i]->u<<"   "<<adj[i]->v<<endl;
        }
    }
    
}

/*
6 9
0 1 3
0 3 1
1 3 3
3 2 1
1 2 1
3 4 6
2 4 5
2 5 4
4 5 2
*/