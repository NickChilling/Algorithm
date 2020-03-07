#include <iostream>
using namespace std;

int qmi(int a, int k , int p )
{
    int res = 1;
    while(k)
    {
        if(k & 1) res = res* a %p;
        a = a*a %p;
        k >>=1 ; 
    }
    return res;
}
int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int a, b,p ;
        scanf("%d %d %d", &a, &b, &p);
        int res = qmi(a,b,p);
        cout<< res << endl;
    }
}