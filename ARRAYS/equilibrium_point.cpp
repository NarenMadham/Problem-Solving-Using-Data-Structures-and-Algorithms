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
        int f = 0;
        int pre[n];
        int suf[n];
        pre[0] = arr[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + arr[i];
        }
        suf[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i] = suf[i+1] + arr[i];
        }
        for(int i=n-1;i>=0;i--){
            if(pre[i] == suf[i]){
                f = 1;
                cout<<i+1<<endl;
            }
        }
        if(f == 0){
            cout<<-1<<endl;
        }
    }
    return 0;
}