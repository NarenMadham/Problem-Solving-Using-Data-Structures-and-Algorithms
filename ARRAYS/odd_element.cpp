#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]] += 1;
        }
        int f = 0;
        for(auto i: mp){
            if(i.second % 2 == 0){
                continue;
            }else{
                f = 1;
                cout<<i.first<<endl;
                break;
            }
        }
        if(f == 0){
            cout<<0<<endl;
        }
    }
	return 0;
}