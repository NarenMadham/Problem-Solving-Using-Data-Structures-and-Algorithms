/*This is a function problem.You only need to complete the function given below*/

/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
   #include<bits/stdc++.h>
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_set<Node*> s;
    Node *t1 = head1;
    while(t1 != NULL){
        s.insert(t1);
        t1 = t1->next;
    }
    Node * t2 = head2;
    int f = 0;
    while(t2 != NULL){
        if(s.find(t2) == s.end()){
            t2 = t2->next;
            continue;
        }
        else{
            f = 1;
            return t2->data;
        }
    }
    if(f == 0){
        return -1;
    }
}