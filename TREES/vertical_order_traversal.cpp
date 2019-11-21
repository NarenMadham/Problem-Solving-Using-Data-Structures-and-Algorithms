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
void verticalOrder(struct Node* node);
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
     verticalOrder(node);
     cout << endl;
  }
  return 0;
}

void verticalOrder(Node * root){
    if(root == NULL) return;
    map<int, vector<int> > mp;
    int hd = 0;
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, hd));
    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();
        hd = temp.second;
        Node * n = temp.first;
        mp[hd].push_back(n->data);
        if(n->left != NULL){
            q.push(make_pair(n->left,hd-1));
        }
        if(n->right != NULL){
            q.push(make_pair(n->right,hd+1));
        }
    }
    map<int, vector<int> > :: iterator it;
    for(it = mp.begin(); it!= mp.end();it++){
        for(int i=0; i < it->second.size();i++){
            cout<<it->second[i]<<" ";
        }
    }
}

/*
1
14
25 18 L 25 50 R 18 19 L 18 20 R 50 35 L 50 60 R 19 15 R 20 16 L 20 9 R 35 10 L 35 40 R 60 55 L 60 70 R 10 30 R

*/
























