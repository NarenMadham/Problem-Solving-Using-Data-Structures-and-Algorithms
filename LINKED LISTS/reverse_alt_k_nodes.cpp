#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node * next;
};

void reverse(Node * start, Node * end, Node *term){
    stack<int> st;
    Node *curr = start;
    while(curr != term){
        st.push(curr->data);
        curr = curr->next;
    }
    curr = start;
    while(!st.empty()){
        curr->data = st.top();
        st.pop();
        curr = curr->next;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        Node *head = NULL;
        Node * curr = NULL;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            Node * newNode = new Node();
            newNode->data = temp;
            newNode->next = NULL;
            if(head == NULL){
                head = newNode;
                curr = newNode;
                continue;
            }
            curr->next = newNode;
            curr = newNode;
        }
        Node * start = head;
        Node * end = head;
        bool r = true;
        curr = head;
        while(1){
            int i = 1;
            while(i < k){
                if(end == NULL){
                    break;
                }
                end = end->next;
                i += 1;
            }
            if(r == true){
                if(end != NULL){
                    reverse(start, end, end->next);
                    r = false;
                }else{
                    break;
                }
            }else{
                r = true;
            }
            if(end == NULL){
                break;
            }
            start = end->next;
            end = start;
        }
        curr = head;
        while(curr != NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
}

/*

1
9 5
1 2 3 4 5 6 7 8 9

*/
