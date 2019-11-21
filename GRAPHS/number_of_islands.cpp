#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.
int main() {
    
	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		vector<int> A[N];
		for(int i=0;i<N;i++){
		    vector<int> temp(M);
		    A[i] = temp;
		    for(int j=0;j<M;j++){
		        cin>>A[i][j];
		    }
		}
		cout<<findIslands(A,N,M)<<endl;
	}
	return 0;
}

bool isSafe(int i, int j, int n, int m, vector<int> A[], vector<vector<bool> > vis){
    if(i >= 0 && j >= 0 && i < n && j < m && A[i][j] == 1 && !vis[i][j])
        return true;
    return false;
}

int colnum[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int rownum[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void dfs(vector<int> A[], int n, int m, int i, int j, vector<vector<bool> >& vis){
    vis[i][j] = true;
    for(int x=0;x<8;x++){
        if(isSafe(i + rownum[x], j + colnum[x], n, m, A, vis))
            dfs(A, n, m, i + rownum[x], j + colnum[x], vis);    
    }
}

int findIslands(vector<int> A[], int n, int m){
    vector<vector<bool> > vis(n, vector<bool>(m, false));
    int islands = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(A[i][j] == 1){
                if(vis[i][j] == false){
                    dfs(A, n, m, i, j, vis);
                    islands++;
                }
            }
        }
    }
    return islands;
}