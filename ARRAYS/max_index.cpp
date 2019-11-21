#include<bits/stdc++.h>
using namespace std;

int min(int a, int b){
    if(a < b){
        return a;
    }else{
        return b;
    }
}

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n == 1){
            cout<<0<<endl;
            continue;
        }
        int pre[n], suf[n];
        pre[0] = arr[0];
        for(int i=1;i<n;i++){
            pre[i] = min(arr[i], pre[i-1]);
        }
        suf[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            suf[i] = max(suf[i+1], arr[i]);
        }
        int i = 0, j = 0, max_diff = -1;
        while(i < n && j < n){
            if(pre[i] <= suf[j]){
                max_diff = max(max_diff, j-i);
                j += 1;
            }else{
                i += 1;
            }
        }
        cout<<max_diff<<endl;
    }
}