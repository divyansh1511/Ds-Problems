#include<bits/stdc++.h>
using namespace std;

void reversestring(string &s){
    reverse(s.begin() , s.end());
}

bool isPalindrome(string s){
    int i = 0 , j = s.length()-1;
    while (i<=j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

vector<char> FindDuplicate(string s){
    unordered_map<char , int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    vector<char> ans;
    for(auto it : mp){
        if (it.second > 1)
        {
            ans.push_back(it.first);
        }
    }
    return ans;
}

bool IsRotationOfOther(string s1 , string s2){
    if (s1.length() != s2.length())
    {
        return false;
    }
    string a = s1+s1;
    return (a.find(s2) != string::npos);
}

string CountAndSay(int n){
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
        s += '&';
        int c = 1;
        for (int j = 0; j < s.length(); j++)
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

string LongestPalindrome(string s){
    int n = s.length();
    if (n < 2)
    {
        return s;
    }
    int mxlen = 1 , st = 0;
    int low , high;
    for (int i = 0; i < n; i++)
    {
        low = i-1;
        high = i+1;
        while (high < n && s[high] == s[i])
        {
            high++;
        }
        while (low >= 0 && s[low] == s[i])
        {
            low--;
        }
        while (low >=0 && high < n && s[low] == s[high])
        {
            low--;
            high++;
        }
        int len = high-low-1;
        if (mxlen < len)
        {
            mxlen = len;
            st = low+1;
        }
    }
    return s.substr(st , mxlen);
}

int LongestRepeatingSubsequence(string s){
    int n = s.length();
    int dp[n+1][n+1];
    memset(dp , 0 , sizeof(dp));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i-1] == s[j-1] && i != j)
            {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }
    }
    return dp[n][n];
}

void helper(string s , int st , string a , vector<string> &v){
    v.push_back(a);
    for (int i = st; i < s.length(); i++)
    {
        a += s[i];
        helper(s , i+1 , a , v);
        a.pop_back();
    }
}

vector<string> PrintAllSubsequence(string s){
    vector<string> v;
    string a = "";
    helper(s , 0 , a , v);
    return v;
}

void helper1(string s , int st , vector<string> &v){
    if (st == s.length())
    {
        v.push_back(s);
        return;
    }
    for (int i = st; i < s.length(); i++)
    {
        swap(s[i] , s[st]);
        helper1(s , st+1 , v);
        swap(s[i] , s[st]);
    }
}

vector<string> PermutationOfGivenStrings(string s){
    vector<string> v;
    helper1(s , 0 , v);
    return v;
}

int SplitBinaryString(string str){
    int c = 0;
    int a = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1')
        {
            a++;
        }
        else
        {
            a--;
        }
        if (a == 0)
        {
            c++;
        }
    }
    if (a != 0)
    {
        return -1;
    }
    return c;
}

int EditDistance(string s , string t){
    int n = s.length() , m = t.length();
    int dp[n+1][m+1];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; i++)
        {
            if (i == 0)
            {
                dp[i][j] = j;
            }
            else if (j == 0)
            {
                dp[i][j] = i;
            }
            else if (s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min({dp[i-1][j] , dp[i-1][j-1] , dp[i][j-1]});
            }
        }
    }
    return dp[n][m];
}

vector<int> NextPermuatation(vector<int> v){
    int n = v.size();
    int k,l;
    for (k = n-2; k >= 0; k--)
    {
        if (v[k] < v[k+1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(v.begin() , v.end());
    }
    else
    {
        for (l = n-1; l > k; l--)
        {
            if (v[l] > v[k])
            {
                break;
            }
        }
        swap(v[l] , v[k]);
        reverse(v.begin()+k+1 , v.end());
    }
    return v;
}

bool BalancedParenthesis(string s){
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

bool WordBreak(string s , vector<string> &v){
    vector<bool> dp(s.length()+1 , false);

    for (int i = 1; i <= s.length(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((dp[j]) && find(v.begin(), v.end() , s.substr(j , i-j)) != v.end())
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp.back();
}

void RabinKrapAlgo(string pat, string txt, int q)  // you can create your own hash function for searching
{
    int d = 256;
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0; 
    int t = 0; 
    int h = 1;

    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
 
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        t = (d * t + txt[i]) % q;
    }

    for (i = 0; i <= N - M; i++) {
        if (p == t) {
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }

            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}

int KMPalgo(string s){          //Longest prefix suffix --- to match the pattern
    int n = s.length();
    string a1 = "";
    string a2 = "";

    int i = n-1 , j = 1;
    while (i > 0 && j < n-1)
    {
        if (s[0] != s[j])
        {
            i--;
            j++;
            continue;
        }
        a1 = s.substr(0 , i);
        a2 = s.substr(j , n);
        if (a1 == a2)
        {
            return a1.length();
        }
        i--;
        j++;
    }
    if (s[0] == s[n-1])
    {
        return 1;
    }
    return 0;
}

string PrintPhoneNumberSequence(string s){
    vector<string> v = {"2",   "22",  "222", "3",   "33",   "333", "4", "44",  "444", "5",   "55",  "555",  "6", "66", "666", "7", "77",  "777", "7777", "8", "88", "888", "9",   "99",  "999", "9999"};
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            ans += '0';
        }
        else
        {
            int pos = s[i]-'A';
            ans += v[pos];
        }
    }
    return ans;
}

int CountTheReversals(string s){
    int c = 0;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{')
        {
            if (st.empty() || st.top() == '{')
            {
                st.push(s[i]);
            }
        }
        else
        {
            if (st.empty())
            {
                c++;
                st.push('{');
            }
            else if (st.top() == '{')
            {
                st.pop();
            }
            else if (st.top() == '}')
            {
                c++;
                st.pop();
            }
        }
    }
    if (st.empty())
    {
        return c;
    }
    if (st.size()%2 == 0)
    {
        return (st.size()/2)+c;
    }
    return -1;
}

int countPalindromicSequence(string s)
{
    int n = s.length();
    int dp[n + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
        dp[i][i] = 1;

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n-L; i++) {
            int k = L + i - 1;
            if (s[i] == s[k])
                dp[i][k] = dp[i][k - 1] + dp[i + 1][k] + 1;
            else
                dp[i][k] = dp[i][k - 1] + dp[i + 1][k] - dp[i + 1][k - 1];
        }
    }

    return dp[0][n - 1];
}

int helper2(string s , int r , int c , vector<vector<char>> v , int n , int m , int idx){
    int f = 0;
    if (r >= 0 && r <= n && c >= 0 && c <= n && s[idx] == v[r][c])
    {
        char a = s[idx];
        idx++;
        v[r][c] = '0';
        if (s[idx] == '0')
        {
            f = 1;
        }
        else
        {
            f += helper2(s , r , c+1 , v , n , m , idx);
            f += helper2(s , r , c-1 , v , n , m , idx);
            f += helper2(s , r+1 , c , v , n , m , idx);
            f += helper2(s , r-1 , c , v , n , m , idx);
        }
        v[r][c] = a;
    }
    return f;
}

int SearchStringin2Dmatrix(string s , vector<vector<char>> v){
    int count = 0;
    int n = v.size() , m = v[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            count += helper2(s , 0 , 0 ,v , n-1 , m-1 , 0);
        }
    }
    return count;
}

bool BoyerMoreAlgo(string s1 , string s2){
    int n = s1.length();
    int m = s2.length();

    vector<int> tmp(256 , -1);
    for (int i = 0; i < m; i++)
    {
        tmp[s2[i]] = i;
    }
    int s = 0;
    while (s <= (n-m))
    {
        int j = m-1;
        while (j >= 0 && s2[j] == s1[s+j])
        {
            j--;
        }
        if (j < 0)
        {
            cout<<"occurs at "<<s<<endl;
            return true;
        }
        else
        {
            s += max(1 , j-tmp[s1[s+j]]);
        }
    }
    return false;
}

int RomanToDecimal(string &str) {
    unordered_map<char , int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    
    int n = str.length();
    int ans = mp[str[n-1]];
    for(int i=n-2;i>=0;i--){
        if(mp[str[i]] < mp[str[i+1]]){
            ans -= mp[str[i]];
        }
        else{
            ans += mp[str[i]];
        }
        // cout<<ans<<endl;
    }
    return ans;
}

string LongestCommonPrefix(vector<string> v){
    int n = v.size();
    string ans = "";
    sort(v.begin() , v.end());
    string a = v[0];
    string b = v[n-1];
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] != b[i])
        {
            return ans;
        }
        ans += a[i];
    }
    return ans;
}

int minFlips (string s)
{
    int i,count1=0,count2=0;
    for(i=0;i<s.length();i++){
        if((i%2==0&&s[i]!='0')||(i%2!=0&&s[i]!='1'))
            count1++;
        if((i%2==0&&s[i]!='1')||(i%2!=0&&s[i]!='0'))
            count2++;
    }
    return min(count1,count2);
}

string SecondMostFrequent (string arr[], int n)
{
    unordered_map<string , int> mp;
    int mx = INT_MIN;
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
        mx = max(mx ,mp[arr[i]]);
    }
    int ans = INT_MIN;
    string res = "";
    for(auto it : mp){
        if(mx != it.second && ans < it.second){
            ans = it.second;
            res = it.first;
        }
    }
    return res;
}

int MinSwapsForBracketBalancing(string s){
    int cl = 0 , cr = 0;
    int b = 0 , ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
        {
            cl++;
            if (b > 0)
            {
                ans += b;
                b--;
            }
        }
        else if (s[i] == ']')
        {
            cr++;
            b = (cr-cl);
        }
    }
    return ans;
}

int findSubString(string str)
{  
    set<char>s;
    for(auto c:str)
        s.insert(c);
    unordered_map<char,int>m;
    int i=0;
    int j=0;
    int ans=str.size();
    int n=s.size();
    while(i<str.size())
    {
        m[str[i]]++;
        if(m.size()==n)
        {
            while(m[str[j]]>1)
            {
                m[str[j]]--;
                j++;
            }
            ans=min(ans,i-j+1);
        }
        i++;
    }
    return ans;
}

int MinChrtoPalindrome(string s){
    int n = s.length();
    int ans = n-1;
    int i = 0 , j = n-1;
    while (i <= j)
    {
        if (s[i] != s[j])
        {
            i = 0;
            ans--;
            j = ans;
        }
        else
        {
            i++;
            j--;
        }
    }
    return n-ans-1;
}

vector<vector<string>> Anagrams(vector<string> v){
    unordered_map<string , vector<string>> mp;
    for (int i = 0; i < v.size(); i++)
    {
        string a = v[i];
        sort(a.begin() , a.end());
        mp[a].push_back(v[i]);
    }
    vector<vector<string>> ans;
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

string smallestWindow(string s, string p)
{
    vector<int> mp(128,0);
    for(char c: p) mp[c]++;
    int start = 0, end = INT_MAX, i = 0, j =0, len = p.size();
    while(i<s.size()){
        if(mp[s[i++]]-- > 0) len--;
        while(len == 0){
            if(i-j<end) end = i - (start = j);
            if(mp[s[j++]]++ == 0) len++;
        }
    }
    return end != INT_MAX ? s.substr(start,end) : "-1";
}

string removeConsecutiveCharacter(string S)
{
    string str;
    for(int i=0;i<S.length();i++){
        if(S[i]!=S[i+1]){
            str+=S[i];
        }
    }
    return str;
}

bool WildCardmatch(string wild, string pattern)
{
    int n = wild.length();
    int m = pattern.length();
      
    bool t[n+1][m+1];
    
    for(int i=n;i>=0;i--){
        for(int j = m;j>=0;j--){
            if(i==n && j==m)
                t[i][j] = true;
            else if(i==n )
                t[i][j] = false;
            else if(j==m){
                if(wild.at(i)=='*')
                    t[i][j] = t[i+1][j];
                else
                    t[i][j] = false;
            }
            else if((wild.at(i)=='?') || (wild.at(i)==pattern.at(j)))
                t[i][j] = t[i+1][j+1];
            else if(wild.at(i)=='*')
                t[i][j] = t[i+1][j] || t[i][j+1];
            else
                t[i][j] = false;
        }
    }
    return t[0][0];
}

bool areIsomorphic(string str1, string str2)
{
    if(str1.length() != str2.length()){
        return false;
    }
    int count[256] = {0};
    int dcount[256] = {0};
    for(int i=0;i<str1.length();i++){
        count[str1[i] - 'a']++;
        dcount[str2[i] - 'a']++;
        if(count[str1[i] - 'a'] != dcount[str2[i] - 'a']){
            return false;
        }
    }
    return true;
}

int main(){
    
}