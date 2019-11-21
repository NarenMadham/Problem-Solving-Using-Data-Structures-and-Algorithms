#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int temp;
        int f = 0;
        for(int i=0;i<n;i++){
            temp = k - arr[i];
            unordered_set<int> s;
            for(int j=0;j<n;j++){
                if(i == j){
                    continue;
                }
                if(s.find(temp - arr[j]) == s.end()){
                    s.insert(arr[j]);
                }else{
                    f = 1;
                    cout<<1<<endl;
                    break;
                }
            }
            if(f == 1){
                break;
            }
        }
        if(f == 0){
            cout<<0<<endl;   
        }
    }
    return 0;
}