#include <iostream>
using namespace std;

const int N = 10000010;
int q[N];

int max_k(int nums[], int start, int end, int k)
{
    if (start >= end)
        return nums[start];
    int x = nums[(start + end >> 1)], i = start - 1, j = end + 1;
    int res;
    while (i < j)
    {
        i++;
        j--;
        while (nums[i] < x)
            i++;
        while (nums[j] > x)
            j--;
        if (i < j)
            swap(nums[i], nums[j]);
    }
    if (j >= (k - 1))
        res = max_k(nums, start, j, k);
    else
        res = max_k(nums, j + 1, end, k);
    return res;
}

int main()
{
    int k, n;
    scanf("%d %d", &k, &n);
    for (int i; i < n; i++)
        scanf("%d", &q[i]);
    int res;
    res = max_k(q, 0, n - 1, k);
    printf("%d", res);
}