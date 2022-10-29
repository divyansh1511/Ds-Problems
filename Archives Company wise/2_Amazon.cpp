#include <bits/stdc++.h>
using namespace std;

//------------------- https://practice.geeksforgeeks.org/problems/parenthesis-checker2744/1

bool BalancedParenthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.empty())
            {
                return false;
            }
            char a = st.top();
            st.pop();
            if (a != '(')
            {
                return false;
            }
        }
        else if (s[i] == ']')
        {
            if (st.empty())
            {
                return false;
            }
            char a = st.top();
            st.pop();
            if (a != '[')
            {
                return false;
            }
        }
        else if (s[i] == '}')
        {
            if (st.empty())
            {
                return false;
            }
            char a = st.top();
            st.pop();
            if (a != '{')
            {
                return false;
            }
        }
    }
    return st.empty() ? true : false;
}

//------------------- https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

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

vector<int> LeftViewOfBT(treenode *root)
{
    queue<treenode *> pendingnodes;
    pendingnodes.push(root);
    vector<int> ans;
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode *curr = pendingnodes.front();
            pendingnodes.pop();
            if (i == 0)
            {
                ans.push_back(curr->data);
            }
            if (curr->left)
            {
                pendingnodes.push(curr->left);
            }
            if (curr->right)
            {
                pendingnodes.push(curr->right);
            }
        }
    }
    return ans;
}

//-------------- https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1

vector<int> RightViewOfBT(treenode *root)
{
    queue<treenode *> pendingnodes;
    pendingnodes.push(root);
    vector<int> ans;
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode *curr = pendingnodes.front();
            pendingnodes.pop();
            if (i == n - 1)
            {
                ans.push_back(curr->data);
            }
            if (curr->left)
            {
                pendingnodes.push(curr->left);
            }
            if (curr->right)
            {
                pendingnodes.push(curr->right);
            }
        }
    }
    return ans;
}

//-------------- https://practice.geeksforgeeks.org/problems/circular-tour-1587115620/1

int GasStations(int petrol[], int distance[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({petrol[i], distance[i]});
    }
    int balance = 0;
    int d = 0, st = 0;
    for (int i = 0; i < n; i++)
    {
        balance += v[i].first - v[i].second;
        if (balance < 0)
        {
            d += balance;
            st = i + 1;
            balance = 0;
        }
    }
    return balance + d >= 0 ? st : -1;
}

//---------- https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1

bool static cmp(string &a, string &b)
{
    return a + b < b + a;
}

string LargestNumber(vector<string> arr)
{
    string ans = "";
    sort(arr.begin(), arr.end(), cmp);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        ans += arr[i];
    }
    return ans;
}

//--------------- https://practice.geeksforgeeks.org/problems/number-of-provinces/1

void helper(vector<vector<int>> adj, bool *&visited, int sv, int n)
{
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (adj[i][sv] == 1 && !visited[i])
        {
            helper(adj, visited, i, n);
        }
    }
}

int ConnectedComponents(vector<vector<int>> adj, int V)
{
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
    {
        visited[i] = false;
    }
    int ans = 0;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            helper(adj, visited, i, V);
            ans++;
        }
    }
    return ans;
}

int main()
{
}