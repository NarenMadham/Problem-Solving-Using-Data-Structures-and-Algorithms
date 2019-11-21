#include<bits/stdc++.h>
using namespace std;

class Point{
public:
    int x, y;
};

float min(float a, float b){
    if(a < b){
        return a;
    }
    return b;
}

float dist(Point a, Point b){
    return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

float bruteForce(Point p[], int n){
    float m = FLT_MAX;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            float temp = dist(p[i], p[j]);
            if(temp < m){
                m = temp;
            }
        }
    }
    return m;
}

int compareX(const void *a, const void *b){
    Point * p1 = (Point *) a;
    Point * p2 = (Point *) b;
    return p1->x - p2->x;
}

int compareY(const void *a, const void *b){
    Point * p1 = (Point *) a;
    Point * p2 = (Point *) b;
    return p1->y - p2->y;
}

float strip_closest(Point strip[], int size, float d){
    qsort(strip, size, sizeof(Point), compareY);
    float m = d;
    for(int i=0; i<size; i++){
        for(int j=i+1; j<size && (strip[i].y - strip[j].y) < m; j++){
            float temp = dist(strip[i], strip[j]);
            if(temp < d){
                m = temp;
            }
        }
    }
    return m;
}

float cutil(Point p[], int n){
    if(n <= 3)
       return bruteForce(p, n); //BLUNDER! DONT FORGET TO WRITE RETURN!
    int mid = n/2;
    Point mp = p[mid];
    float dl = cutil(p, mid);
    float dr = cutil(p+mid, n-mid);
    float d = min(dl, dr);
    
    Point strip[n];
    int j = 0;
    for(int i=0;i<n;i++){
        if(abs(p[i].x - mp.x) < d){
            strip[j] = p[i];
            j++;
        }
    }
    return min(d, strip_closest(strip, j, d));
}

float closest_pair(Point p[], int n){
    qsort(p, n, sizeof(Point), compareX);
    return cutil(p, n);
}

int main(){
    Point P[] = {{2,3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P)/sizeof(P[0]);
    cout<<closest_pair(P, n)<<endl;
    return 0;
}