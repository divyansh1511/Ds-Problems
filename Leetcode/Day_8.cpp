#include <bits/stdc++.h>
using namespace std;

//---------------------------------151. Reverse words in string -------------------------------//

string ReverseWords(string s)
{
    stack<string> st;
    string tmp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            if (tmp != "")
            {
                st.push(tmp);
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
        st.push(tmp);
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
        if (!st.empty())
        {
            ans += " ";
        }
    }
    return ans;
}

//---------------------------------152. Max Product Subarray ----------------------------------//

int Maxprosubarr(int arr[], int n)
{
    int pro = 1;
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        pro *= arr[i];
        maxi = max(maxi, pro);
        if (pro == 0)
        {
            pro = 1;
        }
    }
    pro = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        pro *= arr[i];
        maxi = max(maxi, pro);
        if (pro == 0)
        {
            pro = 1;
        }
    }
    return maxi;
}

//---------------------------------153. Minimum in Rotated Sorted Array --------------------------//

int MinRotatedSortedarr(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        int mid = (i + j) / 2;
        if (arr[i] <= arr[j])
        {
            return arr[i];
        }
        if (arr[i] <= arr[mid])
        {
            i = mid + 1;
        }
        else
        {
            j = mid;
        }
    }
    return arr[i];
}

//--------------------------------154. Find Minimum in Rotated Sorted Array II ---------------------//

int MinRotatedSortedArrII(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        int mid = (i + j) / 2;
        if (arr[i] < arr[j])
        {
            return arr[i];
        }
        if (arr[mid] > arr[j])
        {
            i = mid + 1;
        }
        else if (arr[mid] == arr[j])
        {
            i++;
            j--;
        }
        else
        {
            j = mid;
        }
    }
    return arr[i];
}

//-------------------------------155. Min Stack -----------------------------//

class MinStack
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int x)
    {
        s1.push(x);
        if (s2.empty() || s2.top() >= x)
        {
            s2.push(x);
        }
    }
    void pop()
    {
        if (s1.top() == s2.top())
        {
            s2.pop();
        }
        s1.pop();
    }
    int top()
    {
        return s1.top();
    }
    int getmin()
    {
        return s2.top();
    }
};

//-------------------------------156 - 159 , 161 PREMIUM ---------------------------------//

//-------------------------------160. Intersection of Two Linked List ----------------------------//

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

node *IntersectionOf2Nodes(node *h1, node *h2)
{
    int n = 0, m = 0;
    node *tmp = h1;
    while (tmp != NULL)
    {
        n++;
        tmp = tmp->next;
    }
    tmp = h2;
    while (tmp != NULL)
    {
        m++;
        tmp = tmp->next;
    }
    node *p1 = h1;
    node *p2 = h2;
    if (n > m)
    {
        for (int i = 0; i < (n - m); i++)
        {
            p1 = p1->next;
        }
    }
    else
    {
        for (int i = 0; i < (m - n); i++)
        {
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        if (p1 == p2)
        {
            return p1;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    return NULL;
}

//--------------------------------162. Find Peak Element ----------------------------//

int FindPeakEle(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        int mid1 = (i + j) / 2;
        int mid2 = mid1 + 1;
        if (arr[mid1] < arr[mid2])
        {
            i = mid2;
        }
        else
        {
            j = mid1;
        }
    }
    return i;
}

//----------------------------------164. Maximum Gap -------------------------------------//

int MaximumGap_M1(int arr[], int n)
{
    sort(arr, arr + n);
    int gap = 0;
    for (int i = 0; i < n - 1; i++)
    {
        gap = max(gap, arr[i + 1] - arr[i]);
    }
    return gap;
}

int MaximumGap_M2(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    int ans = 0;
    while (pq.size() >= 2)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        ans = max(ans, b - a);
        pq.push(b);
    }
    return ans;
}

//---------------------------------165. Compare Version Numbers ----------------------------//

int CompareNumbers(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();

    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        int sum1 = 0;
        while (i < n1 && s1[i] != '.')
        {
            sum1 = sum1 * 10 + s1[i] - '0';
            i++;
        }
        int sum2 = 0;
        while (j < n2 && s2[j] != '.')
        {
            sum2 = sum2 * 10 + s2[j] - '0';
            j++;
        }
        if (sum1 > sum2)
        {
            return 1;
        }
        else if (sum1 < sum2)
        {
            return -1;
        }
        i++;
        j++;
    }
    return 0;
}

//---------------------------------166. Fraction to recurring decimal ---------------------------//

string FractionToDecimal(int num, int den)
{
    if (num == 0)
    {
        return "0";
    }
    string ans = "";
    ans += ((num < 0) ^ (den < 0)) ? "-" : "";
    int n = abs(num), d = abs(den);
    ans += to_string(n / d);
    n = n % d;
    if (n == 0)
    {
        return ans;
    }
    ans += ".";
    unordered_map<long, int> mp;
    mp[n] = ans.size();
    while (n)
    {
        n *= 10;
        ans += to_string(n / d);
        n = n % d;
        if (mp[n])
        {
            ans.insert(mp[n], "(");
            ans += ")";
            break;
        }
        mp[n] = ans.size();
    }
    return ans;
}

//---------------------------------167. TWO SUM - II -----------------------------------//

vector<int> TwoSum(vector<int> v, int key)
{
    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        if (v[i] + v[j] == key)
        {
            return {i, j};
        }
        else if (v[i] + v[j] < key)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return {-1};
}

//--------------------------------168. Excel Sheet Column Title --------------------------//

string columnName(int n)
{
    string ans = "";
    while (n)
    {
        ans += char((n - 1) % 26 + 'A');
        n = (n - 1) / 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//-----------------------------169. Majority Element -------------------------------//

int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> counter;
    for (int num : nums)
    {
        if (++counter[num] > nums.size() / 2)
        {
            return num;
        }
    }
    return 0;
}

//---------------------------170. Excel sheet column number --------------------------//

int titleToNumber(string s)
{
    int no = 0;
    for (int i = 0; s[i] != 0; i++)
    {
        no = no * 26 + (int)(s[i] - 'A') + 1;
    }
    return no;
}

//--------------------------172. Factorial Trailing Zeros ----------------------------//

int trailingZeroes(int n)
{
    int result = 0;
    for (long long i = 5; (n / i) > 0; i *= 5)
    {
        result += (n / i);
    }
    return result;
}

//-------------------------173. BST Iterator --------------LEETCODE -------------------//

//----------------------------179. Largest Number-----------------------------//

static bool cmp(string a, string b)
{
    return a + b > b + a;
}
string largestNumber(vector<int> &nums)
{
    vector<string> v;
    for (int i = 0; i < nums.size(); i++)
    {
        v.push_back(to_string(nums[i]));
    }
    sort(v.begin(), v.end(), cmp);
    string res;
    for (auto it : v)
    {
        res += it;
    }
    while (res[0] == '0' && res.length() > 1)
        res.erase(0, 1);
    return res;
}

//---------------------------------187. Repeated DNA sequence ------------------------------//

vector<string> RepeatedDNAsequence(string s)
{
    unordered_map<string, int> mp;
    vector<string> res;
    if (s.length() < 10)
    {
        return res;
    }
    for (int i = 0; i < s.length() - 9; i++)
    {
        mp[s.substr(i, 10)]++;
    }
    for (auto it : mp)
    {
        if (it.second > 1)
        {
            res.push_back(it.first);
        }
    }
    return res;
}

//--------------------------------188. Best Time to buy and sell IV-----------------------------//

int maxProfit(int k, vector<int> &prices)
{
    int len = prices.size();
    if (len < 2)
        return 0;
    if (k > len / 2)
    { // simple case
        int ans = 0;
        for (int i = 1; i < len; ++i)
        {
            ans += max(prices[i] - prices[i - 1], 0);
        }
        return ans;
    }
    int hold[k + 1];
    int rele[k + 1];
    for (int i = 0; i <= k; ++i)
    {
        hold[i] = INT_MIN;
        rele[i] = 0;
    }
    int cur;
    for (int i = 0; i < len; ++i)
    {
        cur = prices[i];
        for (int j = k; j > 0; --j)
        {
            rele[j] = max(rele[j], hold[j] + cur);
            hold[j] = max(hold[j], rele[j - 1] - cur);
        }
    }
    return rele[k];
}

//----------------------------------189. Rotate Array --------------------------------//

void rotate(int nums[], int n, int k)
{
    reverse(nums, nums + n);
    reverse(nums, nums + k % n);
    reverse(nums + k % n, nums + n);
}

void rotate(vector<int> v, int k)
{
    rotate(v.rbegin(), v.rbegin() + k % v.size(), v.rend());
}

//----------------------------------190. Reverse Bits -----------------------------//

uint32_t reverseBits(uint32_t n)
{
    uint32_t result = 0;
    for (int i = 0; i < 32; i++)
        result = (result << 1) + (n >> i & 1);
    return result;
}

//---------------------------------191. Number of 1 bits ----------------------------//

int hammingWeight(uint32_t n)
{
    int count = 0;
    while (n)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

//-------------------------------198. House Robbery ---------------------------//

int rob(vector<int> &nums)
{
    const int n = nums.size();
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return nums[0];
    }
    if (n == 2)
    {
        return max(nums[0], nums[1]);
    }
    vector<int> f(n, 0);
    f[0] = nums[0];
    f[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
    {
        f[i] = max(f[i - 2] + nums[i], f[i - 1]);
    }
    return f[n - 1];
}

//---------------------------------------199. Binary Tree Right side view --------------------------//

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

vector<int> rightSideView(TreeNode *root)
{
    vector<int> v;
    if (root == NULL)
    {
        return v;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            q.pop();
            if (i == n - 1)
            {
                v.push_back(temp->val);
            }
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
    return v;
}

//--------------------------------------200. Number of Islands-------------------------------//

void removeisland(vector<vector<char>> &grid, int i, int j)
{
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0')
    {
        return;
    }
    grid[i][j] = '0';
    removeisland(grid, i - 1, j);
    removeisland(grid, i + 1, j);
    removeisland(grid, i, j + 1);
    removeisland(grid, i, j - 1);
}

int numIslands(vector<vector<char>> &grid)
{
    int islands = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1')
            {
                islands++;
                removeisland(grid, i, j);
            }
        }
    }
    return islands;
}

int main()
{
}