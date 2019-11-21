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
    int depth;
    int hd;
    
    Node(int x){
        data = x;
        left = right = NULL;
        depth = 0;
        hd = 0;
    }
};
void left_view(struct Node* node);
void top_view_orderless(struct Node* node);
void top_view(struct Node* node);
void right_view(struct Node* node);
void bottom_view(struct Node* node);
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
int max_depth = -1;

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
        if (lr == 'L'){
          parent->left = child;
            child->hd = parent->hd -1;
        }
        else{
          parent->right = child;
            child->hd = parent->hd + 1;
        }
        m[n2]  = child;
         child->depth = parent->depth + 1;
     }
      cout<<"LEFT VIEW : "<<endl;
     left_view(node);
      cout<<endl;
      max_depth = -1;
      cout<<"RIGHT VIEW : "<<endl;
     right_view(node);
     cout << endl;
      max_depth = -1;
      cout<<"TOP VIEW : "<<endl;
      top_view(node);
      cout<<endl;
      cout<<"BOTTOM VIEW : "<<endl;
      bottom_view(node);
  }
  return 0;
}

void left_view(Node * root){
    if(root == NULL) return;
    if(root->depth > max_depth){
        cout<<root->data<<" ";
        max_depth = root->depth;
    }
    left_view(root->left);
    left_view(root->right);
}

void right_view(Node * root){
    if(root == NULL) return;
    if(root->depth > max_depth){
        cout<<root->data<<" ";
        max_depth = root->depth;
    }
    right_view(root->right);
    right_view(root->left);
}

//Irrespective of the order!!!
void top_view_orderless(Node * root){
    if(root == NULL) return;
    queue<Node *> q;
    q.push(root);
    int min = INT_MAX;
    int max = INT_MIN;
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        if(temp->hd < min){
            cout<<temp->data<<" ";
            min = temp->hd;
        }
        else if(temp->hd > max){
            cout<<temp->data<<" ";
            max = temp->hd;
        }
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}

void top_view(Node * root){
    if(root == NULL) return;
    
    map<int, vector<int> > mp;
    int hd;
    
    queue<pair<Node*, int> > q;
    q.push(make_pair(root, hd));
    while(!q.empty()){
        pair<Node *, int> temp = q.front();
        q.pop();
        hd = temp.second;
        Node * node = temp.first;
        mp[hd].push_back(node->data);
        if(node->left != NULL){
            q.push(make_pair(node->left, hd-1));
        }
        if(node->right != NULL){
            q.push(make_pair(node->right, hd+1));
        }
    }
    map<int, vector<int> > :: iterator it;
    for(it = mp.begin(); it != mp.end();it++){
        cout<<it->second[0]<<" ";
    }
}

void bottom_view(Node * root){
    if(root == NULL) return;
    map<int, vector<int> > mp;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node * temp = q.front();
        q.pop();
        mp[temp->hd].push_back(temp->data);
        if(temp->left != NULL){
            q.push(temp->left);
        }
        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
    map<int, vector<int> > :: iterator it;
    for(it = mp.begin(); it != mp.end(); ++it){
        cout<<it->second[it->second.size() - 1]<<" ";
    }
}

/*
1
14
25 18 L 25 50 R 18 19 L 18 20 R 50 35 L 50 60 R 19 15 R 20 16 L 20 9 R 35 10 L 35 40 R 60 55 L 60 70 R 10 30 R

*/