#include<bits/stdc++.h>
using namespace std;

class node{
public: 
    node * left = NULL;
    node * right = NULL;
    int data;
public:
    void setData(int data){
        this->data = data;
    }
};

class BST{
public:
    node * root;
public:
    BST(){
        this->root = NULL;
    }
    node * insert(class node* n, int data);
    void inorder(node * root);
    node * delete_node(node* n, int data);
    node * get_successor(node * root);
    int size(node * root);
    int height(node * root);
};

int BST :: size(node * root){
    if(root == NULL){
        return 0;
    }
    int lh = size(root->left);
    int rh = size(root->right);
    return 1 + lh + rh;
}

int BST:: height(node * root){
    if(root == NULL){
        return 0;
    }
    int lh = height(node->left);
    int rh = height(node ->right);
    return 1 + max(lh, rh);
}

node * BST:: get_successor(node * root){
    node * current = root;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}

node * BST:: delete_node(node * root, int data){
    if(root == NULL){
        //cout<<"The tree is empty\n";
        return root;
    }
    
    if(data < root->data){
        root->left = delete_node(root->left, data);
    }else if(data > root->data){
        root->right = delete_node(root->right, data);
    }else{
        if(root->left == NULL){
            node * temp = root->right;
            free(root);
            return temp;
        }
        if(root->right == NULL){
            node * temp = root->left;
            free(root);
            return temp;
        }
        node * temp = get_successor(root->right);
        root->data = temp->data;
        root->right = BST::delete_node(root->right, temp->data);
    }
    return root;
}

node * BST :: insert(class node* n, int data){
    if(n == NULL){
        node * temp = (node *)malloc(sizeof(node));
        temp->setData(data);
        return temp;
    }
    if(data < n->data){
        n->left = insert(n->left, data);
    }
    if(data > n->data){
        n->right = insert(n->right, data);
    }
    return n;
}

void BST :: inorder(node * root){
    if(root != NULL){
        BST::inorder(root->left);
        cout<<root->data<<endl;
        BST::inorder(root->right);
    }
}

int main(){
    BST bst;
    bst.root = bst.insert(bst.root, 20);
    bst.insert(bst.root,10);
    bst.insert(bst.root,30);
    bst.insert(bst.root,60);
    bst.insert(bst.root,70);
    bst.insert(bst.root,40);
    bst.insert(bst.root,50);
    bst.insert(bst.root,80);
    bst.inorder(bst.root);
    cout<<"Size : "<<bst.size(bst.root)<<endl;
    cout<<"\nafter delete\n"<<endl;
    bst.delete_node(bst.root, 60);
    bst.inorder(bst.root);
    cout<<"Size : "<<bst.size(bst.root)<<endl;
    cout<<"Height : "<<bst.height(bst.root)<<endl;
    return 0;
}