using namespace std;
int main()
 {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int, int> > arr;
        for(int i=0;i<n;i++){
            int a, b;
            cin>>a>>b;
            arr.push_back(make_pair(a, b));
        }
        sort(arr.begin(), arr.end());
        stack<pair<int, int> > st;
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(arr[i]);
                continue;
            }
            pair<int, int> temp = st.top();
            if(temp.second >= arr[i].first){
                st.pop();
                st.push(make_pair(temp.first, max(temp.second, arr[i].second)));
                continue;
            }
            st.push(arr[i]);
        }
        stack<pair<int, int> > st2;
        while(!st.empty()){
            pair<int, int> temp = st.top();
            st.pop();
            st2.push(temp);
        }
        while(!st2.empty()){
            pair<int, int> i = st2.top();
            st2.pop();
            cout<<i.first<<" "<<i.second<<" ";
        }
        cout<<endl;
    }
	return 0;
}