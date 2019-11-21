#include<bits/stdc++.h>
#define ll long long int
using namespace std;
/*O(n) solution*/
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        deque<ll> d;
        for(int i=0;i<n;i++){
            ll temp;
            cin>>temp;
            d.push_back(temp);
        }
        ll k = 0;
        while(d.size() != 1){
            d.push_front(d.at(d.size()-1));
            d.pop_back();
            if(d.size() < k){
                d.pop_front();
            }else{
                d.erase(d.begin() + d.size() - 1 - k);
            }
            k += 1;
        }
        cout<<d.at(0)<<endl;
        d.clear();
    }
}

/*O(1) Solution*/

#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        long long int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(n == 1){
            cout<<arr[0]<<endl;
        }else if(n%2 == 0){
            ll index = n - 2;
            index = index / 4;
            index += 2;
            cout<<arr[index-1]<<endl;
        }else{
            ll index = n - 3;
            index = index / 4;
            index += 3;
            cout<<arr[index-1]<<endl;
        }
    }
}