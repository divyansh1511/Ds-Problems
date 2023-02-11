#include <bits/stdc++.h>
using namespace std;

//-------------------------------Subset Sum ---------------------------//

void helper1(vector<int> v, int st, int sum, int n, vector<int> &ans)
{
    if (st == n)
    {
        ans.push_back(sum);
        return;
    }
    helper1(v, st + 1, sum, n, ans);
    helper1(v, st + 1, sum + v[st], n, ans);
}

vector<int> subsetsums(vector<int> v)
{
    int n = v.size();
    vector<int> ans;
    helper1(v, 0, 0, n, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

//----------------------------Subsets II -----------------------------//

void helper2(vector<int> v, int idx, vector<int> &tmp, vector<vector<int>> &ans)
{
    if (idx == v.size())
    {
        ans.push_back(tmp);
        return;
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (i != 0 && v[i] == v[i - 1])
        {
            continue;
        }
        tmp.push_back(v[i]);
        helper2(v, idx + 1, tmp, ans);
        tmp.pop_back();
    }
}

vector<vector<int>> subsets(vector<int> v)
{
    vector<vector<int>> ans;
    vector<int> tmp;
    helper2(v, 0, tmp, ans);
    return ans;
}

//-------------------------------Combination Sum ------------------------------//

void helper3(vector<int> v, int idx, int target, vector<int> &tmp, vector<vector<int>> &ans)
{
    if (idx == v.size())
    {
        if (target == 0)
        {
            ans.push_back(tmp);
        }
        return;
    }
    if (v[idx] <= target)
    {
        tmp.push_back(v[idx]);
        helper3(v, idx, target - v[idx], tmp, ans);
        tmp.pop_back();
    }
    helper3(v, idx + 1, target, tmp, ans);
}

vector<vector<int>> CombinationSum(vector<int> v, int target)
{
    vector<vector<int>> ans;
    vector<int> tmp;
    helper3(v, 0, target, tmp, ans);
    return ans;
}

//-----------------------------Combination Sum II ------------------------------//

void helper4(vector<int> v, int idx, int target, vector<int> tmp, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(tmp);
        return;
    }
    for (int i = idx; i < v.size(); i++)
    {
        if (i > idx && v[i] == v[i - 1])
        {
            continue;
        }
        if (v[i] > target)
        {
            break;
        }
        tmp.push_back(v[i]);
        helper4(v, idx + 1, target - v[i], tmp, ans);
        tmp.pop_back();
    }
}

vector<vector<int>> CombinationSumII(vector<int> v, int target)
{
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    vector<int> tmp;
    helper4(v, 0, target, tmp, ans);
    return ans;
}

//------------------------------Palindrome Partitioning --------------------------//

bool isPalindrome(string s, int i, int j)
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

void helper5(string s, int idx, vector<string> tmp, vector<vector<string>> &ans)
{
    if (idx == s.length())
    {
        ans.push_back(tmp);
        return;
    }
    for (int i = idx; i < s.length(); i++)
    {
        if (isPalindrome(s, idx, i))
        {
            tmp.push_back(s.substr(idx, i - idx + 1));
            helper5(s, i + 1, tmp, ans);
            tmp.pop_back();
        }
    }
}

vector<vector<string>> PalindromePartitioning(string s)
{
    vector<vector<string>> ans;
    vector<string> tmp;
    helper5(s, 0, tmp, ans);
    return ans;
}

//-------------------------------Permutations -----------------------------//

void helper6(vector<int> v, int st, vector<vector<int>> &ans)
{
    if (st >= v.size())
    {
        ans.push_back(v);
        return;
    }
    for (int i = st; i < v.size(); i++)
    {
        swap(v[st], v[i]);
        helper6(v, st + 1, ans);
        swap(v[st], v[i]);
    }
}

vector<vector<int>> Permutations(vector<int> v)
{
    vector<vector<int>> ans;
    helper6(v, 0, ans);
    return ans;
}

//-----------------------------Generate All Parenthesis -------------------------------//

void helper7(string tmp, int a, int b, vector<string> &ans)
{
    if (a == 0 && b == 0)
    {
        ans.push_back(tmp);
        return;
    }
    if (b > 0)
    {
        helper7(tmp + ")", a, b - 1, ans);
    }
    if (a > 0)
    {
        helper7(tmp + "(", a - 1, b + 1, ans);
    }
}

vector<string> generateparenthesis(int n)
{
    vector<string> ans;
    string tmp = "";
    helper7(tmp, 0, n, ans);
    return ans;
}

//-----------------------------------sudoku solver -----------------------------//

bool isValid(vector<vector<char>> &board, int row, int col, char ch)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == ch)
            return false;

        if (board[i][col] == ch)
            return false;

        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
            return false;
    }
    return true;
}
bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (isValid(board, i, j, c))
                    {
                        board[i][j] = c;
                        if (solve(board) == true)
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &A)
{
    solve(A);
}

//-------------------------------N queen ------------------------------//

vector<vector<string>> ret;
bool is_valid(vector<string> &board, int row, int col)
{
    // check col
    for (int i = row; i >= 0; --i)
        if (board[i][col] == 'Q')
            return false;
    // check left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 'Q')
            return false;
    // check right diagonal
    for (int i = row, j = col; i >= 0 && j < board.size(); --i, ++j)
        if (board[i][j] == 'Q')
            return false;
    return true;
}
void dfs(vector<string> &board, int row)
{
    // exit condition
    if (row == board.size())
    {
        ret.push_back(board);
        return;
    }
    // iterate every possible position
    for (int i = 0; i < board.size(); ++i)
    {
        if (is_valid(board, row, i))
        {
            // make decision
            board[row][i] = 'Q';
            // next iteration
            dfs(board, row + 1);
            // back-tracking
            board[row][i] = '.';
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    // return empty if n <= 0
    if (n <= 0)
        return {{}};
    vector<string> board(n, string(n, '.'));
    dfs(board, 0);
    return ret;
}

//---------------------------------Rat and Maze -------------------------------//

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

int main()
{
}