#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n)
{
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int getLengthOfLIS(vector<int> &A)
{
    int n = A.size();
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dp[j - 1] < A[i] && A[i] < dp[j])
            {
                dp[j] = A[i];
            }
        }
    }
    int result = 0, counter = 0;
    for (int x : dp)
    {
        if (x != INT_MAX)
        {
            result = counter;
        }
        counter++;
    }
    return result;
}

int getLengthOfLCS(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int maxSumSubsequence(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp = arr;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] >= arr[j])
            {
                dp[i] = max(dp[j] + arr[i], dp[i]);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

string lps(string s)
{
    int n = s.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    int mxlen = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        mxlen = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            start = i;
            mxlen = 2;
        }
    }
    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
            {
                dp[i][j] = 1;
                if (k > mxlen)
                {
                    start = i;
                    mxlen = k;
                }
            }
        }
    }
    return s.substr(start, mxlen);
}

int minOperations(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]});
            }
        }
    }
    return dp[n][m];
}

bool hasValidSubset(vector<int> &A, int target)
{
    int n = A.size();
    int dp[n + 1][target + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= target; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (A[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - A[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
}

int subsetSum(vector<int> &A, int target)
{
    int n = A.size();
    int dp[n + 1][target + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i <= target; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (A[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - A[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
}

int findMaxPath(vector<vector<int>> &M)
{
    int n = M.size();
    int m = M[0].size();
    int maxi = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (j > 0 && j < m - 1)
            {
                M[i][j] += max({M[i - 1][j], M[i - 1][j - 1], M[i - 1][j + 1]});
            }
            else if (j > 0)
            {
                M[i][j] += max(M[i - 1][j], M[i - 1][j - 1]);
            }
            else if (j < m - 1)
            {
                M[i][j] += max(M[i - 1][j], M[i - 1][j + 1]);
            }
            maxi = max(maxi, M[i][j]);
        }
    }
    return maxi;
}

int numberOfCombinations(vector<int> &coins, int target)
{
    int n = coins.size();
    int dp[n + 1][target + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            if (i == 0)
            {
                dp[i][j] = 0;
            }
            else if (j == 0)
            {
                dp[i][j] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= target; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][target];
}

int numDecodings(string s)
{
    int mod = pow(10, 9) + 7;
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
            if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7'))
            {
                dp[i] = (dp[i] + dp[i + 2]) % mod;
            }
        }
    }
    return s.empty() ? 0 : dp[0] % mod;
}

int uniquePaths(int m, int n)
{
    int mod = pow(10, 9) + 7;
    vector<vector<int>> v(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            v[i][j] = (v[i - 1][j] + v[i][j - 1]) % mod;
        }
    }
    return v[m - 1][n - 1] % mod;
}

int maxProduct(vector<int> &A)
{
    int pro = 1;
    int n = A.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        pro *= A[i];
        maxi = max(maxi, pro);
        if (pro == 0)
        {
            pro = 1;
        }
    }
    pro = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        pro *= A[i];
        maxi = max(maxi, pro);
        if (pro == 0)
        {
            pro = 1;
        }
    }
    return maxi;
}

bool wordBreak(string s, vector<string> &w)
{
    int n = s.length();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((dp[j]) && (find(w.begin(), w.end(), s.substr(j, i - j)) != w.end()))
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}

int maxProfit(vector<int> &prices)
{
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for (int i = 0; i < prices.size(); i++)
    {
        mini = min(mini, prices[i]);
        maxi = max(maxi, prices[i] - mini);
    }
    return maxi;
}

int maxProfitII(vector<int> &prices)
{
    int sum = 0;
    for (int i = 0; i < prices.size() - 1; i++)
    {
        if (prices[i] > prices[i + 1])
        {
            continue;
        }
        else
        {
            sum += (prices[i + 1] - prices[i]);
        }
    }
    return sum;
}

int maxProfitIII(vector<int> &prices)
{
    if (prices.size() == 0)
    {
        return 0;
    }
    int buy1 = INT_MAX;
    int profit1 = INT_MIN;
    int buy2 = INT_MAX;
    int profit2 = INT_MIN;
    for (int i = 0; i < prices.size(); i++)
    {
        buy1 = min(buy1, prices[i]);
        profit1 = max(profit1, prices[i] - buy1);
        buy2 = min(buy2, prices[i] - profit1);
        profit2 = max(profit2, prices[i] - buy2);
    }
    return profit2;
}

int maxProfit(vector<int> &prices, int k)
{
    int len = prices.size();
    if (len < 2)
        return 0;
    if (k > len / 2)
    { // simple case
        int ans = 0;
        for (int i = 1; i < len; ++i)
        {
            ans += max(prices[i] - prices[i - 1], 0);
        }
        return ans;
    }
    int hold[k + 1];
    int rele[k + 1];
    for (int i = 0; i <= k; ++i)
    {
        hold[i] = INT_MIN;
        rele[i] = 0;
    }
    int cur;
    for (int i = 0; i < len; ++i)
    {
        cur = prices[i];
        for (int j = k; j > 0; --j)
        {
            rele[j] = max(rele[j], hold[j] + cur);
            hold[j] = max(hold[j], rele[j - 1] - cur);
        }
    }
    return rele[k];
}

bool isMatch(string s, string p)
{
    int n = s.length();
    int m = p.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            if (i == n && j == m)
            {
                dp[i][j] = true;
            }
            else if (i < n && j < m)
            {
                if (s[i] == p[j] || p[j] == '?')
                {
                    dp[i][j] = dp[i + 1][j + 1];
                }
                else if (p[j] == '*')
                {
                    dp[i][j] = dp[i + 1][j] || dp[i][j + 1];
                }
                else
                {
                    dp[i][j] = false;
                }
            }
            else if (i == n && p[j] == '*')
            {
                dp[i][j] = dp[i][j + 1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[0][0];
}

int main()
{
}