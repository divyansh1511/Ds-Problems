#include<bits/stdc++.h>
using namespace std;

int IsPalindrome(string s){
    transform(s.begin() , s.end() , s.begin() , ::tolower);
    string tmp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 48 && s[i] <= 57))
        {
            tmp += s[i];
        }
    }
    int n = tmp.length();
    int i = 0 , j = n-1;
    while (i < j)
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

int ConstAndVowel(string s){
    int n = s.length();
    if (n == 1)
    {
        return 0;
    }
    int ans = 0;
    int cons = 0 , vowel = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            vowel++;
        }
        else
        {
            cons++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            ans += cons;
            cons--;
        }
        else
        {
            ans += vowel;
            vowel--;
        }
    }
    return ans;
}

string RemoveConsequtive(string s , int k){
    int count = 1;
    int n = s.length();
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == s[i+1])
        {
            count++;
        }
        else
        {
            if (count == k)
            {
                count = 1;
                continue;
            }
            ans += s[i];
            count = 1;
        }
    }
    return ans;
}

string serialize(vector<string> v){
    string ans = "";
    for (int i = 0; i < v.size(); i++)
    {
        ans += v[i];
        ans += to_string(v[i].length());
        ans += '~';
    }
    return ans;
}

vector<string> Deserialize(string s){
    vector<string> ans;
    string tmp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 97 && s[i] <= 122)
        {
            tmp += s[i];
        }
        else
        {
            if (tmp != "")
            {
                ans.push_back(tmp);
            }
            tmp = "";
        }
    }
    return ans;
}

string StrandFrequency(string s){
    map<char , int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (mp[s[i]] > 0)
        {
            ans += s[i];
            ans += to_string(mp[s[i]]);
            mp[s[i]] = 0;
        }
    }
    return ans;
}

string BullsAndCows(string A, string B) {
    unordered_map<char , int> mp1;
    unordered_map<char , int> mp2;
    int bulls = 0;
    for(int i=0;i<A.length();i++){
        if(A[i] == B[i]){
            bulls++;
            continue;
        }
        mp1[A[i]]++;
        mp2[B[i]]++;
    }
    int cow = 0;
    for(auto it : mp1){
        int a = it.second;
        int b = mp2[it.first];
        if(a == b){
            cow += a;
        }
        else if(a < b){
            cow += a;
        }
        else{
            cow += b;
        }
    }
    string ans = "";
    ans += to_string(bulls);
    ans += 'A';
    ans += to_string(cow);
    ans += 'B';
    return ans;
}

int SelfPermuatation(string A, string B) {
    if(A.length() != B.length()){
        return 0;
    }
    map<char , int> mp;
    for(int i=0;i<A.length();i++){
        mp[A[i]]++;
        mp[B[i]]--;
    }
    for(auto it : mp){
        if(it.second > 0 || it.second < 0){
            return false;
        }
    }
    return true;
}

string LonestCommonPrefix(vector<string> &v){
    int n = v.size();
    string ans = "";
    if (n == 0)
    {
        return ans;
    }
    sort(v.begin() , v.end());
    string a = v[0];
    string b = v[n-1];
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
    for (int i = 3; i < n; i++)
    {
        string tmp = "";
        s += "&";
        int c =1;
        for (int j = 1; j < s.length(); j++)
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

int AmazingSubarr(string a){
    int n = a.length();
    int cnt = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u' || a[i] == 'A' || a[i] == 'E' || a[i] == 'I' || a[i] == 'O' || a[i] == 'U')
        {
            cnt += (n-i);
        }
    }
    return cnt;
}

int StrStr(const string A, const string B) {
    int n = A.length();
    int m = B.length();
    if(B == ""){
        return 0;
    }
    if(m > n){
        return -1;
    }
    for(int i=0;i<n-m+1;i++){
        if(A.substr(i , m) == B){
            return i;
        }
    }
    return -1;
}

int MinChrReqToMakePalindrome(string s){
    int n = s.length();
    int i = 0 , j = n-1 , k = n;
    while (i <= j)
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

bool ConverToPalindrome(string s){
    int i = 0 , j = s.length()-1;
    int c = 0;
    while (i <= j)
    {
        if (s[i] == s[j])
        {
            i++;
            j--;
        }
        else
        {
            c++;
            i++;
            if (c > 1)
            {
                return false;
            }
        }
    }
    return true;
}

bool isPalindrome(string s){
    int i = 0 , j = s.length()-1;
    while (i <= j)
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

int MinAppendPalindrome(string s){
    int n = s.length();
    if (isPalindrome(s) == 1)
    {
        return 0;
    }
    int c = 0;
    while (n--)
    {
        string a = s.substr(++c);
        if (isPalindrome(a) == 1)
        {
            break;
        }
    }
    return c;
}

int MinParenthesis(string A){
    stack<char> s;
    int n = A.length();
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(A[i] == '('){
            s.push(A[i]);
        }
        else{
            if(s.empty()){
                cnt++;
            }
            else{
                s.pop();
            }
        }
    }
    return s.size()+cnt;
}

string longestPalindrome(string s) {
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
    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n-k+1; i++)
        {
            int j = i+k-1;
            if (s[i] == s[j] && dp[i+1][j-1] == 1)
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
    return s.substr(start , mxlen);
}

int compareVersion(string A, string B) {
    int i=0,j=0;
    while(i<A.length() && j<B.length()){
        string n,n1;
        while(i<A.length() && A[i]!='.'){
            n=n+(A[i]);
            i++;
        }
        i++;
        while(j<B.length() && B[j]!='.'){
            n1=n1+(B[j]);
            j++;
        }
        j++;
        int m=0,l=0;
        while(n[m]=='0') m++;
        while(n1[l]=='0') l++;
       
        n=n.substr(m);
        n1=n1.substr(l);
       
        if(n.length()>n1.length()) return 1;
        else if(n1.length()>n.length()) return -1;
        else if(n>n1) return 1;
        else if(n1>n) return -1;
    }
    if(i<A.length()){
        while(i<A.length()){
            if(A[i]!='.' && A[i]!='0') return 1;
            i++;
        }
    }
    if(j<B.length()){
        while(j<B.length()){
            if(B[j]!='.' && B[j]!='0') return -1;
            j++;
        }
    }
    return 0;
}

int atoi(const string s) {
    long long int res = 0;
    int indi = 1;
    int n = s.size();
    if(n==0){
        return 0;
    }
    int i=0;
    while((s[i] == ' ') && (i<n)){
        i++;
    }
    if(i == n){
        return 0;
    }
    if((s[i] == '-' || s[i] == '+') && i<n){
        indi = (s[i++] == '-') ? -1 : 1;
    }
    while(s[i] >= '0' && s[i] <= '9' && i<n){
        res = res*10 + (s[i++] - '0');
        if(res*indi >= INT_MAX){
            return INT_MAX;
        }
        if(res*indi <= INT_MIN){
            return INT_MIN;
        }
    }
    return res*indi;
}

int LengthofLastWord(string s){
    int n = s.length();
    int i = n-1;
    while (i >= 0 && s[i] == ' ')
    {
        i--;
    }
    int count = 0;
    while (i>=0 && s[i] != ' ')
    {
        count++;
        i--;
    }
    return count;
}

string ReverseStringinWords(string s) {
    stack<string> st;
    int n = s.length();
    int count = 0;
    string a = "";
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            if (count != 0)
            {
                st.push(a);
            }
            count = 0;
            a = "";
        }
        else
        {
            count++;
            a += s[i];
        }
    }
    if (a != "")
    {
        st.push(a);
    }
    string ans = st.top();
    st.pop();
    while (!st.empty())
    {
        ans += " ";
        ans += st.top();
        st.pop();
    }
    return ans;
}

string intToRoman(int A) {
    string str[] = {"M" , "CM" , "D" , "CD" , "C" , "XC" , "L" , "XL" , "X" , "IX" , "V" , "IV" , "I"};
    int val[] = {1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4 , 1};
    
    string s = "";
    for(int i=0; A!=0 ; i++){
        while(A >= val[i]){
            A -= val[i];
            s += str[i];
        }
    }
    return s;
}

int romanToInt(string A) {
    unordered_map<char , int> mp;
    mp['I'] = 1;
    mp['V'] = 5;
    mp['X'] = 10;
    mp['L'] = 50;
    mp['C'] = 100;
    mp['D'] = 500;
    mp['M'] = 1000;
    int n = A.length();
    int sum = mp[A[n-1]];
    for(int i=n-2;i>=0;i--){
        if(mp[A[i]] < mp[A[i+1]]){
            sum -= mp[A[i]];
        }
        else{
            sum += mp[A[i]];
        }
    }
    return sum;
}

string addBinary(string A, string B) {
    string res = "";
    int i = A.length() - 1 , j = B.length() - 1;
    int carry = 0;
    while(i >= 0 || j >= 0){
        int sum = carry;
        if(i >= 0){
            sum += A[i--] - '0';
        }
        if(j >= 0){
            sum += B[j--] - '0';
        }
        carry = (sum > 1) ? 1 : 0;
        res += to_string(sum%2);
    }
    if(carry){
        res += '1';
    }
    reverse(res.begin() , res.end());
    return res;
}

int powerof2(string s){
    int n = stoi(s);
    return n && (!(n & (n-1)));
}

string multiply(string A, string B) {
    int n = A.length();
    int m = B.length();
    string res((n+m) , '0');
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            int num = (A[i] - '0')*(B[j] - '0') + res[i+j+1] - '0';
            res[i+j+1] = num%10 + '0';
            res[i+j] += num/10;
        }
    }
    for(int i=0;i<res.length();i++){
        if(res[i] != '0'){
            return res.substr(i);
        }
    }
    return "0";
}

string convert(string s, int numRows) {
    if(numRows == 1){
        return s;
    }
    vector<vector<char>> v(numRows);
    int j = 0;
    bool flag = true;
    for(int i=0;i<s.length();i++){
        v[j].push_back(s[i]);
        if(flag){
            if(j == numRows - 1){
                flag = false;
                j--;
                continue;
            }
            j++;
        }
        else{
            if(j == 0){
                flag = true;
                j++;
                continue;
            }
            j--;
        }
    }
    string ans = "";
    for(auto it : v){
        for(auto x : it){
            ans += x;
        }
    }
    return ans;
}



int main(){

}