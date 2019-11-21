#include <bits/stdc++.h>
using namespace std;
//void levelOrder(struct Node* node);
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

class Attribute{
public:
    bool val;
    int size;
    int min;
    int max;
public:
    Attribute(bool val, int size, int min, int max){
        this->val = val;
        this->size = size;
        this->min = min;
        this->max = max;
    }
};

Attribute * largest_bst(struct Node* root);
int lbst(Node * root);
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
     Attribute * a = largest_bst(node);
     cout<<a->size;
  }
  return 0;
}

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

Attribute * largest_bst(Node * root){
    Attribute * a = (Attribute *)malloc(sizeof(Attribute));
    if(root == NULL){
        a->val = true;
        a->size = 0;
        a->min = INT_MAX;
        a->max = INT_MIN;
        return a;
    }
    Attribute * l = largest_bst(root->left);
    Attribute * r = largest_bst(root->right);
    if(l->val==false || r->val==false ||(root->data < l->max || root->data > r->min)){
        //cout<<"asdfa"<<endl;
        a->val = false;
        a->size = max(l->size, r->size);
        return a;
    }
    a->val = true;
    a->size = 1 + l->size + r->size;
    if(root->left != NULL)
        a->min = l->min;
    else
        a->min = root->data;
    if(root->right != NULL)
        a->max = r->max;
    else
        a->max = root->data;
    
    return a;
}
/*
    1
    14
    25 18 L 25 50 R 18 19 L 18 20 R 50 35 L 50 60 R 19 15 R 20 18 L 20 25 R 35 20 L 35 40 R 60 55 L 60 70 R 20 25 R

*/
