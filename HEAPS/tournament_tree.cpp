#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int index;
    Node * left, *right;
public:
    Node(int data){
        this->index = data;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node * root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->index<<" ";
    inorder(root->right);
}

void traverseHeight(Node * root, vector<int>& arr, int& res){
    if(root == NULL){
        return;
    }
    if(root->left == NULL && root->right == NULL){
        return;
    }
    if(res > arr[root->left->index] && root->index != root->left->index){
        res = arr[root->left->index];
        traverseHeight(root->right, arr, res);
    }
    else if(res > arr[root->right->index] && root->index != root->right->index){
        res = arr[root->right->index];
        traverseHeight(root->left, arr, res);
    }
}

int second_smallest(vector<int>& arr, int n){
    deque<Node *> dq;
    Node * hr = NULL;
    for(int i=0;i<n;i+=2){
        Node * t1 = new Node(i);
        if(i+1 < n){
            Node * t2 = new Node(i + 1);
            Node * root;
            if(arr[t1->index] < arr[t2->index]){
                root = new Node(t1->index);
            }else{
                root = new Node(t2->index);
            }
            root->left = t1;
            root->right = t2;
            dq.push_back(root);
            hr = root;
        }else{
            dq.push_back(t1);
        }
    }
    while(dq.size() != 1){
        int dsize = dq.size();
        int last = (dsize & 1) ? (dsize-2) : (dsize-1);
        for(int i=0;i<last;i+=2){
            Node * f1 = dq.front();
            dq.pop_front();
            Node * f2 = dq.front();
            dq.pop_front();
            Node * root;
            if(arr[f1->index] < arr[f2->index]){
                root = new Node(f1->index);
            }else{
                root = new Node(f2->index);
            }
            root->left = f1;
            root->right = f2;
            hr = root;
            dq.push_back(root);
        }
        if(dsize & 1){
            dq.push_back(dq.front());
            dq.pop_front();
        }
    }
    int res = INT_MAX;
    traverseHeight(hr, arr, res);
    cout<<"Inorder : "<<endl;
    inorder(hr);
    cout<<endl;
    cout<<"Smallest : "<<arr[hr->index]<<endl;
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.push_back(temp);
    }
    int res = second_smallest(v, n);
    cout<<"Second Smallest : "<<res<<endl;
}

/*

7
61 6 100 9 10 12 17

*/