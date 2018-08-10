#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
using namespace std;
struct pt
{
    long x1,x2;
    long y1,y2;
    pt(long _x1,long _y1,long _x2,long _y2):x1(_x1),y1(_y1),x2(_x2),y2(_y2){};
};
int main()
{
    int n;
    while(cin>>n)
    {
        long x1,y1,x2,y2;  
        vector<long> xs(2*n);
        vector<long> ys(2*n);
         
        vector<pt> co;
        for(int i=0;i<n;i++)
            co.push_back(pt(0,0,0,0));
        for(int i=0;i<n;i++)
        {
            cin>>xs[i];
            co[i].x1=xs[i];
        }
          for(int i=0;i<n;i++)
        {
            cin>>ys[i];
            co[i].y1=ys[i];
        }
         for(int i=0;i<n;i++)
        {
            cin>>xs[i+n];
            co[i].x2=xs[i+n];
        }
         for(int i=0;i<n;i++)
        {
            cin>>ys[i+n];
            co[i].y2=ys[i+n];
        }
         
       int out=0;
         
       for(int i=0;i<2*n;i++)
       {
           for(int j=0;j<2*n;j++)
           {
               int cnt=0;
               for(int p=0;p<n;p++)
               {
                   if(co[p].x1<=xs[i]&&co[p].x2>xs[i]&&
                     co[p].y1<=ys[j]&&co[p].y2>ys[j])
                       cnt++;
               }
               out=max(out,cnt);
           }
       }
       cout<<out<<endl;
    }
}
