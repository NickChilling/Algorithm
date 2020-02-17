/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 *
 * https://leetcode.com/problems/partition-equal-subset-sum/description/
 *
 * algorithms
 * Medium (42.19%)
 * Likes:    1875
 * Dislikes: 54
 * Total Accepted:    133.9K
 * Total Submissions: 317.4K
 * Testcase Example:  '[1,5,11,5]'
 *
 * Given a non-empty array containing only positive integers, find if the array
 * can be partitioned into two subsets such that the sum of elements in both
 * subsets is equal.
 * 
 * Note:
 * 
 * 
 * Each of the array element will not exceed 100.
 * The array size will not exceed 200.
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: [1, 5, 11, 5]
 * 
 * Output: true
 * 
 * Explanation: The array can be partitioned as [1, 5, 5] and [11].
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1, 2, 3, 5]
 * 
 * Output: false
 * 
 * Explanation: The array cannot be partitioned into equal sum subsets.
 * 
 * 
 * 
 * 
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int n = nums.size();

        int s = 0;
        for (auto &i : nums)
        {
            s += i;
        };
        if (s % 2 == 1)
        {
            return false;
        }
        int half_sum = s / 2;
        vector<bool> dp(half_sum+1,false);
        dp[0] = true;
        // 简化问题为选取数字，之和为half_sum
        // 简单的递归做法是，选取这个元素 和不选这个元素以及还差多少
        // 动态规划;定义状态: dp[i] 选了i。
        // 状态转移：
        for (auto &x :nums)
        {
            for(int i=half_sum;i>=x;i--)
            {
                dp[i] = dp[i] || dp[i-x];
            }
        }
        return dp[half_sum];
    }
};
// @lc code=end
