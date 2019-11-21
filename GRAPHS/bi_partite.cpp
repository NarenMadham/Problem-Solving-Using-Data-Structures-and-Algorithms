{
// C++ program to find out whether a given graph is Bipartite or not.
// It works for disconnected graph also.
#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
bool isBipartite(int G[][MAX],int V);
int main()
{
    int t;
	cin>>t;
	int g[MAX][MAX];
	while(t--)
	{
		memset(g,0,sizeof (g));
		int n;
		cin>>n;
	
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cin>>g[i][j];
			}
		}
		
		cout<<isBipartite(g,n)<<endl;
	}
	return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */

bool butil(int adj[][MAX], set<int>& vis, int v, int vertex, int color[]){
    vis.insert(vertex);
    for(int i=0;i<v;i++){
        if(adj[vertex][i] == 0){
            continue;
        }else{
            if(vis.find(i) == vis.end()){
                color[i] = 1 - color[vertex];
            }else{
                if(color[vertex] == color[i])
                    return false;
            }
        }
    }
    return true;
}

bool isBipartite(int adj[][MAX],int v){
    int color[v];
    memset(color, 0, sizeof(color));
    set<int> vis;
    for(int i=0;i<v;i++){
        if(vis.find(i) == vis.end()){
            if(!butil(adj, vis, v, i, color))
                return false;
        }
    }
    return true;
}