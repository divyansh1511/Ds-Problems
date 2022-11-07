#include <bits/stdc++.h>
using namespace std;

bool validPalindrome(string s)
{
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    int n = s.length();
    string tmp = "";
    for (int i = 0; i < n; i++)
    {
        if ((s[i] >= 48 && s[i] <= 57) || (s[i] >= 97 && s[i] <= 122))
        {
            tmp += s[i];
        }
    }
    n = tmp.length();
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (tmp[i] != tmp[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

bool isAnagram(string a, string b)
{
    if (a.length() != b.length())
    {
        return false;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}

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

string RemoveConsequtiveCharacters(string S)
{
    string tmp = "";
    for (int i = 0; i < S.length(); i++)
    {
        if (tmp == "" || tmp.back() != S[i])
        {
            tmp += S[i];
        }
    }
    return tmp;
}

string LongestCommonPrefix(vector<string> v)
{
    if (v.size() == 0)
    {
        return "";
    }
    sort(v.begin(), v.end());
    string a = v[0];
    string b = v[v.size() - 1];
    string ans = "";
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            break;
        }
        ans += a[i];
    }
    return ans;
}

string MobileKeypad(string s)
{
    vector<string> v = {"2", "22", "222", "3", "33", "333", "4", "44", "444", "5", "55", "555", "6", "66", "66", "7", "77", "777", "7777", "8", "88", "888", "9", "99", "999", "9999"};
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            ans += "0";
        }
        else
        {
            ans += v[s[i] - 'A'];
        }
    }
    return ans;
}

void printDuplicates(string s)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    for (auto it : mp)
    {
        if (it.second > 1)
        {
            cout << it.first << " " << it.second << endl;
        }
    }
}

int LengthOfLongestSubstring(string s)
{
    vector<int> v(256, -1);
    int len = 0;
    int left = 0, right = 0;
    int n = s.length();
    while (right < n)
    {
        if (v[s[right]] != -1)
        {
            left = max(v[s[right]] + 1, left);
        }
        v[s[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }
    return len;
}

int LongestCharacterRepeating(string s, int k)
{
    int res = 0, maxf = 0;
    unordered_map<int, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        maxf = max(maxf, ++mp[s[i]]);
        if (res - maxf < k)
        {
            res++;
        }
        else
        {
            mp[s[i - res]]--;
        }
    }
    return res;
}

vector<vector<string>> groupAnagrams(vector<string> v)
{
    unordered_map<string, vector<string>> mp;
    for (int i = 0; i < v.size(); i++)
    {
        string s = v[i];
        sort(s.begin(), s.end());
        mp[s].push_back(v[i]);
    }
    vector<vector<string>> ans;
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

string longestPalindromicSubstring(string s)
{
    int n = s.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    int mxlen = 0, st = 0;
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
            mxlen = 2;
            st = i;
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
                    st = i;
                    mxlen = k;
                }
            }
        }
    }
    return s.substr(st, mxlen);
}

int CountPalindromicSubstring(string s)
{
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n));
    int count = 0;
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
                dp[i][j] = (s[i] == s[j]) ? 1 : 0;
            }
            else
            {
                dp[i][j] = (s[i] == s[j]) ? dp[i + 1][j - 1] : 0;
            }
            count += dp[i][j];
        }
    }
    return count;
}

void nextPermutation(vector<int> v)
{
    int n = v.size();
    int k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (v[k] < v[k + 1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(v.begin(), v.end());
    }
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (v[l] > v[k])
            {
                break;
            }
        }
        swap(v[k], v[l]);
        reverse(v.begin() + k + 1, v.end());
    }
}

int countPalindromicSubsequence(string s)
{
    int n = s.length();
    int dp[n + 1][n + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][i] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            int k = i + j - 1;
            if (s[i] == s[k])
            {
                dp[i][k] = (dp[i][k - 1] + dp[i + 1][k] + 1);
            }
            else
            {
                dp[i][k] = dp[i][k - 1] + dp[i + 1][k] - dp[i + 1][k - 1];
            }
        }
    }
    return dp[0][n - 1];
}

string SmallestWindow(string s, string p)
{
    vector<int> v(128, 0);
    for (auto it : s)
    {
        v[it]++;
    }
    int start = 0, end = INT_MAX, i = 0, j = 0, len = p.length();
    while (i < s.size())
    {
        v[s[i]]--;
        i++;
        if (v[s[i]] > 0)
        {
            len--;
        }
        while (len == 0)
        {
            if (i - j < end)
            {
                end = i - (start = j);
            }
            if (v[s[j++]]++ == 0)
            {
                len++;
            }
        }
    }
    return end != INT_MAX ? s.substr(start, end) : "-1";
}

bool match(string wild, string pattern)
{
    int n = wild.length();
    int m = pattern.length();

    bool t[n + 1][m + 1];

    for (int i = n; i >= 0; i--)
    {
        for (int j = m; j >= 0; j--)
        {
            if (i == n && j == m)
                t[i][j] = true;
            else if (i == n)
                t[i][j] = false;
            else if (j == m)
            {
                if (wild.at(i) == '*')
                    t[i][j] = t[i + 1][j];
                else
                    t[i][j] = false;
            }
            else if ((wild.at(i) == '?') || (wild.at(i) == pattern.at(j)))
                t[i][j] = t[i + 1][j + 1];
            else if (wild.at(i) == '*')
                t[i][j] = t[i + 1][j] || t[i][j + 1];
            else
                t[i][j] = false;
        }
    }
    return t[0][0];
}

int longestprefixsuffix(string s)
{
    int n = s.size();
    string s1 = "";
    string s2 = "";
    int i = n - 1, j = 1;
    while (i > 0 and j < n - 1)
    {
        if (s[0] != s[j])
        {
            i--;
            j++;
            continue;
        }
        s1 = s.substr(0, i);
        s2 = s.substr(j, n);

        if (s1 == s2)
            return s1.size();
        j++;
        i--;
    }
    if (s[0] == s[n - 1])
        return 1;
    return 0;
}



int main()
{
}