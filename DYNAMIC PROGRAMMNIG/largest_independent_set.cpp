#include <bits/stdc++.h>
#include <string.h>
using namespace std;
void levelOrder(struct Node* node);
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    int liss;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
        liss = 0;
    }
};
int LargestIndependentSet(struct Node* node);
/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node* node)
{
  if (node == NULL)
    return;
  inOrder(node->left);
  printf("%d ", node->data);
  inOrder(node->right);
}
/* Driver program to test size function*/
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
     cout<<LargestIndependentSet(node);
  }
  return 0;
}

int LargestIndependentSet(Node * root){
    if(root == NULL) return 0;
    if(root->liss != 0){
        return root->liss;
    }
    if(root->left == NULL && root->right == NULL){
        root->liss = 1;
        return 1;
    }
    int incl = LargestIndependentSet(root->left) + LargestIndependentSet(root->right);
    int excl = 1;
    if(root->left)
        excl += (LargestIndependentSet(root->left->left) + LargestIndependentSet(root->left->right));
    if(root->right)
        excl += (LargestIndependentSet(root->right->left) + LargestIndependentSet(root->right->right));
    root->liss = max(incl, excl);
    return root->liss;
}

/*

1
7
10 20 L 10 30 R 20 40 L 20 50 R 30 60 R 50 70 L 50 80 R


*/