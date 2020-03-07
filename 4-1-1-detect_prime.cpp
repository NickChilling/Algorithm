#include <iostream>
using namespace std;

bool isprime(int n )
{
    for(int i = 2 ; i <= n / i; i ++)
    {
        if(n %i == 0) return false;
    }

    return true;
}


int main()
{
    int n ; 
    cin >> n;
    int a;
    while(n--)
    {
        cin >> a;
        if(isprime(a)) puts("Yes");
        else puts("No");
    }
}