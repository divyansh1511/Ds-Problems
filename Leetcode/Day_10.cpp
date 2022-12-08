#include <bits/stdc++.h>
using namespace std;

//-----------------------------------235. LCA in BST-----------------------------------//

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

treenode *LCAinBST(treenode *root, treenode *p, treenode *q)
{
    int small = min(p->data, q->data);
    int large = max(p->data, q->data);

    while (root != NULL)
    {
        if (root->data > large)
        {
            root = root->left;
        }
        else if (root->data < small)
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }
    return NULL;
}

//-----------------------------------236. LCA in BT -----------------------------------//

treenode *LCAinBT(treenode *root, treenode *p, treenode *q)
{
    if (root == NULL || p == NULL || q == NULL)
    {
        return NULL;
    }
    if (root->data == p->data || root->data == q->data)
    {
        return root;
    }
    treenode *l = LCAinBT(root->left, p, q);
    treenode *r = LCAinBT(root->right, p, q);

    if (l && r)
    {
        return root;
    }
    return l ? l : r;
}

//------------------------------237. Delete Node in Linked List------------------------------//

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

void deletenode(node *head)
{
    head->data = head->next->data;
    head->next = head->next->next;
}

//-----------------------------238. Product of array except itself -----------------------------//

vector<int> Productofarr(vector<int> v)
{
    int n = v.size();
    vector<int> ans(n);
    int pro = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] = pro;
        pro *= v[i];
    }
    pro = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] *= pro;
        pro *= v[i];
    }
    return ans;
}

//-----------------------------------239. Sliding Window Maximum-----------------------------------//

vector<int> slidingwindow(vector<int> v, int k)
{
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        if (!dq.empty() && dq.front() == i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && v[dq.back()] < v[i])
        {
            dq.pop_back();
        }
        dq.push_back(v[i]);
        if (i >= k - 1)
        {
            ans.push_back(dq.front());
        }
    }
    return ans;
}

//-----------------------------------240. Search Matrix II -----------------------------------//

bool searchMatrixII(vector<vector<int>> mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int r = 0, c = m - 1;
    while (r < n && c >= 0)
    {
        if (mat[r][c] == target)
        {
            return true;
        }
        mat[r][c] < target ? r++ : c--;
    }
    return false;
}

//----------------------------241. Different ways to add parenthesis ----------------------------//

vector<int> differentcomputation(string s)
{
    vector<int> ans;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < '0')
        {
            vector<int> v1 = differentcomputation(s.substr(0, i));
            vector<int> v2 = differentcomputation(s.substr(i + 1));

            for (auto it1 : v1)
            {
                for (auto it2 : v2)
                {
                    switch (s[i])
                    {
                    case '+':
                        ans.push_back(it1 + it2);
                        break;
                    case '-':
                        ans.push_back(it1 - it2);
                        break;
                    case '*':
                        ans.push_back(it1 * it2);
                        break;
                    }
                }
            }
        }
    }
    if (ans.empty())
    {
        ans.push_back(stoi(s));
    }
    return ans;
}

//-----------------------------------242. Valid Anagram -----------------------------------//

bool isvalidanagram_m1(string s1, string s2)
{
    if (s1.length() != s2.length())
    {
        return false;
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    if (s1 == s2)
    {
        return true;
    }
    return false;
}

bool isvalidanagram_m2(string s, string t)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    for (int i = 0; i < t.length(); i++)
    {
        mp[t[i]]--;
        if (mp[t[i]] == 0)
        {
            mp.erase(t[i]);
        }
    }
    return mp.size() == 0 ? true : false;
}

//-----------------------------------257. Binary Tree Path -----------------------------------//

void helper(treenode *root, vector<string> ans, string s)
{
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(s);
        return;
    }
    if (root->left != NULL)
    {
        helper(root->left, ans, s + "->" + to_string(root->left->data));
    }
    if (root->right != NULL)
    {
        helper(root->right, ans, s + "->" + to_string(root->right->data));
    }
}

vector<string> BinaryTreePath(treenode *root)
{
    vector<string> ans;
    if (root == NULL)
    {
        return ans;
    }
    helper(root, ans, to_string(root->data));
    return ans;
}

//-----------------------------------258. Add digit -----------------------------------//

int AddDigit(int num)
{
    if (num < 10)
    {
        return num;
    }
    int sum = 0;
    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    if (sum > 9)
    {
        return AddDigit(sum);
    }
    return sum;
}

//-----------------------------------260. Single Number III-----------------------------------//

vector<int> SinglenumberIII(vector<int> v)
{
    int a = 0;
    for (int i = 0; i < v.size(); i++)
    {
        a ^= v[i];
    }
    a &= -a;
    int x = 0, y = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] & a)
        {
            x ^= v[i];
        }
        else
        {
            y ^= v[i];
        }
    }
    return {x, y};
}

//-----------------------------------263. Ugly Number-----------------------------------//

bool uglyNumber(int n)
{
    if (n == 0)
    {
        return false;
    }
    while (n % 2 == 0)
    {
        n = n / 2;
    }
    while (n % 3 == 0)
    {
        n = n / 3;
    }
    while (n % 5 == 0)
    {
        n = n / 5;
    }
    return n == 1;
}

//-----------------------------------264. Ugly Number II-----------------------------------//

int nthuglynumber(int n)
{
    int dp[n];
    dp[0] = 1;
    int c2 = 0, c3 = 0, c5 = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i] = min({2 * dp[c2], 3 * dp[c3], 5 * dp[c5]});
        if (2 * dp[c2] == dp[i])
        {
            c2++;
        }
        else if (3 * dp[c3] == dp[i])
        {
            c3++;
        }
        else
        {
            c5++;
        }
    }
    return dp[n - 1];
}

//-----------------------------------268. Missing Number -----------------------------------//

int MissingNumber_M1(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != i)
        {
            return i;
        }
    }
    return nums.size();
}

int MissingNumber_M2(vector<int> &nums)
{
    int n = nums.size();
    vector<int> v(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        v[nums[i]]++;
    }
    for (int i = 0; i <= n; i++)
    {
        if (v[i] == 0)
        {
            return i;
        }
    }
    return n;
}

//-----------------------------------273. Integer to English Word -----------------------------------//

string ones[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string tens[10] = {"Zero", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string helper2(int n)
{
    if (n >= 1000000000)
    {
        return helper2(n / 1000000000) + "Billon" + helper2(n % 1000000000);
    }
    else if (n >= 1000000)
    {
        return helper2(n / 1000000) + "Millon" + helper2(n % 1000000);
    }
    else if (n >= 1000)
    {
        return helper2(n / 1000) + "Thousand" + helper2(n % 1000);
    }
    else if (n >= 100)
    {
        return helper2(n / 100) + "Hundred" + helper2(n % 100);
    }
    else if (n >= 20)
    {
        return " " + tens[n / 10] + helper2(n % 10);
    }
    else if (n >= 1)
    {
        return " " + ones[n];
    }
    else
    {
        return "";
    }
}

string numtoword(int n)
{
    if (n == 0)
    {
        return "zero";
    }
    else
    {
        string ans = helper2(n);
        return ans.substr(1, ans.length() - 1);
    }
}

//-----------------------------------274. H-Index -----------------------------------//

int Hindex(vector<int> a)
{
    int n = a.size();
    if (n == 0)
    {
        return 0;
    }
    vector<int> v(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= n)
        {
            v[n]++;
        }
        else
        {
            v[a[i]]++;
        }
    }
    int paper = 0;
    int i = n;
    for (i; i >= 0; i--)
    {
        paper += v[i];
        if (paper >= i)
        {
            break;
        }
    }
    return i;
}

//-----------------------------------275. H-Index II -----------------------------------//

int Hindex(vector<int> v)
{
    int n = v.size();
    int i = 0, j = n - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (v[mid] < n - mid)
        {
            i = mid + 1;
        }
        else
        {
            j = mid - 1;
        }
    }
    return n - i;
}

//-----------------------------------278. FirstBad version-----------------------------------//

bool isBadVersion(int n)
{
}

int firstBadVersion(int n)
{
    int i = 0, j = n;
    int ans = -1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (isBadVersion(mid))
        {
            ans = mid;
            j = mid - 1;
        }
        else
        {
            i = mid + 1;
        }
    }
    return ans;
}

//-----------------------------------279. Perfect Square -----------------------------------//

int numSquare(int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    int count = 1;
    while (count * count <= n)
    {
        int sq = count * count;
        for (int i = sq; i <= n; i++)
        {
            dp[i] = min(dp[i], dp[i - sq] + 1);
        }
        count++;
    }
    return dp[n];
}

//-----------------------------------283. Move Zeros -----------------------------------//

void movezeros(vector<int> &v)
{
    int j = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != 0)
        {
            v[j] = v[i];
            j++;
        }
    }
    for (j; j < v.size(); j++)
    {
        v[j] = 0;
    }
}

//-----------------------------------287. Find Duplicate -----------------------------------//

int duplicate(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int ind = abs(arr[i]) - 1;
        arr[ind] *= -1;
        if (arr[ind] > 0)
        {
            return abs(arr[i]);
        }
    }
    return -1;
}

//-----------------------------------289. Game of Life -----------------------------------//

void gameOfLife(vector<vector<int>> &board)
{
    int m = board.size(), n = m ? board[0].size() : 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int count = 0;
            for (int ss = max(i - 1, 0); ss < min(i + 2, m); ss++)
            {
                for (int tt = max(j - 1, 0); tt < min(j + 2, n); tt++)
                {
                    count += board[ss][tt] & 1;
                }
            }
            count -= board[i][j];

            if (count == 3 || (board[i][j] && count == 2))
                board[i][j] |= 2;
        }
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            board[i][j] >>= 1;
}

//-----------------------------------290. Word Pattern -----------------------------------//

bool wordPattern(string pattern, string str)
{
    map<char, int> p2i;
    map<string, int> w2i;
    istringstream in(str);
    int i = 0, n = pattern.size();
    for (string word; in >> word; ++i)
    {
        if (i == n || p2i[pattern[i]] != w2i[word])
            return false;
        p2i[pattern[i]] = w2i[word] = i + 1;
    }
    return i == n;
}

//-----------------------------------292. Nim Game -----------------------------------//

bool canWinNim(int n)
{
    return n % 4;
}

//-----------------------------------295. Median from Data Stram-----------------------------------//

class MedianFinder
{
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxheap.empty() || maxheap.top() > num)
        {
            maxheap.push(num);
        }
        else
        {
            minheap.push(num);
        }
        if (maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (minheap.size() > maxheap.size() + 1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian()
    {
        if (maxheap.size() == minheap.size())
        {
            return maxheap.empty() ? 0 : (maxheap.top() + minheap.top()) / 2.0;
        }
        return (maxheap.size() > minheap.size()) ? maxheap.top() : minheap.top();
    }
};

//-----------------------------------299. Bulls and Cows -------------------------------//

string getHint(string secret, string guess)
{
    int n = secret.length();
    int c = 0;
    vector<int> a(10, 0), b(10, 0);
    for (int i = 0; i < n; i++)
    {
        if (secret[i] == guess[i])
        {
            // cout<<secret[i]<<" ";
            c++;
        }
        else
        {
            a[secret[i] - '0']++;
            b[guess[i] - '0']++;
        }
    }
    int bc = 0;
    for (int i = 0; i < a.size(); i++)
    {
        bc += min(a[i], b[i]);
    }
    string ans = "";
    ans += to_string(c) + "A";
    ans += to_string(bc) + "B";
    return ans;
}

//--------------------------------300. Longest Increasing Sequence --------------------------------//

int lengthOfLIS(vector<int> &nums)
{
    int n = nums.size();
    vector<int> res(n, 1);
    for (int i = 1; i < n; i++)
    {
        res[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && res[i] < res[j] + 1)
            {
                res[i] = res[j] + 1;
            }
        }
    }
    return *max_element(res.begin(), res.end());
}

int main()
{
}