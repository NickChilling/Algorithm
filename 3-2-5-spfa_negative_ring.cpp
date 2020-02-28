#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 2010 , M = 10010;

int h[N], ne[M], e[M], w[M],dist[N], cnt[N], st[N];
int idx, n , m;


int add(int a, int b , int c )
{
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    w[idx] = c;
}
bool spfs()
{
    queue<int> q;
    for(int i = 1; i <= n ; i++)
    {
        q.push(i);
        st[i] = 1;
    }
    while(q.size())
    {
        int node = q.front();
        q.pop();
        for(int i = h[node]; i != -1 ; i = ne[i])
        {
            int ne_node = e[i];
            if(dist[ne_node] > dist[node]+w[i])
            {
                dist[ne_node] = dist[node]+w[i];
                cnt[ne_node] = cnt[node] +1;
                if (cnt[ne_node] >= n) return true;
                if(!st[ne_node])
                {
                    q.push(ne_node);
                    st[ne_node] = 1;
                }
            }
        }
    }
    return false;
}

int main()
{
    memset(h, -1 ,sizeof h );
    cin >> n >> m;
    while(m--)
    {
        int a ,b ,c ; 
        scanf("%d%d%d", &a, &b , &c);
        add(a,b,c);
    }
    bool res = spfs();
    if(res) puts("Yes");
    else puts("No");
}