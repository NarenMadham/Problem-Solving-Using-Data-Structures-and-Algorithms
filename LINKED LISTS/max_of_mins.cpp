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
	    vector<int> rmin(n, n);
	    vector<int> lmin(n, -1);
	    stack<int> str;
	    stack<int> stl;
	    for(int i=0;i<n;i++){
	        if(str.empty()){
	            str.push(i);
	            continue;
	        }
	        if(!str.empty() &&  arr[str.top()] < arr[i]){
	            str.push(i);
	            continue;
	        }
	        while(!str.empty() && arr[str.top()] > arr[i]){
	            int temp = str.top();
	            str.pop();
	            rmin[temp] = i;
	        }
	        str.push(i);
	    }
	    while(!str.empty()){
	        int temp = str.top();
	        str.pop();
	        rmin[temp] = n;
	    }
	    for(int i = n-1; i >= 0; i--){
	        if(stl.empty()){
	            stl.push(i);
	            continue;
	        }
	        if(!stl.empty() && arr[stl.top()] < arr[i]){
	            stl.push(i);
	            continue;
	        }
	        while(!stl.empty() && arr[stl.top()] > arr[i]){
	            int temp = stl.top();
	            stl.pop();
	            lmin[temp] = i;
	        }
	        stl.push(i);
	    }
	    while(!stl.empty()){
	        int temp = stl.top();
            stl.pop();
            lmin[temp] = -1;
	    }
	    vector<int> wsize(n);
	    for(int i=0;i<n;i++){
            wsize[i] = rmin[i] - lmin[i] - 1;
	    }
	    vector<int> ans(n+1, 0);
	    for(int i=0;i<n;i++){
	        ans[wsize[i]] = max(ans[wsize[i]], arr[i]);
	    }
	    for(int i = n-1; i>=1;i--){
	        ans[i] = max(ans[i+1], ans[i]);
	    }
	    for(int i=1;i<=n;i++){
	        cout<<ans[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}