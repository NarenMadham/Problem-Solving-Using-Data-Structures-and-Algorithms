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
        stack<long long int> st;
        vector<long long int> v(n);
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
                continue;
            }
            if(arr[st.top()] > arr[i]){
                st.push(i);
                continue;
            }
            while(!st.empty() && arr[st.top()] < arr[i]){
                v[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            v[st.top()] = -1;
            st.pop();
        }
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
	return 0;
}