#include<bits/stdc++.h>
using namespace std;

int LongestCommonSubsequence(string a , string b){
    int n = a.length();
    int m = b.length();
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
            if (a[i-1] == b[j-1])
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

int LongestPalindromicSubstring(string a){
    int n = a.length();
    string s = a;
    reverse(s.begin() , s.end());
    return LongestCommonSubsequence(a , s);
}

int EditDistance(string s1 , string s2){
    int n = s1.length();
    int m = s2.length();
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
            if (s1[i-1] == s2[j-1])
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

int RepeatedSubsequence(string s){
    int n = s.length();
    int dp[n+1][n+1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (dp[i-1] == dp[j-1] && i != j)
            {
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    if (dp[n][n] >= 2)
    {
        return 1;
    }
    return 0;
}

int RegularExpressionMatching(const string a, const string b) {
    int n=a.length(),m=b.length();
    vector<vector<bool>> v(n+1,vector<bool>(m+1));
    for(int i=0;i<=n;i++){
        v[i][0]=false;
    }
    v[0][0]=true;
    for(int i=1;i<=m;i++){
        v[0][i]=true;
        for(int j=1;j<=i;j++){
            if(b[j-1]!='*'){
                v[0][i]=false;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1] || b[j-1]=='?'){
                v[i][j]=v[i-1][j-1];
            }
            else if(b[j-1]=='*'){
                v[i][j]=v[i-1][j] || v[i][j-1];
            }
            else{
                v[i][j]=false;
            }
        }
    }
    return v[n][m];
}

int LengthofLongestSubsequence(vector<int> &v){
    int n = v.size();
    vector<int> Lis(n , 1);
    vector<int> Lds(n , 1);
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((v[i] > v[j]) && (Lis[i] <= Lis[j]))
            {
                Lis[i] = Lis[j]+1;
            }
        }
    }
    
    for (int i = n-2; i >= 0; i--)
    {
        for (int j = n-1; j > i; j--)
        {
            if ((v[i] > v[j]) && (Lds[i] <= Lds[j]))
            {
                Lds[i] = Lds[j]+1;
            }
        }
    }
    int maxi = Lis[0]+Lds[0]-1;
    for (int i = 1; i < n; i++)
    {
        if (Lis[i] + Lds[i] - 1 > maxi)
        {
            maxi = Lis[i]+Lds[i]-1;
        }
    }
    return maxi;
}

int stairs(int n){
    int dp[n+1];
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i-1]+dp[i-2];
    }
    return dp[n];
}

int Lis(vector<int> &v){
    int n = v.size();
    int arr[n];
    arr[0] = 1;
    for (int i = 0; i < n; i++)
    {
        arr[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (v[i] > v[j] && arr[i] < arr[j]+1)
            {
                arr[i] = arr[j]+1;
            }
        }
    }
    *max_element(arr , arr+n);
}

int MinjumpArray(vector<int> &A) {
    int n = A.size();
    if (n <= 1)
    {
        return 0;
    }
    if (A[0] == 0)
    {
        return -1;
    }
    int maxreach = A[0];
    int step = A[0];
    int jumps = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n-1)
        {
            return jumps;
        }
        maxreach = max(maxreach , i + A[i]);
        step--;
        if (step == 0)
        {
            jumps++;
            if (i >= maxreach)
            {
                return -1;
            }
            step = maxreach - i;
        }
    }
    return -1;
}

int LongestArthematicProgression(const vector<int> &A) {
    int n=A.size();
    unordered_map<int ,int> mp;
    int dp[n][n];
    memset(dp,0,sizeof(dp));
    int ans=1;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {

            int diff=A[j]-A[i];
            int need=2*A[i]-A[j];

            if(mp.find(need)!=mp.end())
            {
                int pos=mp[need];

                dp[i][j]=max(dp[i][j],dp[pos][i]+1);
            }
            else
                dp[i][j]=2;
                
            ans=max(ans,dp[i][j]);
        }
        mp[A[i]]=i;
    }
    return ans;
}

int BestTimeToBuySellIII(const vector<int> &prices) {
    if(!prices.size())
        return 0;
    int buy1    = INT_MAX;
    int profit1 = INT_MIN;
    int buy2    = INT_MAX;
    int profit2 = INT_MIN;
    for(int i = 0; i < prices.size(); i++){
        buy1    = min(buy1, prices[i]);
        profit1 = max(profit1, prices[i] - buy1);
        buy2    = min(buy2, prices[i] - profit1);
        profit2 = max(profit2, prices[i] - buy2);
    }
    return profit2;
}

int longestValidParentheses(string A) {
    stack<int> s1;
    s1.push(-1);
    int maxi = 0;
    for(int i=0;i<A.length();i++){
        int a = s1.top();
        if(a != -1 && A[i] == ')' && A[a] == '('){
            s1.pop();
            maxi = max(maxi , i - s1.top());
        }
        else{
            s1.push(i);
        }
    }
    return maxi;
}

int MaxPathInTriangle(vector<vector<int> > &A) {
    vector<int> mini = A[A.size()-1];
    for ( int i = A.size() - 2; i>= 0 ; --i )
        for ( int j = 0; j < A[i].size() ; ++ j )
            mini[j] = A[i][j] + max(mini[j],mini[j+1]);
    return mini[0];
}

int MaxSizeofSquare(vector<vector<int> > &A) {
    int ans=0;
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            if(A[i][j]==1){
               if(i&&j) A[i][j]=min(min(A[i-1][j],A[i][j-1]),A[i-1][j-1])+1;
                ans=max(ans,A[i][j]);
            }
        }
    }
    return ans*ans;
}

int MinDiffSubset(vector<int> &arr) {
    int n = arr.size();
    int W = 0;
    for(int i=0;i<n;i++){
        W += arr[i];
    }
    int dp[n+1][W+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 1; i <= W; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= W; j++)
        {
            if (arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    vector<int> v;
    for(int i=0;i<=W;i++){
        if(dp[n][i] == true){
            v.push_back(i);
        }
    }
    int mn = INT_MAX;
    for(int i=0;i<=v.size()/2;i++){
        mn = min(mn , abs(W-2*v[i]));
    }
    return mn;
}

bool isPalindrome(string A, int i, int j){
    while(i<j){
        if(A[i]!=A[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}


int PalindromePartition(string A) {
    int n=A.length();
    vector<int>dp(n,INT_MAX);
    for(int i=0;i<n;i++){
        for(int j=i;j>=0;j--){
            if(isPalindrome(A,j,i)){
                if(j>0) dp[i]=min(dp[i],dp[j-1]+1);
                else dp[i]=0;
            }
        }
    }
    return dp[n-1];
    
}

int wordBreak(string A, vector<string> &B) {
    int m  = B.size();
    int len = A.size();
    bool dp[len+1];
    dp[0] = 1;
    for(int i =1;i<len+1;i++) {
        dp[i] = 0;
        for(int j=0;j<m;j++) {
            string w = B[j];
            if(B[j].size()<=i) {
                if(B[j] == A.substr(i-B[j].size(),B[j].size()) && dp[i-B[j].size()]==1) {
                    dp[i] =1;
                    break;
                }
            }
        }
    }
    return dp[len];
}

int UniqueBSTs(int n) {         // CATALAN NUMBERS
    int dp[n+1]={0};
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<i;j++)
            dp[i] += dp[j]*dp[i-j-1];
    return dp[n];
}



int main(){

}