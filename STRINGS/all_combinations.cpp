#include<bits/stdc++.h>
using namespace std;

void all_combinations(map<int, string> mp, int arr[], int i, int n, char res[]){
    if(i == n){
        for(int j=0;j<n;j++){
            cout<<res[j];
        }
        cout<<endl;
        return;
    }
    string s = mp[arr[i]];
    int l = s.length();
    for(int j=0;j<l;j++){
        res[i] = s[j];
        all_combinations(mp, arr, i+1, n, res);
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int, string> mp;
    mp[1] = "1";
    mp[2] = "ABC";
    mp[3] = "DEF";
    mp[4] = "GHI";
    mp[5] = "JKL";
    mp[6] = "MNO";
    mp[7] = "PQRS";
    mp[8] = "TUV";
    mp[9] = "WXYZ";
    char res[10];
    all_combinations(mp, arr, 0, n, res);
}


/*

2
2 3

*/