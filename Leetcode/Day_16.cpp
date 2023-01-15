#include <bits/stdc++.h>
using namespace std;

//--------------------------485. Max Consequtive Ones ----------------------------//

int findmaxone(vector<int> v)
{
    int c = 0, mx = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
        {
            c++;
        }
        else
        {
            mx = max(mx, c);
            c = 0;
        }
    }
    mx = max(mx, c);
    return mx;
}

//-------------------------------493. Reverse Pairs ---------------------------//

void merge(vector<int> v, int st, int mid, int end, int &count)
{
    int l = st, r = mid + 1;
    while (l <= mid && r <= end)
    {
        if (v[l] > 2 * v[r])
        {
            count += (mid - l + 1);
            r++;
        }
        else
        {
            l++;
        }
    }
    sort(v.begin() + st, v.begin() + end + 1);
}

void mergesort(vector<int> v, int st, int end, int &count)
{
    if (st == end)
    {
        return;
    }
    int mid = (st + end) / 2;
    mergesort(v, st, mid, count);
    mergesort(v, mid + 1, end, count);
    merge(v, st, mid, end, count);
}

int ReversePairs(vector<int> &v)
{
    if (v.size() == 0)
    {
        return 0;
    }
    int count = 0;
    mergesort(v, 0, v.size() - 1, count);
    return count;
}

//-----------------------------------494. Target Sum --------------------------------//

int countsubset(vector<int> v, int n, int sum)
{
    int dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (v[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - v[i]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][sum];
}

int targetsum(vector<int> v, int target)
{
    int n = v.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
    }
    int sum1 = (sum + target) / 2;
    if (sum < target || (sum + target) % 2 != 0)
    {
        return 0;
    }
    return countsubset(v, n, sum1);
}

//-----------------------------------496. Next Greater Element ---------------------------//

vector<int> nextGreaterElement(vector<int> v1, vector<int> v2)
{
    stack<int> s;
    unordered_map<int, int> mp;
    for (int n : v2)
    {
        while (s.size() && s.top() < n)
        {
            mp[s.top()] = n;
            s.pop();
        }
        s.push(n);
    }
    vector<int> ans;
    for (int n : v1)
    {
        ans.push_back(mp.count(n) ? mp[n] : -1);
    }
    return ans;
}

//-----------------------------------498. Digonal Traversal ------------------------------//

vector<int> FindDigonal(vector<vector<int>> v)
{
    int n = v.size(), m = v[0].size();
    vector<vector<int>> ans(n + m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[i + j].push_back(v[i][j]);
        }
    }
    vector<int> res;
    for (int i = 0; i < ans.size(); i++)
    {
        if (i % 2 == 0)
        {
            int a = v[i].size();
            for (int j = a - 1; j >= 0; j--)
            {
                res.push_back(v[i][j]);
            }
        }
        else
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                res.push_back(v[i][j]);
            }
        }
    }
    return res;
}

//-----------------------------503. Next greater Element II--------------------------------//

vector<int> nextGreaterElementII(vector<int> v)
{
    int n = v.size();
    vector<int> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i] = INT_MIN;
    }
    for (int i = 0; i < n; i++)
    {
        int a = v[i];
        for (int j = i + 1; j < n; j++)
        {
            if (v[j] > a)
            {
                ans[i] = v[j];
                break;
            }
        }
        if (ans[i] == INT_MIN)
        {
            for (int j = 0; j < i; j++)
            {
                if (v[j] > a)
                {
                    ans[i] = v[j];
                    break;
                }
            }
        }
        if (ans[i] == INT_MIN)
        {
            ans[i] = -1;
        }
    }
    return ans;
}

//-----------------------------506. Relative Ranks ----------------------------//

vector<string> findRelativeRanks(vector<int> &score)
{
    int n = score.size();
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(make_pair(score[i], i));
    }
    vector<string> res(n, "");
    int count = 1;
    for (int i = 0; i < n; i++)
    {
        if (count == 1)
        {
            res[pq.top().second] = "Gold Medal";
            count++;
        }
        else if (count == 2)
        {
            res[pq.top().second] = "Silver Medal";
            count++;
        }
        else if (count == 3)
        {
            res[pq.top().second] = "Bronze Medal";
            count++;
        }
        else
        {
            res[pq.top().second] = to_string(count);
            count++;
        }
        pq.pop();
    }
    return res;
}

//-------------------------------509. Fibnocci Number ------------------------//

int fib(int n)
{
    if (n < 2)
    {
        return n;
    }
    int arr[n];
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n - 1];
}

//-------------------------------513. Find Bottom left Tree Value ------------------//

class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};

void helper(TreeNode *root, int &maxdepth, int &leftval, int depth)
{
    if (root == NULL)
    {
        return;
    }
    helper(root->left, maxdepth, leftval, depth + 1);
    helper(root->right, maxdepth, leftval, depth + 1);
    if (depth > maxdepth)
    {
        maxdepth = depth;
        leftval = root->val;
    }
}

int findBottomLeftValue(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftval = root->val;
    int maxdepth = 0;
    helper(root, maxdepth, leftval, 0);
    return leftval;
}

//-------------------------------515. Find largest value in each row- ----------------//

vector<int> largestValues(TreeNode *root)
{
    if (root == NULL)
    {
        return {};
    }
    vector<int> ans;
    queue<TreeNode *> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        int maxnode = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = pendingnodes.front();
            pendingnodes.pop();
            maxnode = max(maxnode, curr->val);
            if (curr->left != NULL)
            {
                pendingnodes.push(curr->left);
            }
            if (curr->right != NULL)
            {
                pendingnodes.push(curr->right);
            }
        }
        ans.push_back(maxnode);
    }
    return ans;
}

//-------------------------------516. Longest Palindromic Subsequence ----------------------//

int LCS(string a, string b, int n, int m)
{
    int dp[n + 1][m + 2];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}
int longestPalindromeSubseq(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    int n = s.length();
    return LCS(s, a, n, n);
}

//-------------------------------518 Coin change II --------------------------------//

int Coinchange(int amount, vector<int> &coins)
{
    int n = coins.size();
    int dp[n + 1][amount + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= amount; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - coins[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amount];
}

//-------------------------------520. Detect Capital ---------------------------//

bool detectCapitalUse(string word)
{
    for (int i = 1; i < word.size(); i++)
    {
        if (isupper(word[1]) != isupper(word[i]) || islower(word[0]) && isupper(word[i]))
        {
            return false;
        }
    }
    return true;
}

//--------------------------------523. Continous Subarr sum -------------------------//

bool checkSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    if (n < 2)
    {
        return false;
    }
    unordered_map<int, int> mp;
    mp[0] = -1;
    int ressum = 0;
    for (int i = 0; i < n; i++)
    {
        ressum += nums[i];
        if (k != 0)
        {
            ressum = ressum % k;
        }
        if (mp.find(ressum) != mp.end())
        {
            if (i - mp[ressum] > 1)
            {
                return true;
            }
        }
        else
        {
            mp[ressum] = i;
        }
    }
    return false;
}

//----------------------------------525. Contiguous Array -------------------------//

int findMaxLength(vector<int> &nums)
{
    unordered_map<int, int> mp;
    mp[0] = -1;

    int maxx = 0, sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i] ? 1 : -1;
        if (mp.find(sum) != mp.end())
            maxx = max(i - mp[sum], maxx);
        else
            mp[sum] = i;
    }
    return maxx;
}

//---------------------------------528. Random Pick with Weight ---------------------------//

class Solution
{
public:
    vector<int> v;
    Solution(vector<int> &w)
    {
        for (int i = 0; i < w.size(); i++)
        {
            if (v.empty())
            {
                v.push_back(w[i]);
            }
            else
            {
                v.push_back(w[i] + v.back());
            }
        }
    }

    int pickIndex()
    {
        int x = v.back();
        int ind = rand() % x;
        auto it = upper_bound(v.begin(), v.end(), ind);
        return it - v.begin();
    }
};

//------------------------------530. Minimum absolute difference ------------------------//

class Solution
{
public:
    int min_dif = INT_MAX, val = -1;
    int getMinimumDifference(TreeNode *root)
    {
        if (root->left != NULL)
            getMinimumDifference(root->left);
        if (val >= 0)
            min_dif = min(min_dif, root->val - val);
        val = root->val;
        if (root->right != NULL)
            getMinimumDifference(root->right);
        return min_dif;
    }
};

//--------------------------------540. Single Element in sorted array ---------------------//

int singleNonDuplicate(vector<int> &nums)
{
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        int mid = (i + j) / 2;
        if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1]))
        {
            i = mid + 1;
        }
        else
        {
            j = mid;
        }
    }
    return nums[i];
}

//-------------------------------543. Diamerter of BT ---------------------------//

int rec(TreeNode *root, int &d)
{
    if (root == NULL)
        return 0;
    int ld = rec(root->left, d);
    int rd = rec(root->right, d);
    d = max(d, ld + rd);
    return max(ld, rd) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int d = 0;
    rec(root, d);
    return d;
}

//---------------------------------

int main()
{
}