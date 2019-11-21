#include<bits/stdc++.h>
using namespace std;

swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

class MinHeap{
public:
    int * harr;
    int hs;
    int cap;
public:
    MinHeap(int cap){
        harr = new int[cap];
        hs = 0;
        this->cap = cap;
    }
    int left(int i){
        return 2*i + 1;
    }
    int right(int i){
        return 2*i + 2;
    }
    int parent(int i){
        return (i-1)/2;
    }
    int extractMin();
    void decreaseKey(int i, int nv);
    int top();
    void push(int k);
    void deleteKey(int i);
    void minHeapify(int i);
};

void MinHeap :: push(int k){
    if(hs == cap){
        cout<<"The heap is full!"<<endl;
        return;
    }
    hs += 1;
    int i = hs - 1;
    harr[i] = k;
    while(i != 0 && harr[parent(i)] > harr[i]){
        swap(&harr[parent(i)], &harr[i]);
        i = parent(i);
    }
}

void MinHeap ::  decreaseKey(int i, int k){
    harr[i] = k;
    while(i != 0 && harr[parent(i)] > harr[i]) {
        swap(&harr[parent(i)], &harr[i]);
        i = parent(i);
    }
}

void MinHeap :: deleteKey(int i){
    if(i >= hs){
        cout<<"Cannot be deleted! Overflow!"<<endl;
    }
    decreaseKey(i, INT_MIN);
    extractMin();
}

int MinHeap :: top(){
    return harr[0];
}

void MinHeap :: minHeapify(int i){
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if(l < hs && harr[l] < harr[i]){
        smallest = l;
    }
    if(r < hs && harr[r] < harr[smallest]){
        smallest = r;
    }
    if(smallest != i){
        swap(&harr[i], &harr[smallest]);
        minHeapify(smallest);
    }
}

int MinHeap :: extractMin(){
    if(hs == 0){
        cout<<"Heap is empty ! "<<endl;
        return INT_MAX;
    }
    int root = harr[0];
    harr[0] = harr[hs-1];
    hs--;
    minHeapify(0);
    return root;
}

int main(){
    MinHeap *h = new MinHeap(11); 
	h->push(3); 
	h->push(2); 
	h->deleteKey(1); 
	h->push(15); 
	h->push(5); 
	h->push(4); 
	h->push(45); 
    for(int i=0;i<h->hs;i++){
        cout<<h->harr[i]<<" ";
    }
    cout<<endl;
	cout << h->extractMin() << " "; 
	cout << h->top() << " "; 
	h->decreaseKey(2, 1); 
	cout << h->top(); 
	return 0; 
}