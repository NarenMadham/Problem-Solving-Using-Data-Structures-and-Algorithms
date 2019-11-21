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
void iterativeInOrder(struct Node* node);
/* Helper function to test mirror(). Given a binary
   search tree, print out its data elements in
   increasing sorted order.*/
void inOrder(struct Node* node)
{
  if (node == NULL)
    return;
  inOrder(node->left);
  inOrder(node->right);
  printf("%d ", node->data);
  
}
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while(t--)
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
     iterativeInOrder(node);
     cout << endl;
  }
  return 0;
}

void iterativeInOrder(Node * root){
    if(root == NULL) return;
    stack<Node *> s;
    while(true){
        if(root != NULL){
            s.push(root);
            root = root->left;
        }else{
            if(s.empty()) break;
            Node * temp = s.top();
            s.pop();
            cout<<temp->data<<" ";
            root = temp->right;
        }
    }
}

/*
1
7
10 20 L 10 30 R 20 40 L 30 50 L 30 60 R 40 80 R 60 70 L
*/