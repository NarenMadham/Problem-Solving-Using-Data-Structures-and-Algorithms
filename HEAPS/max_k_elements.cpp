#include<bits/stdc++.h>
using namespace std;

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

class Heap{
public:
    int hs;
    int * harr;
    int cap;
public:
    Heap(int cap){
        this->cap = cap;
        harr = new int[cap];
        hs = 0;
    }
    int left(int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }
    int parent(int i){
        return (i-1)/2;
    }
    void push(int k);
    int pop();
    int top();
    void decreaseKey(int i, int k);
    void deleteKey(int i);
    void heapify(int i);
};

void Heap ::  push(int k){
    if(hs == cap){
        cout<<"Overflow"<<endl;
        return;
    }
    hs++;
    int i = hs - 1;
    harr[i] = k;
    while(i != 0 && harr[i] > harr[parent(i)]){
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int Heap :: top(){
    return harr[0];
}

void Heap :: deleteKey(int i){
    if(i > hs){
        cout<<"invalid index"<<endl;
    }
    decreaseKey(i, INT_MIN);
    pop();
}

void Heap :: decreaseKey(int i, int k){
    if(i> hs){
        cout<<"Invalid Index"<<endl;
        return;
    }
    harr[i] = k;
    while(i != 0 && harr[i] > harr[parent(i)]){
        swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}

int Heap :: pop(){
    int root = harr[0];
    hs -= 1;
    harr[0] = harr[hs-1];
    heapify(0);
    return root;
}

void Heap :: heapify(int i){
    int l = left(i);
    int r =  right(i);
    int s = i;
    if(l < hs && harr[l] > harr[i]){
        s = l;
    }
    if(r < hs && harr[r] > harr[s]){
        s = r;
    }
    if(s != i){
        swap(&harr[i], &harr[s]);
        heapify(s);
    }
}

int main(){
    int n, k;
    cin>>n>>k;
    Heap *h = new Heap(n); 
	for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        h->push(temp);
    }
    for(int i=0;i<h->hs;i++){
        cout<<h->harr[i]<<" ";
    }
    cout<<endl;
	
    for(int i=0;i<k;i++){
        cout<<h->top()<<" ";
        h->pop();
    }
    cout<<endl;
    return 0; 
}


/*

10 4
6 8 2 1 3 12 5 9 4 15

*/