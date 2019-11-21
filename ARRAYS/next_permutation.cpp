#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr;
	    for(int i=0;i<n;i++){
	        int temp;
	        cin>>temp;
	        arr.push_back(temp);
	    }
	    int f = 0;
	    int i = n-1;
	    int j = n-1;
	    while(i >= 1){
	        if(arr[i] < arr[i-1]){
	            i--;
	        }else{
	            i -= 1;
	            while(arr[j] < arr[i]){
	                j--;
	            }
	            break;
	        }
	    }
	    int temp = arr[i];
	    arr[i] = arr[j];
	    arr[j] = temp;
	    sort(arr.begin()+i+1, arr.begin() + n);
	    for(int i=0;i<n;i++){
	        cout<<arr[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}