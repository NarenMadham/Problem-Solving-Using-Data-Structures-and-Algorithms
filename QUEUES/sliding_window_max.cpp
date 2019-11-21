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
	    deque<int> d;
	    for(int i=0;i<k;i++){
	        if(d.empty()){
	            d.push_front(i);
	        }else{
	            while(!d.empty() && arr[d.back()] < arr[i]){
	                d.pop_back();
	            }
	            d.push_back(i);
	        }
	    }
	    cout<<arr[d.front()]<<" ";
	    for(int i = k; i < n;i++){
	        if(i - d.front() >= k){
	            d.pop_front();
	        }
	        while(!d.empty() && arr[d.back()] < arr[i]){
	            d.pop_back();
	        }
	        d.push_back(i);
	        cout<<arr[d.front()]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}