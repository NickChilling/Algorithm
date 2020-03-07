#include <iostream>

using namespace std;

void exgcd(int a, int b, int &x, int &y)
{
    if(!b)
    {
        x =1 , y =0;
    }
    else{
        exgcd(b, a%b, x,y);
        int t = x;
        x =y;
        y = t-a/b*y;
    }
}
int main()
{
    int n ;
    cin >> n;
    while(n--)
    {
        int a, b, x, y;
        scanf("%d %d", &a, &b);
        exgcd(a,b,x,y);
        printf("%d %d\n", x, y);
    }
}