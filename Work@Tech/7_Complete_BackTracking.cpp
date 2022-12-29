#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<int>> &maze, int x, int y, vector<vector<int>> &visited)
{
    if (x < 0 || y < 0 || x >= maze.size() || y >= maze[0].size())
    {
        return;
    }
    if (maze[x][y] == 0)
    {
        return;
    }
    if (visited[x][y])
    {
        return;
    }
    visited[x][y] = true;
    helper(maze, x + 1, y, visited);
    helper(maze, x, y + 1, visited);
}

bool RatInMaze(vector<vector<int>> &maze)
{
    vector<vector<int>> visited(maze.size(), vector<int>(maze[0].size(), 0));
    helper(maze, 0, 0, visited);
    if (visited[maze.size() - 1][maze[0].size() - 1])
    {
        return true;
    }
    else
    {
        return false;
    }
}

void helper1(vector<vector<int>> &ans, vector<int> &v, int st, vector<int> &A)
{
    ans.push_back(v);
    for (int i = st; i < A.size(); i++)
    {
        v.push_back(A[i]);
        helper1(ans, v, i + 1, A);
        v.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> &A)
{
    vector<vector<int>> ans;
    vector<int> v;
    helper1(ans, v, 0, A);
    return ans;
}

void helper2(vector<vector<int>> &ans, vector<int> &v, int st, vector<int> &A)
{
    ans.push_back(v);
    for (int i = st; i < A.size(); i++)
    {
        if (i != st && A[i] == A[i - 1])
        {
            continue;
        }
        v.push_back(A[i]);
        helper2(ans, v, i + 1, A);
        v.pop_back();
    }
}

vector<vector<int>> subsetsII(vector<int> &A)
{
    vector<vector<int>> ans;
    vector<int> v;
    sort(A.begin(), A.end());
    helper2(ans, v, 0, A);
    return ans;
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

void helper3(vector<int> A, int val, vector<vector<int>> &ans, vector<int> &help, int ind)
{
    if (ind == A.size())
    {
        if (val == 0)
        {
            ans.push_back(help);
        }
        return;
    }
    if (A[ind] <= val)
    {
        help.push_back(A[ind]);
        helper3(A, val - A[ind], ans, help, ind);
        help.pop_back();
    }
    helper3(A, val, ans, help, ind + 1);
}

vector<vector<int>> combinationSum(vector<int> &A, int val)
{
    vector<vector<int>> ans;
    vector<int> help;
    helper3(A, val, ans, help, 0);
    return ans;
}

void helper4(vector<vector<int>> &ans, vector<int> &v, int val, int st, vector<int> &A)
{
    if (val == 0)
    {
        ans.push_back(v);
        return;
    }
    for (int i = st; i < A.size(); i++)
    {
        if (i > st && A[i] == A[i - 1])
        {
            continue;
        }
        if (A[i] > val)
        {
            break;
        }
        if (A[i] <= val)
        {
            v.push_back(A[i]);
            helper4(ans, v, val - A[i], i + 1, A);
            v.pop_back();
        }
    }
}

vector<vector<int>> combinationSumII(vector<int> &A, int val)
{
    vector<vector<int>> ans;
    vector<int> v;
    sort(A.begin(), A.end());
    helper4(ans, v, val, 0, A);
    return ans;
}

void combinationsUtil(int curr, int n, int k, vector<vector<int>> &result, vector<int> &current)
{
    if (k == 0)
    {
        result.push_back(current);
    }

    for (int i = curr; i <= n; i++)
    {
        current.push_back(i);
        combinationsUtil(i + 1, n, k - 1, result, current);
        current.pop_back();
    }
}

vector<vector<int>> combinations(int n, int k)
{
    vector<vector<int>> result = vector<vector<int>>();
    vector<int> current = vector<int>();
    combinationsUtil(1, n, k, result, current);
    return result;
}

void helper5(vector<string> &ans, string s, string a)
{
    if (s.length() == 0)
    {
        ans.push_back(a);
        return;
    }
    for (int i = 0; i < s.length(); i++)
    {
        string left = s.substr(0, i);
        string right = s.substr(i + 1, s.size() - i - 1);
        string total = left + right;
        helper5(ans, total, a + s[i]);
    }
}

vector<string> getAllPermutations(string s)
{
    vector<string> ans;
    string a = "";
    helper5(ans, s, a);
    return ans;
}

void helper6(string digits, string s, vector<string> &res, int st, unordered_map<char, string> &mp)
{
    if (st == digits.length())
    {
        res.push_back(s);
        return;
    }
    for (char i : mp[digits[st]])
    {
        s += i;
        helper6(digits, s, res, st + 1, mp);
        s.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    if (digits == "")
    {
        return {};
    }
    unordered_map<char, string> mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";
    vector<string> res;
    string s = "";
    helper6(digits, s, res, 0, mp);
    return res;
}

void helper7(vector<string> &ans, string s, int a, int b)
{
    if (a == 0 && b == 0)
    {
        ans.push_back(s);
        return;
    }
    if (b > 0)
    {
        helper7(ans, s + ")", a, b - 1);
    }
    if (a > 0)
    {
        helper7(ans, s + "(", a - 1, b + 1);
    }
}

vector<string> generateParentheses(int n)
{
    vector<string> ans;
    string s = "";
    helper7(ans, s, n, 0);
    return ans;
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

bool isPalindrome(string &s, int i, int j)
{
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

void dfs(vector<vector<string>> &v, vector<string> &t, int st, string &s)
{
    if (st == s.length())
    {
        v.push_back(t);
        return;
    }
    for (int i = st; i < s.size(); i++)
    {
        if (isPalindrome(s, st, i))
        {
            t.push_back(s.substr(st, i - st + 1));
            dfs(v, t, i + 1, s);
            t.pop_back();
        }
    }
}

vector<vector<string>> getPartitions(string s)
{
    vector<vector<string>> v;
    if (s.length() == 0)
    {
        return v;
    }
    vector<string> t;
    dfs(v, t, 0, s);
    return v;
}

bool isValid(vector<string> &v, int r, int c)
{
    for (int i = r; i >= 0; i--)
    {
        if (v[i][c] == 'Q')
        {
            return false;
        }
    }
    for (int i = r, j = c; i >= 0 && j >= 0; i--, j--)
    {
        if (v[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = r, j = c; i >= 0 && j < v.size(); i--, j++)
    {
        if (v[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void dfs1(vector<string> v, int r, vector<vector<string>> &res)
{
    if (r == v.size())
    {
        res.push_back(v);
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (isValid(v, r, i))
        {
            v[r][i] = 'Q';
            dfs1(v, r + 1, res);
            v[r][i] = '.';
        }
    }
}

vector<vector<string>> getNQueensSolutions(int n)
{
    if (n <= 0)
    {
        return {{}};
    }
    vector<vector<string>> res;
    vector<string> v(n, string(n, '.'));
    dfs1(v, 0, res);
    return res;
}

bool isSafe(vector<vector<char>> &board, int i, int j, char c)
{
    int row = i - i % 3, col = j - j % 3;
    for (int x = 0; x < 9; x++)
    {
        if (board[x][j] == c)
        {
            return false;
        }
    }
    for (int y = 0; y < 9; y++)
    {
        if (board[i][y] == c)
        {
            return false;
        }
    }
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (board[row + x][col + y] == c)
            {
                return false;
            }
        }
    }
    return true;
}
bool solveSudoku(vector<vector<char>> &board, int i, int j)
{
    if (i == 9)
    {
        return true;
    }
    if (j == 9)
    {
        return solveSudoku(board, i + 1, 0);
    }
    if (board[i][j] != '.')
    {
        return solveSudoku(board, i, j + 1);
    }

    for (char c = '1'; c <= '9'; c++)
    {
        if (isSafe(board, i, j, c))
        {
            board[i][j] = c;
            if (solveSudoku(board, i, j + 1))
            {
                return true;
            }
            board[i][j] = '.';
        }
    }
    return false;
}

void sudokuSolver(vector<vector<char>> &sudoku)
{
    solveSudoku(sudoku, 0, 0);
}

void nextPermutation(vector<int>& nums, int k){

    if(k==1) return;

    int i=nums.size()-2;

    while(i>=0 && nums[i+1]<=nums[i]) i--;

    if(i>=0){

        int j=nums.size()-1;

        while(nums[j]<=nums[i]) j--;

        swap(nums[j], nums[i]);

    }

    reverse(nums.begin()+i+1, nums.end());

    nextPermutation(nums, k-1);

}

string getKthPermutation(int A, int B) {
	vector<int> nums;

    for(int i=1;i<=A;i++) nums.push_back(i);

    nextPermutation(nums, B);

    string ans;

    for(int i=0;i<A;i++) ans+=to_string(nums[i]);

    return ans;
}

int main()
{
}