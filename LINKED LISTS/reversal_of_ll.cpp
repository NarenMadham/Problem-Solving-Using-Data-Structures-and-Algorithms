/*

USING STACK

*/

#include<stack>

Node* reverseList(Node *head){
    
    Node * curr = head;
    stack<Node *> st;
    while(curr != NULL){
        st.push(curr);
        curr = curr->next;
    }
    head = st.top();
    while(!st.empty()){
        Node * temp = st.top();
        st.pop();
        if(!st.empty()){
            temp->next = st.top();
        }else{
            temp->next = NULL;
        }
    }
    return head;
}

/*

USING RECURSION

*/


Node* reverseList(Node *head){
    if(head == NULL || head->next == NULL) return head;
    Node * tempHead = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return tempHead;
}



Node * reverse(Node *head, reversed = NULL){
    if(!head) return reversed;
    Node * x = head->next;
    head->next = reversed;
    return reverse(x, head);
}