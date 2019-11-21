
/*This is a function problem.You only need to complete the function given below*/
/* This function is used to detect a cycle in undirected graph
*  adj[]: array of vectors to represent graph
*  V: number of vertices
*/

void dfs(vector<int> adj[], int curr, int parent, set<int>& vis, bool& cycle){
    vis.insert(curr);
    for(int i=0;i<adj[curr].size(); i++){
        //cout<<curr<<" : "<<adj[curr][i]<<endl;
        if(adj[curr][i] == parent){
            continue;
        }else{
            if(vis.find(adj[curr][i]) == vis.end()){
                dfs(adj, adj[curr][i], curr, vis, cycle);
            }else{
                cycle = true;
                return;
            }
        }
    }
}

bool isCyclic(vector<int> adj[], int V){
    set<int> vis;
    bool cycle = false;
    for(int i=0;i<V;i++){
        if(vis.find(i) == vis.end())
            dfs(adj, i, -1, vis, cycle);
        if(cycle)
            break;
    }
    return cycle;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int V, E;
        cin>>V>>E;
        
        // array of vectors to represent graph
        vector<int> adj[V];
        
        int u, v;
        for(int i=0;i<E;i++)
        {
            cin>>u>>v;
            
            // adding edge to the graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        cout << isCyclic(adj, V)<<endl;

    }
}