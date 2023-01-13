#include <bits/stdc++.h>
using namespace std;

//-------------------------------417. Pacific Atlantic Waterflow -------------------------------//

void dfs(vector<vector<int>> &matrix, vector<vector<bool>> &visited, int i, int j)
{
    int m = matrix.size();
    int n = matrix[0].size();

    visited[i][j] = true;
    if (i - 1 >= 0 && visited[i - 1][j] != true && matrix[i - 1][j] >= matrix[i][j])
    {
        dfs(matrix, visited, i - 1, j);
    }
    if (i + 1 < m && visited[i + 1][j] != true && matrix[i + 1][j] >= matrix[i][j])
    {
        dfs(matrix, visited, i + 1, j);
    }
    if (j - 1 >= 0 && visited[i][j - 1] != true && matrix[i][j - 1] >= matrix[i][j])
    {
        dfs(matrix, visited, i, j - 1);
    }
    if (j + 1 < n && visited[i][j + 1] != true && matrix[i][j + 1] >= matrix[i][j])
    {
        dfs(matrix, visited, i, j + 1);
    }
}

vector<pair<int, int>> pacificAtlantic(vector<vector<int>> matrix)
{
    vector<pair<int, int>> r;
    int m = matrix.size();
    if (m == 0)
    {
        return r;
    }
    int n = matrix[0].size();
    if (n == 0)
    {
        return r;
    }
    vector<vector<bool>> pacific(m, vector<bool>(n));
    vector<vector<bool>> atlantic(m, vector<bool>(n));

    for (int i = 0; i < m; i++)
    {
        dfs(matrix, pacific, i, 0);
        dfs(matrix, atlantic, i, n - 1);
    }
    for (int j = 0; j < n; j++)
    {
        dfs(matrix, pacific, 0, j);
        dfs(matrix, atlantic, m - 1, j);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (pacific[i][j] && atlantic[i][j])
            {
                r.push_back(make_pair(i, j));
            }
        }
    }
    return r;
}

//--------------------------------419. Battle ship in a board -------------------------------//

void dfs(vector<vector<char>> &board, int i, int j, int n, int m)
{
    if (i < 0 || i >= n || j < 0 || j >= m || board[i][j] == '.')
    {
        return;
    }
    board[i][j] = '.';
    dfs(board, i - 1, j, n, m);
    dfs(board, i + 1, j, n, m);
    dfs(board, i, j - 1, n, m);
    dfs(board, i, j + 1, n, m);
}

int countBattleships(vector<vector<char>> &board)
{
    int count = 0;
    int n = board.size();
    int m = board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 'X')
            {
                count++;
                dfs(board, i, j, n, m);
            }
        }
    }
    return count;
}

//--------------------------------420. Strong Password --------------------------------//

int strongPasswordChecker(string password)
{
    int n = password.length();

    // character check (replace)
    bool containsUpper = false, containsLower = false, containsDigit = false;
    for (char c : password)
    {
        if (!containsUpper && isupper(c))
        {
            containsUpper = true;
        }
        if (!containsLower && islower(c))
        {
            containsLower = true;
        }
        if (!containsDigit && isdigit(c))
        {
            containsDigit = true;
        }
    }

    int c_swaps = 3 - (containsUpper + containsLower + containsDigit);

    // repeating check (replace)
    vector<int> reps;
    for (int i = 0; i < n;)
    {
        int j = i + 1;
        while (j < n && password[i] == password[j])
        {
            j++;
        }
        reps.push_back(j - i);
        i = j;
    }

    // length (addition, subtraction)
    if (n < 6)
    {
        int adds = 6 - n;
        return max(adds, c_swaps);
    }
    else if (n <= 20)
    {
        int r_swaps = 0;
        for (int elem : reps)
        {
            r_swaps += elem / 3;
        }
        return max(c_swaps, r_swaps);
    }
    else
    {
        int subs = n - 20;
        int r = reps.size();
        for (int i = 0; i < r; i++)
        {
            if (subs >= 1 && reps[i] % 3 == 0)
            {
                reps[i]--;
                subs--;
            }
        }
        for (int i = 0; i < r; i++)
        {
            if (subs >= 2 && reps[i] % 3 == 1 && reps[i] > 3)
            {
                reps[i] -= 2;
                subs -= 2;
            }
        }
        for (int i = 0; i < r; i++)
        {
            if (subs > 0 && reps[i] > 2)
            {
                int removed = min(subs, reps[i] - 2);
                reps[i] -= removed;
                subs -= removed;
            }
        }

        int r_swaps = 0;
        for (int elem : reps)
        {
            r_swaps += elem / 3;
        }
        return max(c_swaps, r_swaps) + (n - 20);
    }
}

//------------------------------423. Reconstruct digits from english word ------------------------//

string originalDigits(string s)
{
    vector<int> a(10, 0);
    vector<int> alpha(128, 0);
    for (char c : s)
        alpha[c]++;
    a[0] = alpha['z'];
    a[2] = alpha['w'];
    a[4] = alpha['u'];
    a[6] = alpha['x'];
    a[8] = alpha['g'];
    a[3] = alpha['h'] - a[8];
    a[5] = alpha['f'] - a[4];
    a[7] = alpha['v'] - a[5];
    a[1] = alpha['o'] - a[0] - a[2] - a[4];
    a[9] = alpha['i'] - a[5] - a[6] - a[8];
    string ans;
    for (int i = 0; i < 10; i++)
    {
        if (a[i] > 0)
            ans += string(a[i], '0' + i);
    }
    return ans;
}

//------------------------------424. Longest repeating character replacement -----------------------//

int characterReplacement(string s, int k)
{
    int res = 0, maxf = 0;
    unordered_map<int, int> count;
    for (int i = 0; i < s.length(); ++i)
    {
        maxf = max(maxf, ++count[s[i]]);
        if (res - maxf < k)
            res++;
        else
            count[s[i - res]]--;
    }
    return res;
}

//-------------------------------429. n-tree level order traversal ----------------------------//

class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val)
    {
        val = _val;
    }

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};

vector<vector<int>> levelOrder(Node *root)
{
    if (root == nullptr)
        return {};
    queue<Node *> q;
    q.push(root);
    vector<vector<int>> ans;
    while (!q.empty())
    {
        ans.emplace_back();
        for (int i = q.size(); i >= 1; i--)
        {
            Node *curr = q.front();
            q.pop();
            ans.back().push_back(curr->val);
            for (Node *child : curr->children)
            {
                q.push(child);
            }
        }
    }
    return ans;
}

//-----------------------------430. Flatten a multilevel doubly ll--------DONE-----------------//

//----------------------------432. All one data structure --------------Done ------------//

//----------------------------434. Number of segments in a string ---------------------------//

int countSegments(string s)
{
    string tmp = "";
    int c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if (tmp != "")
            {
                c++;
            }
            tmp = "";
        }
        else
        {
            tmp += s[i];
        }
    }
    if (tmp != "")
    {
        c++;
    }
    return c;
}

//--------------------------------435. Non - Overlapping Intervals ------------------------//

static bool cmp(vector<int> &v1, vector<int> &v2)
{
    return v1[1] < v2[1];
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int ans = -1;
    if (intervals.size() == 0)
        return 0;
    sort(intervals.begin(), intervals.end(), cmp);
    vector<int> prev = intervals[0];

    for (vector<int> i : intervals)
    {
        if (prev[1] > i[0])
        {
            ans++;
        }
        else
            prev = i;
    }
    return ans;
}

//-------------------------------436. Find Right Interval ----------------------------//

vector<int> findRightInterval(vector<vector<int>> &intervals)
{
    vector<int> ans(intervals.size());
    map<int, int> m;
    for (int i = 0; i < intervals.size(); i++)
        m[intervals[i][0]] = i;
    for (int i = 0; i < intervals.size(); i++)
        ans[i] = m.lower_bound(intervals[i][1]) != end(m) ? m.lower_bound(intervals[i][1])->second : -1;
    return ans;
}

//------------------------------437. Path Sum III ----------------------------//

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

int sumup(treenode *root, int pre, int sum)
{
    if (root == NULL)
    {
        return 0;
    }
    int curr = root->data + pre;
    return (curr == sum) + sumup(root->left, curr, sum) + sumup(root->right, curr, sum);
}

int PathSum(treenode *root, int targetsum)
{
    if (root == NULL)
    {
        return 0;
    }
    return sumup(root, 0, targetsum) + PathSum(root->left, targetsum) + PathSum(root->right, targetsum);
}

//-----------------------------------438. Find Anagrams ----------------------------//

vector<int> findAnagrams(string s, string p)
{
    vector<int> pv(26, 0), sv(26, 0), res;
    if (s.size() < p.size())
    {
        return res;
    }
    for (int i = 0; i < p.size(); i++)
    {
        ++pv[p[i] - 'a'];
        ++sv[s[i] - 'a'];
    }
    if (pv == sv)
    {
        res.push_back(0);
    }
    for (int i = p.size(); i < s.size(); i++)
    {
        ++sv[s[i] - 'a'];
        --sv[s[i - p.size()] - 'a'];
        if (pv == sv)
        {
            res.push_back(i - p.size() + 1);
        }
    }
    return res;
}

//--------------------------------------441. arranging coins ---------------------------//

int arrangeCoins(int n)
{
    int a = 1;
    int c = 0;
    while ((n - a) >= 0)
    {
        c++;
        n -= a;
        a++;
    }
    return c;
}

//-----------------------------------442. Find all duplicate in array ---------------------------//

vector<int> findDuplicates(vector<int> &nums)
{
    if (nums.empty())
        return {};
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[abs(nums[i]) - 1] < 0)
            ans.push_back(abs(nums[i]));
        nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
    }
    return ans;
}

//--------------------------------443. String Compression ---------------------------------//

int compress(vector<char> &chars)
{
    int n = chars.size();
    string res = "";
    for (int i = 0; i < n; i++)
    {
        int count = 1;
        while (i + 1 < chars.size() && chars[i] == chars[i + 1])
        {
            i++;
            count++;
        }
        if (count > 1)
        {
            res += chars[i];
            res += to_string(count);
        }
        else
        {
            res += chars[i];
        }
    }
    for (int i = 0; i < res.size(); i++)
    {
        chars[i] = res[i];
    }
    return res.size();
}

//---------------------------------445. Add 2 Numbers in LL ------------DONE-------------------//

//-------------------------------446. Arthematic Slice -------------------------//

int numberOfArithmeticSlices(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    vector<unordered_map<long long, int>> dp(n); // dp[i][d]
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            long long diff = (long long)nums[i] - nums[j];
            int cnt = dp[j].count(diff) ? dp[j][diff] : 0;
            dp[i][diff] += cnt + 1;
            ans += cnt;
        }
    }
    return ans;
}

//---------------------------------447. Number of anagrams -------------------------------//

int numberOfBoomerangs(vector<vector<int>> &p)
{
    int result = 0;
    unordered_map<int, int> umap;
    for (int i = 0; i < p.size(); i++)
    {
        for (int j = 0; j < p.size(); j++)
        {
            int d = pow(p[j][1] - p[i][1], 2) + pow(p[j][0] - p[i][0], 2);
            result += 2 * umap[d]++;
        }
        umap.clear();
    }
    return result;
}

//--------------------------------448. find all numbers disapperaed in an array --------------------//

vector<int> findDisappearedNumbers(vector<int> &nums)
{
    int n = nums.size();
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (nums[abs(nums[i]) - 1] > 0)
        {
            nums[abs(nums[i]) - 1] *= -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            v.push_back(i + 1);
        }
    }
    return v;
}

//------------------------449. Serialized and desiralized ---------------------//

//------------------------450. delete a node in BST -------------------------------------//

treenode* deletenode(treenode* root , int k){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == k)
    {
        if (root->right == NULL)
        {
            treenode* l = root->left;
            delete root;
            return l;
        }
        else
        {
            treenode* r = root->right;
            while (r->left)
            {
                r = r->left;
            }
            swap(root->data , r->data);
        }
    }
    root->left = deletenode(root->left , k);
    root->right = deletenode(root->right , k);
    return root;
}

int main()
{
}