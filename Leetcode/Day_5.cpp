#include <bits/stdc++.h>
using namespace std;

//--------------------------------76. Minimum Substring Window--------------------------------//

string minWindow(string s, string t)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < t.length(); i++)
    {
        mp[t[i]]++;
    }

    int i = 0, j = 0;
    int count = mp.size();
    string ans = "", res = "";
    bool flag = true;

    while (j < s.length())
    {
        if (mp.find(s[j]) != mp.end())
        {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
            {
                count--;
            }
        }
        ans += s[j];
        if (count == 0)
        {
            if (flag == true)
            {
                res = ans;
                flag = false;
            }
            if (res.length() > ans.length() && flag == false)
            {
                res = ans;
            }
            while (count == 0)
            {
                if (res.length() > ans.length() && flag == false)
                {
                    res = ans;
                }
                ans = ans.substr(1);
                if (mp.find(s[i]) != mp.end())
                {
                    mp[s[i]]++;
                    if (mp[s[i]] == 1)
                    {
                        count++;
                    }
                }
                i++;
            }
        }
        j++;
    }
    return res;
}

//----------------------------------77. Combinations -----------------------------//

void helper(int n, int k, int idx, vector<int> tmp, vector<vector<int>> &ans)
{
    if (k == tmp.size())
    {
        ans.push_back(tmp);
        return;
    }
    for (int i = idx; i <= n; i++)
    {
        tmp.push_back(i);
        helper(n, k, i + 1, tmp, ans);
        tmp.pop_back();
    }
}
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> ans;
    vector<int> tmp;
    helper(n, k, 1, tmp, ans);
    return ans;
}

//-----------------------------------78. Subsets ------------------------------//

void helper1(vector<int> &nums, int st, vector<int> tmp, vector<vector<int>> &ans)
{
    ans.push_back(tmp);
    for (int i = st; i < nums.size(); i++)
    {
        tmp.push_back(nums[i]);
        helper1(nums, i + 1, tmp, ans);
        tmp.pop_back();
    }
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> tmp;
    helper1(nums, 0, tmp, ans);
    return ans;
}

//-----------------------------------79. Word Search --------------------------//

bool DFS(vector<vector<char>> v, string word, int i, int j)
{
    if (word.length() == 0)
    {
        return true;
    }
    if (i < 0 || j < 0 || i >= v.size() || j >= v[i].size() || v[i][j] != word[0])
    {
        return false;
    }
    char c = v[i][j];
    v[i][j] = '*';
    string s = word.substr(1);
    bool ans = DFS(v, s, i + 1, j) || DFS(v, s, i, j + 1) || DFS(v, s, i - 1, j) || DFS(v, s, i, j - 1);
    v[i][j] = c;
    return ans;
}

bool wordSearch(vector<vector<char>> &v, string word)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (DFS(v, word, i, j))
            {
                return true;
            }
        }
    }
    return false;
}

//--------------------------80. Remove Duplicates from sorted array II-------------------------//

int removeDuplicates(vector<int> &nums)
{
    if (nums.size() <= 2)
    {
        return nums.size();
    }
    int count = 0;
    for (int i = 2; i < nums.size(); i++)
    {
        if (nums[i] != nums[i - 2 - count])
        {
            nums[i - count] = nums[i];
        }
        else
        {
            count++;
        }
    }
    return nums.size() - count;
}

//----------------------------81. Search in Rotated Sorted array II -----------------------------//

bool search(vector<int> &nums, int target)
{
    int left = 0, right = nums.size() - 1, mid;

    while (left <= right)
    {
        mid = (left + right) >> 1;
        if (nums[mid] == target)
            return true;

        // the only difference from the first one, trickly case, just updat left and right
        if ((nums[left] == nums[mid]) && (nums[right] == nums[mid]))
        {
            ++left;
            --right;
        }

        else if (nums[left] <= nums[mid])
        {
            if ((nums[left] <= target) && (nums[mid] > target))
                right = mid - 1;
            else
                left = mid + 1;
        }
        else
        {
            if ((nums[mid] < target) && (nums[right] >= target))
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return false;
}

//-------------------------------82. Remove Duplicates from Sorted List II---------------------//

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

node *helper2(node *curr)
{
    if (curr == NULL)
    {
        return NULL;
    }
    if (curr->next == NULL)
    {
        return curr;
    }
    node *temp = curr;
    while (curr->next != NULL && curr->data == curr->next->data)
    {
        curr = curr->next;
    }
    if (temp == curr)
    {
        curr->next = helper2(curr->next);
        return curr;
    }
    else
    {
        curr = curr->next;
        return helper2(curr);
    }
}

node *deleteDuplicates(node *head)
{
    return helper2(head);
}

//---------------------------------83. Remove Duplicates from Sorted List ------------------------//

node *deleteDuplicatesI(node *head)
{
    node *newnode = head;
    if (newnode == NULL)
    {
        return NULL;
    }
    while (newnode->next != NULL)
    {
        if (newnode->data == newnode->next->data)
        {
            newnode->next = newnode->next->next;
        }
        else
        {
            newnode = newnode->next;
        }
    }
    return head;
}

//---------------------------------84. Largest Rectangle in Histogram -------------------------//

int largestRectangleArea(vector<int> &heights)
{
    stack<int> st;
    int ans = 0;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int top = heights[st.top()];
            st.pop();
            int ran = st.empty() ? -1 : st.top();
            ans = max(ans, top * (i - ran - 1));
        }
        st.push(i);
    }
    return ans;
}

//--------------------------------85. Maximum Rectangle area -------------------------//

int maximalRectangle(vector<vector<char>> &grid)
{
    int m = grid.size(), n = grid[0].size(), res = 0;
    vector<int> histogram(n, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
                histogram[j] += 1;
            else
                histogram[j] = 0;
        }
        res = max(res, largestRectangleArea(histogram));
    }
    return res;
}

//------------------------------86. Partition List ----------------------------------//

node *partition(node *head, int x)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *q1 = NULL;
    node *q2 = NULL;
    node *newnode1 = NULL;
    node *newnode2 = NULL;
    node *curr = head;
    while (curr != NULL)
    {
        if (curr->data < x)
        {
            if (q1 == NULL)
            {
                q1 = curr;
                newnode1 = curr;
            }
            else
            {
                q1->next = curr;
                q1 = q1->next;
            }
        }
        else
        {
            if (q2 == NULL)
            {
                q2 = curr;
                newnode2 = curr;
            }
            else
            {
                q2->next = curr;
                q2 = q2->next;
            }
        }
        curr = curr->next;
    }
    if (q1 == NULL)
    {
        q2->next = NULL;
        return newnode2;
    }
    if (q2 == NULL)
    {
        q1->next = NULL;
        return newnode1;
    }
    q2->next = NULL;
    q1->next = newnode2;
    return newnode1;
}

//----------------------------------87. Scrambled Strings ---------------------------//

unordered_map<string, bool> ump;
bool isScrambled(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;
    int n = s1.size();
    if (s1 == s2 or n == 0)
        return true;

    string key = s1 + " " + s2;
    if (ump.find(key) != ump.end())
        return ump[key];

    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        // for swaped string
        if (isScrambled(s1.substr(0, i), s2.substr(n - i, i)) and isScrambled(s1.substr(i, n - i), s2.substr(0, n - i)))
        {
            flag |= true;
            break;
        }

        // for unswaped string
        if (isScrambled(s1.substr(0, i), s2.substr(0, i)) and isScrambled(s1.substr(i, n - i), s2.substr(i, n - i)))
        {
            flag |= true;
            break;
        }
    }
    ump[key] = flag;
    return flag;
}

bool isScramble(string s1, string s2)
{
    if (s1.size() != s2.size())
        return false;
    return isScrambled(s1, s2);
}

//-------------------------------------88. Merge Sorted Array -------------------------------//

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, tar = m + n - 1;
    while (j >= 0)
    {
        nums1[tar--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
    }
}

//------------------------------------89. Gray Code ------------------------------------//

vector<int> grayCode(int n)
{
    vector<int> ans(1 << n);
    for (int i = 0; i < (1 << n); i++)
        ans[i] = i ^ (i >> 1);
    return ans;
}

//-----------------------------------90. Subsets II -----------------------------------//

void helper(int ind, vector<int> nums, vector<int> &v, vector<vector<int>> &ans)
{
    ans.push_back(v);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
        {
            continue;
        }
        v.push_back(nums[i]);
        helper(i + 1, nums, v, ans);
        v.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> v;
    sort(nums.begin(), nums.end());
    helper(0, nums, v, ans);
    return ans;
}

//----------------------------------91. Decode Ways ----------------------------------//

int numDecodings(string s)
{
    int n = s.length();
    int dp[n + 1];
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = dp[i + 1];
            if (i < n - 1 && (s[i] == '1' || s[i] == '2' && s[i + 1] < '7'))
            {
                dp[i] += dp[i + 2];
            }
        }
    }
    return s.empty() ? 0 : dp[0];
}

//----------------------------------92. Reverse Linked List II ------------------------//

node *reverseBetween(node *head, int m, int n)
{
    node *dummy = new node(0), *pre = dummy, *cur;
    dummy->next = head;
    for (int i = 0; i < m - 1; i++)
    {
        pre = pre->next;
    }
    cur = pre->next;
    for (int i = 0; i < n - m; i++)
    {
        node *temp = pre->next;
        pre->next = cur->next;
        cur->next = cur->next->next;
        pre->next->next = temp;
    }
    return dummy->next;
}

//----------------------------------93. Restore IP Address -----------------------------//

void dfs1(string s, int start, int step, string ip, vector<string> &result)
{
    if (start == s.size() && step == 4)
    {
        ip.erase(ip.end() - 1); // remove the last '.' from the last decimal number
        result.push_back(ip);
        return;
    }
    if (s.size() - start > (4 - step) * 3)
        return;
    if (s.size() - start < (4 - step))
        return;
    int num = 0;
    for (int i = start; i < start + 3; i++)
    {
        num = num * 10 + (s[i] - '0');
        if (num <= 255)
        {
            ip += s[i];
            dfs1(s, i + 1, step + 1, ip + '.', result);
        }
        if (num == 0)
            break;
    }
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> result;
    string ip;
    dfs1(s, 0, 0, ip, result); // paras:string s,start index of s,step(from0-3),intermediate ip,final result
    return result;
}

int main()
{
}