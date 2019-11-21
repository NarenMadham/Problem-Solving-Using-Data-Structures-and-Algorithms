{
#include <bits/stdc++.h>
using namespace std;
void printDuplicates(int arr[], int n);
int main()
{
  int t;
  cin>>t;
  while(t-- > 0){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
			cin>>a[i];
		printDuplicates(a, n);
		cout<<endl;
  }
  return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function below*/
/* in sorted order*/
void printDuplicates(int arr[], int n)
{
    int f = 0;
   for(int i=0;i<n;i++){
       int index = arr[i] % n;
       arr[index] += n;
   }
   for(int i=0;i<n;i++){
       if(arr[i]/n > 1){
           f = 1;
           cout<<i<<" ";
       }
   }
   if(f == 0){
       cout<<-1;
   }
}

/*With order preserved*/
void printDuplicates(int arr[], int n)
{
    int f = 0;
    for(int i=0;i<n;i++){
        if(arr[arr[i] % n] >= n){
            if(arr[arr[i] % n] < 2*n){
                cout<<arr[i]%n<<" ";
                f = 1;
            }
        }
        arr[arr[i] %n] += n;
    }
   if(f == 0){
       cout<<-1;
   }
}