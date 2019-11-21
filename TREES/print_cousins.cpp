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
void printCousins(struct Node* node, int key);
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
     int n, key;
     scanf("%d %d",&n, &key);
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
     printCousins(node, key);
  }
  return 0;
}

void printCousins(Node * root, int key){
    if(root == NULL){
        return;
    }
    queue<Node *> q;
    q.push(root);
    int lc = 1;
    int cc = 0;
    bool found = false;
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        lc -= 1;
        if(temp->left->data == key || temp->right->data == key){
            found = true;
            continue;
        }else{
            if(temp->left){
                q.push(temp->left);
                cc += 1;
            }
            if(temp->right){
                q.push(temp->right);
                cc += 1;
            }
        }
        if(lc == 0){
            if(found){
                while(!q.empty()){
                    Node * temp = q.front();
                    q.pop();
                    cout<<temp->data<<" ";
                }
                cout<<endl;
                break;
            }else{
                lc = cc;
                cc = 0;
            }
        }
    }
    cout<<endl;
}

/*

6 5
1 2 L 1 3 R 2 4 L 2 5 R 3 6 L 3 7 R


*/