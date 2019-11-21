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
void spiral_traversal(struct Node* node);
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
     spiral_traversal(node);
     cout << endl;
  }
  return 0;
}

void spiral_traversal(struct Node* root){
    if(root == NULL) return;
    stack<Node*> s1;
    stack<Node*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            Node * temp = s1.top();
            s1.pop();
            if(temp->left != NULL){
                s2.push(temp->left);    
            }
            if(temp->right != NULL){
                s2.push(temp->right);    
            }
            cout<<temp->data<<" ";
        }
        cout<<endl;
        while(!s2.empty()){
            Node *temp = s2.top();
            s2.pop();
            if(temp->right != NULL){
                s1.push(temp->right);
            }
            if(temp->left != NULL){
                s1.push(temp->left);
            }
            cout<<temp->data<<" ";
        }
        cout<<endl;
    }
}