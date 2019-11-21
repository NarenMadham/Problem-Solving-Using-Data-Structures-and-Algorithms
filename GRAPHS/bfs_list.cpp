
#include<bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> adj[], bool vis[])
{
    // Your code here
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        cout<<temp<<" ";
        vis[temp] = true;
        vector<int> v = adj[temp];
        vector<int> :: iterator it;
        for(it = v.begin(); it != v.end();it++){
            if(!vis[*it]){
                q.push(*it);
                vis[*it] = true;
            }
        }
        
    }
}
//Position this line where user code will be pasted.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        
        int N, E;
        cin>>N>>E;
        vector<int> adj[N];
        bool vis[N];
        for(int i=0;i<N;i++)
            vis[i] = false;
        for(int i=0;i<E;i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        
        bfs(0, adj, vis);
        cout<<endl;
    }
}

/*This is a function problem.You only need to complete the function given below*/
/* You have to complete this function*/
/* Function to do BFS of graph
*  adj[]: array of vectors
*  vis[]: array to keep track of visited nodes
*/
