{
#include <bits/stdc++.h>
using namespace std;
#define MAX 100
vector<string> printPath(int m[MAX][MAX], int n);
int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
	int m[100][100];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>m[i][j];
		}
	}
	
	vector<string> res = printPath(m,n);
	for(int i=0;i<res.size();i++)
	cout<<res[i]<<" ";
	cout<<endl;
}
	return 0;
}

}

vector<string> res;

/*

USE A STRING INSTEAD OF CHARACTER ARRAY! 

*/

void putil(int m[MAX][MAX], string temp, int pos, int i, int j, int n){
    if(i >= n || i < 0) return;
    if(j >= n || j < 0) return;
    if(m[i][j] == 0 || m[i][j] == 2){
        return;
    }
    if(i == n-1 && j == n-1){
        res.push_back(temp);
        return;
    }
    else{
        m[i][j] = 2;
        
        putil(m, temp+'D', pos+1, i+1, j, n);
        
        putil(m, temp+'U', pos+1, i-1, j, n);
        
        putil(m, temp+'R', pos+1, i, j+1, n);
        
        putil(m, temp+'L', pos+1, i, j-1, n);
        
        m[i][j] = 1;//IMPORTANT
    }
}

vector<string> printPath(int m[MAX][MAX], int n){
    res.clear();
    putil(m, "", 0, 0, 0, n);
    sort(res.begin(), res.end());
    return res;
}