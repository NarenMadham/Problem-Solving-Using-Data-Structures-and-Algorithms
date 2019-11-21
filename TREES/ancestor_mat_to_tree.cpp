#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node * left;
    Node * right;
public:
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorder(Node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    int n;
    cin>>n;
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    vector<int> parent(n, 0);
    multimap<int, int> mp;
    map<int, Node*> adj;
    
    for(int i=0;i<n;i++){
        Node * node = new Node(i);
        adj[i] = node;
    }
    
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            sum += arr[i][j];
        }
        mp.insert(make_pair(sum, i));
    }
    
    multimap<int, int> :: iterator it;
    Node * root = NULL;
    for(it = mp.begin(); it != mp.end(); it++){
        root = adj[it->second];
        if(it->first != 0){
            for(int i=0;i<n;i++){
                if(parent[i] == 0 && arr[it->second][i] == 1){
                    parent[i] = 1;
                    if(root->left != NULL){
                        root->left = adj[i];
                    }else{
                        root->right = adj[i];
                    }
                }
            }
        }
        
    }
    inorder(root);
    cout<<endl;
    return 0;
}

/*

6
0 0 0 0 0 0
1 0 0 0 1 0
0 0 0 1 0 0
0 0 0 0 0 0
0 0 0 0 0 0
1 1 1 1 1 0

*/