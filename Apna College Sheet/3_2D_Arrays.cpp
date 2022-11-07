#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ZigZagTraversal(vector<vector<int>> v)
{
    int n = v.size();
    int m = v[0].size();
    vector<vector<int>> ans(n + m - 2);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[i + j].push_back(v[i][j]);
        }
    }
    return ans;
}

void SetMatrixZero(vector<vector<int>> v)
{
    int n = v.size();
    int m = v[0].size();
    bool firstrow = false;
    bool firstcol = false;
    for (int i = 0; i < n; i++)
    {
        if (v[i][0] == 0)
        {
            firstcol = true;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (v[0][i] == 0)
        {
            firstrow = true;
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                v[i][0] = 0;
                v[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][0] == 0 || v[0][j] == 0)
            {
                v[i][j] = 0;
            }
        }
    }
    if (firstrow)
    {
        for (int i = 0; i < m; i++)
        {
            v[0][i] = 0;
        }
    }
    if (firstcol)
    {
        for (int i = 0; i < n; i++)
        {
            v[i][0] = 0;
        }
    }
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> v;
    int n = matrix.size();
    int m = matrix[0].size();
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            v.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            v.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                v.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                v.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return v;
}

void RotateImage(vector<vector<int>> &v)
{
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(v[i][j], v[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(v[i].begin(), v[i].end());
    }
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

int dx[8] = {0, 0, 1, -1, -1, -1, 1, 1};
int dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
void helper(vector<vector<char>> &grid, int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1')
    {
        return;
    }
    grid[i][j] = '0';
    for (int k = 0; k < 8; k++)
    {
        helper(grid, i + dx[k], j + dy[k], n, m);
    }
}
int numIslands(vector<vector<char>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '1')
            {
                helper(grid, i, j, n, m);
                count++;
            }
        }
    }
    return count;
}
int M = 6;
int N = 6;
void floodFillUtil(vector<vector<char>> mat, int x, int y, char prevV, char newV)
{
    // Base cases
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (mat[x][y] != prevV)
        return;

    // Replace the color at (x, y)
    mat[x][y] = newV;

    // Recur for north, east, south and west
    floodFillUtil(mat, x + 1, y, prevV, newV);
    floodFillUtil(mat, x - 1, y, prevV, newV);
    floodFillUtil(mat, x, y + 1, prevV, newV);
    floodFillUtil(mat, x, y - 1, prevV, newV);
}

int replaceSurrounded(vector<vector<char>> mat)
{
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] == 'O')
                mat[i][j] = '-';

    for (int i = 0; i < M; i++) // Left side
        if (mat[i][0] == '-')
            floodFillUtil(mat, i, 0, '-', 'O');
    for (int i = 0; i < M; i++) //  Right side
        if (mat[i][N - 1] == '-')
            floodFillUtil(mat, i, N - 1, '-', 'O');
    for (int i = 0; i < N; i++) // Top side
        if (mat[0][i] == '-')
            floodFillUtil(mat, 0, i, '-', 'O');
    for (int i = 0; i < N; i++) // Bottom side
        if (mat[M - 1][i] == '-')
            floodFillUtil(mat, M - 1, i, '-', 'O');

    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++)
            if (mat[i][j] == '-')
                mat[i][j] = 'X';
}

vector<int> CommonElementinRowWiseSortedMatrix(vector<vector<int>> v)
{
    unordered_map<int, int> mp;
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        mp[v[i][0]]++;

        for (int j = 1; j < m; i++)
        {
            if (v[i][j] != v[i][j - 1])
            {
                mp[v[i][j]]++;
            }
        }
    }
    vector<int> ans;
    for (auto it : mp)
    {
        if (it.second == n)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}

int maxhist(vector<int> heights)
{
    stack<int> st;
    int ans = 0;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int top = heights[st.top()];
            st.pop();
            int ran = st.empty() ? -1 : st.top();
            ans = max(ans, top * (i - ran - 1));
        }
        st.push(i);
    }
    return ans;
}

int maxArea(vector<vector<int>> M, int n, int m)
{
    vector<int> currrow = M[0];
    int maxans = maxhist(currrow);
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (M[i][j] == 1)
            {
                currrow[j] += 1;
            }
            else
            {
                currrow[j] = 0;
            }
        }
        maxans = max(maxans, maxhist(currrow));
    }
    return maxans;
}

int main()
{
}