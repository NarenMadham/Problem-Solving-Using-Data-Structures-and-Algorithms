#include<stdio.h>
 
int main(){
    int t, n;
    int two_main(int a, int b);
    int three_main(int a, int b, int c);
    scanf("%d", &t);
    for(int x = 0;x<t;x++){
        int i;
        scanf("%d", &n);
        int P[n];
        int O[n];
        int Y[n];
        for(i=0;i<n;i++){
            scanf("%d", &P[i]);
            scanf("%d", &O[i]);
            scanf("%d", &Y[i]);
        }
        int dpp[n+1];
        int dpo[n+1];
        int dpy[n+1];
        for(int i=0;i<=n;i++){
            dpp[i] = 0;
            dpo[i] = 0;
            dpy[i] = 0;
        }
        dpp[0] = P[0];
        dpo[0] = O[0];
        dpy[0] = Y[0];
        
        for(i=1;i<n;i++){
            dpp[i] = two_min(dpo[i-1], dpy[i-1]) + P[i];
            dpo[i] = two_min(dpp[i-1], dpy[i-1]) + O[i];
            dpy[i] = two_min(dpp[i-1], dpo[i-1]) + Y[i];
        }
        printf("%d\n",three_min(dpp[n-1], dpo[n-1], dpy[n-1]));
        
    }
    
    return 0;
}
 
int two_min(int a, int b){
    if(a<b){
        return a;
    }
    else{
        return b;
    }
}
 
int three_min(int a, int b, int c){
    if(a<b){
        if(a<c){
            return a;
        }else{
            return c;
        }
    }else{
        if(b<c){
            return b;
        }else{
            return c;
        }
    }
}