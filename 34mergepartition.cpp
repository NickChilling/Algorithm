// 快速合并重叠的区间。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int > PII;

vector<PII> divisions;

void merge(vector<PII> &segs)
{
    vector<PII> res;
    sort(segs.begin(),segs.end());
    int st = -2e9,ed = -2e9;
    for (auto item : segs)
    {
        if (ed < item.first)
        {
            if(st!=-2e9)
            {
                res.push_back(item);
            }
            st = item.first;
            ed = item.second;
        }

        else 
        {
            ed = max(ed,item.second);
        }
    }
    segs = res; 
}


int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int f,s;
        cin>>f>>s;
        divisions.push_back({f,s});
    }
    merge(divisions);
    cout << divisions.size()<<endl;
}