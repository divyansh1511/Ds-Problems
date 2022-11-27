#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[] , int val[] , int W , int n){
    if (W == 0 || n == 0)
    {
        return 0;
    }
    if (wt[n-1] <= W)
    {
        return max(knapsack(wt , val , W-wt[n-1] , n-1) + val[n-1] , knapsack(wt , val , W , n-1));
    }
    else
    {
        return knapsack(wt , val , W , n-1);
    }
}

int KnapsackDp(int wt[] , int val[] , int W , int n){
    int dp[n+1][W+1];
    memset(dp , 0 , sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i-1] <= j)
            {
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

bool SubsetSumProblem(int wt[] , int sum , int n){
    if (n == 0 && sum == 0)
    {
        return true;
    }
    if (n == 0)
    {
        return false;
    }
    if (sum == 0)
    {
        return true;
    }
    if (wt[n-1] <= sum)
    {
        return SubsetSumProblem(wt , sum-wt[n-1] , n-1) || SubsetSumProblem(wt , sum , n-1);
    }
    return SubsetSumProblem(wt , sum , n-1);
}

bool SubsetSumProblemDp(int wt[] , int sum , int n){
    bool dp[n+1][sum+1];
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
            if (wt[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-wt[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

bool EqualSumPartition(int wt[] , int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += wt[i];
    }
    if (sum%2 != 0)
    {
        return false;
    }
    return SubsetSumProblemDp(wt , sum/2 , n);
}

int CountSubsetByGivenSum(int wt[] , int n , int sum){
    if (n == 0 && sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (sum == 0)
    {
        return 1;
    }
    if (wt[n-1] <= sum)
    {
        return CountSubsetByGivenSum(wt , n-1 , sum-wt[n-1]) + CountSubsetByGivenSum(wt , n-1 , sum);
    }
    return CountSubsetByGivenSum(wt , n-1 , sum);
}

int CountSubsetByGivenSumDP(int wt[] , int n , int sum){
    int dp[n+1][sum+1];
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
            if (wt[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-wt[i-1]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int countsubsetsofGivenDiff(int wt[] , int n , int diff){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += wt[i];
    }
    int sum1 = (sum+diff)/2;
    return CountSubsetByGivenSumDP(wt , n , sum1);
}

int Mindifferecesubset(int wt[] , int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += wt[i];
    }
    int dp[n+1][sum+1];
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
            if (wt[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-wt[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }   
        }
    }
    int mn = INT_MAX;
    for (int i = 0; i <= sum; i++)
    {
        if (dp[n][i] == 1)
        {
            mn = min(mn , abs(sum-2*i));
        }
    }
    return mn;
}

int targetsum(int arr[] , int n , int target){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int sum1 = (sum+target)/2;
    if (sum < target || (sum+target)%2 != 0)
    {
        return 0;
    }
    return CountSubsetByGivenSumDP(arr , n , sum1);
}

//---------------------//---------------------//---------------------//---------------------

int UnboundedKnapsack(int wt[] , int val[] , int n , int W){
    if (n == 0 || W == 0)
    {
        return 0;
    }
    if (wt[n-1] <= W)
    {
        return max(UnboundedKnapsack(wt , val , n, W-wt[n-1]) + val[n-1] , UnboundedKnapsack(wt , val , n-1 , W));
    }
    else
    {
        return UnboundedKnapsack(wt , val , n-1, W);
    }
}

int UnboundedKnapsackDP(int wt[] , int val[] , int n , int W){
    int dp[n+1][W+1];
    memset(dp , 0 , sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (wt[i-1] <= j)
            {
                dp[i][j] = max(dp[i][j-wt[i-1]] + val[i-1] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}

int RodCuttingProblem(int len[] , int prices[] , int n , int length){
    if (n == 0 || length == 0)
    {
        return 0;
    }
    if (len[n-1] <= length)
    {
        return max(prices[n-1] + RodCuttingProblem(len , prices , n , length-len[n-1]) , RodCuttingProblem(len , prices , n-1 , length));
    }
    else
    {
        return RodCuttingProblem(len , prices , n-1 , length);
    }
}

int RodCuttingProblemDP(int len[] , int prices[] , int n , int length){
    int dp[n+1][length+1];
    memset(dp , 0 , sizeof(dp));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= length; j++)
        {
            if (len[i-1] <= j)
            {
                dp[i][j] = max(prices[i-1] + dp[i][j-len[i-1]] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][length];
}

int coinchangepr_numberofways(int coins[] , int n , int sum){
    if (n == 0 && sum == 0)
    {
        return 1;
    }
    if (n == 0)
    {
        return 0;
    }
    if (sum == 0)
    {
        return 1;
    }
    if (coins[n-1] <= sum)
    {
        return coinchangepr_numberofways(coins , n , sum-coins[n-1]) + coinchangepr_numberofways(coins , n-1 , sum);
    }
    else
    {
        return coinchangepr_numberofways(coins , n-1 , sum);
    }
}

int coinchange_nowDP(int coins[] , int n , int sum){
    int dp[n+1][sum+1];
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
            if (coins[i-1] <= j)
            {
                dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

int coinchangeproble_mincoins(int coins[] , int n , int sum){
    if (n == 0 && sum == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return INT_MAX;
    }
    if (sum == 0)
    {
        return 0;
    }
    if (coins[n-1] <= sum)
    {
        return min(1+coinchangeproble_mincoins(coins , n , sum-coins[n-1]) , coinchangeproble_mincoins(coins , n-1 , sum));
    }
    else
    {
        return coinchangeproble_mincoins(coins , n-1 , sum);
    }
}

int coinchangeproblem_mincoinsDP(int coins[] , int n , int sum){
    int dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = INT_MAX;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i-1] <= j)
            {
                dp[i][j] = min(1+dp[i][j-coins[i-1]] , dp[i-1][j]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

//---------------------//---------------------//---------------------//---------------------

int LongestCommonSubsequence(string s1 , string s2 , int n , int m){
    if (n == 0 || m == 0)
    {
        return 0;
    }
    if (s1[n-1] == s2[m-1])
    {
        return LongestCommonSubsequence(s1 , s2 , n-1 , m-1);
    }
    else
    {
        return max(LongestCommonSubsequence(s1 , s2 , n-1 , m) , LongestCommonSubsequence(s1 , s2 , n , m-1));
    }
}

int LongestCommonSubsequenceDP(string s1 , string s2 , int n , int m){
    int dp[n+1][m+1];
    memset(dp , 0 , sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int LongestCommonSubstring(string s1 , string s2 , int n , int m){
    int dp[n+1][m+1];
    memset(dp , 0 , sizeof(dp));
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
                ans = max(ans , dp[i][j]);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return ans;
}

int LongestPalindromicSubsequence(string a , int n){
    string b = a;
    reverse(b.begin() , b.end());
    return LongestCommonSubsequenceDP(a , b , n , n);
}

string ShortedCommonSuperSequence(string s1 , string s2 , int n , int m){
    int dp[n+1][m+1];
    memset(dp , 0 , sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    int i = n , j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (s1[i-1] == s2[j-1])
        {
            ans += s1[i-1];
            i--;
            j--;
        }
        else
        {
            if (dp[i-1][j] < dp[i][j-1])
            {
                ans += s2[j-1];
                j--;
            }
            else
            {
                ans += s1[i-1];
                i--;
            }
        }
    }
    return ans;
}

int LongestRepeatingSubsequence(string s , int n){
    int dp[n+1][n+1];
    memset(dp , 0 , sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i-1] == s[j-1] && i != j)
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

//---------------------//---------------------//---------------------//---------------------

int LongestIncreasingSubsequence(int arr[] , int n){
    int lis[n];
    lis[0] = 1;
    for (int i = 1; i < n; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j]+1)
            {
                lis[i] = lis[j]+1;
            }
        }
    }
    return *max_element(lis , lis+n);
}

int maximumSumIncreasingSubsequence(int arr[] , int n){
    int lis[n];
    for (int i = 0; i < n; i++)
    {
        lis[i] = arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j]+arr[i])
            {
                lis[i] = lis[j]+arr[i];
            }
        }
    }
    return *max_element(lis , lis+n);
}

int maximumProductIncreasingSubsequence(int arr[] , int n){
    int lis[n];
    for (int i = 0; i < n; i++)
    {
        lis[i] = arr[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j]*arr[i])
            {
                lis[i] = lis[j]*arr[i];
            }
        }
    }
    return *max_element(lis , lis+n);
}

int helper(int arr[] , int i , int j){
    if (i >= j)
    {
        return 0;
    }
    int mini = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int steps = arr[i-1]*arr[k]*arr[j] + helper(arr , i , k) + helper(arr , k+1 , j);
        if (steps < mini)
        {
            mini = steps;
        }
    }
    return mini;
}

int MatrixChainMultiplication(int arr[] , int n){
    return helper(arr , 1 , n-1);
}

bool isPalindrome(string s , int a , int b){
    while (a < b)
    {
        if (s[a] != s[b])
        {
            return false;
        }
        a++;
        b--;
    }
    return true;
}

int helper1(string s , int i , int j){
    if (i >= j)
    {
        return 0;
    }
    if (isPalindrome(s , i , j))
    {
        return 0;
    }
    int mini = INT_MAX;
    for (int k = i+1; k < j; k++)
    {
        int tmp = 1 + helper1(s , i , k) + helper1(s , k+1 , j);
        if (tmp < mini)
        {
            mini = tmp;
        }
    }
    return mini;
}

int PalindromePartition(string s , int n){
    return helper1(s , 0 , n-1);
}

int main(){

}