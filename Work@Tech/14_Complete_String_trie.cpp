#include<bits/stdc++.h>
using namespace std;

string reverseWords(string &s) {
	stack<string> st;
	string curr = "";
	int n = s.length();
	for(int i=0;i<n;i++){
		if(s[i] != ' '){
			curr += s[i];
		}
		else{
			st.push(curr);
			curr = "";
		}
	}
	if(curr != ""){
		st.push(curr);
	}
	string ans = st.top();
	st.pop();
	while(!st.empty()){
		ans += " ";
		ans += st.top();
		st.pop();
	}
	return ans;
}

string getLongestPalindrome(string s) {
	int n = s.length();
	if(n < 2){
		return s;
	}
	int mxlen = 1 , st = 0;
	int low , high;
	for(int i=0;i<s.length();i++){
		low = i-1;
		high = i+1;
		while(low >= 0 && s[low] == s[i]){
			low--;
		}
		while(high < n && s[high] == s[i]){
			high++;
		}
		while(low >= 0 && high < n && s[low] == s[high]){
			low--;
			high++;
		}
		int len = high - low-1;
		if(mxlen < len){
			mxlen = len;
			st = low+1;
		}
	}
	return s.substr(st , mxlen);
}

int romanToInt(string s) {
	unordered_map<char , int> mp;
	mp['I'] = 1;
	mp['V'] = 5;
	mp['X'] = 10;
	mp['L'] = 50;
	mp['C'] = 100;
	mp['D'] = 500;
	mp['M'] = 1000;
	int sum = mp[s.back()];
	for(int i=s.length()-2;i>=0;i--){
		if(mp[s[i]] < mp[s[i+1]]){
			sum -= mp[s[i]];
		}
		else{
			sum += mp[s[i]];
		}
	}
	return sum;
}

string integerToRoman(int num) {
	vector<string> v1 = {"M" , "CM" , "D" , "CD" , "C" , "XC" , "L" , "XL" , "X" , "IX" , "V" , "IV" , "I"};
	
	vector<int> v2 = {1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4 , 1};
	
	string res = "";
	for(int i=0;num != 0;i++){
		while(num >= v2[i]){
			num -= v2[i];
			res += v1[i];
		}
	}
	return res;
}

bool areAnagrams(string A, string B) {
	vector<int> v(26 , 0);
	for(int i=0;i<A.length();i++){
		v[A[i]-'a']++;
	}
	for(int i=0;i<B.length();i++){
		v[B[i]-'a']--;
	}
	for(int i=0;i<26;i++){
		if(v[i] != 0){
			return false;
		}
	}
	return true;
}

string longestCommonPrefix(vector<string> &str) {
	sort(str.begin() , str.end());
	string a = str[0];
	string b = str[str.size()-1];
	string ans = "";
	for(int i=0;i<a.length();i++){
		if(a[i] != b[i]){
			break;
		}
		ans += a[i];
	}
	return ans;
}

int findStartIndexOfSubstring(string s1, string s2) {
	int n = s1.length();
	int m = s2.length();
	if(n < m){
		return -1;
	}
	for(int i=0;i<=n-m;i++){
		int a = 1;
		for(int j=0;j<m;j++){
			if(s1[i+j] != s2[j]){
				a = 0;
				break;
			}
		}
		if(a == 1){
			return i;
		}
	}
	return -1;
}

int minCharactersToBeInserted (string s) {
	string rev = s;
	reverse (rev.begin(), rev.end());
	s += '#';
	s += rev;
	int n = s.size(), lps[n], palindromeLength = 0;
	lps[0] = 0;
	int i = 1;
	while(i < n) {
		if (s[i] == s[palindromeLength]) {
			palindromeLength++;
			lps[i++] = palindromeLength;
		} else {
			if (palindromeLength == 0)
				lps[i++] = 0;
			else
				palindromeLength = lps[palindromeLength - 1];
		}
	}
	int ans = n / 2 - lps[n - 1];
	return ans;
}

string countAndSay(int n) {
	if(n == 1){
		return "1";
	}
	if(n == 2){
		return "11";
	}
	string s = "11";
	int c = 1;
	for(int i=3;i<=n;i++){
		string t = "";
		s += "&";
		for(int j=1;j<s.length();j++){
			if(s[j] != s[j-1]){
				t += to_string(c);
				t += s[j-1];
				c = 1;
			}
			else{
				c++;
			}
		}
		s = t;
	}
	return s;
}

int compareVersion(string version1, string version2) {
   string subVersion1 = "", subVersion2 = "";
   int i = 0, j = 0;
   while (i < version1.size() || j < version2.size()) {
       while (i < version1.size() && version1[i] == '0') {
           i++;
       }
       while (i < version1.size() && version1[i] != '.') {
           subVersion1 += version1[i];
           i++;
       }
       while (j < version2.size() && version2[j] == '0') {
           j++;
       }
       while (j < version2.size() && version2[j] != '.') {
           subVersion2 += version2[j];
           j++;
       }
       if (subVersion1.size() > subVersion2.size()) {
           return 1;
       } else if (subVersion1.size() < subVersion2.size()) {
           return -1;
       }
       for (int k = 0; k < subVersion1.size(); k++) {
           if (subVersion1[k] > subVersion2[k]) {
               return 1;
           } else if (subVersion1[k] < subVersion2[k]) {
               return -1;
           }
       }
       subVersion1 = "";
       subVersion2 = "";
       i++;
       j++;
   }
   return 0;
}

int main(){

}