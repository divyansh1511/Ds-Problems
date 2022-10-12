#include <bits/stdc++.h>
using namespace std;

int CoinChangeProblem(int coins[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
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
    return dp[n][sum];
}

int knapsack01(int wt[], int val[], int n, int W)
{
    int dp[n + 1][W + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i - 1] <= j)
            {
                dp[i][j] = max(dp[i - 1][j - wt[i - 1]] + val[i - 1], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][W];
}

int nCr(int n, int r)
{
    int mod = 1e9 + 7;
    vector<vector<int>> dp(n + 1, vector<int>(r + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= r; i++)
    {
        dp[0][1] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= r; j++)
        {
            if (i == j)
                dp[i][j] = 1;
            else if (i < j)
                dp[i][j] = 0;
            else
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
        }
    }
    return dp[n][r];
}

int PermutationCofficient(int n, int k)
{
    int fact[n + 1];
    fact[0] = 1;
    for (int i = 1; i < n; i++)
    {
        fact[i] = i * fact[i - 1];
    }
    return fact[n] / fact[n - k];
}

int FindCatlanNumber(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

int EditDistance(string s, string t)
{
    int n = s.length();
    int m = t.length();
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
            else if (s[i - 1] == t[j - 1])
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

bool SubsetSumProblem(int arr[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int FriendsProblem(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    long *dp = new long[n + 1];
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = (dp[i - 1] + (i - 1) * dp[i - 2]) % 1000000007;
    }
    return dp[n];
}

int MaxGold(vector<vector<int>> arr, int n, int m)
{
    int dp[n][m];

    for (int i = 0; i < n; i++)
    {
        dp[i][0] = arr[i][0];
    }
    for (int j = 1; j < m; j++)
    {
        for (int i = 0; i < n; i++)
        {
            int r = arr[i][j - 1];
            int rup = (i == 0) ? 0 : dp[i - 1][j - 1];
            int rdown = (i == n - 1) ? 0 : dp[i + 1][j - 1];

            dp[i][j] = arr[i][j] + max({r, rup, rdown});
        }
    }
    int res = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        res = max(res, dp[i][m - 1]);
    }
    return res;
}

int PaintingFence(int n, int k)
{
    int dp[n + 1];
    if (n == 1)
    {
        return k;
    }
    else if (n == 2)
    {
        return k * k;
    }
    dp[1] = k;
    dp[2] = k * k;
    for (int i = k; i <= n; i++)
    {
        dp[i] = ((k - 1) * dp[i - 1] + (k - 1) * dp[i - 2]);
    }
    return dp[n];
}

int MaximizeTheCuts(int n, int a, int b, int c)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 0; i <= n; i++)
    {
        dp[i] = -1;
        if (i - a >= 0)
        {
            dp[i] = max(dp[i], dp[i - a]);
        }
        if (i - b >= 0)
        {
            dp[i] = max(dp[i], dp[i - b]);
        }
        if (i - c >= 0)
        {
            dp[i] = max(dp[i], dp[i - c]);
        }
        if (dp[i] != -1)
        {
            dp[i]++;
        }
    }
    return dp[n] == -1 ? 0 : dp[n];
}

int LongestCommonSubsequence(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

int LongestRepeatedSubsequence(string str)
{
    int n = str.length();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));
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

int LongestIncreasingSubsequence(int arr[], int n)
{
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }
    return *max_element(lis, lis + n);
}

int LCSof3(string s1, string s2, string s3, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> v(n1 + 1, vector<vector<int>>(n2 + 1, vector<int>(n3 + 1, 0)));

    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= n2; i++)
        {
            for (int k = 1; k <= n3; k++)
            {
                if (s1[i - 1] == s2[j - 1] && s2[j - 1] == s3[k - 1])
                {
                    v[i][j][k] = 1 + v[i - 1][j - 1][k - 1];
                }
                else
                {
                    v[i][j][k] = max(v[i - 1][j][k], v[i][j - 1][k], v[i][j][k - 1]);
                }
            }
        }
    }
    return v[n1][n2][n3];
}

int MaximumSumIncreasingSubsequence(int arr[], int n)
{
    int lis[n];
    for (int i = 0; i < n; i++)
    {
        lis[i] = arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j] + arr[i])
            {
                lis[i] = lis[j] + arr[i];
            }
        }
    }
    return *max_element(lis, lis + n);
}

int ProductSubsequence(vector<int> &arr, int k)
{
    int n = arr.size();
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1];
            if (arr[j - 1] <= i)
            {
                dp[i][j] += dp[i / arr[j - 1]][j - 1] + 1;
            }
        }
    }
    return dp[k][n];
}

int LongestSubsequencewithdiff(int arr[], int n)
{
    int dp[n + 1];
    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (abs(arr[i] - arr[j]) == 1)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp, dp + n);
}

int MaxSumof3consequtive(int arr[], int n)
{
    int sum[n];
    if (n >= 1)
    {
        sum[0] = arr[0];
    }
    if (n >= 2)
    {
        sum[1] = arr[0] + arr[1];
    }
    if (n > 2)
    {
        sum[2] = max({sum[1], arr[1] + arr[2], arr[0] + arr[2]});
    }
    for (int i = 3; i < n; i++)
    {
        sum[i] = max(max(sum[i - 1], sum[i - 1] + arr[i]), arr[i] + arr[i - 1] + sum[i - 3]);
    }
    return sum[n - 1];
}

int tb[201][201];
int solve(int n, int k)
{
    if (k == 1 || k == 0 || n == 1)
    {
        return k;
    }
    if (tb[n][k] != -1)
    {
        return tb[n][k];
    }
    int ans = INT_MAX;
    for (int i = 1; i <= k; i++)
    {
        int temp = max(solve(n - 1, i - 1), solve(n, k - i)) + 1;
        ans = min(ans, temp);
    }
    return tb[n][k] = ans;
}
int eggDrop(int n, int k)
{
    memset(tb, -1, sizeof(tb));
    return solve(n, k);
}

static bool cmp(pair<int, int> &v1, pair<int, int> &v2)
{
    return v1.first < v2.first;
}

int maxChainLen(vector<pair<int, int>> p, int n)
{
    sort(p.begin(), p.end(), cmp);
    int dp[n];
    dp[0] = 1;

    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        int mx = 0;
        for (int j = 0; j < i; j++)
        {
            if (p[i].first > p[j].second)
            {
                mx = max(mx, dp[j]);
            }
        }

        dp[i] = mx + 1;
        ans = max(ans, dp[i]);
    }

    return ans;
}

int LargestSquare(int n, int m, vector<vector<int>> &v)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j])
            {
                v[i][j] += min({v[i - 1][j], v[i - 1][j - 1], v[i][j - 1]});
            }
        }
    }
    int ans = 0;
    for (auto it : v)
    {
        for (auto a : it)
        {
            ans = max(ans, a);
        }
    }
    return ans;
}

int maximumPath(int N, vector<vector<int>> mat)
{
    int n = mat.size(), m = mat[0].size();
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            int temp = mat[i + 1][j];
            if (j - 1 >= 0)
                temp = max(temp, mat[i + 1][j - 1]);
            if (j + 1 < n)
                temp = max(temp, mat[i + 1][j + 1]);
            mat[i][j] += temp;
        }
    }
    int ans = 0;
    for (int j = 0; j < m; j++)
    {
        ans = max(ans, mat[0][j]);
    }
    return ans;
}

int removalstoMaxandMin(vector<int> &a, int k)
{
    sort(a.begin(), a.end());
    int n = a.size();
    int dp[n][n];
    for (int g = 0; g < n; g++)
    {
        for (int i = 0, j = g; j < n; i++, j++)
        {
            if (g == 0)
            {
                dp[i][j] = 0;
            }
            if (g == 1)
            {
                dp[i][j] = (a[j] - a[i] <= k) ? 0 : 1;
            }
            else
            {
                if (a[j] - a[i] <= k)
                {
                    dp[i][j] = 0;
                }
                else if (a[j] - a[i] > k)
                {
                    dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
    }
    return dp[0][n - 1];
}

int LongestCommonSubstring(string s1, string s2, int n, int m)
{
    int dp[n + 1][m + 1];
    int res = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                res = max(res, dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[n][m];
}

int ReachGivenScore(int n)
{
    int dp[n + 1];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] += dp[i - 3];
    }
    for (int i = 5; i <= n; i++)
    {
        dp[i] += dp[i - 5];
    }
    for (int i = 10; i <= n; i++)
    {
        dp[i] += dp[i - 10];
    }
    return dp[n];
}

int UnboundedKnapsack(int wt[], int val[], int n, int W)
{
    int dp[n + 1][W + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
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

int wordBreakProblem(string s, vector<string> words)
{
    vector<bool> dp(s.length() + 1, false);
    dp[0] = true;
    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && (find(words.begin(), words.end(), s.substr(j, i - j)) != words.end()))
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}

int LongestPalindromeSubsequence(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    int n = s.length();
    return LongestCommonSubsequence(s, a);
}

string longestPalindrome(string s)
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

int palindromicPartition(string str)
{
    int cut[str.length()];
    bool pal[str.length()][str.length()];
    memset(pal, false, sizeof(pal));
    for (int i = 0; i < str.length(); i++)
    {
        int minicut = i;
        for (int j = 0; j <= i; j++)
        {
            if (str[i] == str[j] && (i - j < 2 || pal[j + 1][i - 1]))
            {
                pal[j][i] = true;
                minicut = min(minicut, j == 0 ? 0 : (cut[j - 1] + 1));
            }
        }
        cut[i] = minicut;
    }
    return cut[str.length() - 1];
}

int maxProfitAtmostktransaction(int K, int N, int A[])
{
    int dp[K + 1][N];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= K; i++)
    {
        int mx = INT_MIN;
        for (int j = 1; j < N; j++)
        {
            mx = max(mx, dp[i - 1][j - 1] - A[j - 1]);
            dp[i][j] = max(dp[i][j - 1], mx + A[j]);
        }
    }

    return dp[K][N - 1];
}

bool isInterleave(string A, string B, string C)
{
    int n = A.length(), m = B.length(), w = C.length();
    if (n + m != w)
    {
        return false;
    }
    bool dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = dp[i][j - 1] && B[j - 1] == C[i + j - 1];
            }
            else if (j == 0)
            {
                dp[i][j] = dp[i - 1][j] && A[i - 1] == C[i + j - 1];
            }
            else
            {
                dp[i][j] = (dp[i][j - 1] && B[j - 1] == C[i + j - 1]) || (dp[i - 1][j] && A[i - 1] == C[i + j - 1]);
            }
        }
    }
    return dp[n][m];
}

static bool cmp1(vector<int> &a, vector<int> &b)
{
    return a[1] < b[1] || a[1] == b[1] && a[0] < b[0];
}
int findLongestChain(vector<vector<int>> &pairs)
{
    sort(pairs.begin(), pairs.end(), cmp1);
    int count = 0;
    vector<int> &pair = pairs[0];
    for (int i = 0; i < pairs.size(); i++)
    {
        if (i == 0 || pairs[i][0] > pair[1])
        {
            pair = pairs[i];
            count++;
        }
    }
    return count;
}

int main()
{
}