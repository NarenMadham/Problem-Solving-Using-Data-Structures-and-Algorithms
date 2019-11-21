#include<bits/stdc++.h>
#define n 9
using namespace std;

bool findFreeSpace(int arr[n][n], int &row, int &col){
    for(row=0;row<n;row++){
        for(col=0;col<n;col++){
            if(arr[row][col] == 0){
                return true;
            }
        }   
    }
    return false;
}

bool rowSafe(int arr[n][n], int row, int num){
    for(int i=0;i<n;i++){
        if(arr[row][i] == num){
            return true;
        }
    }
    return false;
}

bool colSafe(int arr[n][n], int col, int num){
    for(int i=0;i<n;i++){
        if(arr[i][col] == num){
            return true;
        }
    }
    return false;
}

bool boxSafe(int arr[n][n], int row, int col, int num){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(arr[i+row][j+col] == num){
                return true;
            }
        }
    }
    return false;
}

bool isSafe(int arr[n][n], int row, int col, int num){
    return (arr[row][col] == 0 && !rowSafe(arr, row, num) && !colSafe(arr, col, num) && !boxSafe(arr, row-row%3, col-col%3, num));
}

bool solveSudoku(int arr[n][n]){
    int row, col;
    if(!findFreeSpace(arr, row, col)){
        return true;
    }
    
    for(int i=1;i<=9;i++){
        if(isSafe(arr, row, col, i)){
            arr[row][col] = i;
            if(solveSudoku(arr)){
                return true;
            }
            arr[row][col] = 0;
        }
    }
    return false;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    int arr[n][n];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            cin>>arr[i][j];
	        }
	    }
	    if(solveSudoku(arr) == true){
	        for(int i=0;i<n;i++){
	            for(int j=0;j<n;j++){
	                cout<<arr[i][j]<<" ";
	            }
	            cout<<endl;
	        }
	    }else{
            cout<<"not possible"<<endl;
        }
	}
	return 0;
}



/*

1
3 0 6 5 0 8 4 0 0
5 2 0 0 0 0 0 0 0
0 8 7 0 0 0 0 3 1
0 0 3 0 1 0 0 8 0
9 0 0 8 6 3 0 0 5
0 5 0 0 9 0 6 0 0
1 3 0 0 0 0 2 5 0
0 0 0 0 0 0 0 7 4
0 0 5 2 0 6 3 0 0

*/