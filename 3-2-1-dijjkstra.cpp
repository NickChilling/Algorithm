#include <iostream>
#include <cstring>

using namespace std;

const int N = 510;

int g[N][N], st[N], dist[N];
int n, m;
void add(int x, int y, int w)
{
    g[x][y] = min(g[x][y], w);
}
void dijkstra()
{
    dist[1] = 0 ;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 0; j < n; j++)
        {
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
            {
                t = j;
            }
        }
        st[t] = 1;
        for (int j = 0; j < n; j++)
        {
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        }
    }
    if (dist[n] == 0x3f)
        cout << -1;
    else
        cout << dist[n];
}
int main()
{
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    memset(dist, 0x3f, sizeof dist);
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;
        add(x, y, z);
    }
    dijkstra();
}