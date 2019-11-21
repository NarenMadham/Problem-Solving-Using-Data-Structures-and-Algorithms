#include<bits/stdc++.h>
using namespace std;
int min(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;   
    }
}

void constructTree(int arr[], int stree[],int l, int h, int pos){
    if(l == h){
        stree[pos] = arr[l];
        return;
    }
    int mid = (l + h)/2;
    int left = (2*pos) +1;
    int right = (2*pos) +2;
    constructTree(arr, stree, l, mid, left);
    constructTree(arr, stree, mid+1, h, right);
    stree[pos] = min(stree[left], stree[right]);
    return;
}

int minQuery(int stree[], int lazy[], int l, int h, int ql, int qh, int pos){
    int left = 2*pos + 1;
    int right = 2*pos + 2;
    if(lazy[pos] != 0){
        stree[pos] += lazy[pos];
        if(l != h){
            lazy[left] += lazy[pos];
            lazy[right] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(l > qh || h < ql){
        return INT_MAX;
    }
    if(l>= ql && h <=qh ){
        return stree[pos];
    }
    int mid = (l + h) / 2;
    return min(minQuery(stree, lazy, l, mid, ql, qh, left), minQuery(stree, lazy, mid+1, h, ql, qh, right));
}

void update(int stree[], int lazy[], int low, int high, int pos, int ql, int qh, int delta){
    if(low > high){
        return;
    }
    //cout<<"low : "<<low<<", high : "<<high<<endl;
    int left = (2*pos) + 1;
    int right = (2*pos) + 2;
    if(lazy[pos] != 0){
        stree[pos] += lazy[pos];
        if(low != high){
            lazy[left] += lazy[pos];
            lazy[right] += lazy[pos];
        }
        lazy[pos] = 0;
    }
    if(high < ql || low > qh){
        return;
    }
    if(ql <= low && qh >= high){
        stree[pos] += delta;
        if(low != high){
            lazy[left] += delta;
            lazy[right] += delta;
        }
        return;
    }
    int mid = low + (high - low) / 2;
    update(stree, lazy, low, mid, left, ql, qh, delta);
    update(stree, lazy, mid+1, high, right, ql, qh, delta);
    stree[pos] = min(stree[left], stree[right]);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int size = 1;
    while(n > size){
        size *= 2;
    }
    size = (2 * size) -1;
    int stree[size], lazy[size];
    for(int i=0;i<size;i++){
        stree[i] = INT_MAX;
        lazy[i] = 0;
    }
    constructTree(arr, stree, 0, n-1, 0);
    /*for(int i=0;i<size;i++){
        if(stree[i] != INT_MAX)
            cout<<stree[i] << " ";
    }*/
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int opt, a, b;
        cin>>opt;
        if(opt == 1){
            int delta;
            cin>>a>>b>>delta;
            update(stree, lazy, 0, n-1, 0, a, b, delta);
        }else{
            cin>>a>>b;
            cout<<minQuery(stree,lazy, 0, n-1, a, b, 0)<<endl;    
        }
    }
    for(int i=0;i<size;i++){
        if(stree[i] != INT_MAX)
            cout<<stree[i] << " ";
    }
    return 0;
}


/*

5
-1 2 5 -3 6
4
1 0 3 3
1 0 3 1
1 0 0 2
0 2 4

*/