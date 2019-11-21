// C++ program to find the largest subtree 
// having identical left and right subtree 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to left 
child and a pointer to right child */
struct Node 
{ 
	int data; 
	Node* left, * right; 
}; 

/* Helper function that allocates a new node with 
the given data and NULL left and right pointers. */
Node* newNode(int data) 
{ 
	Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 

// Sets maxSize to size of largest subtree with 
// identical left and right. maxSize is set with 
// size of the maximum sized subtree. It returns 
// size of subtree rooted with current node. This 
// size is used to keep track of maximum size. 
int lutil(Node * root, string& str, int& maxsize, Node *& maxNode){
    if(root == NULL){
        return 0;
    }
    string left = "", right = "";
    int ls = lutil(root->left, left, maxsize, maxNode);
    int rs = lutil(root->right, right, maxsize, maxNode);
    int size = ls + rs + 1;
    if(left.compare(right) == 0){
        if(size > maxsize){
            maxsize = size;
            maxNode = root;
        }
    }
    str.append("|").append(left).append("|");
    str.append("|").append(to_string(root->data)).append("|");
    str.append("|").append(right).append("|");
    return size;
}

int largestSubtree(Node * root, Node *& maxNode){
    int maxsize = 0;
    string str = "";
    lutil(root, str, maxsize, maxNode);
    return maxsize;
}

/* Driver program to test above functions*/
int main() 
{ 
	/* Let us construct the following Tree 
              50 
			/	 \ 
			10	 60 
			/ \	 / \ 
			5 20 70 70 
				/ \ / \ 
				65 80 65 80 */
	Node* root = newNode(50); 
	root->left = newNode(10); 
	root->right = newNode(60); 
	root->left->left = newNode(5); 
	root->left->right = newNode(20); 
	root->right->left = newNode(70); 
	root->right->left->left = newNode(65); 
	root->right->left->right = newNode(80); 
	root->right->right = newNode(70); 
	root->right->right->left = newNode(65); 
	root->right->right->right = newNode(80); 

	Node *maxNode = NULL; 
	int maxSize = largestSubtree(root, maxNode); 

	cout << "Largest Subtree is rooted at node "
		<< maxNode->data << "\nand its size is "
		<< maxSize; 

	return 0; 
}

