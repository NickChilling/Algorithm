#include <iostream>

using namespace std;

const int N = 8;
int st[N],q[N];
int n ;
void dfs(int k)
{
    if (k == n)
    {
        for(int i = 0 ; i < n ; i ++) printf("%d ", q[i]);
        puts("");
    }
    for(int i = 1; i <= n ; i++)
    {
        if (!st[i])
        {
            st[i] = 1;
            q[k] = i;
            dfs(k+1);
            st[i] = 0; 
        }
    }
}


int main()
{
    cin >> n;
    dfs(0);
}