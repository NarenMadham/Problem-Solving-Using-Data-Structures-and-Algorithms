#include<bits/stdc++.h>
using namespace std;

void zigzag(char a[], int n){
    if(n==1){
        cout<<a<<endl;
        return;
    }
    map<int, vector<char> > mp;
        bool dir = true;
        int level = 1;
        int length = strlen(a);
        for(int i=0;i<length;i++){
            mp[level].push_back(a[i]);
            if(dir){
                level += 1;
            }else{
                level -= 1;
            }
            if(level == n+1){
                dir = false;
                level -= 2;
            }else if(level == 0){
                dir = true;
                level += 2;
            }
        }
        map<int, vector<char> > :: iterator it;
        for(it = mp.begin(); it!= mp.end(); it++){
            vector<char> :: iterator vit;
            for(vit = it->second.begin(); vit != it->second.end(); vit++){
                cout<<*vit;
            }
        }
        cout<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        char a[10004] = {'\0'};
        int n;
        scanf("%s", a);
        cin>>n;
        zigzag(a, n);
    }
	return 0;
}