#include <bits/stdc++.h>
using namespace std;

//----------------------------------743. Network Delay Time ---------------------------//

int NetworkDelay(vector<vector<int>> times, int n, int k)
{
    vector<int> dist(n, INT_MAX);
    dist[k] = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto it : times)
        {
            int a = it[0], b = it[1], c = it[2];
            if (dist[a] != INT_MAX && dist[a] > dist[b] + c)
            {
                dist[a] = dist[b] + c;
            }
        }
    }

    int maxtime = 0;
    for (int i = 0; i < n; i++)
    {
        maxtime = max(maxtime, dist[i]);
    }
    return maxtime == INT_MAX ? -1 : maxtime;
}

//--------------------------------745. Prefix and Suffix Search -----------------------------//

class WordFilter
{
public:
    unordered_map<string, int> mp;

    WordFilter(vector<string> &words)
    {
        for (int i = 0; i < words.size(); i++)
        {
            string w = words[i];
            for (int j = 1; j <= w.length(); j++)
            {
                string p = w.substr(0, j);
                for (int k = 0; k < w.length(); k++)
                {
                    string s = w.substr(k, w.length());
                    mp[p + "|" + s] = i + 1;
                }
            }
        }
    }

    int f(string p, string s)
    {
        string tmp = p + "|" + s;
        return mp[tmp] - 1;
    }
};

//--------------------------746. Min Cost Climbing ------------------------//

int MinCostClimbing(vector<int> cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        int a = dp[i - 1] + cost[i - 1];
        int b = dp[i - 2] + cost[i - 2];
        dp[i] = min(a, b);
    }
    return dp[n];
}

//------------------------------------754. Reach a Number ------------------------------//

int ReachNumber(int target)
{
    target = abs(target);
    int step = 0, sum = 0;

    while (true)
    {
        step++;
        sum += step;
        if (sum == target)
        {
            return step;
        }
        if (sum > target && (sum - target) % 2 == 0)
        {
            return step;
        }
    }
}

//--------------------------------------767. Reorganize String ----------------------------//

string reorganizeString(string S)
{
    vector<int> cnt(26, 0);
    int mostfreq = 0, i = 0;

    for (char c : S)
    {
        cnt[c - 'a']++;
        if (cnt[c - 'a'] > cnt[mostfreq])
        {
            mostfreq = c - 'a';
        }
    }

    if (2 * cnt[mostfreq] - 1 > S.length())
    {
        return "";
    }

    while (cnt[mostfreq])
    {
        S[i] = ('a' + mostfreq);
        i += 2;
        cnt[mostfreq]--;
    }

    for (int j = 0; j < 26; j++)
    {
        while (cnt[j])
        {
            if (i >= S.length())
            {
                i = 1;
            }
            S[i] = 'a' + j;
            cnt[j]--;
            i += 2;
        }
    }
    return S;
}

//----------------------------------783. Min distance between BST nodes ------------------------//

class treenode
{
public:
    int data;
    treenode *left;
    treenode *right;
    treenode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~treenode()
    {
        delete left;
        delete right;
    }
};

int res = INT_MAX, pre = -1;

int MinDiff(treenode *root)
{
    if (root->left)
    {
        MinDiff(root->left);
    }
    if (pre > 0)
    {
        res = min(res, root->data - pre);
    }
    pre = root->data;
    if (root->right)
    {
        MinDiff(root->right);
    }
    return res;
}

//---------------------------------------785. Is Graph Bipratite --------------------------//

bool ishelper(vector<vector<int>> graph, int sv, vector<int> color)
{
    queue<int> q;
    q.push(sv);
    color[sv] = 1;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        for (auto it : graph[n])
        {
            if (color[it] == -1)
            {
                color[it] = 1 - color[n];
                q.push(it);
            }
            else if (color[it] == color[n])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!ishelper(graph, i, color))
            {
                return false;
            }
        }
    }
    return true;
}

//-------------------------------787. Cheapest flights within K stops ---------------------//

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    vector<vector<int>> dp(K + 2, vector<int>(n, INT_MAX));

    for (int i = 0; i <= K + 1; i++)
    {
        dp[i][src] = 0; // Dist to reach src always zero
    }

    for (int i = 1; i <= K + 1; i++)
    {
        for (auto &f : flights)
        {
            // Using indegree
            int u = f[0];
            int v = f[1];
            int w = f[2];

            if (dp[i - 1][u] != INT_MAX)
                dp[i][v] = min(dp[i][v], dp[i - 1][u] + w);
        }
    }

    return (dp[K + 1][dst] == INT_MAX) ? -1 : dp[K + 1][dst];
}

//------------------------------790. Domino and Tromino Tiling -------------------------------//

int NumTilling(int n)
{
    int mod = 1e9 + 7;
    vector<long long> v(1001, 0);
    v[1] = 1;
    v[2] = 2;
    v[3] = 5;
    if (n <= 3)
    {
        return v[n];
    }
    for (int i = 4; i <= n; i++)
    {
        v[i] = 2 * v[i - 1] + v[i - 3];
        v[i] %= mod;
    }
    return v[n];
}

//-----------------------------797. All path from source to target ---------------------------//

void dfs(vector<vector<int>> &g, vector<vector<int>> &res, vector<int> &path, int cur)
{
    path.push_back(cur);
    if (cur == g.size() - 1)
        res.push_back(path);
    else
        for (auto it : g[cur])
            dfs(g, res, path, it);
    path.pop_back();
}

vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &g)
{
    vector<vector<int>> paths;
    vector<int> path;
    dfs(g, paths, path, 0);
    return paths;
}

//--------------------------------------------------------------

int main()
{
}