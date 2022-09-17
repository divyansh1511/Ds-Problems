#include<bits/stdc++.h>
using namespace std;

void BFShelper(int** edges , int n , int sv , bool* &visited){
    queue<int> pendingvertex;
    pendingvertex.push(sv);
    visited[sv] = true;
    while (!pendingvertex.empty())
    {
        int currindex = pendingvertex.front();
        pendingvertex.pop();
        cout<<currindex<<endl;
        for (int i = 0; i < n; i++)
        {
            if (i == currindex)
            {
                continue;
            }
            if (edges[i][currindex] != 1 && !visited[i])
            {
                visited[i] = true;
                pendingvertex.push(i);
            }
        }
    }
}

void BFS(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            BFShelper(edges , n , i , visited);
        }
    }
}

void DFShelper(int** edges , int n , int sv , bool* &visited){
    cout<<sv<<" ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[i][sv] == 1 && !visited[i])
        {
            visited[i] = true;
            DFShelper(edges , n , i , visited);
        }
    }
}

void DFS(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFShelper(edges , n , i , visited);
        }
    }
}

bool iscycleBFShelper(int** edges , int n , int sv , bool* &visited){
    queue<pair<int,int>> q;
    q.push({sv , -1});
    visited[sv] = true;
    while (!q.empty())
    {
        int nod = q.front().first;
        int par = q.front().second;

        for (int i = 0; i < n; i++)
        {
            if (edges[i][nod] == 1)
            {
                if (!visited[i])
                {
                    visited[i] = true;
                    q.push({i , nod});
                }
                if (i != par)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

bool iscycleBFS(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (iscycleBFShelper(edges , n , i , visited))
            {
                return true;
            }
        }
    }
    return false;
}

bool iscycleDFShelper(int** edges , int n , int sv , int parent , bool* &visited){
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[i][sv] == 1)
        {
            if (!visited[i])
            {
                if (iscycleDFShelper(edges , n , i , sv , visited))
                {
                    return true;
                }
            }
            if (i != parent)
            {
                return true;
            }
        }
    }
    return false;
}

bool iscycleDFS(int** edges , int n){
    bool* visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            if (iscycleDFShelper(edges , n , i , -1 , visited))
            {
                return true;
            }
        }
    }
    return false;
}

bool iscycleDirectedDFShelper(vector<vector<int>> v , int n , int sv , bool* &visited , bool* &dfsvisited){
    visited[sv] = true;
    dfsvisited[sv] = true;

    for(auto it : v[sv]){
        if (!visited[it])
        {
            if (iscycleDirectedDFShelper(v, n , it , visited , dfsvisited))
            {
                return true;
            }
            if (dfsvisited[it])
            {
                return true;
            }
        }
    }
    dfsvisited[sv] = false;
    return false;
}

bool iscycleDirectedDFS(vector<vector<int>> v , int n){
    bool* visited = new bool[n];
    bool* dfsvisited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        dfsvisited[i] = false;
    }
    
    for (int i = 0; i < n; i++)
    {
        if (iscycleDirectedDFShelper(v , n , i , visited , dfsvisited))
        {
            return true;
        }
    }
    return false;
}

void topohelper(vector<vector<int>> &v , int n , int sv , stack<int> &st , vector<bool> &visited){
    visited[sv] = true;
    for(auto it:v[sv]){
        if (!visited[it])
        {
            topohelper(v , n , it , st , visited);
        }
    }
    st.push(sv);
}

vector<int> topologicalSort(vector<vector<int>> &v , int n){
    stack<int> st;
    vector<bool> visited(n , false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            topohelper(v , n , i , st , visited);
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

vector<int> topo(int N, vector<int> adj[]) {
    queue<int> q; 
    vector<int> indegree(N, 0); 
	for(int i = 0;i<N;i++) {
        for(auto it: adj[i]) {
	        indegree[it]++; 
	    }
	}
	    
	for(int i = 0;i<N;i++) {
        if(indegree[i] == 0) {
	        q.push(i); 
	    }
	}
    vector<int> topo;
	while(!q.empty()) {
        int node = q.front(); 
	    q.pop(); 
	    topo.push_back(node);
        for(auto it : adj[node]) {
	        indegree[it]--;
	        if(indegree[it] == 0) {
	            q.push(it); 
            }
	    }
	}
    return topo;
}

void removeIslands(vector<vector<char>> &grid , int i , int j){
    int m = grid.size() , n = grid[0].size();
    if(i<0 || i == m || j < 0 || j == n || grid[i][j] == '0'){
        return;
    }
    grid[i][j] = '0';
    removeIslands(grid , i-1 , j);
    removeIslands(grid , i+1 , j);
    removeIslands(grid , i , j+1);
    removeIslands(grid , i , j-1);
}

int numIslands(vector<vector<char>> &grid){
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); i++)
        {
            if (grid[i][j] == '1')
            {
                count++;
                removeIslands(grid , i , j);
            }
        }
    }
    return count;
}

bool ishelper(vector<vector<char>> & graph , int sv , vector<int> color){
    queue<int> q;
    q.push(sv);
    color[sv] = 1;
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        for(auto it : graph[n]){
            if(color[it] == -1){
                color[it] = 1 - color[n];
                q.push(it);
            }
            else if(color[it] == color[n]){
                return false;
            }
        }
    }
    return true;
}

bool isBiparatite(vector<vector<char>> &graph){
    int n = graph.size();
    vector<int> color(n , -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!ishelper(graph , i , color))
            {
                return false;
            }
        }
    }
    return true;
}

bool bipartiteDfs(int node, vector<int> adj[], int color[]) {
    for(auto it : adj[node]) {
        if(color[it] == -1) {
            color[it] = 1 - color[node];
            if(!bipartiteDfs(it, adj, color)) {
                return false; 
            }
        } else if(color[it] == color[node]) return false; 
    }
    return true; 
}
bool checkBipartite(vector<int> adj[], int n) {
    int color[n];
    memset(color, -1, sizeof color); 
    for(int i = 0;i<n;i++) {
        if(color[i] == -1) {
            color[i] = 1;
            if(!bipartiteDfs(i, adj, color)) {
                return false;
            }
        } 
    }
    return true; 
}


class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end())   //already clone and stored in map
                {
                    neighbour.push_back(mp[it]);    //directly push back the clone node from map to neigh
                }
                else
                    neighbour.push_back(dfs(it,mp));
            }
            clone->neighbors=neighbour;
            return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)   //if only one node present no neighbors
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
    }
};

//----------------------------ALL GRAPHS ALGOS-----------------------//
// 1. KOSARAJUS
// 2. DIJKSTRA
// 3. BELLMANFORD
// 4. FLOYD WARSHALL
// 5. PRIMS ALGO
// 6. KRUSKALS ALGO

int main(){
    int n,e;
    cin>>n>>e;
    int** edges = new int*[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int first , second;
        cin>>first>>second;
        edges[first][second] = 1;
        edges[second][first] = 1;
    }
}