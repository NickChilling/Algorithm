#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> v;

v divide(v &A, int b, int &r)
{
    v C;
    for (int i = A.size()-1; i >= 0; i--)
    {

        r = 10 * r + A[i];
        C.push_back(r / b);
        r = r % b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1 && C.back()==0) C.pop_back();
    return C;
}

int main()
{
    v A, C;
    int b;
    string a;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    int r = 0;
    C = divide(A, b, r);
    for (int i = C.size() - 1; i >= 0; i--)
        printf("%d", C[i]);
    cout << endl
         << r << endl;
}