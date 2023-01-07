#include <bits/stdc++.h>
using namespace std;

//------------------------------------201. Range Bitwise AND -------------------------------//

int Rangebitwise(int left, int right)
{
    int ans = 0;
    while (left != right)
    {
        ans++;
        left >>= 1;
        right >>= 1;
    }
    return left << ans;
}

//-----------------------------------202. Happy Number ---------------------------------//

int helper(int n)
{
    int sum = 0;
    int tmp;
    while (n != 0)
    {
        tmp = n % 10;
        sum += tmp * tmp;
        n /= 10;
    }
    return sum;
}

bool IsHappy(int n)
{
    int slow = n, fast = n;
    do
    {
        slow = helper(slow);
        fast = helper(fast);
        fast = helper(fast);
        if (fast == 1)
        {
            return true;
        }
    } while (slow != fast);
    return false;
}

//-------------------------------203. Remove elements from linked list --------------------------//

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

node *removeElement(node *head, int val)
{
    node *curr = head;
    node *prev = NULL;
    while (head)
    {
        if (head->data == val)
        {
            head = head->next;
        }
        else
        {
            break;
        }
    }
    curr = head;
    while (curr)
    {
        if (curr->data == val)
        {
            prev->next = curr->next;
        }
        else
        {
            prev = curr;
        }
        curr = curr->next;
    }
    return head;
}

//-----------------------------------204. Count Primes ----------------------------------//

int countprimes(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    vector<bool> v(n, true);
    v[1] = false;
    int sq = sqrt(n);
    int ans = 0;
    for (int i = 2; i <= sq; i++)
    {
        if (!v[i])
        {
            continue;
        }
        for (int j = i; i * j < n; j++)
        {
            v[i * j] = false;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (v[i])
        {
            ans++;
        }
    }
    return ans;
}

//-----------------------------------205. Isomorphic String ---------------------------------//

bool Isomorphicstring(string s, string t)
{
    vector<int> v1(128, 0);
    vector<int> v2(128, 0);
    for (int i = 0; i < s.length(); i++)
    {
        if (v1[s[i]] != v2[t[i]])
        {
            return false;
        }
        v1[s[i]] = i + 1;
        v2[t[i]] = i + 1;
    }
    return true;
}

//----------------------------------206. Reverse Linked List ------------------------------//

node *reverseLL(node *head)
{
    node *curr = head;
    node *prev = NULL;
    node *tmp = NULL;

    while (curr != NULL)
    {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }
    return prev;
}

//----------------------------------207. Course Schedule ---------------------------------//

bool canFinish(int n, vector<vector<int>> &prerequisites)
{
    vector<vector<int>> G(n);
    vector<int> degree(n, 0), bfs;
    for (auto &e : prerequisites)
        G[e[1]].push_back(e[0]), degree[e[0]]++;
    for (int i = 0; i < n; ++i)
        if (!degree[i])
            bfs.push_back(i);
    for (int i = 0; i < bfs.size(); ++i)
        for (int j : G[bfs[i]])
            if (--degree[j] == 0)
                bfs.push_back(j);
    return bfs.size() == n;
}

//----------------------------------208. Implement Trie ----------------------------//

class trienode
{
public:
    int data;
    unordered_map<char, trienode *> children;
    bool isterminating;
    bool isroot;

    trienode(int data)
    {
        this->data = data;
        isterminating = false;
        isroot = false;
    }
};

class Trie
{
    trienode *root;
    int count;

public:
    Trie()
    {
        root = new trienode(' ');
        root->isroot = true;
        count = 0;
    }
    void insertwordhelper(string word, trienode *root)
    {
        if (word.length() == 0)
        {
            root->isterminating = true;
            return;
        }
        trienode *child;
        if (root->children.count(word[0]) > 0)
        {
            child = root->children[word[0]];
        }
        else
        {
            trienode *newnode = new trienode(word[0]);
            root->children[word[0]] = newnode;
            child = newnode;
        }

        insertwordhelper(word.substr(1), child);
    }
    void insert(string word)
    {
        if (!search(word))
        {
            return insertwordhelper(word, root);
        }
    }
    bool searchhelper(string word, trienode *root)
    {
        if (word.length() == 0)
        {
            if (root->isterminating)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        if (root->children.count(word[0]) == 0)
        {
            return false;
        }
        trienode *child = root->children[word[0]];
        return searchhelper(word.substr(1), child);
    }
    bool search(string word)
    {
        return searchhelper(word, root);
    }
    bool startsWithhelper(string word, trienode *root)
    {
        if (word.length() == 0)
        {
            return true;
        }
        if (root->children.count(word[0]) == 0)
        {
            return false;
        }
        trienode *child = root->children[word[0]];
        return startsWithhelper(word.substr(1), child);
    }
    bool startsWith(string prefix)
    {
        return startsWithhelper(prefix, root);
    }
};

//----------------------------------209. Min Subarr Length ------------------------//

int minsubarr(int arr[], int n, int key)
{
    int l = 0, r = 0;
    int len = INT_MAX;
    int sum = 0;
    while (r < n)
    {
        sum += arr[r++];
        while (sum >= key)
        {
            len = min(len, r - l);
            sum -= arr[l++];
        }
    }
    return len == INT_MAX ? 0 : len;
}

//---------------------------------210. Course Schedule II------------------------------//

vector<int> findOrder(int V, vector<vector<int>> &prerequisites)
{
    vector<int> adj[V];
    for (auto it : prerequisites)
    {
        adj[it[1]].push_back(it[0]);
    }
    vector<int> indegree(V, 0);
    // int indegree[V]={0};
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
                q.push(it);
        }
    }
    if (topo.size() == V)
        return topo;
    return {};
}

//---------------------------------211. ,212. ---- Implement trie --------------------------//

//----------------------------------213. House Robbery II----------------------------------//

int robber(vector<int> nums, int l, int r)
{
    int pre = 0, curr = 0;
    for (int i = l; i <= r; i++)
    {
        int tmp = max(pre + nums[i], curr);
        pre = curr;
        curr = tmp;
    }
    return curr;
}

int rob(vector<int> nums)
{
    int n = nums.size();
    if (n < 2)
    {
        return n ? nums[0] : 0;
    }
    return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
}

//----------------------------------215. Kth largest Element ----------------------------//

int Kthlargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        pq.push(nums[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

//----------------------------------216. Combination III---------------------------------//

void combination(vector<vector<int>> &result, vector<int> sol, int k, int n)
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
            combination(result, sol, k, n - i);
            sol.pop_back();
        }
    }
}

vector<vector<int>> combinationSum3(int k, int n)
{
    vector<vector<int>> result;
    vector<int> sol;
    combination(result, sol, k, n);
    return result;
}

//----------------------------------217. Contains Duplicate ---------------------------//

bool containsDuplicate(vector<int> &nums)
{
    return nums.size() > set<int>(nums.begin(), nums.end()).size();
}

//----------------------------------218. The Skyline Problem ---------------------------//

vector<vector<int>> getSkyline(vector<vector<int>> &buildings)
{
    vector<vector<int>> ans;
    vector<pair<int, int>> temp;
    for (auto x : buildings)
    {
        temp.push_back({x[0], -x[2]});
        temp.push_back({x[1], x[2]});
    }
    sort(temp.begin(), temp.end());
    multiset<int, greater<int>> set;
    set.insert(0);
    int height = 0;
    for (auto x : temp)
    {
        int currX = x.first, currH = x.second;
        if (currH < 0)
            set.insert(-currH);
        else
            set.erase(set.find(currH));
        int top = *set.begin();
        if (height != top)
        {
            height = top;
            ans.push_back({currX, top});
        }
    }
    return ans;
}

//----------------------------------219. Cointains Duplicate II -----------------------------//

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(nums[i]) != mp.end() && i - mp[nums[i]] <= k)
        {
            return true;
        }
        mp[nums[i]] = i;
    }
    return false;
}

//----------------------------------220. Contains Duplicate III----------------------------//

bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t)
{
    set<int> window;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i > k)
            window.erase(nums[i - k - 1]);
        auto pos = window.lower_bound(nums[i] - t);
        if (pos != window.end() && *pos - nums[i] <= t)
            return true;
        window.insert(nums[i]);
    }
    return false;
}

//----------------------------------221. Maximal Square ----------------------------------//

int maximalSquare(vector<vector<char>> &matrix)
{
    if (matrix.size() == 0)
    {
        return 0;
    }
    int n = matrix.size(), m = matrix[0].size(), sz = 0;
    int dp[n][m];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!i || !j || matrix[i][j] == '0')
            {
                dp[i][j] = matrix[i][j] - '0';
            }
            else
            {
                dp[i][j] = min({dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1]}) + 1;
            }
            sz = max(sz, dp[i][j]);
        }
    }
    return sz * sz;
}

//----------------------------------222. Count Complete Tree Nodes ----------------------------//

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

int countNode(treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int hl = 0, hr = 0;
    treenode *l = root;
    treenode *r = root;
    while (l)
    {
        l = l->left;
        hl++;
    }
    while (r)
    {
        r = r->right;
        hr++;
    }
    if (hl == hr)
    {
        return pow(2, hl) - 1;
    }
    return 1 + countNode(root->left) + countNode(root->right);
}

//----------------------------------223. Rectangle Area -------------------------------//

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
{
    int s1 = (C - A) * (D - B);
    int s2 = (G - E) * (H - F);
    if (A >= G || C <= E || D <= F || B >= H)
        return s1 + s2;
    return s1 - (min(G, C) - max(A, E)) * (min(D, H) - max(B, F)) + s2;
}

//----------------------------------224. Basic Calculator ------------------------------//

int calculate(string s)
{
    stack<int> signs;
    int sign = 1;
    int num = 0;
    int ans = 0;
    signs.push(1);

    for (auto c : s)
    {
        if (c >= '0' && c <= '9')
        {
            num = 10 * num + c - '0';
        }
        else if (c == '+' || c == '-')
        {
            ans = ans + signs.top() * sign * num;
            num = 0;
            sign = (c == '+' ? 1 : -1);
        }
        else if (c == '(')
        {
            signs.push(sign * signs.top());
            sign = 1;
        }
        else if (c == ')')
        {
            ans = ans + signs.top() * sign * num;
            num = 0;
            signs.pop();
            sign = 1;
        }
    }

    if (num)
    {
        ans = ans + signs.top() * sign * num;
    }

    return ans;
}

//------------------------------225. Implement stack using queue-------------------------//

class MyStack
{
public:
    queue<int> q;

    MyStack()
    {
    }

    void push(int x)
    {
        q.push(x);
        for (int i = 1; i < q.size(); i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        int x = q.front();
        q.pop();
        return x;
    }

    int top()
    {
        return q.front();
    }

    bool empty()
    {
        return q.empty();
    }
};

//---------------------------------226. Invert Tree -----------------------------//

void mirror(treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    treenode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    mirror(root->left);
    mirror(root->right);
}

//---------------------------------227. Basic Calculator --------------------------//

int calculate(string s)
{
    stack<int> myStack;
    char sign = '+';
    int res = 0, tmp = 0;
    for (unsigned int i = 0; i < s.size(); i++)
    {
        if (isdigit(s[i]))
            tmp = 10 * tmp + s[i] - '0';
        if (!isdigit(s[i]) && !isspace(s[i]) || i == s.size() - 1)
        {
            if (sign == '-')
                myStack.push(-tmp);
            else if (sign == '+')
                myStack.push(tmp);
            else
            {
                int num;
                if (sign == '*')
                    num = myStack.top() * tmp;
                else
                    num = myStack.top() / tmp;
                myStack.pop();
                myStack.push(num);
            }
            sign = s[i];
            tmp = 0;
        }
    }
    while (!myStack.empty())
    {
        res += myStack.top();
        myStack.pop();
    }
    return res;
}

//----------------------------------228. Summary Ranges -----------------------------//

vector<string> summaryRanges(vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return {};
    }
    int st = nums[0];
    int en = nums[0];
    vector<string> ans;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] == nums[i - 1] + 1)
        {
            en = nums[i];
        }
        else
        {
            if (st == en)
            {
                ans.push_back(to_string(st));
            }
            else
            {
                string s = to_string(st) + "->" + to_string(en);
                ans.push_back(s);
            }
            st = nums[i];
            en = nums[i];
        }
    }
    if (st == en)
    {
        ans.push_back(to_string(st));
    }
    else
    {
        string s = to_string(st) + "->" + to_string(en);
        ans.push_back(s);
    }
    return ans;
}

//--------------------------------229. Majority Element ------------------------------//

vector<int> majorityElement(vector<int> &nums)
{
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]]++;
    }
    vector<int> ans;
    for (auto it : mp)
    {
        if (it.second > n / 3)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}

//-------------------------------230. Kth smallest element in BST --------------------------//

void helper1(treenode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    helper1(root->left, ans);
    ans.push_back(root->data);
    helper1(root->right, ans);
}

int kthsmallestElement(treenode *root, int k)
{
    vector<int> ans;
    helper1(root, ans);
    return ans[k - 1];
}

//----------------------------------231. Power of 2 ----------------------------------//

bool isPowerof2(int n)
{
    int ans = 1;
    for (int i = 0; i < 31; i++)
    {
        if (ans == n)
        {
            return true;
        }
        if (ans < INT_MAX / 2)
        {
            ans = ans * 2;
        }
    }
    return false;
}

//-------------------------232. Implement Queue using stack ---------------------------//

class MyQueue
{
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue()
    {
    }

    void push(int x)
    {
        if (s1.empty())
        {
            s1.push(x);
            return;
        }
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop()
    {
        int a = s1.top();
        s1.pop();
        return a;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        // cout<<s1.top()<<endl;
        return s1.empty();
    }
};

//------------------------------233. Number of digit one ----------------------------//

int countDigitOne(int n)
{
    int ans = 0;
    if (n <= 0)
        return 0;
    if (n <= 9)
        return 1;

    unordered_map<int, int> mp;
    mp[9] = 1;
    for (int i = 9; i <= (INT_MAX - 9) / 10; i = i * 10 + 9)
    {
        mp[i * 10 + 9] = mp[i] * 10 + (i + 1); // mp[99], mp[999], mp[9999], ... ...
    }

    int nn = n, divisor = 1;
    while (nn / 10)
    {
        nn /= 10;
        divisor *= 10;
    }
    ans += (n / divisor) * mp[divisor - 1];
    ans += (n / divisor > 1) ? divisor : 0;
    ans += (n / divisor == 1) ? n % divisor + 1 : 0;
    ans += countDigitOne(n % divisor);

    return ans;
}

//--------------------------------234. Palindrome Linked List----------------------------//

bool PalindromeLL(node* head){
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* n2 = slow->next;
    slow->next = NULL;
    n2 = reverseLL(n2);
    node* n1 = head;

    while (n1 != NULL && n2 != NULL)
    {
        if (n1->data != n2->data)
        {
            return false;
        }
        n1 = n1->next;
        n2 = n2->next;
    }
    return true;
}

//-----------------------------------------------------------------------------//

int main()
{
}