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
void mulOfSumOfLeaves(struct Node* node);
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
     mulOfSumOfLeaves(node);
     cout << endl;
  }
  return 0;
}

void mulOfSumOfLeaves(struct Node* root){
    queue<Node *> q;
    q.push(root);
    int lc = 1;
    int cc = 0;
    long long int ans = 1;
    long long int count = 0;
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        lc -= 1;
        if(temp->left == NULL && temp ->right == NULL){
            count += temp->data;    
        }else{
            if(temp->left != NULL){
                q.push(temp->left);
                cc += 1;
            }
            if(temp->right != NULL){
                q.push(temp->right);
                cc += 1;
            }
        }
        if(lc == 0){
            lc = cc;
            cc = 0;
            if(count != 0)
                ans *= count;
            count = 0;
        }
    }
    cout<<ans<<endl;
}

/*
1
9
2 7 L 2 5 R 7 8 L 7 6 R 5 9 R 6 1 L 6 11 R 9 4 L 9 10 R


*/