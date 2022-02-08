
#include <bits/stdc++.h>
using namespace std;
struct Dot{
    int x, y;
} ;
int oren(Dot p, Dot q, Dot r){
    int val = (q.y - p.y) * (r.x - q.x) -(q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
void convexHull(Dot p1[], int n){
    if (n < 3) return;
    vector<Dot> hull;
    int l = 0;
    for (int i = 1; i < n; i++)
        if (p1[i].x < p1[l].x)
            l = i;
    int p = l, q;
    do{
        hull.push_back(p1[p]);
        q = (p+1)%n;
        for (int i = 0; i < n; i++){
           if (oren(p1[p], p1[i], p1[q]) == 2)
               q = i;
        }
        p = q;
    } while (p != l);
    for (int i = 0; i < hull.size(); i++)
        cout << "(" << hull[i].x << ", "
              << hull[i].y << ")\n";
}
int main(){
    //Dot p1[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1},{3, 0}, {0, 0}, {3, 3}};
    int n;
    cout<<"Enter the number of p1:";
    cin>>n;
    Dot p1[n];
    for(int i=0;i<n;i++){
        cout<<" Dot "<<i<<" coordinates: ";
        cin>>p1[i].x>>p1[i].y;
    }
    convexHull(p1, n);
    return 0;
}
