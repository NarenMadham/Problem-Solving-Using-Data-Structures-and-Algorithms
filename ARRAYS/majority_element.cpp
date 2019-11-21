/*using count array!*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int max = INT_MIN;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(max < arr[i]){
                max = arr[i];
            }
        }
        vector<int> count(max+1, 0);
        for(int i=0;i<n;i++){
            count[arr[i]] += 1;
        }
        int mid = n/2;
        int f = 0;
        for(int i=0;i<=max;i++){
            if(count[i] > mid){
                f = 1;
                cout<<(i)<<endl;
                break;
            }
        }
        if(f == 0){
            cout<<-1<<endl;
        }
    }
	return 0;
}