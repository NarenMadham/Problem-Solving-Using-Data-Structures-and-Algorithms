#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, s;
        cin>>n>>s;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        unordered_set<int> vis;
        int f = 0;
        for(int i=0;i<n;i++){
            if(vis.find(s - arr[i]) == vis.end()){
                vis.insert(arr[i]);
            }else{
                f = 1;
                break;
            }
        }
        if(f == 1){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
}