#include<bits/stdc++.h>
using namespace std;

int maxProductSubarr(int arr[] , int n){
    int maxpro = INT_MIN;
    int pro = 1;
    for (int i = 0; i < n; i++)
    {
        pro *= arr[i];
        maxpro = max(maxpro , pro);
    }
    pro = 1;
    for (int i = n-1; i >= 0; i--)
    {
        pro *= arr[i];
        maxpro = max(maxpro , pro);
    }
    return maxpro;
}

int LIS(int arr[] , int n){
    vector<int> res(n ,1);
    for (int i = 1; i < n; i++)
    {
        res[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && res[i] < res[j]+1)
            {
                res[i] = res[j]+1;
            }
        }
    }
    return *max_element(res.begin() , res.end());
}

int LCS(string s1 , string s2){
    int n = s1.length();
    int m = s2.length();
    int dp[n+1][m+1];
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

int Knapsack01(int wt[] , int val[] , int n , int m){
    int dp[n+1][m+1];
    memset(dp , 0 , sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (wt[i-1] <= j)
            {
                dp[i][j] = max(dp[i-1][j] , dp[i-1][j-wt[i-1]]+val[i-1]);
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}

int minDistance(string word1 , string word2){
    int n = word1.length();
    int m = word2.length();

    int dp[n+1][m+1];
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
            if (word1[i-1] == word2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1+min({dp[i-1][j] , dp[i-1][j-1] , dp[i][j-1]});
            }
        }
    }
    return dp[n][m];
}

int maxsumLIS(int arr[] , int n){
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
                lis[i] = arr[i]+lis[j];
            }
        }
    }
    return *max_element(lis , lis+n);
}

int dp[101][101];

int solve(int arr[] , int i , int j){
    if(i>=j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int mn = INT_MAX;
    for(int k =i;k<j;k++){
        int temp = solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        mn = min(mn,temp);
    }
    return dp[i][j] = mn;
}

int matrixchainMultiplication(int arr[] , int n){
    for(int i =0;i<101;i++){
        for(int j =0;j<101;j++){
           dp[i][j] = -1;
        }
    }
    return solve(arr,1,n-1);
}

int minPathSum(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();

    int dp[n][m];
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = dp[0][i-1] + grid[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[n-1][m-1];
}

int coinChange(vector<int>& coins, int amount) {
    int n = coins.size();
    int dp[n+1][amount+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=amount;j++){
            if(i == 0 || j == 0){
                dp[i][j] = (j == 0) ? 0 : INT_MAX - 1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=amount;j++){
            if(coins[i-1] <= j){
                dp[i][j] = min(dp[i-1][j] , 1+dp[i][j-coins[i-1]]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][amount] == INT_MAX-1 ? -1 : dp[n][amount];
}

bool subsetsum(vector<int> nums , int sum , int n){
    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++){
        dp[i][0] = true;
    }
    for(int i=1;i<=sum;i++){
        dp[0][i] = false;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(nums[i-1] <= j){
                dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

bool canPartition(vector<int>& nums) {
    int sum = 0;
    int n = nums.size();
    for(int i=0;i<n;i++){
        sum += nums[i];
    }
    if(sum%2 != 0){
        return false;
    }
    return subsetsum(nums , sum/2 , n);
}

int minCost(int n, vector<int>& A) {
    A.push_back(0);
    A.push_back(n);
    sort(begin(A), end(A));
    int N = A.size(), inf = INT_MAX;
    vector<vector<int>> dp(N, vector<int>(N, inf));
    for (int i = 0; i + 1 < N; ++i) dp[i][i + 1] = 0;
    for (int i = 0; i + 2 < N; ++i) dp[i][i + 2] = A[i + 2] - A[i];
    for (int i = N - 4; i >= 0; --i) {
        for (int j = i + 3; j < N; ++j) {
            int val = inf;
            for (int k = i + 1; k < j; ++k) val = min(val, dp[i][k] + dp[k][j]);
            dp[i][j] = val + A[j] - A[i];
        }
    }
    return dp[0][N - 1];
}

int tb[201][201];
int solve(int n,int k){
    if(k==1 || k==0||n==1){
        return k;
    }
    if(tb[n][k]!=-1){
        return tb[n][k];
    }
    int ans = INT_MAX;
    for(int i=1;i<=k;i++){
        int temp = max(solve(n-1,i-1),solve(n,k-i))+1;
        ans = min(ans,temp);
    }
    return tb[n][k] = ans;
}
    
int eggDrop(int n, int k) 
{
    memset(tb,-1,sizeof(tb));
    return solve(n,k);
}

int wordBreak(string s, vector<string> &wordDict) {
    vector<bool> dp(s.size()+1, false);
    dp[0] = true;
        
    for (int i = 1; i <= s.size(); i++)
        for (int j = 0; j < i; j++)
            if ((dp[j]) && (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j)) != wordDict.end())) {
                dp[i] = true;
                break;
            }
    return dp.back();
}

int palindromicPartition(string str)
{
    int cut[str.length()];
    bool pal[str.length()][str.length()];
    memset(pal , false , sizeof(pal));
    for(int i=0;i<str.length();i++){
        int minicut = i;
        for(int j=0;j<=i;j++){
            if(str[i] == str[j] && (i-j < 2 || pal[j+1][i-1])){
                pal[j][i] = true;
                minicut = min(minicut , j==0 ? 0 : (cut[j-1]+1));
            }
        }
        cut[i] = minicut;
    }
    return cut[str.length()-1];
}


int main(){
    
}