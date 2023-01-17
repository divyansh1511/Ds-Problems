#include <bits/stdc++.h>
using namespace std;

//------------------------------628. Maximum product of 3 numbers ---------------------------//

int maxproduct(vector<int> num)
{
    sort(num.begin(), num.end());
    int n = num.size();
    int tmp1 = num[n - 1] * num[n - 2] * num[n - 3];
    int tmp2 = num[0] * num[1] * num[n - 1];
    return tmp1 > tmp2 ? tmp1 : tmp2;
}

//-----------------------------629. K Inverse Pair Array ----------------------------//

int kInversePairs(int n, int k)
{
    int dp[1001][1001] = {1};
    for (int N = 1; N <= n; ++N)
        for (int K = 0; K <= k; ++K)
            for (int i = 0; i <= min(K, N - 1); ++i)
                dp[N][K] = (dp[N][K] + dp[N - 1][K - i]) % 1000000007;
    return dp[n][k];
}

//------------------------------630. Course Schedule III ---------------------------//

int scheduleCourse(vector<vector<int>> &courses)
{
    sort(courses.begin(), courses.end(), [](vector<int> a, vector<int> b)
         { return a[1] < b[1]; });
    priority_queue<int> heap;
    int now = 0;
    for (int i = 0; i < courses.size(); ++i)
    {
        heap.push(courses[i][0]);
        now += courses[i][0];
        if (now > courses[i][1])
            now -= heap.top(), heap.pop();
    }
    return heap.size();
}

//------------------------------637. Average of Level in Binary Tree ---------------------------//

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

vector<double> averageOfLevels(TreeNode *root)
{
    vector<double> v;
    queue<TreeNode *> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        double sum = 0;
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = pendingnodes.front();
            pendingnodes.pop();
            sum += curr->val;
            if (curr->left)
            {
                pendingnodes.push(curr->left);
            }
            if (curr->right)
            {
                pendingnodes.push(curr->right);
            }
        }
        double a = (double)sum / (double)n;
        v.push_back(a);
    }
    return v;
}

//----------------------------------645. Set MisMatch -----------------------------//

vector<int> findErrorNums(vector<int> &nums)
{
    int sum = 0;
    long long squaresum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        sum -= (i + 1);
        squaresum += nums[i] * nums[i];
        squaresum -= (i + 1) * (i + 1);
    }
    squaresum /= sum;
    int a = (squaresum + sum) / 2;
    int b = squaresum - a;
    return {a, b};
}

//--------------------------------646. Max length of pair chain -----------------------//

bool static cmp(vector<int> v1, vector<int> v2)
{
    if (v1[1] == v2[1])
    {
        return v1[0] < v2[0];
    }
    return v1[1] < v2[1];
}

int FindChain(vector<vector<int>> pairs)
{
    sort(pairs.begin(), pairs.end(), cmp);
    int c = 0;
    vector<int> pair = pairs[0];
    for (int i = 0; i < pairs.size(); i++)
    {
        if (i == 0 || pairs[i][0] > pair[1])
        {
            pair = pairs[i];
            c++;
        }
    }
    return c;
}

//---------------------------------647. Palindromic Substrings ------------------------//

int countSubstring(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n));
    int c = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
            {
                dp[i][j] = 1;
            }
            else if (i + 1 == j)
            {
                dp[i][j] = s[i] == s[j] ? 1 : 0;
            }
            else
            {
                dp[i][j] = s[i] == s[j] ? dp[i + 1][j - 1] : 0;
            }
            c += dp[i][j];
        }
    }
    return c;
}

//---------------------------------650. 2 keys keyboard -----------------------------//

int minSteps(int n)
{
    static const int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    if (n <= 5)
    {
        return n == 1 ? 0 : n;
    }
    for (auto i : primes)
    {
        if (n % i == 0)
        {
            return i + minSteps(n / i);
        }
    }
    return n;
}

//--------------------------------653. Two Sum IV --------------------------------//

void inorder(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, v);
    v.push_back(root->val);
    inorder(root->right, v);
}
bool findTarget(TreeNode *root, int k)
{
    vector<int> v;
    inorder(root, v);
    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        if (v[i] + v[j] < k)
        {
            i++;
        }
        else if (v[i] + v[j] > k)
        {
            j--;
        }
        else
        {
            return true;
        }
    }
    return false;
}

//---------------------------------654. Maximum Binary tree ----------------------------//

int maxi(vector<int> nums, int start, int end)
{
    int j = start;
    int max = INT_MIN;
    for (int i = start; i <= end; i++)
    {
        if (max < nums[i])
        {
            max = nums[i];
            j = i;
        }
    }
    return j;
}

TreeNode *solve(vector<int> nums, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int l = maxi(nums, start, end);
    TreeNode *root = new TreeNode(nums[l]);
    root->left = solve(nums, start, l - 1);
    root->right = solve(nums, l + 1, end);
    return root;
}

TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    return solve(nums, start, end);
}

//--------------------------------658. Find k closest element -------------------------//

vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    priority_queue<pair<int, int>> maxheap;
    for (int i = 0; i < arr.size(); i++)
    {
        maxheap.push({abs(x - arr[i]), arr[i]});
        if (maxheap.size() > k)
        {
            maxheap.pop();
        }
    }
    vector<int> v;
    while (!maxheap.empty())
    {
        v.push_back(maxheap.top().second);
        maxheap.pop();
    }
    sort(v.begin(), v.end());
    return v;
}

//--------------------------------659. Split array into consequtive subsequence -------------------//

bool isPossible(vector<int> &A)
{
    unordered_map<int, int> left, end;
    for (int i : A)
    {
        left[i]++;
    }
    for (int i : A)
    {
        if (left[i] == 0)
            continue;
        left[i]--;
        if (end[i - 1] > 0)
        {
            end[i - 1]--;
            end[i]++;
        }
        else if (left[i + 1] > 0 && left[i + 2] > 0)
        {
            left[i + 1]--;
            left[i + 2]--;
            end[i + 2]++;
        }
        else
        {
            return false;
        }
    }
    return true;
}

//----------------------------665. Non - decreasing array ---------------------------//

bool checkPossibility(vector<int> &nums)
{
    int cnt = 0;
    for (int i = 1; i < nums.size() && cnt <= 1; i++)
    {
        if (nums[i - 1] > nums[i])
        {
            cnt++;
            if (i - 2 < 0 || nums[i - 2] <= nums[i])
                nums[i - 1] = nums[i];
            else
                nums[i] = nums[i - 1];
        }
    }
    return cnt <= 1;
}

//----------------------------668. kth smallest number in multiplication table --------------------//

int findKthNumber(int m, int n, int k)
{
    int lo = 0, hi = m * n;
    while (lo < hi)
    {
        int mid = (lo + hi) / 2;
        int count = 0;
        for (int i = 1; i <= m; i++)
        {
            count += n < mid / i ? n : mid / i;
        }
        if (count >= k)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return lo;
}

//------------------------------669. Trim BST --------------------------//

TreeNode *trimBST(TreeNode *root, int low, int high)
{
    if (root == NULL)
        return NULL;
    if (root->val < low)
        return trimBST(root->right, low, high);
    if (root->val > high)
        return trimBST(root->left, low, high);
    root->left = trimBST(root->left, low, high);
    root->right = trimBST(root->right, low, high);
    return root;
}

//-------------------------------673. Number of lis -----------------------//

int findNumberOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> count(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j])
            {
                if (1 + dp[j] == dp[i])
                {
                    count[i] = count[i] + count[j];
                }
                else if (dp[i] < 1 + dp[j])
                {
                    dp[i] = 1 + dp[j];
                    count[i] = count[j];
                }
            }
        }
    }
    int maxi = *max_element(dp.begin(), dp.end());
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
        {
            ans += count[i];
        }
    }
    return ans;
}

//---------------------------------695. max area of island ---------------------------//

int getarea(vector<vector<int>> &grid, int i, int j)
{
    if (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1)
    {
        grid[i][j] = 0;
        return 1 + getarea(grid, i + 1, j) + getarea(grid, i - 1, j) + getarea(grid, i, j - 1) + getarea(grid, i, j + 1);
    }
    return 0;
}
int maxAreaOfIsland(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int maxarea = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            maxarea = max(maxarea, getarea(grid, i, j));
        }
    }
    return maxarea;
}

//-------------------------------------------------------------------------------//

int main()
{
}