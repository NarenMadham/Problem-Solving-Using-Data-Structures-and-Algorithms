#include<bits/stdc++.h.>
using namespace std;

class Point{
public:
    int x, y;
    bool s;
};

int comparePoint(const void * a, const void * b){
    Point * p1 = (Point *) a;
    Point * p2 = (Point *) b;
    if(p1->x == p2->x){
        if(p1->s && p2->s){
            if(p1->y > p2->y){
                return -1;
            }else{
                return 1;
            }
        }
        if(p1->s == false && p2->s == false){
            if(p1->y > p2->y){
                return 1;
            }else{
                return -1;
            }
        }
        if(p1->s){
            return -1;
        }else{
            return 1;
        }
    }
    return p1->x - p2->x;
    
}

void skyline(Point p[], int n){
    set<int> s;
    s.insert(0);
    qsort(p, n, sizeof(Point), comparePoint);
    /*cout<<"After Sorting : "<<endl;
    for(int i=0;i<n;i++){
        cout<<p[i].x<<" "<<p[i].y<<" "<<p[i].s<<endl;
    }*/
    int temp = 0;
    for(int i=0;i<n;i++){
        if(p[i].s){
            s.insert(p[i].y);
        }else{
            s.erase(p[i].y);
        }
        if(temp != *s.rbegin()){
            cout<<p[i].x<<" "<<*s.rbegin()<<endl;
        }
        temp = *s.rbegin();
    }
}

int main(){
    int b;
    cin>>b;
    int n = 2 * b;
    Point p[n];
    int j = 0;
    for(int i=0;i<b;i++){
        int a, b, c;
        cin>>a>>b>>c;
        p[j].x = a;
        p[j].y = c;
        p[j].s = true;
        j++;
        p[j].x = b;
        p[j].y = c;
        p[j].s = false;
        j++;
    }
    skyline(p, n);
}


/*

5
1 3 3
2 4 4
5 8 4
6 7 3
8 9 2

*/