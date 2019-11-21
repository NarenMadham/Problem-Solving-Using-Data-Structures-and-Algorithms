/*

    METHOD 1 : USING MAPS

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int f = 0;
        map<int, int> mp;
        int cs = 0;
        mp[0] = 0;
        for(int i=0;i<n;i++){
            cs += arr[i];
            if(mp.find(cs - k) == mp.end()){
                mp[cs] = i + 1;
            }else{
                f = 1;
                cout<<mp[cs-k] + 1<<" "<<i+1;
                break;
            }
        }
        if(f == 0){
            cout<<-1;
        }
        cout<<endl;
    }
	return 0;
}

/*

METHOD 2 : SLIDING WINDOW

*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int f = 0;
        int h = 0, e  =0;
        int wsum = 0;
        while(e < n){
            wsum += arr[e];
            if(wsum > k){
                while(wsum > k && h < e){
                    wsum -= arr[h];
                    h += 1;
                }
            }
            if(wsum == k){
                f = 1;
                cout<<h+1<<" "<<e+1;
                break;
            }
            e += 1;
        }
        if(f == 0){
            cout<<-1;
        }
        cout<<endl;
    }
	return 0;
}