#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[2][n];
	    for(int i=0;i<2;i++){
	        for(int j=0;j<n;j++){
	            cin>>arr[i][j];
	        }
	    }
	    int in = max(arr[0][0], arr[1][0]);
	    int e = 0;
	    int en;
	    for(int i=1;i<n;i++){
	        en = max(in, e);
	        in = e + max(arr[0][i], arr[1][i]);
	        e = en;
	    }
	    cout<<max(e, in)<<endl;
	}
	return 0;
}