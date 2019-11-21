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
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void mirror(Node * root){
    if(root == NULL){
        return;
    }
    mirror(root->left);
    mirror(root->right);
    Node * temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;
}

int main(){
    int n;
    cin>>n;
    Node * root = NULL;
    map<int, Node*> mp;
    for(int i=0;i<n;i++){
        int a, b;
        char c;
        cin>>a>>b;
        cin>>c;
        if(mp.find(a) == mp.end()){
            Node *node = new Node(a);
            mp[a] = node;
            if(root == NULL){
                root = node;
            }
        }
        Node * node = new Node(b);
        if(c == 'L'){
            mp[a]->left = node;
        }else{
            mp[a]->right = node;
        }
        mp[b] = node;
    }
    mirror(root);
    inorder(root);
}

/*

8
1 2 L 1 4 R 2 5 L 2 7 R 4 3 L 4 2 R 5 8 R 2 1 L


*/