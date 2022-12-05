#include <bits/stdc++.h>
using namespace std;

//-----------------------------------118. Pascal's Triangle --------------------------------------//

vector<vector<int>> PascalsTriangle(int n)
{
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].resize(i + 1);
        v[i][0] = v[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }
    return v;
}

//-----------------------------------119. Pascal's Triangle II -----------------------------------//

vector<int> getrow(int n)
{
    vector<vector<int>> v(n + 1);
    for (int i = 0; i <= n; i++)
    {
        v[i].resize(i + 1);
        v[i][0] = v[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
        }
    }
    return v[n];
}

//------------------------------------120. Triangle --------------------------------------//

int MinTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> v = triangle[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < triangle[i].size(); j++)
        {
            v[j] = triangle[i][j] + min(v[j], v[j + 1]);
        }
    }
    return v[0];
}

//-------------------------------121. Best Time to Buy and Sell Stock ------------------------//

int MaxProfit_M1(int arr[], int n)
{
    int left[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }
    int right[n];
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, right[i] - left[i]);
    }
    return ans;
}

int MaxProfit_M2(int arr[], int n)
{
    int minval = INT_MAX;
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        minval = min(minval, arr[i]);
        profit = max(profit, arr[i] - minval);
    }
    return profit;
}

//------------------------------122. Best Time to Buy and Sell Stock II ---------------------//

int maxprofitII(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            continue;
        }
        else
        {
            sum += arr[i + 1] - arr[i];
        }
    }
    return sum;
}

//----------------------------123. Best Time to Buy and Sell Stock III --------------------//

int maxprofitIII(int arr[], int n)
{
    int buy1 = INT_MAX;
    int profit1 = 0;
    int buy2 = INT_MAX;
    int profit2 = 0;

    for (int i = 0; i < n; i++)
    {
        buy1 = min(arr[i], buy1);
        profit1 = max(profit1, arr[i] - buy1);
        buy2 = min(buy2, arr[i] - profit1);
        profit2 = max(profit2, arr[i] - buy2);
    }
    return profit2;
}

//-------------------------------124. Binary Tree Max Path Sum-------------------------------//

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

int helper(treenode *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftsum = root->data + helper(root->left, ans);
    int rightsum = root->data + helper(root->right, ans);

    ans = max({ans, leftsum, rightsum, leftsum + rightsum - root->data, root->data});

    return max({leftsum, rightsum, root->data});
}

int MaxPathSum(treenode *root)
{
    int ans = INT_MIN;
    helper(root, ans);
    return ans;
}

//------------------------------125. Valid Palindrome ------------------------------//

bool isPalindrome(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int n = s.length();
    string tmp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 97 || s[i] <= 122)
        {
            tmp += s[i];
        }
    }
    int i = 0, j = tmp.length() - 1;
    while (i <= j)
    {
        if (tmp[i] != tmp[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return false;
}

//----------------------------126. , 127. Word Ladder ----------------------------------//

int LadderLength(string begin, string end, vector<string> dict)
{
    if (find(dict.begin(), dict.end(), end) == dict.end())
    {
        return 0;
    }
    set<string> s;
    for (auto it : dict)
    {
        s.insert(it);
    }
    int d = 0;
    queue<string> q;
    q.push(begin);

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
                    {
                        continue;
                    }
                    if (tmp == end)
                    {
                        return d + 1;
                    }
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

//----------------------------128. Longest Consequtive Sequence -------------------------//

int LongestConsequtiveSequence(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    int ans = 0;
    int sum = 1;
    sort(nums.begin(), nums.end());
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == nums[i - 1])
        {
            continue;
        }
        if (nums[i] != nums[i - 1] + 1)
        {
            ans = max(ans, sum);
            sum = 1;
        }
        else
        {
            sum++;
        }
    }
    return ans;
}

//-------------------------------129. Sum to Root Leaf ----------------------------//

int dfs(treenode *root, int curr)
{
    if (root == NULL)
    {
        return 0;
    }
    curr = curr * 10 + root->data;
    if (root->left == NULL && root->right == NULL)
    {
        return curr;
    }
    return dfs(root->left, curr) + dfs(root->right, curr);
}

int SumNumber(treenode *root)
{
    return dfs(root, 0);
}

//------------------------------ 130. Surrounded Regions ----------------------------//

void surrounded_regions(vector<vector<int>> &board)
{
    int n = board.size();
    int m = board[0].size();
    queue<vector<int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && board[i][j] == '0')
            {
                q.push({i, j});
            }
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();

        for (int k = 0; k < 4; k++)
        {
            int i = it[0] + dx[k];
            int j = it[1] + dy[k];

            board[it[0]][it[1]] = 'k';
            if ((i >= 0 && j >= 0 && i < n && j < m) && board[i][j] == 'O')
            {
                q.push({i, j});
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'k')
            {
                board[i][j] = 'O';
            }
            else if (board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
}

//------------------------------132.  131. Palindrome Partition -------------------------//

bool isPalindrome1(string s, int i, int j)
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

void dfs1(string s, int idx, vector<string> v, vector<vector<string>> &ans)
{
    if (idx == s.length())
    {
        ans.push_back(v);
        return;
    }
    for (int i = idx; i < s.length(); i++)
    {
        if (isPalindrome1(s, idx, i))
        {
            v.push_back(s.substr(idx, i - idx + 1));
            dfs1(s, i + 1, v, ans);
            v.pop_back();
        }
    }
}

vector<vector<string>> PalindromePartition(string s)
{
    vector<vector<string>> ans;
    if (s.empty())
    {
        return ans;
    }
    vector<string> path;
    dfs1(s, 0, path, ans);
    return ans;
}

//--------------------------- 133. CLONE GRAPH--CHECK LEETCODE---------------------//

//--------------------------- 134. Gas Stations --------------------------------//

int CompleteCircuit(vector<int> gas, vector<int> cost)
{
    int curr = 0;
    int tf = 0, tc = 0;
    int n = gas.size();
    for (int i = 0; i < n; i++)
    {
        tf += gas[i];
        tc += cost[i];
    }
    if (tf < tc)
    {
        return -1;
    }
    int st = 0;
    for (int i = 0; i < n; i++)
    {
        curr += (gas[i] - cost[i]);
        if (curr < 0)
        {
            st = i + 1;
            curr = 0;
        }
    }
    return st;
}

//----------------------------- 135. Candy ------------------------------------//

int Candy(vector<int> ratings)
{
    int n = ratings.size();
    if (n <= 1)
    {
        return n;
    }
    vector<int> v(n, 1);
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] > ratings[i - 1])
        {
            v[i] = v[i - 1] + 1;
        }
    }
    for (int i = n - 2; i >= 0; i--)
    {
        if (ratings[i] > ratings[i + 1])
        {
            v[i] = max(v[i], v[i + 1] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += v[i];
    }
    return ans;
}

//---------------------------- 136. Single Number ---------------------------//

int SingleNumber_M1(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return -1;
}

int SingleNumber_M2(int arr[], int n)
{
    int xorr = arr[0];
    for (int i = 1; i < n; i++)
    {
        xorr ^= arr[i];
    }
    return xorr;
}

//---------------------------- 137. Single Element II -------------------------------//

int SingleNumberII_M1(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
    return -1;
}

int SingleNumberII_M2(int arr[], int n)
{
    int ones = 0, twos = 0;
    for (int i = 0; i < n; i++)
    {
        ones = (ones ^ arr[i]) & (~twos);
        twos = (twos ^ arr[i]) & (~ones);
    }
    return ones;
}

//---------------------- 138. Copy list with random pointers --------- LEETCODE DONE---------------//

//-----------------------------------139. Word Break --------------------------------//

bool WordBreak(string s, vector<string> dict)
{
    vector<bool> dp(s.length(), false);

    dp[0] = true;
    for (int i = 1; i < s.length(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] && find(dict.begin(), dict.end(), s.substr(j, i - j)) != dict.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}

//----------------------------------141. Linked List Cycle ---------------------------//

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

bool hascycle(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return false;
        }
    }
    return true;
}

//------------------------------142. Linked List Cycle II ----------------------------------//

node *removecycle(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            break;
        }
    }
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

//---------------------------------143. Reorder List --------------------------------//

node *reve(node *head)
{
    node *curr = head;
    node *prev = NULL;
    node *temp = NULL;

    while (curr != NULL)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

void ReorderList(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *mid = slow->next;
    slow->next = NULL;
    mid = reve(mid);
    node *n1 = head, *n2 = mid;
    node *tmp = NULL;
    while (n2 != NULL)
    {
        tmp = n1->next;
        n1->next = n2;
        n1 = tmp;

        tmp = n2->next;
        n2->next = n1;
        n2 = tmp;
    }
}

//----------------------------------144. Preorder Traversal -----------------------------//

void PreOrder(treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

//---------------------------------145. Post Order Traversal ---------------------------//

void PostOrder(treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

//---------------------------------146. LRU cache ------------- LEETCODE DONE --------------//

//--------------------------------147. Insertion Sort LL----------------------------------//

node *insertionSortList(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *p = head->next;
    head->next = NULL;

    while (p != NULL)
    {
        node *pNext = p->next; /*store the next node to be insert*/
        node *q = head;

        if (p->data < q->data) /*node p should be the new head*/
        {
            p->next = q;
            head = p;
        }
        else
        {
            while (q != NULL && q->next != NULL && q->next->data <= p->data)
                q = q->next;
            p->next = q->next;
            q->next = p;
        }

        p = pNext;
    }
    return head;
}

//-----------------------------------148. Sort Linked List ---------------------------//

node *sortList_M1(node *head)
{
    vector<int> v;
    node *p = head;
    while (p)
    {
        v.push_back(p->data);
        p = p->next;
    }
    sort(v.begin(), v.end());
    p = head;
    for (int i = 0; i < v.size(); i++)
    {
        p->data = v[i];
        p = p->next;
    }
    return head;
}

node *merge2sortedlist(node *h1, node *h2)
{
    node *newnode = NULL;
    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }
    if (h1->data < h2->data)
    {
        newnode = h1;
        newnode->next = merge2sortedlist(h1->next, h2);
    }
    else
    {
        newnode = h2;
        newnode->next = merge2sortedlist(h1, h2->next);
    }
    return newnode;
}

node *sortList_M2(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node *tmp = slow->next;
    slow->next = NULL;
    return merge2sortedlist(sortList_M2(head), sortList_M2(tmp));
}

//-----------------------------------149. Max Points on Line --------------------------------//

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}
int maxPoints(vector<vector<int>> &points)
{
    int n = points.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<string, int> mp;
        int dup = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (points[j][0] == points[i][0] && points[j][1] == points[i][1])
            {
                dup++;
            }
            else
            {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = gcd(dx, dy);
                mp[to_string(dx / g) + "_" + to_string(dy / g)]++;
            }
        }
        ans = max(ans, dup);
        for (auto it : mp)
        {
            ans = max(ans, it.second + dup);
        }
    }
    return ans;
}

//---------------------------150. Evaluate Reverse Polish Notation ----------------------------//

int evalRPN(vector<string> &tokens)
{
    stack<int> stn;
    for (auto s : tokens)
    {
        if (s.size() > 1 || isdigit(s[0]))
            stn.push(stoi(s));
        else
        {
            auto x2 = stn.top();
            stn.pop();
            auto x1 = stn.top();
            stn.pop();
            switch (s[0])
            {
            case '+':
                x1 += x2;
                break;
            case '-':
                x1 -= x2;
                break;
            case '*':
                x1 *= x2;
                break;
            case '/':
                x1 /= x2;
                break;
            }
            stn.push(x1);
        }
    }
    return stn.top();
}

int main()
{
}