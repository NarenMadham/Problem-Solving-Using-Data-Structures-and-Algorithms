#include<bits/stdc++.h>
using namespace std;

void print_permutations(char str[], int l, int r){
    if(l == r){
        cout<<str<<" ";
        return;
    }
    
    for(int i=l;i<=r;i++){
        swap(str[l], str[i]);
        print_permutations(str, l+1, r);
        swap(str[l], str[i]);
    }
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    char str[7] = {'\0'};
	    cin>>str;
	    int n = strlen(str);
	    print_permutations(str, 0, n-1);
	    cout<<endl;
	}
	return 0;
}