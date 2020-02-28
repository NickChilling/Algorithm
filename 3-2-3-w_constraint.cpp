#include <iostream>
#include <cstring>

using namespace std ;

const int N = 510, M = 10010;
int dist[N],backup[N];
struct Edge
{
    int a,b,w;
} edges[M];
int n, m ,k ;

int bellman_ford()
{
    memset(dist, 0x3f,sizeof dist);
    dist[1] = 0;
    for(int i = 0; i < k ; i ++)
    {
        memcpy(backup , dist, sizeof dist);
        for(int j = 0; j < m ; j++)
        {
            int a = edges[j].a, b= edges[j].b , w = edges[j].w; 
            dist[b] = min(dist[b], backup[a]+w); // a使用未更新的值， b 使用已更新的值
        }
    }
    if (dist[n] > 0x3f3f3f3f/2) return -1;
    else return dist[n];
}

int main()
{
    cin >> n >> m >> k ;

    for(int i = 0 ; i < n ; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edges[i]={a,b,c}; 
    }
    int t = bellman_ford();
    if (t==-1) cout << "impossible";
    else cout << dist[n];
}