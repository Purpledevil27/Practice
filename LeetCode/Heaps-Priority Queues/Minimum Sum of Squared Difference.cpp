// https://leetcode.com/problems/minimum-sum-of-squared-difference/

/*You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.

The sum of squared difference of arrays nums1 and nums2 is defined as the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n.

You are also given two positive integers k1 and k2. You can modify any of the elements of nums1 by +1 or -1 at most k1 times.
Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times.

Return the minimum sum of squared difference after modifying array nums1 at most k1 times and modifying array nums2 at most k2 times.

Note: You are allowed to modify the array elements to become negative integers.

Example 1:

Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
Output: 579
Explanation: The elements in nums1 and nums2 cannot be modified because k1 = 0 and k2 = 0.
The sum of square difference will be: (1 - 2)2 + (2 - 10)2 + (3 - 20)2 + (4 - 19)2 = 579.

Example 2:

Input: nums1 = [1,4,10,12], nums2 = [5,8,6,9], k1 = 1, k2 = 1
Output: 43
Explanation: One way to obtain the minimum sum of square difference is:
- Increase nums1[0] once.
- Increase nums2[2] once.
The minimum of the sum of square difference will be:
(2 - 5)2 + (4 - 8)2 + (10 - 7)2 + (12 - 9)2 = 43.
Note that, there are other ways to obtain the minimum of the sum of square difference, but there is no way to obtain a sum smaller than 43.

Constraints:

n == nums1.length == nums2.length
1 <= n <= 10^5
0 <= nums1[i], nums2[i] <= 10^5
0 <= k1, k2 <= 10^9
*/

#include <bits/stdc++.h>
using namespace std;

// Using Bucket Sort - Greedy
class Solution
{
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        int n = nums2.size();
        for (int i = 0; i < n; i++)
        {
            nums1[i] = abs(nums1[i] - nums2[i]);
        }
        int m = *max_element(nums1.begin(), nums1.end());
        vector<int> bucket(m + 1);
        for (int i = 0; i < n; i++)
        {
            bucket[nums1[i]]++;
        }
        int k = k1 + k2;
        for (int i = m; i > 0; i--)
        {
            if (bucket[i] > 0)
            {
                int sub = min(bucket[i], k);
                bucket[i] -= sub;
                bucket[i - 1] += sub;
                k -= sub;
            }
        }
        long long ans = 0;
        for (long long i = m; i > 0; i--)
        {
            ans += bucket[i] * i * i;
        }
        return ans;
    }
};

// Using priority Queue - Gives TLE
class Solution
{
public:
    long long minSumSquareDiff(vector<int> &nums1, vector<int> &nums2, int k1, int k2)
    {
        priority_queue<long long> d;
        int n = nums1.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            long long j = abs(nums2[i] - nums1[i]);
            d.push(j);
            ans += (j * j);
        }
        int count = k1 + k2, pos = 0;
        while (count != 0)
        {
            count--;
            if (d.top())
            {
                long long k = d.top();
                ans -= k * k;
                ans += ((k - 1) * (k - 1));
                d.pop();
                d.push(k - 1);
            }
            else
            {
                break;
            }
        }
        return ans;
    }
};