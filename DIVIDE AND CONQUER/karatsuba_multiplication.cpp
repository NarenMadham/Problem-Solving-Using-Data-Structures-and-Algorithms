#include<bits/stdc++.h>
using namespace std;

int makeEqual(string& a, string& b){
    int l1 = a.size();
    int l2 = b.size();
    if(l1 > l2){
        for(int i=0;i<(l1 - l2);i++){
            b = '0' + b;
        }
        return l1;
    }else{
        for(int i=0;i<(l2 - l1);i++){
            a = '0' + a;
        }
    }
    return l2;
}

string addStrings(string a, string b){
    int l = makeEqual(a, b);
    int carry = 0;
    string result;
    for(int i = l-1; i >= 0; i--){
        int fb = a.at(i) - '0';
        int sb = b.at(i) - '0';
        int sum = (fb ^ sb ^ carry) + '0';
        result = (char)sum + result;
        carry = (fb & sb) | (sb & carry) | (fb & carry);
    }
    if(carry == 1){
        result = "1" + result;
    }
    return result;
}

long long int multiplySingleDigits(string a, string b){
    return ((a[0] - '0') * (b[0] - '0'));
}

long long int multiply(string x, string y){
    int n = makeEqual(x, y);
    if(n == 0) return 0;
    if(n == 1) return multiplySingleDigits(x, y);
    
    int fh = n/2;
    int sh = (n - fh);
    
    string a = x.substr(0, fh);
    string b = x.substr(fh, sh);
    
    string c = y.substr(0, fh);
    string d = y.substr(fh, sh);
    
    long long int p1 = multiply(a, c);
    long long int p2 = multiply(b, d);
    long long int p3 = multiply(addStrings(a, b), addStrings(c, d));
    
    long long int res = (1<<2*sh) * p1 + (1<<sh) * (p3 - p1 - p2) + (p2);
    return res;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    string a, b;
	    cin>>a;
	    cin>>b;
	    cout<<multiply(a, b);
	}
	return 0;
}