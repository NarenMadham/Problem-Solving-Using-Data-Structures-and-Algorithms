#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
	    int words;
	    cin>>words;
	    unordered_set<string> st;
	    for(int i=0;i<words;i++){
	        string temp;
	        cin>>temp;
	        st.insert(temp);
	    }
	    string input;
	    cin>>input;
	    int n = input.length();
	    bool dp[n][n];
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            dp[i][j] = false;
	        }
	    }
	    for(int i=0;i<n;i++){
	        if(st.find(input.substr(i, 1)) != st.end()){
	            dp[i][i] = true;
	        }
	    }
	    for(int l=2;l<=n;l++){
	        for(int i=0;i<n-l+1;i++){
	            int j = i + l - 1;
	            if(st.find(input.substr(i, l)) != st.end()){
	                dp[i][j] = true;
	            }else{
	                for(int k=i;k<j;k++){
	                    dp[i][j] |= (dp[i][k] && dp[k+1][j]);
	                }
	            }
	        }
	    }
	    /*for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(dp[i][j])
	                cout<<"T"<<" ";
                else
                    cout<<"F"<<" ";
	        }
	        cout<<endl;
	    }*/
	    if(dp[0][n-1]){
	        cout<<1<<endl;
	    }else{
	        cout<<0<<endl;
	    }
	}
	return 0;
}