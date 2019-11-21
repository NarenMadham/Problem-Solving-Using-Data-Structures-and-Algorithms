#include <bits/stdc++.h>
using namespace std;
void levelOrder(struct Node* node);
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
void MorrisInOrder(struct Node* node);
void MorrisPreOrder(struct Node* node);
/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
/* Driver program to test size function*/
void inorder(Node * root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *node = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (node == NULL)
             node = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     //MorrisInOrder(node);
      MorrisPreOrder(node);
     cout << endl;
  }
  return 0;
}

void MorrisPreOrder(Node * root){
    Node * current = root;
    while(current != NULL){
        if(current->left == NULL){
            cout<<current->data<<" ";
            current = current->right;
        }else{
            Node * predecessor = current->left;
            while(predecessor->right != NULL && predecessor->right != current){
                predecessor = predecessor->right;
            }
            if(predecessor->right == NULL){
                cout<<current->data<<" ";
                predecessor->right = current;
                current = current-> left;
            }else{
                predecessor->right = current;
                current = current->right;
            }
        }
    }
}


void MorrisInOrder(Node * root){
    Node * current = root;
    while(current != NULL){
        if(current->left == NULL){
            cout<<current->data<<" ";
            current = current->right;
        }else{
            Node * predecessor = current->left;
            while(predecessor->right != NULL && predecessor->right != current){
                predecessor= predecessor->right;
            }
            if(predecessor->right == NULL){
                predecessor->right = current;
                current = current->left;
            }else{
                predecessor->right = NULL;
                cout<<current->data<<" ";
                current = current->right;
            }
        }
    }
}

/*

1
8
10 5 L 10 30 R 5 -2 L 5 6 R -2 2 R 2 -1 L 6 8 R 30 40 R



*/
















