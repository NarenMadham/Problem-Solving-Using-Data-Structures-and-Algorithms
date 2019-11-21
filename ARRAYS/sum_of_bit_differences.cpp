#include<bits/stdc++.h>
using namespace std;

bool checkBit(int a, int i){
    return 1 & a>>i;
}

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
	    long long int s = 0;
        for(int i=0;i<32;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(checkBit(arr[j], i)){
                    count += 1;
                }
            }
            s  = (s + (count * (n - count) * 2)) % 1000000007;
            
        }
        
        cout<<s<<endl;
	}
	return 0;
}