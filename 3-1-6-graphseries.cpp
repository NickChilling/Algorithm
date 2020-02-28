#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

queue<int> q;
const int N = 1e5+10;

int h[N], e[N], ne[N], dis[N];

int n ,m,idx ;

void add(int a, int b)
{
    e[++idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
}
void bfs()
{
    q.push(1);
    dis[1] = 0;
    while(!q.empty())
    {
        int j = q.front();
        q.pop();
        for(int i = h[j];i != -1; i = ne[i])
        {
            int s = e[i];
            if (dis[s] == -1)
            {
                dis[s] = dis[j] + 1;
                q.push(s);
            }
        }
        
    }
}

int main()
{
    cin >> n >> m;
    memset(dis, -1, sizeof dis);
    memset(h, -1 , sizeof h);
    while(m--)
    {
        int a, b;
        cin >> a >> b;
        add(a,b);
    
    }
    bfs();
    cout<< dis[n];
}