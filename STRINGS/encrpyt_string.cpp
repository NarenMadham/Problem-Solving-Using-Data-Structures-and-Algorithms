#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        char arr[1005] = {'\0'};
        scanf("%s", arr);
        vector<pair<char, int>  >v;
        int n = strlen(arr);
        int i = 0;
        while(arr[i] != '\0'){
            char c = arr[i];
            int d = 1;
            i += 1;
            while(i < n && arr[i] == arr[i-1]){
                d += 1;
                i += 1;
            }
            v.push_back({c, d});
        }
        reverse(v.begin(), v.end());
        vector<pair<char, int> > :: iterator it;
        for(it = v.begin(); it != v.end(); it++){
            int num = it->second;
            while(num){
                cout<<num%10;
                num/=10;
            }
            cout<<it->first;
        }
        cout<<endl;
    }
}