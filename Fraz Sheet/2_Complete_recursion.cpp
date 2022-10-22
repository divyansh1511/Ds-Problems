#include <bits/stdc++.h>
using namespace std;

double power(double a, int n)
{
    if (n == 0)
    {
        return 1;
    }
    double tmp = power(a, n / 2);
    if (n % 2 != 0)
    {
        return n < 0 ? 1 / a * tmp * tmp : a * tmp * tmp;
    }
    else
    {
        return tmp * tmp;
    }
}

void helper1(vector<int> nums, vector<vector<int>> ans, vector<int> tmp, int idx)
{
    ans.push_back(tmp);
    for (int i = idx; i < nums.size(); i++)
    {
        tmp.push_back(nums[i]);
        helper1(nums, ans, tmp, i + 1);
        tmp.pop_back();
    }
}

vector<vector<int>> Subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> tmp;
    helper1(nums, ans, tmp, 0);
    return ans;
}

void helper2(vector<int> v, int st, vector<vector<int>> &ans)
{
    if (st >= v.size())
    {
        ans.push_back(v);
        return;
    }
    for (int i = st; i < v.size(); i++)
    {
        swap(v[i], v[st]);
        helper2(v, i + 1, ans);
        swap(v[i], v[st]);
    }
}

vector<vector<int>> Permuatations(vector<int> v)
{
    vector<vector<int>> ans;
    helper2(v, 0, ans);
    return ans;
}

void helper3(vector<int> v, int st, int n, vector<vector<int>> &ans)
{
    if (st == n - 1)
    {
        ans.push_back(v);
        return;
    }
    for (int i = st; i < n; i++)
    {
        if (i != st && v[i] == v[st])
        {
            continue;
        }
        swap(v[i], v[st]);
        helper3(v, i + 1, n, ans);
    }
}

vector<vector<int>> PermuatationsofUnique(vector<int> v)
{
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    helper3(v, 0, v.size(), ans);
    return ans;
}

void helper4(vector<int> v, int st, vector<int> tmp, vector<vector<int>> &ans)
{
    ans.push_back(tmp);
    for (int i = st; i < v.size(); i++)
    {
        if (i != st && v[i] == v[st])
        {
            continue;
        }
        tmp.push_back(v[i]);
        helper4(v, i + 1, tmp, ans);
        tmp.pop_back();
    }
}

vector<vector<int>> SubsetsII(vector<int> v)
{
    vector<vector<int>> ans;
    vector<int> tmp;
    sort(v.begin(), v.end());
    helper4(v, 0, tmp, ans);
    return ans;
}

void helper5(vector<int> v, int target, int st, vector<int> ds, vector<vector<int>> &ans)
{
    if (st == v.size())
    {
        if (target == 0)
        {
            ans.push_back(ds);
        }
        return;
    }
    if (v[st] <= target)
    {
        ds.push_back(v[st]);
        helper5(v, target - v[st], st, ds, ans);
        ds.pop_back();
    }
    helper5(v, target, st + 1, ds, ans);
}

vector<vector<int>> CombinationSum(vector<int> v, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    helper5(v, target, 0, ds, ans);
    return ans;
}

void helper6(vector<int> v, int target, int st, vector<int> ds, vector<vector<int>> &ans)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }
    for (int i = st; i < v.size(); i++)
    {
        if (i > st && v[i] == v[st])
        {
            continue;
        }
        if (v[i] > target)
        {
            break;
        }
        ds.push_back(v[i]);
        helper6(v, target - v[i], i + 1, ds, ans);
        ds.pop_back();
    }
}

vector<vector<int>> CombinationSumII(vector<int> v, int target)
{
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    vector<int> ds;
    helper6(v, target, 0, ds, ans);
    return ans;
}

void helper7(vector<vector<int>> &result, vector<int> sol, int k, int n)
{
    if (sol.size() == k && n == 0)
    {
        result.push_back(sol);
        return;
    }
    if (sol.size() < k)
    {
        for (int i = sol.empty() ? 1 : sol.back() + 1; i <= 9; ++i)
        {
            if (n - i < 0)
                break;
            sol.push_back(i);
            helper7(result, sol, k, n - i);
            sol.pop_back();
        }
    }
}

vector<vector<int>> combinationSumIII(int k, int n)
{
    vector<vector<int>> result;
    vector<int> sol;
    helper7(result, sol, k, n);
    return result;
}

void helper8(string digits, int st, string tmp, vector<string> &ans, vector<string> v)
{
    if (st == digits.length())
    {
        ans.push_back(tmp);
        return;
    }
    int d = digits[st] - '0';
    for (char c : v[d])
    {
        helper8(digits, st + 1, tmp + c, ans, v);
    }
}

vector<string> LetterCombination(string digits)
{
    if (digits.length() == 0)
    {
        return {};
    }
    vector<string> ans;
    string tmp = "";
    vector<string> v = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    helper8(digits, 0, tmp, ans, v);
    return ans;
}

void dfs(vector<vector<int>> &image, int i, int j, int val, int newColor)
{
    if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] == newColor || image[i][j] != val)
    {
        return;
    }
    image[i][j] = newColor;
    dfs(image, i - 1, j, val, newColor);
    dfs(image, i + 1, j, val, newColor);
    dfs(image, i, j - 1, val, newColor);
    dfs(image, i, j + 1, val, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int val = image[sr][sc];
    dfs(image, sr, sc, val, newColor);
    return image;
}

bool DFS(vector<vector<char>> &board, string word, int i, int j)
{
    if (!word.size())
    {
        return true;
    }
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])
    {
        return false;
    }
    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    bool res = DFS(board, s, i - 1, j) || DFS(board, s, i + 1, j) || DFS(board, s, i, j - 1) || DFS(board, s, i, j + 1);
    board[i][j] = c;
    return res;
}
bool exist(vector<vector<char>> &board, string word)
{
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[i].size(); j++)
        {
            if (DFS(board, word, i, j))
            {
                return true;
            }
        }
    }
    return false;
}

void dfs1(int row, int col, vector<vector<int>> &m, int n, string op, vector<string> &ans)
{
    if (row < 0 || col < 0 || row >= n || col >= n || m[row][col] == 0)
        return;

    if (row == n - 1 && col == n - 1)
    {
        ans.push_back(op);
        return;
    }
    m[row][col] = 0;
    dfs1(row + 1, col, m, n, op + 'D', ans);
    dfs1(row - 1, col, m, n, op + 'U', ans);
    dfs1(row, col + 1, m, n, op + 'R', ans);
    dfs1(row, col - 1, m, n, op + 'L', ans);
    m[row][col] = 1;
}

vector<string> findPath(vector<vector<int>> &m, int n)
{
    if (m[0][0] == 0 || m[n - 1][n - 1] == 0)
        return {"-1"};
    vector<string> ans;
    string op = "";
    dfs1(0, 0, m, n, op, ans);
    return ans;
}

bool isSafe(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    int x = row, y = col;
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }

    x = row, y = col;
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x--, y--;
    }

    x = row, y = col;
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        x++, y--;
    }

    return true;
}

void addans(vector<vector<int>> &ans, vector<vector<int>> &board)
{
    vector<int> tans;
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {

            if (board[i][j] != 0)
                tans.push_back(j + 1);
        }
    }

    ans.push_back(tans);
}

void solver(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    if (col == n)
    {
        addans(ans, board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, ans, board, n))
        {
            board[row][col] = 1;
            solver(col + 1, ans, board, n);
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueen(int n)
{
    vector<vector<int>> ans;
    vector<vector<int>> board(n, vector<int>(n, 0));
    int src = 0;

    solver(src, ans, board, n);

    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    
}