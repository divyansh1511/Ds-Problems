#include<bits/stdc++.h>
using namespace std;

string GetKthPermutation(int n , int k){
    vector<int> v(n);
    for (int i = 1; i <= n; i++)
    {
        v[i-1] = i;
    }
    while (k--)
    {
        next_permutation(v.begin() , v.end());
    }
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        ans += to_string(v[i]);
    }
    return ans;
}

vector<int>GrayCode(int a){
    vector<int> ans;
    long long n = pow(2 , a);
    for (long long i = 0; i < n; i++)
    {
        int j = i/2;
        ans.push_back(i^j);
    }
    return ans;
}

void helper(vector<int> v , int st , vector<int> tmp , vector<vector<int>> &ans){
    ans.push_back(tmp);
    for (int i = st; i < v.size(); i++)
    {
        tmp.push_back(v[i]);
        helper(v , i+1 , tmp , ans);
        tmp.pop_back();
    }
}

vector<vector<int>> Subset(vector<int> v){
    sort(v.begin() , v.end());
    vector<vector<int>> ans;
    vector<int> tmp;
    helper(v , 0 , tmp , ans);
    return ans;
}

void solve(vector<int> v , vector<vector<int>> &sol , vector<int> curr , int sum , int st){
    if (st == v.size())
    {
        if (sum == 0)
        {
            sol.push_back(curr);
        }
        return;
    }
    if (v[st] <= sum)
    {
        curr.push_back(v[st]);
        solve(v , sol , curr , sum-v[st] , st);
        curr.pop_back();
    }
    solve(v , sol , curr , sum , st+1);
}

vector<vector<int>> CombinationSum(vector<int> v , int k){
    vector<vector<int>> sol;
    vector<int> curr;
    solve(v , sol , curr , k , 0);
    sort(sol.begin() , sol.end());
    return sol;
}

void helper2(vector<int> v , int st , int target , vector<int> tmp , vector<vector<int>> &ans){
    if (target == 0)
    {
        ans.push_back(tmp);
        return;
    }
    for (int i = st; i < v.size(); i++)
    {
        if (i > st && v[i] == v[i-1])
        {
            continue;
        }
        if (v[i] > target)
        {
            break;
        }
        tmp.push_back(v[i]);
        helper2(v , i+1 , target-v[i] , tmp , ans);
        tmp.pop_back();
    }
}

vector<vector<int>> CombinationSumII(vector<int> v , int k){
    sort(v.begin() , v.end());
    vector<vector<int>> ans;
    vector<int> tmp;
    helper2(v , 0 , k , tmp , ans);
    return ans;
}

void helper3(vector<vector<int>> ans , vector<int> tmp , int st , int num , int A , int B){
    if (num == B)
    {
        ans.push_back(tmp);
        return;
    }
    for (int i = st; i < A; i++)
    {
        tmp.push_back(i+1);
        helper3(ans , tmp , i+1 , num+1 , A ,B);
        tmp.pop_back();
    }
}

vector<vector<int>> Combine(int A , int B){
    vector<vector<int>> ans;
    vector<int> tmp;
    helper3(ans , tmp , 0 , 0 , A , B);
    return ans;
}

void helper4(vector<int> v , int st , vector<int> tmp , vector<vector<int>> &ans){
    ans.push_back(tmp);
    for (int i = st; i < v.size(); i++)
    {
        if (i != st && v[i] == v[i-1])
        {
            continue;
        }
        tmp.push_back(v[i]);
        helper4(v , i+1 , tmp , ans);
        tmp.pop_back();
    }
}

vector<vector<int>> SubsetII(vector<int> v){
    vector<vector<int>> ans;
    vector<int> tmp;
    sort(v.begin() , v.end());
    helper4(v , 0 , tmp , ans);
    return ans;
}

void helper5(string s , int st , string tmp , vector<string> &res , vector<string> mp){
    if (st >= s.length())
    {
        res.push_back(tmp);
        return;
    }
    int digit = s[st] - '0';
    string s = mp[digit];
    for(auto it : s){
        tmp.push_back(it);
        helper5(s , st+1 , tmp , res , mp);
        tmp.pop_back();
    }
}

vector<string> LetterCombinations(string s){
    vector<string> mp = {"0" , "1" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
    vector<string> res;
    helper5(s , 0 , "" , res , mp);
    return res;
}

bool isPalindrome(string s , int i , int j){
    while(i<j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}

void helper6(string s , int st , vector<string> path , vector<vector<string>> &ans){
    if (st == s.size())
    {
        ans.push_back(path);
        return;
    }
    for (int i = st; i < s.length(); i++)
    {
        if (isPalindrome(s , st , i))
        {
            path.push_back(s.substr(st , i-st+1));
            helper6(s , i+1 , path, ans);
            path.pop_back();
        }
    }
}

vector<vector<string>> PalindromePartition(string s){
    vector<vector<string>> ans;
    if (s.empty())
    {
        return ans;
    }
    vector<string> path;
    helper6(s , 0 , path , ans);
    return ans;
}

void helper7(string s , vector<string> &ans , int a , int b){
    if (a == 0 && b == 0)
    {
        ans.push_back(s);
        return;
    }
    if (b > 0)
    {
        helper7(s+')' , ans , a , b-1);
    }
    if (a > 0)
    {
        helper7(s+'(' , ans , a-1 , b+1);
    }
}

vector<string> generateParenthesis(int n){
    vector<string> ans;
    helper7("" , ans , n , 0);
    return ans;
}

void helper8(vector<vector<int>> ans , vector<int> v , int index){
    if (index == v.size())
    {
        ans.push_back(v);
        return;
    }
    for (int i = index; i < v.size(); i++)
    {
        swap(v[i] , v[index]);
        helper8(ans , v , index+1);
        swap(v[i] , v[index]);
    }
}

vector<vector<int>> Permutations(vector<int> v){
    vector<vector<int>> ans;
    int index = 0;
    helper8(ans , v , index);
    return ans;
}

bool isValid(vector<string> board , int row , int col){
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

void dfs(vector<string> board , int row , vector<vector<string>> &ans){
    if (row == board.size())
    {
        ans.push_back(board);
        return;
    }
    for (int i = 0; i < board.size(); i++)
    {
        if (isValid(board , row , i))
        {
            board[row][i] = 'Q';
            dfs(board , row+1 , ans);
            board[row][i] = '.';
        }
    }
}

vector<vector<string>> Nqueen(int n){
    if (n <= 0)
    {
        return {{}};
    }
    vector<vector<string>> ans;
    vector<string> board(n , string(n , '.'));
    dfs(board , 0 , ans);
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
bool solveSudoku(vector<vector<char>>& board , int i , int j){
    if(i == 9){
        return true;
    }
    if(j == 9){
        return solveSudoku(board , i+1 , 0);
    }
    if(board[i][j] != '.'){
        return solveSudoku(board , i , j+1);
    }
    
    for(char c = '1'; c<='9' ; c++){
        if(isSafe(board , i , j , c)){
            board[i][j] = c;
            if(solveSudoku(board , i , j+1)){
                return true;
            }
            board[i][j] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    solveSudoku(board , 0 , 0);
}

int main(){

}