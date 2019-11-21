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
    if(root == NULL){
        return;
    }
    queue <Node *> q1;
    queue <Node *> q2;
    q1.push(root);
    //cout<<"a";
    while(!q1.empty() || !q2.empty()){
        while(!q1.empty()){
            //cout<<"a";
            root = q1.front();
            q1.pop();
            if(root ->left != NULL){
                q2.push(root->left);
            }
            if(root->right != NULL){
                q2.push(root->right);
            }
            cout<<root->data<<" ";
        }
        cout<<endl;
        while(!q2.empty()){
            //cout<<"a";
            root = q2.front();
            cout<<root->data<<" ";
            if(root->left != NULL){
                q1.push(root->left);
            }
            if(root->right != NULL){
                q1.push(root->right);
            }
            q2.pop();
        }
        cout<<endl;
    }
}