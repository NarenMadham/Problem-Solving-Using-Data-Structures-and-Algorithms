#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n1, n2, n3;
	    cin>>n1>>n2>>n3;
	    long long int a[n1], b[n2], c[n3];
	    for(int i=0;i<n1;i++){
	        cin>>a[i];
	    }
	    for(int i=0;i<n2;i++){
	        cin>>b[i];
	    }
	    for(int i=0;i<n3;i++){
	        cin>>c[i];
	    }
	    int i = 0, j = 0, k = 0;
	    int f = 0;
	    long long int prev = -1;
	    while(i < n1 && j < n2 && k < n3){
	        if(a[i] == b[j] && b[j] == c[k] && a[i] != prev){
	            f = 1;
	            cout<<a[i]<<" ";
	            prev = a[i];
	            i += 1;
	            j += 1;
	            k += 1;
	        }else if(a[i] < b[j]){
	            i += 1;   
	        }else if(b[j] < c[k]){
	            j += 1;
	        }else{
	            k += 1;
	        }
	    }
	    if(f == 0){
	        cout<<-1;
	    }
	    cout<<endl;
	}
	return 0;
}