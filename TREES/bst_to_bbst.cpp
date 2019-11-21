#include <bits/stdc++.h>
#include <string.h>
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
Node * bst_to_bbst(struct Node* node);
/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void postOrder(struct Node* node)
{
  if (node == NULL)
    return;
  postOrder(node->left);
  printf("%d ", node->data);
  postOrder(node->right);
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
     Node * root = bst_to_bbst(node);
      postOrder(root);
     cout << endl;
  }
  return 0;
}

void inorder(Node * root, vector<Node *>& nodes){
    if(root == NULL){
        return;
    }
    inorder(root->left, nodes);
    nodes.push_back(root);
    inorder(root->right, nodes);
}

Node * butil(vector<Node *>& nodes, int l, int r){
    if(l > r){
        return NULL;
    }
    int m = l + (r-l)/2;
    Node * root = nodes[m];
    root->left = butil(nodes, l, m-1);
    root->right = butil(nodes, m+1, r);
    return root;
}

Node * bst_to_bbst(Node * node){
    Node * root = NULL;
    vector<Node *> nodes;
    inorder(node, nodes);
    int n = nodes.size();
    root = butil(nodes, 0, n-1);
    cout<<endl;
    return root;
}

/*

1
4
10 20 L 10 30 R 20 40 L 20 60 R

*/


















