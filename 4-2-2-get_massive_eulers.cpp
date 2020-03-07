#include <iostream>


using namespace std;

const int N = 1e6+10;

int st[N], primes[N], idx, phi[N];
int filter(int a )
{
    for(int i = 2; i <=a; i++)
    {
        if(!st[i])
        {
            primes[idx++] = i;
            phi[i] = i -1;
        }
        for(int j =0; primes[j]<= a/i; j++)
        {
            st[primes[j]*i] = 1;
            phi[primes[j]*i] = phi[i]*primes[j]-1;
            if(i % primes[j] == 0 )
            {
                phi[i*primes[j]] = phi[i]*primes[j];
                break;
            }
        }
    }
    int res ;
    for(int i = 1 ; i <= a; i++)
    {
        res += phi[i];
    }
    return res;
}   
int main()
{
    int n ;
    cin >> n;
    cout<< filter(n);
}