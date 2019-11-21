#include <bits/stdc++.h>
using namespace std;
//Node * lowest_common_ancestor(struct Node* node, int a, int b);
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
struct Node * lowest_common_ancestor(struct Node* node, int a, int b);
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
        int a, b;
      cin>>a>>b;
     cout<< lowest_common_ancestor(node, a, b)->data;     
  }
  return 0;
}

int min(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

struct Node * lowest_common_ancestor(Node * root, int a, int b){
    if(root == NULL) return NULL;
    if(root->data < min(a,b)){
        return lowest_common_ancestor(root->right, a, b);
    }
    else if(root->data > max(a,b)){
        return lowest_common_ancestor(root->left, a, b);
    }else{
        return root;
    }
}