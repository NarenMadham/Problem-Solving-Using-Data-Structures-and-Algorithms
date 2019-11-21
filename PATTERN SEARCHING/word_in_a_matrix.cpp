#include<bits/stdc++.h>
using namespace std;

int rownum[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int colnum[] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isValid(int rx, int ry, int m, int n, int px, int py){
    if(rx >= 0 && rx < m && ry >= 0 && ry < n && !(rx == px && ry == py)){
        return true;
    }
    return false;
}

void dfs(vector<vector<char> > mat, int x, int y, int px, int py, int m, int n, string word, string path, int pos, int l){
    if(pos > l || mat[x][y] != word[pos]) 
        return;
    path += string(1, word[pos]) + "(" + to_string(x) + ", " + to_string(y) + ")  ";
    //cout<<path<<endl;
    if(pos == l-1){
        cout<<path<<endl;
        return;
    }
    for(int k=0; k<8; k++){
        if(isValid(x + rownum[k], y + colnum[k], m, n, px, py)){
            dfs(mat, x + rownum[k], y + colnum[k], x, y, m, n, word, path, pos+1, l);
        }
    }
}

void find_occurances(int m, int n, string word, vector<vector<char> > mat){
    int l = word.length();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == word[0]){
                dfs(mat, i, j, -1, -1, m, n, word, "", 0, l);
            }
        }
    }
}

int main(){
    int m, n;
    cin>>m>>n;
    vector<vector<char> > mat;
    for(int i=0;i<m;i++){
        vector<char> temp;
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            temp.push_back(c);
        }
        mat.push_back(temp);
    }
    string t;
    cin>>t;
    /*for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<t<<endl;*/
    find_occurances(m, n, t, mat);
    
}