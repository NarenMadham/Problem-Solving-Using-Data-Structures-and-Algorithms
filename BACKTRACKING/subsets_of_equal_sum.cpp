#include<bits/stdc++.h>
using namespace std;

void sutil(int arr[], int temp[], int index, int pos, int s, int S, int n){
    if(s == S){
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(arr[i]);
        }
        for(int i=0;i<pos; i++){
            cout<<temp[i]<<" ";
            st.erase(temp[i]);
        }
        cout<<endl;
        set<int> :: iterator it;
        for(it = st.begin(); it!= st.end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
        return;
    }
    if(s > S || index == n){
        return;
    }
    sutil(arr, temp, index+1, pos, s, S, n);
    temp[pos] = arr[index];
    sutil(arr, temp, index+1, pos+1, s + arr[index], S - arr[index], n);
    return;
}

void subset_sum(int arr[], int n){
    int temp[n];
    int s = 0;
    for(int i=0;i<n;i++){
        s += arr[i];
    }
    sutil(arr, temp, 0, 0, 0, s, n);
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    subset_sum(arr, n);
}


/*

4
2 4 10 12


*/