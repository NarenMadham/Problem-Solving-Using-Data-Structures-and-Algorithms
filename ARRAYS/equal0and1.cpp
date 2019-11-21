{
#include <bits/stdc++.h>
using namespace std;
int maxLen(int arr[], int n);
int main() {
	// your code goes here
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		cout<<maxLen(a,n)<<endl;
		
	}
	return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this method*/
int maxLen(int arr[], int n)
{
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            arr[i] = -1;
        }else{
            continue;
        }
    }
    unordered_map<int, int> mp;
    int s = 0;
    int ei = -1;
    int max_len = 0;
    for(int i=0;i<n;i++){
        s += arr[i];
        if(s == 0){
            max_len = i+1;
            ei = i;
        }
        if(mp.find(s + n) == mp.end()){
            mp[s+n] = i;
        }else{
            max_len = max(max_len, i - mp[s+n]);
        }
    }
    return max_len;
}