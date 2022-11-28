#include <bits/stdc++.h>
using namespace std;

//-------------------------------------1. TWO SUM PROBLEM-----------------------------------------//

vector<int> TwoSumPr_M1(vector<int> v, int target)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[i] + v[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {-1};
}

vector<int> TwoSumPr_M2(vector<int> nums, int target)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < nums.size(); i++)
    {
        v.push_back({nums[i], i});
    }
    sort(v.begin(), v.end());
    int i = 0, j = nums.size() - 1;
    while (i < j)
    {
        int sum = v[i].first + v[j].first;
        if (sum == target)
        {
            return {v[i].second, v[j].second};
        }
        else if (sum < target)
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

vector<int> TwoSumPr_M3(vector<int> nums, int target)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target - nums[i]) != mp.end())
        {
            return {mp[target - nums[i]], i};
        }
        mp[nums[i]] = i;
    }
    return {-1};
}

//------------------------------------2. Add 2 numbers in Linked list-----------------------------//

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

node *add2number(node *h1, node *h2)
{
    node *l1 = h1;
    node *l2 = h2;
    node *ans = new node(-1);
    node *tmp = ans;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }
        ans->next = new node(sum % 10);
        ans = ans->next;
        carry = sum / 10;
    }
    return tmp->next;
}

//----------------------------3. Longest Substring Without Repeating Characters-----------------------//

int LongestSubstring(string s)
{
    vector<int> v(256, -1);
    int len = 0;
    int left = 0, right = 0;
    int n = s.length();
    while (right < n)
    {
        if (v[s[right]] != -1)
        {
            left = max(left, v[s[right]]);
        }
        v[s[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}

//-----------------------------4. Median of 2 sorted arrays---------------------------------------//

double medianof2sortedarr(vector<int> nums1, vector<int> nums2)
{
    vector<int> v;
    for (int i = 0; i < nums1.size(); i++)
    {
        v.push_back(nums1[i]);
    }
    for (int i = 0; i < nums2.size(); i++)
    {
        v.push_back(nums2[i]);
    }
    sort(v.begin(), v.end());
    int n = v.size();
    double ans;
    if (n % 2 == 0)
    {
        ans = (v[n / 2] + v[n / 2 - 1]) / 2.0;
    }
    else
    {
        ans = v[n / 2];
    }
    return ans;
}

double helper(vector<int> nums1, vector<int> nums2)
{
    int n = nums1.size(), m = nums2.size();
    if (n > m)
    {
        return helper(nums2, nums1);
    }
    int lo = 0, hi = n;
    while (lo <= hi)
    {
        int cut1 = lo + (hi - lo) / 2;
        int cut2 = (n + m + 1) / 2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
        int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((n + m) % 2 == 0)
            {
                return (double)(max(l1, l2) + min(r1, r2)) / 2;
            }
            else
            {
                return (double)(max(l1, l2));
            }
        }
        else if (l1 > r2)
        {
            hi = cut1 - 1;
        }
        else
        {
            lo = cut1 + 1;
        }
    }
    return -1.0;
}

double medianof2sortedarr(vector<int> nums1, vector<int> nums2)
{
    double ans;
    ans = helper(nums1, nums2);
    return ans;
}

//---------------------------5. Longest Palindromic Substring----------------------------//

string LongestPalindromicSubstring(string s)
{
    int n = s.length();
    int dp[n][n];
    int mxlen = 0;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        mxlen = 1;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = 1;
            start = i;
            mxlen = 2;
        }
    }
    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1] == 1)
            {
                dp[i][j] = 1;
                if (k > mxlen)
                {
                    mxlen = k;
                    start = i;
                }
            }
        }
    }
    return s.substr(start, mxlen);
}

//------------------------------------6. ZigZag Converstion---------------------------------//

string ZigzagConverstion(string s, int n)
{
    if (n <= 1)
    {
        return s;
    }
    vector<string> v(n, "");
    bool flag = true;
    int j = 0;
    for (int i = 0; i < s.length(); i++)
    {
        v[j] += s[i];
        if (flag)
        {
            if (j == n - 1)
            {
                flag = false;
                j--;
                continue;
            }
            j++;
        }
        else
        {
            if (j == 0)
            {
                flag = true;
                j++;
                continue;
            }
            j--;
        }
    }
    string ans = "";
    for (auto it : v)
    {
        ans += it;
    }
    return ans;
}

//------------------------------7. Reverse Integer-----------------------------//

int ReverseInteger(int n)
{
    int a = 1;
    if (n < 0)
    {
        a = -1;
    }
    long int ans = 0;
    while (n != 0)
    {
        ans = ans * 10 + n % 10;
        n = n / 10;
    }
    if (ans > INT_MAX || ans < INT_MIN)
    {
        return 0;
    }
    return ans;
}

//------------------------------8. String To Integer----------------------//

int MyAtoi(string s)
{
    int n = s.length();
    long int ans = 0;
    int sign = 1;
    int i = 0;
    while (i < n)
    {
        if (s[i] != ' ')
        {
            break;
        }
        i++;
    }
    if (i == n)
    {
        return 0;
    }
    if ((s[i] == '-' || s[i] == '+') && i < n)
    {
        sign = (s[i++] == '-') ? -1 : 1;
    }
    while ('0' <= s[i] && s[i] <= '9' && i < n)
    {
        ans = ans * 10 + (s[i++] - '0');
        if (ans * sign >= INT_MAX)
        {
            return INT_MAX;
        }
        if (ans * sign <= INT_MIN)
        {
            return INT_MIN;
        }
    }
    return ans * sign;
}

//----------------------------------9. Palindrome Number -------------------------------//

bool Palindrome_M1(int n)
{
    string s = to_string(n);
    string a = s;
    reverse(a.begin(), a.end());
    if (a == s)
    {
        return true;
    }
    return false;
}

int reve(int a)
{
    int ans = 0;
    while (a)
    {
        ans = ans * 10 + a % 10;
        a = a / 10;
    }
    return ans;
}

bool Palindrome_M2(int n)
{
    int b = reve(n);
    if (n == b)
    {
        return true;
    }
    return false;
}

//------------------------10. Regular Expression problem-------------------------//

bool isMatch(string s, string p)
{
    int m = s.size(), n = p.size();
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (p[j - 1] == '*')
            {
                dp[i][j] = dp[i][j - 2] || (i && dp[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
            }
            else
            {
                dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
            }
        }
    }
    return dp[m][n];
}

//-----------------------------------------------------------------------------------------//

int main()
{
    
}