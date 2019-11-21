#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    priority_queue<int, vector<int>, greater<int> > pq;
	    long long int total_count = 0;
	    for(int i=0;i<n;i++){
	        int temp;
	        cin>>temp;
	        pq.push(temp);
	    }
	    while(pq.size() != 1){
	        int a = pq.top();
	        pq.pop();
	        int b = pq.top();
	        pq.pop();
            int temp = a + b;
            total_count += temp;
            pq.push(temp);
	    }
	    cout<<total_count<<endl;
	    
	}
	return 0;
}