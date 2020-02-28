#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int h[N], ne[N], e[N], w[N], dist[N], st[N];
int idx;
int n, m;
int add(int a, int b, int c)
{
    e[++idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx;
}
int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (q.size())
    {
        int node = q.front();
        q.pop();
        st[node] = false;
        for (int i = h[node]; i != -1; i = ne[i])
        {
            int link_node = e[i];
            if(dist[link_node] > dist[node]+ w[i])
            {
                dist[link_node] = dist[node] + w[i];
                if(!st[link_node])
                {
                    q.push(link_node);
                    st[link_node] = true;
                }
            }
        }
    }
    if(dist[n] > 0x3f/2 ) return -1;
    else return dist[n];
}
int main()
{
    memset(h, -1, sizeof h);

    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int res = spfa();
    cout << res;
}