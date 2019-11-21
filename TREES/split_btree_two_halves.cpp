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
bool two_halves(struct Node* node);
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
     bool f = two_halves(node);
      if(f == true){
          cout<<"yes";
      }else{
          cout<<"no";
      }
     cout << endl;
  }
  return 0;
}

int count_nodes(Node * root){
    if(root == NULL){
        return 0;
    }
    int l = count_nodes(root->left);
    int r = count_nodes(root->right);
    return l + r + 1;
} 

int tutil(Node * root, int n, bool& res){
    if(root == NULL){
        return 0;
    }
    int count = 0;
    count += tutil(root->left, n, res);
    count += tutil(root->right, n, res);
    count += 1;
    if(count == (n-count)){
        res = true;
    }
    return count;
}

bool two_halves(Node * root){
    int n = count_nodes(root);
    bool res = false;
    tutil(root, n, res);
    return res;
}


/*

1
5
5 1 L 5 6 R 1 3 L 6 7 L 6 4 R


1
7
5 1 L 5 6 R 6 7 L 6 4 R 7 3 L 7 2 R 4 8 R


*/