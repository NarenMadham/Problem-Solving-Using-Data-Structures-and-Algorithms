#include<bots/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    char a[8] = {'\0'};
	    scanf("%s", a);
	    int n = strlen(a);
	    int p = n-1;
	    long long int res = 0;
	    for(int i=0;i<n;i++){
	        res += pow(26, p) * (a[i]-64);
	        p-=1;
	    }
	    cout<<res<<endl;
	}
	return 0;
}