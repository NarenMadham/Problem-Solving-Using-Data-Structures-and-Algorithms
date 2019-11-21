#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n][n];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>arr[i][j];
	        }
	    }
	    for(int i=0;i<n/2;i++){
	        for(int j=i;j<n-i-1;j++){
	            int temp = arr[i][j];
	            arr[i][j] = arr[j][n-i-1];
	            arr[j][n-1-i] = arr[n-i-1][n-j-1];
	            arr[n-1-i][n-j-1] = arr[n-j-1][i];
	            arr[n-j-1][i] = temp;
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cout<<arr[i][j]<<" ";
	        }
	        cout<<endl;
	    }
	}
	return 0;
}