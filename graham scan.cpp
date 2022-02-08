#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;
struct Dot{
    int x, y;
};
Dot p0;
Dot nextToTop(stack<Dot> &S){
    Dot p = S.top();
    S.pop();
    Dot res = S.top();
    S.push(p);
    return res;
}
int swap(Dot &p1, Dot &p2){
    Dot temp = p1;
    p1 = p2;
    p2 = temp;
}
int distSq(Dot p1, Dot p2){
    return (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y);
}
int orientation(Dot p, Dot q, Dot r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}
int compare(const void *vp1, const void *vp2){
   Dot *p1 = (Dot *)vp1;
   Dot *p2 = (Dot *)vp2;
   int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
   return (o == 2)? -1: 1;
}
void convexHull(Dot p1[], int n){
   int ymin = p1[0].y, min = 0;
   for (int i = 1; i < n; i++)
   {
     int y = p1[i].y;
     if ((y < ymin) || (ymin == y &&
         p1[i].x < p1[min].x))
        ymin = p1[i].y, min = i;
   }
   swap(p1[0], p1[min]);
   p0 = p1[0];
   qsort(&p1[1], n-1, sizeof(Dot), compare);
   int m = 1;
   for (int i=1; i<n; i++){
       while (i < n-1 && orientation(p0, p1[i],p1[i+1]) == 0)
          i++;
       p1[m] = p1[i];
       m++;
   }
   if (m < 3) return;
   stack<Dot> S;
   S.push(p1[0]);
   S.push(p1[1]);
   S.push(p1[2]);
   for (int i = 3; i < m; i++){
      while (orientation(nextToTop(S), S.top(), p1[i]) != 2)
         S.pop();
      S.push(p1[i]);
   }
   while (!S.empty()){
       Dot p = S.top();
       cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
   }
}
int main(){
    //Dot p1[] = {{-7,8},{-4,6},{2,6},{6,4},{8,6},{7,-2},{4,-6},{8,-7},{0,0},{3,-2},{6,-10},{0,-6},{-9,-5},{-8,-2},{-8,0},{-10,3},{-2,2},{-10,4}};
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
