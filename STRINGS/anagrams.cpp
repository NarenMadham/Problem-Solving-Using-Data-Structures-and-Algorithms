#include<bits/stdc++.h>
using namespace std;

const int num = 256;

int main()
 {
	int t;
	cin>>t;
	while(t--){
	    char a[1000002] = {'\0'};
	    char b[1000002] = {'\0'};
	    scanf("%s", a);
	    scanf("%s", b);
	    vector<int> hasha(num, 0);
	    vector<int> hashb(num, 0);
	    int i = 0;
	    int j = 0;
	    bool res = true;
	    while(a[i] != '\0'){
	        hasha[a[i]] += 1;
	        i += 1;
	    }
	    while(b[j] != '\0'){
	        hashb[b[j]] += 1;
	        j += 1;
	    }
	    for(int x=0;x<256;x++){
	        if(hasha[x] == hashb[x]){
	            continue;
	        }else{
	            res = false;
	            break;
	        }
	    }
	    if(res){
	        cout<<"YES"<<endl;
	    }else{
	        cout<<"NO"<<endl;
	    }
	}
	return 0;
}