#include<bits/stdc++.h>
using namespace std;

void helper1(vector<int> v , int n , int st , int sum , vector<int> &ans){
    if (st == n)
    {
        ans.push_back(sum);
        return;
    }
    helper1(v , n , st+1 , sum , ans);
    helper1(v , n , st+1 , sum+v[st] , ans);
}

vector<int> SubsetSums(vector<int> v){
    int n = v.size();
    vector<int> ans;
    helper1(v , n , 0 , 0 , ans);
    sort(ans.begin() , ans.end());
    return ans;
}

void helper2(vector<int> v , int st , vector<int> tmp , vector<vector<int>> &ans){
    ans.push_back(tmp);
    for (int i = st; i < v.size(); i++)
    {
        if (i != st && v[i] == v[i-1])
        {
            continue;
        }
        tmp.push_back(v[i]);
        helper2(v , i+1 , tmp , ans);
        tmp.pop_back();
    }
}

vector<vector<int>> Subsets(vector<int> v){
    vector<vector<int>> ans;
    vector<int> tmp;
    sort(v.begin() , v.end());
    helper2(v , 0 , tmp , ans);
    return ans;
}

void helper3(vector<int> v , int st , int target , vector<int> tmp , vector<vector<int>> &ans){
    if (st == v.size())
    {
        if (target == 0)
        {
            ans.push_back(tmp);
        }
        return;
    }
    if (v[st] <= target)
    {
        tmp.push_back(v[st]);
        helper3(v , st , target-v[st] , tmp , ans);
        tmp.pop_back();
    }
    helper3(v , st+1 , target , tmp , ans);
}

vector<vector<int>> CombinationSum(vector<int> &v , int target){
    vector<vector<int>> ans;
    vector<int> tmp;
    helper3(v , 0 , target , tmp , ans);
    return ans;
}

void helper4(vector<int> v , int target , vector<vector<int>> &ans , vector<int> tmp , int ind){
    if (target == 0)
    {
        ans.push_back(tmp);
        return;
    }
    for (int i = ind; i < v.size(); i++)
    {
        if (i > ind && v[i] == v[i-1])
        {
            continue;
        }
        if (v[i] > target)
        {
            break;
        }
        tmp.push_back(v[i]);
        helper4(v , target-v[i] , ans , tmp , ind+1);
        tmp.pop_back();
    }
}

vector<vector<int>> CombinationSum2(vector<int> v , int target){
    sort(v.begin() , v.end());
    vector<vector<int>> ans;
    vector<int> tmp;
    helper4(v , target , ans , tmp , 0);
    return ans;
}

bool isPalindrome(string s , int i , int j){
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void helper5(string s , int st , vector<string> v , vector<vector<string>> &ans){
    if (st == s.size())
    {
        ans.push_back(v);
        return;
    }
    for (int i = st; i < s.size(); i++)
    {
        if (isPalindrome(s , st , i))
        {
            v.push_back(s.substr(st , i-st+1));
            helper5(s , i , v , ans);
            v.pop_back();
        }
    }
}

vector<vector<string>> PalindromePartition(string s){
    vector<vector<string>> ans;
    if (s.empty())
    {
        return ans;
    }
    vector<string> v;
    helper5(s , 0 , v , ans);
    return ans;
}

string getKthPermutation(int n , int k){        //---first method is recursion and second opti
    vector<int> v;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        v.push_back(i);
        fact *= i;
    }
    v.push_back(n);
    string ans = "";
    k = k-1;
    while (true)
    {
        ans += to_string(v[k/fact]);
        v.erase(v.begin()+k/fact);
        if (v.size() == 0)
        {
            break;
        }
        k = k%fact;
        fact = fact%v.size();
    }
    return ans;
}

void helper6(vector<int> nums , int st , vector<vector<int>> &ans){
    if (st >= nums.size())
    {
        ans.push_back(nums);
    }
    for (int i = st; i < nums.size(); i++)
    {
        swap(nums[i] , nums[st]);
        helper6(nums , i+1 , ans);
        swap(nums[i] , nums[st]);
    }
}

vector<vector<int>> Permute(vector<int> &nums){
    vector<vector<int>> ans;
    helper6(nums , 0 , ans);
    return ans;
}

bool isValid(vector<string> &board , int row , int col){
    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row , j = col; i >= 0 && j >= 0; i-- , j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row , j = col; i >= 0 && j < board.size(); i-- , j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void helper7(vector<string> &board , int row , vector<vector<string>> &ans){
    if (row == board.size())
    {
        ans.push_back(board);
        return;
    }
    for (int i = 0; i < row; i++)
    {
        if (isValid(board , row , i))
        {
            board[row][i] = 'Q';
            helper7(board , row+1 , ans);
            board[row][i] = '.';
        }
    }
}

vector<vector<string>> solveNqueens(int n){
    if (n <= 0)
    {
        return {{}};
    }
    vector<string> board(n , string(n , '.'));
    vector<vector<string>> ans;
    helper7(board , 0 , ans);
    return ans;
}

bool isSafe(vector<vector<char>> &board , int i , int j , char c){
    int row = i - i%3 , col = j - j%3;
    for(int x=0;x<9;x++){
        if(board[x][j] == c){
            return false;
        }
    }
    for(int y=0;y<9;y++){
        if(board[i][y] == c){
            return false;
        }
    }
    for(int x = 0;x<3;x++){
        for(int y=0;y<3;y++){
            if(board[row + x][col+y] == c){
                return false;
            }
        }
    }
    return true;
}

bool helper8(vector<vector<char>> &board , int i , int j){
    if (i == 9)
    {
        return true;
    }
    if (j == 9)
    {
        return helper8(board , i+1 , j);
    }
    if (board[i][j] != '.')
    {
        return helper8(board , i , j+1);
    }
    for(char c='1';c<='9';c++){
        if (isSafe(board , i , j , c))
        {
            board[i][j] = c;
            if (helper8(board , i , j+1))
            {
                return true;
            }
            board[i][j] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>> &board){
    helper8(board , 0 , 0);
}

bool possiblecol(int color, int node, bool gr[101][101], vector<int> col,int n){
        for(int i = 0;i<n;i++){
            if(i!=node && gr[node][i]==1 && col[i]==color)
                return false;
        }
        return true;
    }

bool solve(int node, int n, bool gr[101][101], vector<int> &col, int m){
        if(n==node)
            return true;
            
        for(int i=1;i<=m;i++){
            if(possiblecol(i,node,gr,col,n)){
                col[node] = i;
                if(solve(node+1,n,gr,col,m))
                    return true;
                
                col[node] = 0;
            }
        }
        
        return false;
    }

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int> adj[n];
    
    int i,j;
 
        
        vector<int> color(n);
        
        return solve(0,n,graph,color,m);

}

void dfs(int row,int col,vector<vector<int>> &m,int n,string op,vector<string>& ans){
    if(row<0 || col<0 || row>=n || col>=n || m[row][col]==0) return;
       
    if(row==n-1 && col==n-1){
        ans.push_back(op);return;
    }
       //do
    m[row][col]=0;
    dfs(row+1,col,m,n,op+'D',ans);
    dfs(row-1,col,m,n,op+'U',ans);
    dfs(row,col+1,m,n,op+'R',ans);
    dfs(row,col-1,m,n,op+'L',ans);
    m[row][col]=1;
}

vector<string> findPath(vector<vector<int>> &m, int n) {
    if(m[0][0]==0 || m[n-1][n-1]==0) return {"-1"};
    vector<string> ans;
    string op="";
    dfs(0,0,m,n,op,ans);
    return ans;
}

int main(){

}