#include <iostream>
#include <cstring>
#include <queue>

using namespace std; 

// 稀疏图才用heap optimize
typedef pair<int, int > PII;

const int N = 100010;

int h[N], e[2*N], ne[2*N], idx, st[N], dist[N], w[N];
int n ,m ;
void dijkstra()
{
    dist[1] = 0;
    priority_queue<PII, vector<PII> , greater<PII>> heap;
    heap.push({0,1});
    while(heap.size())
    {
        PII t = heap.top();
        heap.pop();
        int weight = t.first, node = t.second;
        if(st[node]) continue;
        for(int i = h[node]; i != -1; i = ne[i])
        {
            int j = e[j];
            if (dist[j] > dist[node]+w[i])
            {
                dist[j] = dist[node]+w[i];
                heap.push({w[i],j});
            }
        }
        st[node] = 1;
    }
    if (dist[n] > 0x3f3f3f / 2) cout << -1;
    else cout <<dist[n];

}
void add(int a, int b, int c)
{
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    w[idx] = c;
}
int main()
{
    cin >> n >> m;
    memset(dist , 0x3f, sizeof dist);
    memset(h, -1 , sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a,b,c);
    }
    dijkstra();
    return 0;
}