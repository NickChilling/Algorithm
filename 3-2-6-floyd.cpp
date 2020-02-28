#include <iostream>
#include <cstring>
using namespace std;

const int N = 210;
int g[N][N];
int n ,m ,o;
int floyed()
{
    for(int k = 1 ; k <=n; k++)
    {
        for(int i =1 ; i <= n ; i++)
        {
            for(int j =1 ; j <= n ;j ++)
            {
                g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
            }
        }
    }

}
int main()
{
    cin >> n >> m>> o ;
    for(int i = 1; i <=n ; i++)
    {
        for(int j =1 ; j<=n; j++)
        {
            if(i==j) g[i][j]= 0;
            else g[i][j]=1e9;
        }
    }
    while(m--)
    {
        int a, b, c;
        scanf("%d%d%d",&a, &b, &c);
        g[a][b] = min(g[a][b],c);
    }
    floyed();
    while(o--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if(g[a][b] > 1e9/2) puts("impossible");
        else printf("%d\n", g[a][b]);
    }
}

