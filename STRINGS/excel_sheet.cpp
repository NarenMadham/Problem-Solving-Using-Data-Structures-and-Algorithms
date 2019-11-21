#include<bits/stdc++.h>
using namespace std;

void excel_sheet(long long int n, long long int powers[]){
    for(int i=5; i>=1; i--){
        if(n <= 26){
            break;
        }
        if(n == 0){
            return;
        }
        if(n/powers[i] == 0 || n == powers[i]){
            continue;
        }else{
            int temp = (n-1)/powers[i];
            //cout<<temp<<endl;
            printf("%c", temp + 64);
            n %= powers[i];
        }
    }
    if(n != 0)
        printf("%c", n+64);
    else
        printf("Z");
}

int main(){
	long long int powers[6];
    powers[1] = 26;
    for(int i=2;i<6;i++){
        powers[i] = powers[i-1] * 26;
    }
    int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        excel_sheet(n, powers);
        cout<<endl;
    }
    return 0;
}