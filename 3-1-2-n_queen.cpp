#include <iostream>

using namespace std;

const int N = 10;
int  n ;
int line[N],l_cross[N], r_cross[N];
char q[N][N];
void dfs(int k )
{
    if (k == n)
    {
        for(int i = 0; i < n ; i ++)
        {
            puts(q[i]);
        }
        puts("");
    }
    else
    {
        for (int i = 0; i < n ; i ++)
        {
            if (!line[i] && !l_cross[i+k] && !r_cross[n-k+i])
            {
               line[i] = l_cross[i+k] = r_cross[n-k+i] = 1;
               q[k][i] = 'Q';
               dfs(k+1);
               line[i] = l_cross[i+k] = r_cross[n-k+i] = 0; 
            }
        }
    }
}


int main()
{
    cin >> n;
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j<n; j++)
        {
            q[i][j] = '.';
        }
    }
    
    dfs(0);

}