#include<bits/stdc++.h>
#include<string.h>

using namespace std;

const int num = 256;

void smallest_window(char a[], char b[]){
    int la = strlen(a);
    int lb = strlen(b);
    if(lb > la){
        cout<<-1<<endl;
        return;
    }
    vector<int> hash_str(num, 0);
    vector<int> hash_ptr(num, 0);
    string temp(a);
    
    for(int i=0;i<lb;i++){
        hash_ptr[b[i]] += 1;
    }
    int start = 0, start_index = -1, min_len = INT_MAX;
    int count = 0;
    for(int i=0;i<la;i++){
        hash_str[a[i]] += 1;
        if(hash_ptr[a[i]] != 0 && hash_str[a[i]] <= hash_ptr[a[i]]){
            count += 1;
        }
        if(count == lb){
            while(hash_ptr[a[start]] == 0 || hash_str[a[start]] > hash_ptr[a[start]]){
                if(hash_str[a[start]] > hash_ptr[a[start]]){
                    hash_str[a[start]] -= 1;
                }
                start++;
            }
            int window_size = i - start + 1;
            if(min_len > window_size){
                min_len = window_size;
                start_index = start;
            }
        }
    }
    if(start_index == -1){
        cout<<-1<<endl;
        return;
    }
    cout<<temp.substr(start_index, min_len)<<endl;
}

int main()
{
	int t;
	cin>>t;
	while(t--){
	    char a[1003] = {'\0'};
	    char b[1003] = {'\0'};
	    scanf("%s", a);
	    scanf("%s", b);
	    smallest_window(a, b);
	}
	return 0;
}