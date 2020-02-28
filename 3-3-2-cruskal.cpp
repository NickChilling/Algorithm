#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e5+10;

int p[N];
int n,m;
int find(int a)
{
    if (p[a] != a) p[a] = find(p[a]);
    return p[a];
}
struct Edge
{
    int a,b,w;
    bool operator <(const Edge &W) const
    {
        return w < W.w;
    }
} edges[2*N];
int cruskal()
{
    int res=0, cnt=0; 
    for(int i =0; i < m ; i++)
    {
        int a = edges[i].a,b = edges[i].b,w = edges[i].w;
        int fa = find(a), fb = find(b);
        if(fa!=fb)
        {
            res += w;
            p[fb] = fa;
            cnt += 1;
        } 
    }
    if(cnt+1 < n ) return -1;
    else return res;
    
}
int main()
{
    cin>> n >>m ;
    for(int i =0 ; i <m; i++)
    {
        int a, b, c;
        cin>> a >>b>> c;
        edges[i] = {a,b,c};
    }

    for(int i = 1; i <= n; i++)
    {
        p[i] = i;
    }
    sort(edges, edges+m);
    int res = cruskal();
    if(res==-1) puts("impossible");
    else cout << res;
}