/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */
#include <vector>
#include <iostream>
using namespace std;
// @lc code=start
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<int> dp(n+1, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        return dp[0];
    }
};
// int main(){
//     vector<vector<int>> test_case {{2},{3,4},{6,5,7},{4,1,8,3}};
//     int res = Solution().minimumTotal(test_case);
//     cout<<res<<endl;
// }
// @lc code=end
