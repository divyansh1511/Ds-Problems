#include <bits/stdc++.h>
using namespace std;

string reversewords(string s)
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
        ans += " ";
        st.pop();
    }
    return ans.substr(0, ans.length() - 1);
}

string LongestPalindrome(string s)
{
    int i = 0, j = 0;
    int n = s.length();

    vector<vector<int>> v(n, vector<int>(n, false));

    for (int i = 0; i < n; i++)
    {
        v[i][i] = true;
        if (i == n - 1)
        {
            break;
        }
        v[i][i + 1] = (s[i] == s[i + 1]);
    }

    for (int i = n - 3; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {
            v[i][j] = (v[i + 1][j - 1] && s[i] == s[j]);
        }
    }

    int maxi = 0, st = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (v[i][j] == true && j - i + 1 > maxi)
            {
                maxi = j - i + 1;
                st = i;
            }
        }
    }
    return s.substr(st, maxi);
}

int RomanToInt(string s)
{
    unordered_map<char, int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int sum = mp[s[s.length() - 1]];

    for (int i = s.length() - 2; i >= 0; i--)
    {
        if (mp[s[i]] < mp[s[i + 1]])
        {
            sum -= mp[s[i]];
        }
        else
        {
            sum += mp[s[i]];
        }
    }
    return sum;
}

int myAtoi(string s)
{
    long long int result = 0;
    int indicator = 1;
    int n = s.length();
    if (n == 0)
    {
        return 0;
    }

    int i = 0;
    while ((s[i] == ' ') && i < n)
    {
        i++;
    }
    if (i == n)
    {
        return 0;
    }
    if ((s[i] == '-' || s[i] == '+') && i < n)
        indicator = (s[i++] == '-') ? -1 : 1;

    while ('0' <= s[i] && s[i] <= '9' && i < n)
    {
        result = result * 10 + (s[i++] - '0');
        if (result * indicator >= INT_MAX)
            return INT_MAX;
        if (result * indicator <= INT_MIN)
            return INT_MIN;
    }
    return result * indicator;
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

bool isAnagram(string s, string t)
{
    if (s.length() != t.length())
    {
        return false;
    }
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

string CountandSay(int n){
    if (n == 1)
    {
        return "1";
    }
    if(n == 2){
        return "11";
    }
    string s = "11";
    for (int i = 3; i < n; i++)
    {
        string tmp = "";
        s += "&";
        int c = 1;
        for (int j = 1; j < s.length(); i++)
        {
            if (s[j] != s[j-1])
            {
                tmp += to_string(c);
                tmp += s[j-1];
                c = 1;
            }
            else
            {
                c++;
            }
        }
        s = tmp;
    }
    return s;
}

int CompareVersions(string s1 , string s2){
    int n1 = s1.length();
    int n2 = s2.length();

    int i = 0 , j = 0;
    int num1 = 0 , num2 = 0;

    while (i<n1 && j < n2)
    {
        while (i < n1 && s1[i] != '.')
        {
            num1 = num1*10 + (s1[i]-'0');
            i++;
        }
        while (j < n2 && s2[j] != '.')
        {
            num2 = num2*10 + (s2[j]-'0');
            j++;
        }
        if (num1 > num2)
        {
            return 1;
        }
        else if (num1 < num2)
        {
            return -1;
        }
        num1 = 0 , num2 = 0;
        i++;
        j++;
    }
    return 0;
}

int main()
{
}