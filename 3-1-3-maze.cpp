#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 110;

int n, m;

int d_x[4] = {0, 0, 1, -1};
int d_y[4] = {1, -1, 0, 0};
int maze[N][N], pth[N][N];
queue<pair<int,int>> q;

void bfs()
{
    memset(pth, -1 , sizeof pth);
    q.push(pair<int, int> (0,0));
    pth[0][0] = 0;
    while(!q.empty())
    {
        pair <int ,int> e = q.front();
        q.pop();
        for(int i =0; i < 4; i++)
        {
            int x = e.first+d_x[i], y = e.second + d_y[i];
            if (x >=0 && x < n && y >=0 && y<m && pth[x][y] == -1 && maze[x][y]==0)

            {
                pth[x][y] = pth[e.first][e.second] + 1;
                q.push(pair<int , int >(x,y));
            }
        }
    }
    
    
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0 ; j < m ; j++)
        {
            cin>>maze[i][j];
        }
    }
    bfs();
    cout<< pth[n-1][m-1];
}