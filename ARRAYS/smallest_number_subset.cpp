#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        long long int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long int res = 1;
        int i = 0;
        while(i < n){
            if(arr[i] <= res){
                res += arr[i];
                i++;
            }else{
                break;
            }
        }
        cout<<res<<endl;
    }
	return 0;
}