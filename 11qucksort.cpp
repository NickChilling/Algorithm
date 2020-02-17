#include <iostream>

using namespace std;

void quick_sort(int nums[], int start, int end)
{
    if (start >= end ) return;
    int x = nums[(start+end >> 1)], i = start , j = end;
    while(i < j ) // nums = 1,2   x = 1
    {
        i++;
        j--;
        while(nums[i] < x) i++; // 不进入这个循环
        while(nums[j] > x) j--; // j--
        if(i < j) swap(nums[i],nums[j]);
        i++;
        j--;
    }
    quick_sort(nums, start, j);
    quick_sort(nums, j+1, end);
    
}


int main()
{
    int N=100010;
    int n ;
    int q[N];
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d", &q[i]);
    }
    quick_sort(q, 0, n-1);
    for(int i = 0; i < n ; i ++) printf("%d", q[i]);
}