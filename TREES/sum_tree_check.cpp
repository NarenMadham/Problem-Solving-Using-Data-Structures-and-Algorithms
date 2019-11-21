/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// Should return true if tree is Sum Tree, else false

int sumUtil(Node * root){
    if(root == NULL){
        return 0;
    }
    if(root->left == NULL && root->right == NULL){
        return root->data;
    }
    int l = sumUtil(root->left);
    int r = sumUtil(root->right);
    if(l == -1 || r == -1){
        return -1;
    }
    if(root->data == l + r){
        return root->data + l +r;
    }
    return -1;
}

bool isSumTree(Node* root)
{
    int temp = sumUtil(root);
    if(temp == -1){
        return false;
    }
    return true;
}