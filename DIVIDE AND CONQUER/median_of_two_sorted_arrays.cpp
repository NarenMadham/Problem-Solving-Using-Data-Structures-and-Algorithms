#include<bits/stdc++.h>
using namespace std;

double findMedian(int input1[], int n, int input2[], int m){
    if(n > m){
        return findMedian(input2, m, input1, n);
    }
    int x = n;
    int y = m;
    int l = 0;
    int h = x-1;
    while(l <= h){
        int px = (l + h + 1)/2;
        int py = (x + y + 1)/2 - px;
        int maxLeftx = (px == 0) ? INT_MIN : input1[px-1];//MISTAKE
        int minRightx = (px== x) ? INT_MAX : input1[px];//MISTAKE
        int maxLefty = (py == 0) ? INT_MIN : input2[py-1];//MISTAKE
        int minRighty = (py == y) ? INT_MAX : input2[py];//MISTAKE
        
        if(maxLeftx <= minRighty && maxLefty <= minRightx){ //<=
            if((x+y)%2 == 0){
                return (double)((max(maxLeftx, maxLefty) + min(minRightx, minRighty))/2);
            }else{
                return (double)(max(maxLeftx, maxLefty));
            }
        }else if(maxLefty > minRightx){
            l = px + 1;
        }else{
            h = px - 1;
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;
    int in1[n], in2[m];
    for(int i=0;i<n;i++){
        cin>>in1[i];
    }
    for(int j=0;j<m;j++){
        cin>>in2[j];
    }
    cout<<findMedian(in1, n, in2, m);
}


/*

5 5
1 2 15 26 38
2 13 17 30 45

5 6
1 3 8 9 15
7 11 18 19 21 25

*/