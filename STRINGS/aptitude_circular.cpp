#include<bits/stdc++.h>
using namespace std;

bool isCircular(char a[], int n){
    int h = 0, v = 0;
    int l = 0, r = 0;
    for(int i=0;i<n;i++){
        if(a[i] == 'L'){
            l++;
        }
        if(a[i] == 'R'){
            r++;
        }
        int temp = (l + r) % 4;
        if(temp == 0){
            h += 1;
        }else if(temp == 1){
            if(r > l){
                v -= 1; 
            }else{
                v += 1;
            }
        }else if(temp == 2){
            h -= 1;
        }else if(temp == 3){
            if(l > r){
                v -= 1;
            }else{
                v += 1;
            }
        }
    }
    if(h==0 && v==0){
        return true;
    }
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        char a[205] = {'\0'};
        scanf("%s", a);
        int n = strlen(a);
        bool res = isCircular(a, n);
        if(res){
            cout<<"Circular"<<endl;
        }else{
            cout<<"Not Circular"<<endl;
        }
    }
	return 0;
}