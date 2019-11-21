#include<bits/stdc++.h>
using namespace std;

const int num = 26;

void dfs(map<int, vector<int> > adj, vector<bool> &vis, int start){
    vis[start] = true;
    vector<int> :: iterator it;
    for(it = adj[start].begin(); it!= adj[start].end(); it++){
        if(!vis[*it]){
            dfs(adj, vis, *it);
        }
    }
}

bool isConnected(map<int, vector<int> > adj, vector<bool> mark, int n, int start){
    vector<bool> vis(num, false);
    dfs(adj, vis, start);
    for(int i=0;i<num;i++){
        if(mark[i] && !vis[i]){
            return false;
        }
    }
    return true;
}

bool circle (string arr[], int n){
    map<int, vector<int> > adj;
    vector<bool> mark(num, false);
    vector<int> in(num, 0);
    vector<int> out(num,0);
    for(int i=0;i<n;i++){
        int f = arr[i].front() - 'a';
        int l = arr[i].back() - 'a';
        mark[f] = true;
        mark[l] = true;
        in[l] += 1;
        out[f] += 1;
        adj[f].push_back(l);
    }
    for(int i=0;i<num;i++){
        if(in[i] != out[i]){
            return false;
        }
    }
    int temp = arr[0].front() - 'a';
    return isConnected(adj, mark, n, temp);
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    string arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    if(circle(arr, n)){
	        cout<<1<<endl;
	    }else{
	        cout<<0<<endl;
	    }
	}
	return 0;
}