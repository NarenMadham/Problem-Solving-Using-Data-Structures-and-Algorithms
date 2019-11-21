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
void levelOrder(struct Node* node);
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
int arb_to_children_sum(Node * root);
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
     arb_to_children_sum(node);
      inOrder(node);
     cout << endl;
  }
  return 0;
}

void arb_util(Node * root, int diff){
    if(root->left != NULL){
        arb_util(root->left, diff);
    }else if(root->right != NULL){
        arb_util(root->right, diff);
    }
    root->data += diff;
}

int arb_to_children_sum(Node * root){
    if(root->left  == NULL && root->right == NULL){
        return root->data;
    }
    arb_to_children_sum(root->left);
    arb_to_children_sum(root->right);
    int l = 0;
    int r = 0;
    if(root->left != NULL){
        l = root->left->data;
    }
    if(root->right != NULL){
        r = root->right->data;
    }
    int diff = root->data - (l + r);
    if(diff == 0){
        return root->data;
    }else if(diff < 0){
        root->data += abs(diff);
        return root->data;
    }else{
        if(root->left != NULL)
            arb_util(root->left, diff);
        else
            arb_util(root->right, diff);
        return root->data;
    }
}


/*

1
6
50 7 L 50 2 R 7 3 L 7 5 R 2 1 L 2 30 R

*/