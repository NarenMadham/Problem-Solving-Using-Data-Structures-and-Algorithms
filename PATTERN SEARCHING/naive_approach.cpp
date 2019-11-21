#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string a;
        string b;
        cin>>a>>b;
        int la, lb;
        la = a.length();
        lb = b.length();
        if(lb > la){
            cout<<"There is not Pattern!"<<endl;
        }
        int c = 0;
        for(int i=0;i<=la-lb;i++){
            int f = 1;
            int idx = 0;
            for(int j=0;j<lb;j++){
                if(a[i + idx] == b[j]){
                    idx++;
                    continue;
                }else{
                    f = 0;
                    break;
                }
            }
            if(f == 1)
                c += 1;
        }
        cout<<c<<endl;
    }
}


/*

1
aabaacaadaabaaba
aaba

*/