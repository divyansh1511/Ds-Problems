#include <bits/stdc++.h>
using namespace std;

void DFS(vector<vector<int>> grid, int n, int i, int j, string tmp, vector<string> &v)
{
    if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] == 0)
    {
        return;
    }
    if (i == n - 1 && j == n - 1)
    {
        v.push_back(tmp);
        return;
    }
    grid[i][j] = 0;
    DFS(grid, n, i + 1, j, tmp + "D", v);
    DFS(grid, n, i - 1, j, tmp + "U", v);
    DFS(grid, n, i, j + 1, tmp + "R", v);
    DFS(grid, n, i, j - 1, tmp + "L", v);
    grid[i][j] = 1;
}

vector<string> RanMazeProblem(vector<vector<int>> grid, int n)
{
    if (grid[0][0] == 0 || grid[n - 1][n - 1] == 0)
    {
        return {"-1"};
    }
    vector<string> v;
    string tmp = "";
    DFS(grid, n, 0, 0, tmp, v);
    return v;
}

bool isValid(vector<string> board, int row, int col)
{
    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void DFSqueen(vector<string> board, int row, vector<vector<string>> &ans)
{
    if (row == board.size())
    {
        ans.push_back(board);
        return;
    }
    for (int i = 0; i < board.size(); i++)
    {
        if (isValid(board, row, i))
        {
            board[row][i] = 'Q';
            DFSqueen(board, row + 1, ans);
            board[row][i] = '.';
        }
    }
}

vector<vector<string>> SolveNqueens(int n)
{
    if (n <= 0)
    {
        return {{}};
    }
    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    DFSqueen(board, 0, res);
    return res;
}

void helper(string s, int index, int lr, int rr, int pair, string tmp, unordered_set<string> &st)
{
    if (index == s.length())
    {
        if (lr == 0 && rr == 0 && pair == 0)
        {
            st.insert(tmp);
        }
        return;
    }
    if (s[index] != '(' || s[index] != ')')
    {
        helper(s, index + 1, lr, rr, pair, tmp + s[index], st);
    }
    else if (s[index] == '(')
    {
        if (lr > 0)
        {
            helper(s, index + 1, lr - 1, rr, pair, tmp, st);
        }
        helper(s, index + 1, lr, rr, pair + 1, tmp + s[index], st);
    }
    else if (s[index] == ')')
    {
        if (rr > 0)
        {
            helper(s, index + 1, lr, rr - 1, pair, tmp, st);
        }
        if (pair > 0)
        {
            helper(s, index + 1, lr, rr, pair - 1, tmp + s[index], st);
        }
    }
}

vector<string> RemoveInValidParenthesis(string s)
{
    unordered_set<string> st;
    int lr = 0;
    int rr = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            lr++;
        }
        if (s[i] == ')')
        {
            if (lr != 0)
            {
                lr--;
            }
            else
            {
                rr++;
            }
        }
    }
    helper(s, 0, lr, rr, 0, "", st);
    return vector<string>(st.begin(), st.end());
}

bool issafe(int grid[9][9], int row, int col, int val)
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == val)
            return false;
        if (grid[i][col] == val)
            return false;
        if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
            return false;
    }
    return true;
}

bool SolveSudoku(int grid[9][9])
{
    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            if (grid[row][col] == 0)
            {
                for (int val = 1; val <= 9; val++)
                {
                    if (issafe(grid, row, col, val))
                    {
                        grid[row][col] = val;
                        bool furtherpossible = SolveSudoku(grid);
                        if (furtherpossible)
                            return true;
                        else
                            grid[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void helper(vector<int> A, vector<int> &vt, vector<vector<int>> &v, int B, int i)
{
    if (B == 0)
    {
        v.push_back(vt);
        return;
    }
    if (B < 0)
    {
        return;
    }
    vt.push_back(A[i]);
    helper(A, vt, v, B - A[i], i);
    vt.pop_back();
    if (i + 1 < A.size())
    {
        helper(A, vt, v, B, i + 1);
    }
}
vector<vector<int>> combinationSum(vector<int> &A, int B)
{
    set<int> s;
    for (auto it : A)
    {
        s.insert(it);
    }
    A.clear();
    for (auto it : s)
    {
        A.push_back(it);
    }
    vector<vector<int>> v;
    vector<int> vt;
    helper(A, vt, v, B, 0);
    sort(v.begin(), v.end());
    return v;
}

void helper(string s, int l, int r, vector<string> &v)
{
    if (l == r)
    {
        v.push_back(s);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(s[l], s[i]);
            helper(s, l + 1, r, v);
            swap(s[l], s[i]);
        }
    }
}
vector<string> find_permutation(string S)
{
    vector<string> v;
    helper(S, 0, S.length() - 1, v);
    sort(v.begin(), v.end());
    return v;
}

void solve(string str, int n, int k, string &ans, int index)
{
    if (k == 0)
        return;
    char mx = str[index];
    for (int i = index + 1; i < n; i++)
    {
        mx = max(mx, str[i]);
    }
    if (mx != str[index])
        k--;
    for (int i = n - 1; i >= index; i--)
    {
        if (str[i] == mx)
        {
            swap(str[i], str[index]);
            if (ans < str)
                ans = str;

            solve(str, n, k, ans, index + 1);
            swap(str[i], str[index]);
        }
    }
}
string findMaximumNum(string str, int k)
{
    string ans = str;
    int n = str.size();
    solve(str, n, k, ans, 0);
    return ans;
}

int main()
{
}