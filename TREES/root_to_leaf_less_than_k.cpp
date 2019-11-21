#include <bits/stdc++.h>
using namespace std;
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

Node * removeUtil(Node * root, int level, int k){
    if(root == NULL){
        return NULL;
    }
    root->left = removeUtil(root->left, level+1, k);
    root->right = removeUtil(root->right, level+1, k);
    
    if(root->left == NULL && root->right == NULL && level < k){
        delete root;
        return NULL;
    }
    return root;
}

Node * removeNodes(struct Node * root, int k){
    return removeUtil(root, 1, k);
}

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
     int n, k;
     scanf("%d %d",&n, &k);
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
     removeNodes(node, k);
      inOrder(node);
     cout << endl;
  }
  return 0;
}



/*

1
7 4
1 2 L 1 3 R 2 4 L 2 5 R 3 6 R 4 7 L 6 8 L

*/