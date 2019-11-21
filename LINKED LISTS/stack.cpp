#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node * next;
public:
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

class Stack{
public:
    Node * head;
    Node * top;
    Node * min;
public:
    Stack(){
        this->head = NULL;
        this->top = NULL;
        this->min = NULL;
    }
    bool isEmpty();
    void push(int data);
    void pop();
    int top_element();
    void print();
    int getMin();
};

int Stack :: getMin(){
    return this->min->data;
}

bool Stack :: isEmpty(){
    if(Stack::head == NULL){
        return true;
    }
    return false;
}

void Stack :: push(int data){
    Node * node = new Node(data);
    if(Stack::isEmpty()){
        head = node;
        top = node;
        min = node;
        return;
    }
    top->next = node;
    top = top->next;
    if(top->data <= min->data){
        min = top;
    }
}

int Stack :: top_element(){
    return this->top->data;
}

void Stack ::  pop(){
    if(head == top){
        Node * temp = head;
        head = NULL;
        top = NULL;
        free(temp);
        return;
    }
    Node * curr = this->head;
    if(top == min){
        min->data = head->data;
    }
    while(curr->next != top){
        curr = curr->next;
        if(curr->data < min->data){
            min = curr;
        }
    }
    Node * temp = top;
    top = curr;
    free(temp);
    top->next = NULL;
}

void Stack :: print(){
    if(this->head == NULL){
        cout<<"The stack is empty"<<endl;
        return;
    }
    Node *curr = this->head;
    while(curr != NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

int main(){
    Stack *st = new Stack();
    cout<<st->isEmpty()<<endl;
    st->push(40);
    st->push(70);
    st->push(10);
    st->push(5);
    st->push(30);
    st->push(60);
    st->push(20);
    st->push(80);
    st->print();
    st->pop();
    st->pop();
    st->print();
    cout<<st->top_element()<<endl;
        st->print();
    cout<<"Min Element : "<<st->getMin()<<endl;
    st->pop();
    st->pop();
    st->pop();
    cout<<"Min Element : "<<st->getMin()<<endl;
    st->print();
}