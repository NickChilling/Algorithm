#include<iostream>

using namespace std;

const int N = 1e6+10;
int s[N];
int a[N];

int main()
{
    int n,m,start,end;
    s[0] =0;
    scanf("%d %d", &n, &m);
    for(int i = 1 ; i <= n ;i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 1 ; i<= n; i++)
    {
        s[i] = a[i]+a[i-1]; 
    }
    while(m--)
    {
        scanf("%d %d",start, end);
        printf("%d",s[end]-s[start-1]);
    }

}