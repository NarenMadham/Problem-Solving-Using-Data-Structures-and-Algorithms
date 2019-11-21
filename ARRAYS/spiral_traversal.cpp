#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
        int m, n;
        scanf("%d %d", &n, &m);
        int count = n * m;
        int arr[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                scanf("%d", &arr[i][j]);
            }
        }
        int t = 0, r = n-1, b = n-1, l = 0;
        int temp;
        while(count > 0){
            temp = l;
            while(temp<=r){
                printf("%d ", arr[t][temp]);
                count -= 1;
                temp += 1;
            }
            t += 1;
            
            temp = t;
            while(temp <= b){
                printf("%d ",arr[temp][r]);
                temp += 1;
                count -= 1;
            }
            r -= 1;
            
            temp = r;
            while(temp >= l){
                printf("%d ",arr[b][temp]);
                temp -= 1;
                count -= 1;
            }
            b -= 1;
            
            temp = b;
            while(temp >= t){
                printf("%d ",arr[temp][l]);
                temp -= 1;
                count -= 1;
            }
            l += 1;
        }
	    cout<<endl;
	}
	return 0;
}