#include <bits/stdc++.h>
using namespace std;

//------------------------------------------EASY PROBLEMS-----------------------------------//

int MaximumSubarrsum(int arr[], int n)
{
    int sum = 0;
    int maxsum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = max(arr[i], sum + arr[i]);
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}

int ClimbingStairs(int n)
{
    if (n <= 2)
    {
        return n;
    }
    int arr[n];
    arr[0] = 1;
    arr[1] = 2;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n - 1];
}

vector<int> CountingBits(int n)
{
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        res[i] = res[i & (i - 1)] + 1;
    }
    return res;
}

//------------------------------------------MEDIUM PROBLEMS-----------------------------------//

int DecodeWays(string s)
{
    int n = s.length();
    int dp[n + 1];
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = dp[i + 1];
            if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] == '7'))
            {
                dp[i] += dp[i + 2];
            }
        }
    }
    return s.empty() ? 0 : dp[0];
}

bool WordBreak(string s, vector<string> v)
{
    vector<bool> dp(s.length() + 1, false);
    dp[0] = true;

    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((dp[j]) && find(v.begin(), v.end(), s.substr(j, i - j)) != v.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}

int MaximamSquare(vector<vector<int>> v)
{
    int n = v.size(), m = v[0].size();

    int dp[n][m];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!i || !j || v[i][j] == '0')
            {
                dp[i][j] = v[i][j] - '0';
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + 1;
            }
            ans = max(ans, dp[i][j]);
        }
    }
    return ans * ans;
}

int CoinchangeMinCoins(vector<int> coins, int amount)
{
    int n = coins.size();
    int dp[n + 1][amount + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= amount; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = (j == 0) ? 0 : INT_MAX - 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
}

int MaxProduct(vector<int> nums)
{
    int pro = 1;
    int currmax = INT_MIN;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        pro *= nums[i];
        currmax = max(currmax, pro);
        if (pro == 0)
        {
            pro = 1;
        }
    }
    pro = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        pro *= nums[i];
        currmax = max(currmax, pro);
        if (pro == 0)
        {
            pro = 1;
        }
    }
    return currmax;
}

int MaxLengthofRepeatedSubarr(vector<int> v1, vector<int> v2)
{
    int n = v1.size();
    int m = v2.size();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (v1[i - 1] == v2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
        }
    }
    return ans;
}

int PalindromicSubstring(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n));
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (i + 1 == j)
            {
                dp[i][j] = (s[i] == s[j]) ? 1 : 0;
            }
            else
            {
                dp[i][j] = (s[i] == s[j]) ? dp[i + 1][j - 1] : 0;
            }
            count += dp[i][j];
        }
    }
    return count;
}

int HouseRobbery(vector<int> nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return nums[0];
    }
    if (n == 2)
    {
        return max(nums[0], nums[0]);
    }
    vector<int> v(n, 0);
    v[0] = nums[0];
    v[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        v[i] = max(v[i - 2] + nums[i], v[i - 1]);
    }
    return v[n - 1];
}

int LongestIncreasingSubsequence(vector<int> nums)
{
    int n = nums.size();
    vector<int> res(n, 1);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && res[i] < res[j] + 1)
            {
                res[i] = res[j] + 1;
            }
        }
    }
    return *max_element(res.begin(), res.end());
}

int UniquePaths(int n, int m)
{
    vector<vector<int>> dp(n, vector<int>(m));
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    return dp[n - 1][m - 1];
}

int CountSquareWithOne(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] && i && j)
            {
                v[i][j] += min({v[i - 1][j], v[i - 1][j - 1], v[i][j - 1]});
            }
            res += v[i][j];
        }
    }
    return res;
}

int longestArithSeqLength(vector<int> &A)
{
    int res = 2, n = A.size();
    vector<vector<int>> dp(n, vector<int>(2000, 0));
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            int d = A[j] - A[i] + 1000;
            dp[j][d] = max(2, dp[i][d] + 1);
            res = max(res, dp[j][d]);
        }
    return res;
}

//------------------------------------------HARD PROBLEMS-----------------------------------//

int trappingRainWater(int arr[], int n)
{
    int left[n];
    int right[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - arr[i];
    }
    return ans;
}

bool RegularExpression(string s, string p)
{
    int n = s.length(), m = p.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
            else
            {
                dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
    }
    return dp[n][m];
}

int maxAreaHistogram(vector<int> &histogram)
{
    histogram.push_back(0);
    int area = 0, n = histogram.size();
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && histogram[st.top()] >= histogram[i])
        {
            int h = histogram[st.top()];
            st.pop();
            int left = st.empty() ? -1 : st.top();
            int right = i;
            area = max(area, h * (right - left - 1));
        }
        st.push(i);
    }
    return area;
}

int maximalRectangle(vector<vector<char>> &grid)
{
    int m = grid.size(), n = grid[0].size(), res = 0;
    vector<int> histogram(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
                histogram[j] += 1;
            else
                histogram[j] = 0;
        }
        res = max(res, maxAreaHistogram(histogram));
    }
    return res;
}

int longestValidParentheses(string s)
{
    stack<int> s1;
    s1.push(-1);
    int maxi = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int a = s1.top();
        if (a != -1 && s[i] == ')' && s[a] == '(')
        {
            s1.pop();
            maxi = max(maxi, i - s1.top());
        }
        else
        {
            s1.push(i);
        }
    }
    return maxi;
}

int MinDistance(string word1, string word2)
{
    int n = word1.length();
    int m = word2.length();

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + 1;
            }
        }
    }
    return dp[n][m];
}

bool FrogJump(vector<int> &stones)
{
    int n = stones.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    dp[0][1] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int d = stones[i] - stones[j];
            if (d > 0 && d < n && dp[j][d])
            {
                if (i == n - 1)
                {
                    return true;
                }
                dp[i][d] = true;
                if (d + 1 < n)
                {
                    dp[i][d + 1] = true;
                }
                if (d - 1 < n)
                {
                    dp[i][d - 1] = true;
                }
            }
        }
    }
    return false;
}

int helper(string a, string b, int n1, int n2)
{
    int dp[n1 + 1][n2 + 2];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i <= n1; i++)
    {
        for (int j = 0; j <= n2; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n1][n2];
}

int minInsertions(string s)
{
    int n = s.length();
    string b = s;
    reverse(b.begin(), b.end());
    return n - helper(s, b, n, n);
}

int main()
{
    
}