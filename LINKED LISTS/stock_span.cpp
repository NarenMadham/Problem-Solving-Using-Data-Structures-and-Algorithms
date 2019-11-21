using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    stack<int> st;
	    st.push(0);
	    cout<<1<<" ";
	    for(int i=1;i<n;i++){
	        if(!st.empty() && arr[i] < arr[st.top()]){
	            st.push(i);
	            cout<<1<<" ";
	            continue;
	        }
	        while(!st.empty() && arr[st.top()] <= arr[i]){
	            st.pop();
	        }
	        if(!st.empty())
	            cout<<i - st.top()<<" ";
	        else{
	            cout<<i+1<<" ";
	        }
	        st.push(i);
	    }
	    cout<<endl;
	}
	return 0;
}