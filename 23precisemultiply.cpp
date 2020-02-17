#include <iostream>
#include <vector>

using namespace std;

typedef vector<int> v;

v multiply(v &A, int b)
{
    int t = 0;
    v C;
    for (int i = 0 ; i < A.size(); i++)
    {
        int m = A[i]*b;
        t += m; 
        C.push_back(t %10);
        t /= 10;
    }
    while(t)
    {
        C.push_back(t %10);
        t /= 10;
    }
    return C;
}

int main()
{
    string a;
    int b;
    v A;
    cin>>a>>b;
    for(int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    v C = multiply(A,b);
    for(int i = C.size() - 1; i >= 0; i -- ) printf("%d",C[i]);
}