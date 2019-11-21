{
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int v, e;
	    cin >> v >> e;
	    
	    vector<int> adj[v];
	    
	    for(int i =0;i<e;i++){
	        int u, v;
	        cin >> u >> v;
	        adj[u].push_back(v);
	    }
	    
	    cout << isCyclic(v, adj) << endl;
	    
	}
	
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*  Function to check if the given graph contains cycle
*   V: number of vertices
*   adj[]: representation of graph
*/

void dfs(vector<int> adj[], int curr, set<int>& g, set<int>& b, bool& cycle){
    g.insert(curr);
    for(int i=0;i<adj[curr].size(); i++){
        int temp = adj[curr][i];
        if(b.find(temp) != b.end())
            continue;
        if(g.find(temp) == g.end()){
            dfs(adj, temp, g, b, cycle);
        }
        else{
            cycle = true;
            return;
        }
    }
    b.insert(curr);
}

bool isCyclic(int V, vector<int> adj[]){
    set<int> g;
    set<int> b;
    bool cycle = false;
    for(int i=0;i<V;i++){
        if(b.find(i) == b.end()){
            dfs(adj, i, g, b, cycle);
        }
        if(cycle)
            break;
    }
    return cycle;
}