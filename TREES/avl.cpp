#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    Node * left;
    Node * right;
    int data;
    int height;
};

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

Node * newNode(int data){
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 0;
    return node;
}

int height(Node * node){
    if(node == NULL){
        return -1;
    }
    return node->height;
}

int balance(Node * node){
    return (height(node->left) - height(node->right));
}

Node * rotateRight(Node * node){
    Node * temproot = node->left;
    Node * temp = temproot->right;
    temproot->right = node;
    node->left = temp;
    temproot->height = 1 + max(height(temproot->left), height(temproot->right));
    node->height = 1 + max(height(node->left), height(node->right));
    return temproot;
}

Node * rotateLeft(Node * node){
    if(node == NULL){
        return NULL;
    }
    Node * temproot = node->right;
    Node * temp = temproot->left;
    temproot->left = node;
    node->right = temp;
    temproot->height = 1 + max(height(temproot->left), height(temproot->right));
    node->height = 1 + max(height(node->left), height(node->right));
    return temproot;
}

Node * insert(Node * node, int data){
    if(node == NULL){
        return newNode(data);
    }
    if(data <= node->data){
        node->left = insert(node->left, data);
    }
    else if(data > node->data){
        node->right = insert(node->right, data);
    }else{
        return node;
    }
    node->height = max(height(node->left), height(node->right)) + 1;
    int bal = balance(node);
    if(bal > 1 && data < node->left->data){
        cout<<"ll rotation"<<endl;
        return rotateRight(node);
    }else if(bal > 1 && data > node->left->data){
        cout<<"lr rotation"<<endl;
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }else if(bal < -1 && data > node->right->data){
        cout<<"rr rotation"<<endl;
        return rotateLeft(node);
    }else if(bal < -1 && data < node->right->data){
        cout<<"rl rotation"<<endl;
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

Node * getpredecessor(Node * node){
    if(node == NULL){
        return NULL;
    }
    Node * current = node;
    while(current->right!= NULL){
        current = current->right;
    }
    return current;
}

Node * remove(Node * node, int data){
    if(node == NULL){
        cout<<"The element is not present in the tree!"<<endl;
        return node;
    }
    if(data < node->data){
        node->left = remove(node->left, data);
    }else if(data > node->data){
        node->right = remove(node->right, data);
    }else{
        if(node->left == NULL && node->right == NULL){
            delete(node);
            return NULL;
        }
        else if (node->left == NULL){
            Node * temp = node->right;
            delete(node);
            return temp;
        }else if(node->right == NULL){
            Node * temp = node->left;
            delete(node);
            return temp;
        }
        
        Node * temp = getpredecessor(node->left);
        node->data = temp->data;
        remove(node->left, temp->data);
        
        if(node == NULL){
            return node;
        }
        node->height = 1 + max(height(node->left), height(node->right));
        int bal = balance(node);
        
        
        if(bal > 1 && balance(node->left) >= 0){
            cout<<"LL ROTATION"<<endl;
            return rotateRight(node);
        }else if(bal > 1 && data > balance(node->left) < 0){
            cout<<"LR ROTATION"<<endl;
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }else if(bal < -1 && balance(node->right) <= 0){
            cout<<"RR ROTATION"<<endl;
            return rotateLeft(node);
        }else if(bal < -1 && balance(node->right) > 0){
            cout<<"RL ROTATION"<<endl;
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }
        return node;
    }
}

void inorder(Node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    Node * root = NULL;
    root = insert(root , -2);
    root = insert(root , -1);
    root = insert(root , 2);
    root = insert(root , 5);
    root = insert(root , 10);
    root = insert(root , 6);
    root = insert(root , 8);
    root = insert(root , 30);
    root = insert(root , 40);
    root = remove(root , 40);
    inorder(root);
    return 0;
}