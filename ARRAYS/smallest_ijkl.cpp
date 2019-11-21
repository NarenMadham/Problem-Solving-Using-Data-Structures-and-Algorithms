/*

FOR EACH OPERATION... GET THE MAXIMUM WE CAN DO TILL THAT POINT

T1 FOR A[L]
T2 FOR A[L] - A[K]
T3 FOR A[L] - A[K] + A[J]
T4 FOR A[L] - A[K] + A[J] - A[I]

SINCE WE TRAVERSE FROM RIGHT TO LEFT, THE FIRST ELEMENT OF T4 WILL HAVE THE RESULT

*/

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
	    vector<int> t1(n+1, INT_MIN);
	    vector<int> t2(n, INT_MIN);
	    vector<int> t3(n-1, INT_MIN);
	    vector<int> t4(n-2, INT_MIN);
	    for(int i = n-1;i>=0;i--){
	        t1[i] = max(t1[i+1], arr[i]);
	    }
	    for(int i = n-2; i>=0; i--){
	        t2[i] = max(t2[i+1], t1[i+1] - arr[i]);
	    }
	    for(int i = n-3; i>=0; i--){
	        t3[i] = max(t3[i+1], t2[i+1] + arr[i]);
	    }
	    for(int i = n-4; i>=0; i--){
	        t4[i] = max(t4[i+1], t3[i+1] - arr[i]);
	    }
	    cout<<t4[0]<<endl;
	}
	return 0;
}