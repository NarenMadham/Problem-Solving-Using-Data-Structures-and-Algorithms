#include<bits/stdc++.h>
using namespace std;

int main(){
    string temp;
    cin>>temp;
    int tl = temp.length();
    string input;
    int index = 0;
    for(int i=0;i<(2 * tl) + 1;i++){
        if(i%2 != 0){
            input += temp[index++];
        }else{
            input += '$';
        }
    }
    int l = input.length();
    int s = 0;
    int e = 0;
    vector<int> t(l, 0);
    for(int i=0;i<l;){
        //checking for the palindrome
        while(s > 0 && e < l-1 && input[s-1] == input[e+1]){
            s--;
            e++;
        }
        t[i] = e - s + 1;
        if(e == l-1) break;
        
        //intializing the new center to the point after the box
        int nc = e + (i%2 == 0 ? 1: 0);
        
        for(int j=i+1; j <= e; j++){
            //taking the value of mirror
            t[j] = min(t[i-(j-i)], 2 * (e - j) + 1);
            if(j + t[i-(j-i)]/2 == e){
                //if any point is extending up too the right end of the box
                nc = j;
                break;
            }
        }
        i = nc;
        //initializing to the end points where it is a palindrome already
        s = nc - t[i]/2;
        e = nc + t[i]/2;
    }
    int M = INT_MIN;
    for(int i=0;i<l;i++){
        cout<<t[i]<<" ";
        if(t[i]/2 > M){
            M = t[i]/2;
        }
    }
    cout<<endl;
    cout<<"The length of the longest palindromic substring is : "<<M<<endl;
}

/*

abaxabaxabb

abaxabaxabybaxabyb

*/