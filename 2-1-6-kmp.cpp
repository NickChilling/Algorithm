#include <iostream>
using namespace std;

const int N = 1e4+10;
const int M = 1e5+10;
char s[M],p[N], ne[N];


int main()
{
    int n,m;
    cin>>n>>p+1>>m>>s+1;
    for(int i = 2, j = 0; i <= n ; i ++)
    {
        while(j && p[j+1] != p[i]) j = ne[j];
        if (p[i]==p[j+1]) j++;
        ne[i] = j;
    }
    for(int i = 1, j =0; i <= n; i++)
    {
        while(j &&p[j+1]!=s[i]) j = ne[j];
        if(s[i] == p[j+1]) j++;
        if (j == n)
        {
            cout<<i-n-1;
            j = ne[j];
        }
    }
}