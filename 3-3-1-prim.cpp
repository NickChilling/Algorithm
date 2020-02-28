#include <iostream>
#include <cstring>
using namespace std; 
const int N = 510;

int g[N][N],st[N], dist[N];
int n ,m;
int prim()
{
    int res = 0;
    for(int i = 0 ; i < n ; i++)
    {
        int t = -1;
        for(int j = 1; j <= n ; j++)
        {
            if (!st[j] && (t==-1 || dist[j] < dist[t]))  t=j;
        }
        if(!i && dist[t]==0x3f3f3f3f) return -1;
        if(!i) res += dist[t];
        for(int j = 1; j<= n ; j++)
        {
            dist[j] = min(dist[j],g[t][j]);
        }
        st[t]= 1;
    }
    return res;
}


int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    while(m--)
    {
        int a,b ,c;
        cin >> a >> b >> c ;
        g[b][a] = g[a][b] = min(g[a][b], c);
    }
    int res = prim();
    if (res == -1 ) cout << "impossible";
    else cout<< res;
}
