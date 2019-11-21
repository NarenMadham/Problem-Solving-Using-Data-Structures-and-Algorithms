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
void level_by_level(struct Node* node);
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
     level_by_level(node);
     cout << endl;
  }
  return 0;
}

void level_by_level(Node * root){
    if(root == NULL) return;
    queue<Node *> q;
    q.push(root);
    int lc = 1;
    int cc = 0;
    while(!q.empty()){
        Node * curr = q.front();
        q.pop();
        lc -= 1;
        cout<<curr->data<<" ";
        if(curr->left != NULL){
            cc += 1;
            q.push(curr->left);
        }
        if(curr->right != NULL){
            cc += 1;
            q.push(curr->right);
        }
        if(lc == 0){
            cout<<endl;
            lc = cc;
            cc = 0;
        }
    }
}