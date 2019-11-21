#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        ll m = arr[0];
        ll max_diff = arr[1] - arr[0];
        
        for(int i=1;i<n;i++){
            if(max_diff < arr[i] - m){
                max_diff = arr[i] - m;
            }
            if(arr[i] < m){
                m = arr[i];
            }
        }
        cout<<max_diff<<endl;
    }
	return 0;
}

/*or 
 * we can do it by finding the diff array  
 * maximum sum subarray of the diff array is the required       answer*/