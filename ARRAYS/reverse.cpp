#include<bits/stdc++.h>
using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        char a[10000] = {'\0'};
        scanf("%s", a);
        int n = strlen(a);
        int p1 = 0, p2 = n-1;
        while(p1 < p2){
            char temp = a[p1];
            a[p1] = a[p2];
            a[p2] = temp;
            p1++;
            p2--;
        }
        cout<<a<<endl;
    }
	return 0;
}