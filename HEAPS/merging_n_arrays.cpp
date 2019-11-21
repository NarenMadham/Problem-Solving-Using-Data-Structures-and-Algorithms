#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    int i;
    int j;
};

void swap(Node * a, Node * b){
    Node temp = *a;
    *a = *b;
    *b = temp;
}

class Heap{
public:
    Node * harr;
    int hs;
public:
    Heap(Node a[], int cap);
    int left(int i){
        return 2 * i + 1;
    }
    int right(int i){
        return 2 * i + 2;
    }
    int parent(int i){
        return (i-1)/2;
    }
    void replaceMin(Node n);
    void heapify(int i);
    Node top(){
        return harr[0];
    }
};

void Heap :: heapify(int i){
    int l = left(i);
    int r = right(i);
    int s = i;
    if(l < hs && harr[l].data < harr[i].data){
        s = l;
    }
    if(r < hs && harr[r].data < harr[s].data){
        s = r;
    }
    if(s != i){
        swap(&harr[i], &harr[s]);
        heapify(s);
    }
}

Heap :: Heap(Node a[], int cap){
    harr = a;
    hs = cap;
    int i = (hs-1)/2;
    while(i >= 0){
        heapify(i);
        i -= 1;
    }
}

void Heap :: replaceMin(Node n){
    harr[0] = n;
    heapify(0);
}

int main(){
    int m, n;
    cin>>m>>n;
    int arr[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    int * out = new int[n*m];//mistake!
    Node *nodes = new Node[m];//mistake!
    for(int i=0;i<m;i++){
        nodes[i].data = arr[i][0];
        nodes[i].i = i;
        nodes[i].j = 1;
    }
    Heap h(nodes, m);
    int pos = 0;
    for(int i=0;i<n*m;i++){
        Node temp = h.top();
        out[pos] = temp.data;
        pos++;
        if(temp.j < n){
            temp.data = arr[temp.i][temp.j];
            temp.j += 1;
        }else{
            temp.data = INT_MAX;
        }
        h.replaceMin(temp);
    }

    for(int i=0;i<n*m;i++){
        cout<<out[i]<<" ";
    }
    cout<<endl;
}

/*

3 4
1 3 5 7
2 4 6 8
0 9 10 11

*/