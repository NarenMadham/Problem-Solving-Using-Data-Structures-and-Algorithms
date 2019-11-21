void serialize(Node *root,vector<int> &A)
{
    if(!root)
    return;
    queue<Node *> q;
    q.push(root);
    A.push_back(root->data);
    while(q.size()!=0){
        Node *curr = q.front();
        q.pop();
        if(curr->left){
            q.push(curr->left);
            A.push_back(curr->left->data);
        }else A.push_back(-1);
        if(curr->right){
            q.push(curr->right);
            A.push_back(curr->right->data);
        }else A.push_back(-1);
    }
}
/*this function deserializes
 the serialized vector A*/
Node * deSerialize(vector<int> &A)
{
    Node *root = NULL;
   if(A[0]!=-1)
   root = newNode(A[0]);
   queue<Node *> q;
   q.push(root);
   int i = 0;
   while(q.size()!=0){
       Node *curr = q.front();
       q.pop();
       if(i+1>=A.size())
       break;
       if(A[i+1]!=-1){
           curr->left = newNode(A[i+1]);
           q.push(curr->left);
       }
       if(i+2>=A.size())
       break;
       if(A[i+2]!=-1){
           curr->right = newNode(A[i+2]);
           q.push(curr->right);
       }
       i = i+2;
   }
   return root;
}