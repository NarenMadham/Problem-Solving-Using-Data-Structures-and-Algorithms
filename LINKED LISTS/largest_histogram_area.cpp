using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    long long int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    stack<long long int> s;
	    long long int max_area = 0;
	    int i = 0;
	    while(i < n){
	        if(s.empty() || arr[s.top()] < arr[i]){
	            s.push(i++);
	            continue;
	        }
	        long long int temp = s.top();
	        long long int curr = 0;
	        s.pop();
            if(s.empty()){
	            curr = arr[temp] * i;
	        }else{
	            curr = arr[temp] * (i - s.top() - 1);
	        }
	        if(curr > max_area){
	            max_area = curr;
	        }
	    }
	    while(!s.empty()){
	        long long int temp = s.top();
	        s.pop();
	        long long int curr;
	        if(s.empty()){
	            curr = arr[temp] * i;
	        }else{
	            curr = arr[temp] * (i - s.top() - 1);
	        }
	        if(curr > max_area){
	            max_area = curr;
	        }
	    }
	    cout<<max_area<<endl;
	}
	return 0;
}