#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std  ;

const int N = 1e5+10;
queue<int> q;

int n,m, idx;
vector<int> res; 
int h[N],e[N], ne[N], st[N], in[N];

void top_sort()
{
    for(int i = 1 ; i<=n ; i++)
    {
        if (in[i] == 0 && !st[i])
        {
            res.push_back(i);
            st[i] = 1;
            q.push(i);
            while(!q.empty())
            {
                int j = q.front();
                q.pop();
                for(int m= h[j]; m != -1 ; m = ne[m])
                {
                    int k = e[m];
                    in[k] -= 1;
                    if(in[k]==0 && !st[k])
                    {
                        st[k] = 1;
                        res.push_back(k);
                        q.push(k);
                    }
                }
            }

        }
    }
}


void add(int a , int b)
{
    e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}
int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof h );
    while(m--)
    {
        int a,b;
        cin >> a>> b;
        add(a,b);
        in[b] += 1;
    }
    top_sort();
    if(res.size() != n) cout << -1;
    else{
        for(int i = 0 ; i < res.size(); i++)
        {
            cout<<res[i]<<" ";
        }
    }
}
