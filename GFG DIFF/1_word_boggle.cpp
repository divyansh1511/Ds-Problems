#include <bits/stdc++.h>
using namespace std;

void dfs(int r, int c, int k, string ssf, vector<string> &ans, vector<vector<char>> &board, vector<vector<int>> &visited)
{

    int n = board.size(), m = board[0].size();
    if (k == ssf.size())
    {
        auto it2 = find(ans.begin(), ans.end(), ssf);
        if (it2 == ans.end())
            ans.push_back(ssf);
        return;
    }

    visited[r][c] = 1;
    vector<vector<int>> pos{{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

    for (int i = 0; i < 8; i++)
    {
        int nr = r + pos[i][0];
        int nc = c + pos[i][1];

        if (nr >= 0 and nc >= 0 and nr < n and nc < m and !visited[nr][nc] and board[nr][nc] == ssf[k])
        {
            dfs(nr, nc, k + 1, ssf, ans, board, visited);
        }
    }
    visited[r][c] = 0;
}

vector<string> wordBoggle(vector<vector<char>> &board, vector<string> &dictionary)
{
    vector<string> ans;
    int n = board.size(), m = board[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    for (auto x : dictionary)
    {
        char ch = x[0];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == ch)
                {
                    int k = 1;
                    dfs(i, j, k, x, ans, board, visited);
                }
            }
        }
    }

    return ans;
}

int main()
{
}