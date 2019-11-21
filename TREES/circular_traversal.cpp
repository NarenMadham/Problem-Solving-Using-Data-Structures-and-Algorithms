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
void circular_traversal(struct Node* node);
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
     circular_traversal(node);
     cout << endl;
  }
  return 0;
}

void circular_traversal(Node * root){
    if(root == NULL) return;
    map<int, vector<int> > mp;
    queue<Node * > q;
    q.push(root);
    int lc = 1;
    int cc = 0;
    int level = 0;
    while(!q.empty()){
        Node * temp  = q.front();
        q.pop();
        mp[level].push_back(temp->data);
        lc -= 1;
        if(temp->left != NULL){
            q.push(temp->left);
            cc += 1;
        }
        if(temp->right != NULL){
            q.push(temp->right);
            cc += 1;
        }
        if(lc == 0){
            lc = cc;
            cc = 0;
            level += 1;
        }
    }
    int it1 = 0;
    int it2 = level-1;
    while(true){
        for(int i=0;i<mp[it1].size();i++){
            cout<<mp[it1][i]<<" ";
        }
        //cout<<endl;
        if(it1 == it2){
            break;
        }
        ++it1;
        for(int i = mp[it2].size() - 1;i>=0;i--){
            cout<<mp[it2][i]<<" ";
        }
        --it2;
        //cout<<endl;
    }
    
}

/*
1
14
25 18 L 25 50 R 18 19 L 18 20 R 50 35 L 50 60 R 19 15 R 20 16 L 20 9 R 35 10 L 35 40 R 60 55 L 60 70 R 10 30 R

*/