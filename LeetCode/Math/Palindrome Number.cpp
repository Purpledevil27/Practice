// https://leetcode.com/problems/palindrome-number/

/*Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward.

For example, 121 is a palindrome while 123 is not.

Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Constraints:
-2^31 <= x <= 2^31 - 1
*/

#include <bits/stdc++.h>
using namespace std;

// Approach #1
class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        long long num = x;
        long long num2 = 0;
        while (x)
        {
            num2 = 10 * num2 + x % 10;
            x /= 10;
        }
        return num == num2;
    }
};

// Approach #2
class Solution
{
public:
    bool isPalindrome(int x)
    {
        // -ve no or last digit is 0 but not first digit
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }
        int revNum = 0;
        while (x > revNum)
        {
            revNum = revNum * 10 + x % 10;
            x /= 10;
        }

        return x == revNum || x == revNum / 10;
    }
};