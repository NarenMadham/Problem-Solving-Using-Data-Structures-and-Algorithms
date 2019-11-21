#include<bits/stdc++.h>
#define maxheap priority_queue<int>
#define minheap priority_queue<int, vector<int>, greater<int> >
using namespace std;

void addElement(int k, maxheap& lower, minheap& higher){
    if(lower.size() == 0 || k < higher.top()){
        lower.push(k);
    }else{
        higher.push(k);
    }
}

void rebalance(maxheap& lower, minheap& higher){
    if(lower.size() <= higher.size()){
        maxheap smaller = lower;
        minheap bigger = higher;
        if(bigger.size() - smaller.size() >= 2){
            int temp = bigger.top();
            bigger.pop();
            smaller.push(temp);
        }
    }else{
        minheap smaller = higher;
        maxheap bigger = lower;
        if(bigger.size() - smaller.size() >= 2){
            int temp = bigger.top();
            bigger.pop();
            smaller.push(temp);
        }
    }
}

double getMedian(maxheap& lower, minheap& higher){
    if(lower.size() < higher.size()){
        maxheap smaller = lower;
        minheap bigger = higher;
        if(smaller.size() == bigger.size()){
            int a = smaller.top();
            int b = bigger.top();
            return (double)((a + b)/2);
        }else{
            return bigger.top();
        }
    }else{
        minheap smaller = higher;
        maxheap bigger = lower;
        if(smaller.size() == bigger.size()){
            int a = smaller.top();
            int b = bigger.top();
            return (double)((a + b)/2);
        }else{
            return bigger.top();
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    maxheap lower;
    minheap higher;
    for(int i=0;i<n;i++){
        addElement(arr[i], lower, higher);
        rebalance(lower, higher);
        cout<<getMedian(lower, higher)<<" ";
    }
}

/*

5
5 15 10 20 3

*/
