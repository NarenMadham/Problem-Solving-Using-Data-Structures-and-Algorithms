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
void iterative_PostOrder1(struct Node* node);
void iterative_PostOrder2(struct Node* node);
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
     iterative_PostOrder2(node);
     cout << endl;
  }
  return 0;
}

void iterative_PostOrder1(struct Node* node){
    if(node == NULL) return;
    stack<Node *> s1;
    stack<Node *> s2;
    s1.push(node);
    while(!s1.empty()){
        Node * temp = s1.top();
        s1.pop();
        s2.push(temp);
        if(temp->left != NULL){
            s1.push(temp->left);
        }
        if(temp->right != NULL){
            s1.push(temp->right);
        }
    }
    while(!s2.empty()){
        Node * current = s2.top();
        s2.pop();
        cout<<current->data<<" ";
    }
}


//Using only one stack
void iterative_PostOrder2(struct Node* root){
    if(root == NULL) return;
    stack<Node *> s;
    Node * curr = root;
    while(curr != NULL || !s.empty()){
        if(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }else{
            Node * temp = s.top()->right;
            if(temp != NULL){
                curr = temp;
            }else{
                Node * x = s.top();
                cout<<x->data<<" ";
                s.pop();
                while(!s.empty() && x == s.top()->right){
                    x = s.top();
                    cout<<x->data<<" ";
                    s.pop();
                }
            }
        }
    }
}


/*
1
7
10 20 L 10 30 R 20 40 L 30 50 L 30 60 R 40 80 R 60 70 L
*/