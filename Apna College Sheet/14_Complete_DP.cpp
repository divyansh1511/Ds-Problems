#include <bits/stdc++.h>
using namespace std;

int knapsackdupli(int wt[], int val[], int n, int W)
{
    int dp[n + 1][W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(dp[i][j - wt[i - 1]] + val[i - 1], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

long long int countBT(int h)
{
    long long ans = 0;
    long long int dp[h + 1];
    long long mod = 1e9 + 7;
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= h; i++)
    {
        dp[i] = (dp[i - 1] * (2 * dp[i - 2] + dp[i - 1])) % mod;
    }
    return dp[h];
}

long long int count(long long int n)
{
    long long int table[n + 1], i;
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for (int i = 3; i <= n; i++)
    {
        table[i] += table[i - 3];
    }
    for (int i = 5; i <= n; i++)
    {
        table[i] += table[i - 5];
    }
    for (int i = 10; i <= n; i++)
    {
        table[i] += table[i - 10];
    }
    return table[n];
}

int maxSubstring(string S)
{
    int sum = 0, maxi = -1;
    for (int i = 0; i < S.length(); i++)
    {
        if (sum < 0)
        {
            sum = 0;
        }
        if (S[i] == '0')
        {
            sum++;
        }
        else
        {
            sum--;
        }
        maxi = max(maxi, sum);
    }
    return maxi;
}

int climbStairs(int n)
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

int permutationCoeff(int n, int k)
{
    int P[n + 1][k + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= std::min(i, k); j++)
        {
            if (j == 0)
                P[i][j] = 1;
            else
                P[i][j] = P[i - 1][j] +
                          (j * P[i - 1][j - 1]);
            P[i][j + 1] = 0;
        }
    }
    return P[n][k];
}

int LongestRepeatingSubsequence(string str)
{
    int n = str.length();
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str[i - 1] == str[j - 1] && i != j)
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][n];
}

int coinChange(vector<int> &coins, int amount)
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
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
}

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, 1);
    for (int i = 1; i < n; i++)
    {
        res[i] = 1;
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

int longestCommonSubsequence(string text1, string text2)
{
    int n = text1.length();
    int m = text2.length();
    int dp[n + 1][m + 2];
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
            if (text1[i - 1] == text2[j - 1])
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

bool wordBreak(string s, vector<string> &wordDict)
{
    vector<bool> dp(s.size() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.size(); i++)
        for (int j = 0; j < i; j++)
            if ((dp[j]) && (find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()))
            {
                dp[i] = true;
                break;
            }
    return dp.back();
}

//------------all done in leetcode days

int main()
{
}