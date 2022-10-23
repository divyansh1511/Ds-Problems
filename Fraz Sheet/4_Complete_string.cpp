#include <bits/stdc++.h>
using namespace std;

string addStrings(string num1, string num2)
{
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;
    string res = "";
    while (i >= 0 || j >= 0 || carry)
    {
        long sum = 0;
        if (i >= 0)
        {
            sum += (num1[i] - '0');
            i--;
        }
        if (j >= 0)
        {
            sum += (num2[j] - '0');
            j--;
        }
        sum += carry;
        carry = sum / 10;
        sum = sum % 10;
        res = to_string(sum) + res;
    }
    return res;
}

string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    string ans = "";
    if (n == 0)
    {
        return "";
    }
    sort(strs.begin(), strs.end());
    string a = strs[0];
    string b = strs[n - 1];
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[i])
        {
            ans = ans += a[i];
        }
        else
        {
            break;
        }
    }
    return ans;
}

bool validPalindrome(string s)
{
    for (int i = 0, j = s.size() - 1; i < j; i++, j--)
    {
        if (s[i] != s[j])
        {
            int i1 = i + 1, j1 = j, i2 = i, j2 = j - 1;
            while (i1 < j1 && s[i1] == s[j1])
            {
                i1++;
                j1--;
            }
            while (i2 < j2 && s[i2] == s[j2])
            {
                i2++;
                j2--;
            }
            return i1 >= j1 || i2 >= j2;
        }
    }
    return true;
}

int romanToInt(string s)
{
    unordered_map<char, int> T = {{'I', 1},
                                  {'V', 5},
                                  {'X', 10},
                                  {'L', 50},
                                  {'C', 100},
                                  {'D', 500},
                                  {'M', 1000}};

    int sum = T[s.back()];
    for (int i = s.length() - 2; i >= 0; --i)
    {
        if (T[s[i]] < T[s[i + 1]])
        {
            sum -= T[s[i]];
        }
        else
        {
            sum += T[s[i]];
        }
    }
    return sum;
}

int strStr(string haystack, string needle)
{
    int n = haystack.length();
    int h = needle.length();
    if (needle == "")
    {
        return 0;
    }
    if (h > n)
    {
        return -1;
    }
    for (int i = 0; i < n - h + 1; i++)
    {
        if (haystack.substr(i, h) == needle)
        {
            return i;
        }
    }
    return -1;
}

int lengthOfLongestSubstring(string s)
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

string longestPalindrome(string s)
{
    int n = s.length();
    int dp[n][n];
    memset(dp, 0, sizeof(dp));
    int mxlen = 0, start = 0;
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
                    start = i;
                    mxlen = k;
                }
            }
        }
    }
    return s.substr(start, mxlen);
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    unordered_map<string, vector<string>> mp;
    for (auto s : strs)
    {
        string t = s;
        sort(t.begin(), t.end());
        mp[t].push_back(s);
    }
    vector<vector<string>> v;
    for (auto it : mp)
    {
        v.push_back(it.second);
    }
    return v;
}

void helper(string s, vector<string> &v, int a, int b)
{
    if (a == 0 && b == 0)
    {
        v.push_back(s);
        return;
    }
    if (b > 0)
    {
        helper(s + ")", v, a, b - 1);
    }
    if (a > 0)
    {
        helper(s + "(", v, a - 1, b + 1);
    }
}
vector<string> generateParenthesis(int n)
{
    vector<string> v;
    helper("", v, n, 0);
    return v;
}

int calculate(string s)
{
    istringstream in('+' + s + '+');
    long long total = 0, term = 0, n;
    char op;
    while (in >> op)
    {
        if (op == '+' or op == '-')
        {
            total += term;
            in >> term;
            term *= 44 - op;
        }
        else
        {
            in >> n;
            if (op == '*')
                term *= n;
            else
                term /= n;
        }
    }
    return total;
}

string intToRoman(int num)
{
    string str[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int val[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string res = "";
    for (int i = 0; num != 0; i++)
    {
        while (num >= val[i])
        {
            num -= val[i];
            res += str[i];
        }
    }
    return res;
}

string reverseWords(string s)
{
    if (s.length() == 0)
    {
        return s;
    }
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        string a = "";
        while (s[i] != ' ' && i < s.length())
        {
            a += s[i];
            i++;
        }
        if (a.length() != 0)
        {
            st.push(a);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top() + " ";
        st.pop();
    }
    while (ans[0] == ' ' || ans[ans.length() - 1] == ' ')
    {
        if (ans[0] == ' ')
        {
            ans = ans.substr(1, ans.length());
        }
        else
        {
            ans = ans.substr(0, ans.length() - 1);
        }
    }
    return ans;
}

string simplifyPath(string path)
{
    string temp;
    vector<string> v;
    stringstream ss(path);
    while (getline(ss, temp, '/'))
    {
        if (temp == "." || temp == "")
        {
            continue;
        }
        if (temp == ".." && !v.empty())
        {
            v.pop_back();
        }
        else if (temp != "..")
        {
            v.push_back(temp);
        }
    }
    string res;
    for (string str : v)
    {
        res += "/" + str;
    }
    return res.empty() ? "/" : res;
}

string convert(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    vector<vector<char>> v(numRows);
    int j = 0;
    bool flag = true;
    for (int i = 0; i < s.length(); i++)
    {
        v[j].push_back(s[i]);
        if (flag)
        {
            if (j == numRows - 1)
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
        for (auto x : it)
        {
            ans += x;
        }
    }
    return ans;
}

string minWindowSubstring(string s, string t)
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

int DistinctSubsequence(string s, string t)
{
    vector<vector<unsigned int>> dp(t.size() + 1, vector<unsigned int>(s.size() + 1));
    for (int j = 0; j <= s.size(); j++)
        dp[0][j] = 1;
    for (int i = 1; i <= t.size(); i++)
    {
        for (int j = 1; j <= s.size(); j++)
        {
            if (t[i - 1] == s[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
            }
            else
            {
                dp[i][j] = dp[i][j - 1];
            }
        }
    }
    return dp[dp.size() - 1][dp[0].size() - 1];
}



int main()
{
}