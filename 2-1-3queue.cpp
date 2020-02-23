#include <iostream>
using namespace std;

const int N = 100010;

int hh = 0, tt = 0;
int q[N];

int main()
{
    int n = 0;
    cin >> n;
    while (n--)
    {
        string op;
        cin >> op;
        int x;
        if (op == "push")
        {
            cin >> x;

            if (tt + 1 + N % N == hh)
                cout << "queue overflow";
            q[tt] = x;
            tt = tt + 1 + N % N;
        }
        else if (op == "pop")
        {
            if (hh == tt)
                cout << "empty queue";
            hh = hh + 1 + N % N;
        }
        else if (op == "query")
        {
            cout << q[hh] << endl;
        }
        else
        {
            if (hh == tt)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }
}