{
#include<bits/stdc++.h>
using namespace std;
int maxHeight(int height[],int width[],int length[],int n);
int main()
{
	int t;
	cin>>t;
	while(t--){
	int n;
	cin>>n;
	
 	int A[1000],B[1000],C[10001];
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		A[i]=a;
		B[i]=b;
		C[i]=c;
	}
	cout<<maxHeight(A,B,C,n)<<endl;
}
 
} 
}
/*This is a function problem.You only need to complete the function given below*/
/*The function takes an array of heights, width and 
length as its 3 arguments where each index i value 
determines the height, width, length of the ith box. 
Here n is the total no of boxes.*/
class Box{
public:
    int h, w, l;
};

bool myComparator(Box a, Box b){
    return((a.l * a.w) > (b.l * b.w));
}

int maxHeight(int height[],int width[],int length[],int l){
    int n = 3 * l;
    Box boxes[n];
    int j = 0;
    for(int i=0;i<l; i++){
        boxes[j].h = height[i];
        boxes[j].w = min(width[i], length[i]);
        boxes[j].l = max(length[i], width[i]);
        
        j++;
        
        boxes[j].h = length[i];
        boxes[j].w = min(width[i], height[i]);
        boxes[j].l = max(height[i], width[i]);
        
        j++;
        
        boxes[j].h = width[i];
        boxes[j].w = min(height[i], length[i]);
        boxes[j].l = max(height[i], length[i]);
        
        j++;
        
    }
    sort(boxes, boxes+n, myComparator);
    /*for(int i=0;i<n;i++){
        cout<<boxes[i].l<<" "<<boxes[i].w<<" "<<boxes[i].h<<" "<<boxes[i].l*boxes[i].w<<endl;
    }*/
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i] = boxes[i].h;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(boxes[j].l > boxes[i].l && boxes[j].w > boxes[i].w){
                dp[i] = max(dp[i], dp[j] + boxes[i].h);
            }
        }
    }
    int M = 0;
    for(int i=0;i<n;i++){
        if(dp[i] > M)
            M = dp[i];
    }
    return M;
}