#include<bits/stdc++.h>
using namespace std;

string reversewords(string s){
    string ans = "";
    string word = "";
    stack<string> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            word += s[i];
        }
        else
        {
            if (word != "")
            {
                st.push(word);
            }
            word = "";
        }
    }
    if (word != "")
    {
        st.push(word);
    }
    
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    return ans;
}

string longestPalindrome(string s){
    int n = s.length();
    int dp[n][n];
    memset(dp , 0 , sizeof(dp));

    int mxlen = 0 , start = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        mxlen = 1;
    }
    for (int i = 0; i < n-1; i++)
    {
        if (s[i] == s[i+1])
        {
            dp[i][i+1] = 1;
            start = i;
            mxlen = 2;
        }
    }
    for (int k = 0; k <= n; k++)
    {
        for (int i = 0; i < n-k+1; i++)
        {
            int j = i + k -1;
            if (s[i] == s[j] && dp[i+1][j-1] == 1)
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
    return s.substr(start , mxlen);
}

int RomanToInt(string s){
    unordered_map<char , int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;

    int sum = mp[s.back()];
    for (int i = s.length()-2; i >= 0; i--)
    {
        if (mp[s[i]] < mp[s[i+1]])
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

int MyAtoi(string s){
    long long ans = 0;
    int indicator = 1;
    int n = s.length();
    if (n == 0)
    {
        return 0;
    }
    int i = 0;
    while (i < n && s[i] == ' ')
    {
        i++;
    }
    if (s[i] == '-' || s[i] == '+')
    {
        indicator = (s[i++] == '-') ? -1 : 1;
    }
    while (s[i] >= '0' && s[i] <= '9' && i<n)
    {
        ans = ans*10 + (s[i++] - '0');
        if (ans*indicator >= INT_MAX)
        {
            return INT_MAX;
        }
        if (ans*indicator <= INT_MIN)
        {
            return INT_MIN;
        }
    }
    return ans*indicator;
}

string longestCommonPrefix(vector<string> &v){
    int n = v.size();
    string ans = "";
    if (n == 0)
    {
        return "";
    }
    sort(v.begin() , v.end());
    string a = v[0];
    string b = v[n-1];
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[i])
        {
            ans += a[i];
        }
        else
        {
            break;
        }
    }
    return ans;
}

int strstr(string a , string b){
    int n = a.length();
    int m = b.length();
    if (a == "")
    {
        return 0;
    }
    if (m > n)
    {
        return -1;
    }
    for (int i = 0; i < n-m+1; i++)
    {
        if (a.substr(i , m) == b)
        {
            return i;
        }
    }
    return -1;
}

int mincharactertomakePalindrome(string s){
    int n = s.length();
    int i = 0 , j = n-1 , k = n;

    while (i<=j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            while (s[j] != s[0])
            {
                j--;
            }
            k = j;
            i = 0;
        }
    }
    if (k == n)
    {
        return 0;
    }
    return n-k-1;
}

bool isAnagram(string s1 , string s2){
    if (s1.length() != s2.length())
    {
        return false;
    }
    sort(s1.begin() , s1.end());
    sort(s2.begin() , s2.end());
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] != s2[i])
        {
            return false;
        }
    }
    return true;
}

string countandsay(int n){
    if (n == 1)
    {
        return "1";
    }
    if (n == 2)
    {
        return "11";
    }
    string s = "11";
    for (int i = 3; i <= n; i++)
    {
        string t = "";
        s = s+"&";
        int c = 1;
        for (int j = 1; j < s.length(); j++)
        {
            if (s[j] != s[j-1])
            {
                t += to_string(c);
                t += s[j-1];
                c = 1;
            }
            else
            {
                c++;
            }
        }
        s = t;
    }
    return s;
}

int compareVerion(string s1 , string s2){
    int n1 = s1.length();
    int n2 = s2.length();

    int i = 0 , j = 0;
    int num1 = 0 , num2 = 0;

    while (i<n1 || j<n2)
    {
        while (i<n1 && s1[i] != '.')
        {
            num1 = num1*10 + (s1[i++]-'0');
        }
        while (j<n2 && s2[j] != '.')
        {
            num2 = num2*10 + (s2[j++]-'0');
        }
        if (num1 > num2)
        {
            return 1;
        }
        if (num1 < num2)
        {
            return -1;
        }
        num1 = 0;
        num2 = 0;
        i++;
        j++;
    }
    return 0;
}

//----------------RABIN KRAP ALGO------------------//

//----------------KMP ALGO------------------------//

int main(){

}