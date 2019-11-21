#include<bits/stdc++.h>
using namespace std;

set<long long int> res;

void bfs(long long int n, long long int i){
    queue<long long int> q;
    q.push(i);
    while(!q.empty()){
        long long int temp = q.front();
        q.pop();
        if(temp <= n)
            res.insert(temp);
        int ld = temp % 10;
        if(ld == 0){
            if(temp * 10 + (ld + 1) <= n){
                q.push(temp * 10 + (ld + 1));
            }
        }else if(ld == 9){
            if(temp * 10 + (ld - 1) <= n){
                q.push(temp * 10 + (ld - 1));
            }
        }else{
            if(temp * 10 + (ld - 1) <= n){
                q.push(temp * 10 + (ld - 1));
            }
            if(temp * 10 + (ld + 1) <= n){
                q.push(temp * 10 + (ld + 1));
            }
        }
    }
}

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    for(int i=0;i<=9;i++){
	        if(i <= n)
	            bfs(n, i);
	    }
	    set<long long int> :: iterator it;
	    for(it = res.begin(); it != res.end(); it++){
	        if(*it < n)
	            cout<<*it<<" ";
	    }
	    res.clear();
	    cout<<endl;
	}
	return 0;
}