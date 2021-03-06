// https://leetcode.com/problems/frog-jump/

/*A frog is crossing a river. The river is divided into some number of units, and at each unit, there may or may not exist a stone. The frog can jump on a stone, but it must not jump into the water.

Given a list of stones' positions (in units) in sorted ascending order, determine if the frog can cross the river by landing on the last stone. Initially, the frog is on the first stone and assumes the first jump must be 1 unit.

If the frog's last jump was k units, its next jump must be either k - 1, k, or k + 1 units. The frog can only jump in the forward direction.

Example 1:

Input: stones = [0,1,3,5,6,8,12,17]
Output: true
Explanation: The frog can jump to the last stone by jumping 1 unit to the 2nd stone, then 2 units to the 3rd stone, then 2 units to the 4th stone, then 3 units to the 6th stone, 4 units to the 7th stone, and 5 units to the 8th stone.

Example 2:

Input: stones = [0,1,2,3,4,8,9,11]
Output: false
Explanation: There is no way to jump to the last stone as the gap between the 5th and 6th stone is too large.

Constraints:
2 <= stones.length <= 2000
0 <= stones[i] <= 231 - 1
stones[0] == 0
stones is sorted in a strictly increasing order.
*/

#include <bits/stdc++.h>
using namespace std;

// Bottom Up approach Dp
class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int dist = stones[i] - stones[j];
                if (dist < 0 || dist > n || !dp[j][dist])
                    continue;
                dp[i][dist] = 1;
                if (dist > 0)
                    dp[i][dist - 1] = 1;
                if (dist < n)
                    dp[i][dist + 1] = 1;
                if (i == n - 1)
                    return true;
            }
        }
        return false;
    }
};

// Memoization - Top Down Approach
class Solution
{
    vector<vector<int>> dp;
    bool solve(vector<int> &stones, int step = 1, int index = 2, int lastIndex = 1)
    {
        if (index == stones.size())
        {
            return true;
        }
        if (dp[lastIndex][step] != -1)
            return false;
        while (index < stones.size() && stones[index] <= stones[lastIndex] + step + 1)
        {
            if (step + stones[lastIndex] == stones[index] && (dp[lastIndex][step] = solve(stones, step, index + 1, index)))
            {
                return true;
            }
            else if (step - 1 + stones[lastIndex] == stones[index] && (dp[lastIndex][step] = solve(stones, step - 1, index + 1, index)))
            {
                return true;
            }
            else if (step + 1 + stones[lastIndex] == stones[index] && (dp[lastIndex][step] = solve(stones, step + 1, index + 1, index)))
            {
                return true;
            }
            index++;
        }
        return dp[lastIndex][step] = false;
    }

public:
    bool canCross(vector<int> &stones)
    {
        dp.resize(stones.size() + 1, vector<int>(2001, -1));
        int step = 1;
        if (stones[1] != 1)
            return false;
        return solve(stones);
    }
};
