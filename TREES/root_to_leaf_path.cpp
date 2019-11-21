/* Structure of Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};*/
/* The function should print all the paths from root
 to leaf nodes of the binary tree */
 
void path(Node * root, int arr[], int i){
    if(root == NULL){
        return;
    }
    arr[i] = root->data;
    if(root->left == NULL && root->right == NULL){
        for(int j=0;j<=i;j++){
            cout<<arr[j]<<" ";
        }
        cout<<"#";
    }
    path(root->left, arr, i+1);
    path(root->right, arr, i+1);
}
 
void printPaths(Node* root)
{
    int arr[101];
    path(root, arr, 0);
    cout<<endl;
}