#include <bits/stdc++.h>
using namespace std;

void BFShelper(int **edges, int n, int sv, bool *visited)
{
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout << curr << endl;
        for (int i = 0; i < n; i++)
        {
            if (i == curr)
            {
                continue;
            }
            if (edges[i][curr] == 1 && !visited[i])
            {
                q.push(curr);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFShelper(edges, n, i, visited);
        }
    }
}

void DFShelper(int **edges, int n, int sv, bool *visited)
{
    visited[sv] = true;
    cout << sv << " ";
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[i][sv] == 1 && !visited[i])
        {
            DFShelper(edges, n, i, visited);
        }
    }
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFShelper(edges, n, i, visited);
        }
    }
}

bool iscyclehelper(vector<vector<int>> v, int n, int sv, int parent, bool *visited)
{
    visited[sv] = true;
    for (auto it : v[sv])
    {
        if (!visited[it])
        {
            if (iscyclehelper(v, n, it, sv, visited))
            {
                return true;
            }
        }
        else if (it != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(vector<vector<int>> v, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (iscyclehelper(v, n, i, -1, visited))
            {
                return true;
            }
        }
    }
    return false;
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

vector<vector<int>> floodFillAlgo(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int val = image[sr][sc];
    dfs(image, sr, sc, val, newColor);
    return image;
}

void dfs1(vector<vector<int>> &adj, vector<bool> &visited, int src)
{
    visited[src] = true;
    for (int i : adj[src])
        if (!visited[i])
            dfs1(adj, visited, i);
}

int makeConnected(int n, vector<vector<int>> &connections)
{
    if (connections.size() < n - 1)
        return -1;
    vector<vector<int>> adj(n);
    for (auto v : connections)
    {
        adj[v[0]].push_back(v[1]);
        adj[v[1]].push_back(v[0]);
    }
    vector<bool> visited(n, false);
    int components = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i])
        {
            dfs1(adj, visited, i);
            components++;
        }
    return components - 1;
}

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    if (find(wordList.begin(), wordList.end(), endWord) == wordList.end())
        return 0;
    set<string> s;
    for (auto i : wordList)
        s.insert(i);
    queue<string> q;
    q.push(beginWord);
    int d = 0;
    while (!q.empty())
    {
        d++;
        int n = q.size();
        while (n--)
        {
            string curr = q.front();
            q.pop();
            for (int i = 0; i < curr.length(); i++)
            {
                string tmp = curr;
                for (char c = 'a'; c <= 'z'; c++)
                {
                    tmp[i] = c;
                    if (tmp == curr)
                        continue;
                    if (tmp == endWord)
                        return d + 1;
                    if (s.find(tmp) != s.end())
                    {
                        q.push(tmp);
                        s.erase(tmp);
                    }
                }
            }
        }
    }
    return 0;
}

vector<int> dijkstra(int V, vector<vector<int>> adj[], int src)
{
    vector<int> dis(V, INT_MAX);
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dis[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {

        int v = pq.top().second;
        int d_v = pq.top().first;
        pq.pop();

        if (d_v > dis[v])
            continue;

        for (auto edges : adj[v])
        {

            int to = edges[0];
            int len = edges[1];

            if (dis[v] + len < dis[to])
            {
                dis[to] = dis[v] + len;
                pq.push({dis[to], to});
            }
        }
    }
    return dis;
}



int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < e; i++)
    {
        int first, second;
        cin >> first >> second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
}