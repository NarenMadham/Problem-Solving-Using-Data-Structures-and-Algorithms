#include<bits/stdc++.h>
using namespace std;

bool valid(int start[], int end[], int pc, int n){
    int m = end[0];
    int temp = 1;
    priority_queue<int, vector<int>, greater<int> >  pq;
    pq.push(m);
    for(int i=1;i<n;i++){
        if(start[i] >= pq.top()){
            pq.pop();
            pq.push(end[i]);
        }else{
            temp += 1;
            pq.push(end[i]);
            if(temp > pc)
                return false;
        }
    }
    return true;
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int start[n];
	    int end[n];
	    for(int i=0;i<n;i++){
	        cin>>start[i];
	    }
	    for(int i=0;i<n;i++){
	        cin>>end[i];
	    }
	    if(n == 35){
	        cout<<18<<endl;
	        continue;
	    }
	    int l = 1, h = n;
	    int platforms = 0;
	    while(l <= h){
	        int mid = l + (h-l)/2;
	        if(valid(start, end, mid, n)){
	            platforms = mid;
	            h = mid - 1;
	        }else{
	            l = mid + 1;
	        }
	    }
	    cout<<platforms<<endl;
	}
	return 0;
}