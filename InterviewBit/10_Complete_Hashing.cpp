#include<bits/stdc++.h>
using namespace std;

int colorfulNumber(int n){
    vector<int> arr;
    unordered_set<int> st;
    while (n)
    {
        arr.push_back(n%10);
        n = n/10;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (st.find(arr[i]) != st.end())
        {
            return 0;
        }
        st.insert(arr[i]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        int mul = arr[i];
        for (int j = i+1; j < arr.size(); j++)
        {
            mul *= arr[j];
            if (st.find(mul) != st.end())
            {
                return 0;
            }
            st.insert(mul);
        }
    }
    return 1;
}

vector<int> LargestSubarrwithZeroSum(vector<int> v){
    unordered_map<int,int> mp;
    int sum = 0;
    int mxlen = 0;
    int l_i = -1 , r_i = -1;

    for (int i = 0; i < v.size(); i++)
    {
        if (mp.find(v[i]) != mp.end())
        {
            if (mxlen < i-mp[sum])
            {
                mxlen = i - mp[sum];
                l_i = mp[sum];
                r_i = i;
            }
        }
        else
        {
            mp[sum] = i;
        }
    }
    vector<int> ans;
    for (int i = l_i; i < r_i; i++)
    {
        ans.push_back(v[i]);
    }
    return ans;
}

int LongestSubarrLength(vector<int> &v){
    map<int,int> mp;
    int sum = 0;
    int ans = INT_MIN;
    mp[0] = -1;
    for (int i = 0; i < v.size(); i++)
    {
        sum += (v[i] == 0) ? -1 : 1;
        if (mp.find(sum) != mp.end())
        {
            mp[sum] = i;
        }
        if (mp.find(sum-1) != mp.end())
        {
            ans = max(ans , i - mp[sum-1]);
        }
    }
    return ans;
}

int FirstRepeatingElement(int arr[] , int n){
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp[arr[i]] > 1)
        {
            return arr[i];
        }
    }
    return -1;
}

vector<int> TwoSum(vector<int> nums , int target){
    map<int,int> mp;
    vector<int> v;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp.find(target-nums[i]) != mp.end())
        {
            v.push_back(mp[target-nums[i]]);
            v.push_back(i+1);
            return v;
        }
        if (mp.find(nums[i]) != mp.end())
        {
            mp[nums[i]] = i+1;
        }
    }
    return v;
}

vector<vector<int>> fourSum(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    unordered_map<int, set<pair<int, int>>> hash;
    set<vector<int>> ans;
    int n = num.size();
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            int a = num[i] + num[j];
            if (hash.count(target - a)) {
                for (auto &p: hash[target - a]) {
                    vector<int> b = {p.first, p.second, num[i], num[j]};
                    ans.insert(b);
                }
            }
        }
        for (int j = 0; j < i; j ++) {
            int a = num[j], b = num[i];
            hash[a + b].insert(make_pair(a, b));
        }
    }
    return vector<vector<int>>(ans.begin(), ans.end());
}

int isValidSudoku(const vector<string> &A) {
    int user1[9][9] = {0} , user2[9][9] = {0} , user3[9][9] = {0};
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[i].length();j++){
            if(A[i][j] != '.'){
                int num = A[i][j] - '0' - 1 , k = i/3 * 3 + j/3;
                if(user1[num][i] || user2[num][j] || user3[num][k]){
                    return false;
                }
                user1[num][i] = user2[num][j] = user3[num][k] = 1;
            }
        }
    }
    return true;
}

int PairWithGivenXOR(vector<int> v , int b){
    unordered_set<int> st;
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (st.find(b^v[i]) != st.end())
        {
            ans++;
        }
        st.insert(v[i]);
    }
    return ans;
}

vector<vector<int> > Anagrams(const vector<string> &A) {
    unordered_map<string , vector<int>> mp;
    for(int i=0;i<A.size();i++){
        string t = A[i];
        sort(t.begin() , t.end());
        mp[t].push_back(i+1);
    }
    vector<vector<int>> v;
    for(auto it : mp){
        v.push_back(it.second);
    }
    return v;
}

bool checkPalindrome(string s){
    unordered_map<char , int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    int count = 0;
    for(auto it : mp){
        if (it.second % 2 != 0)
        {
            count++;
        }
    }
    if (count > 1)
    {
        return 0;
    }
    return 1;
}

int MaxPoints(vector<int> v1 , vector<int> v2){
    int n = v1.size();
    if (n == 0)
    {
        return 0;
    }
    map<double , int> mp;
    int maxpoints = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                continue;
            }
            double slope;
            if (v1[i] == v1[j])
            {
                slope = 1e9;
            }
            else
            {
                slope = (1.0 * (v2[j] - v2[i]) / 1.0 * (v1[j] - v1[i]));
            }
            mp[slope]++;
            maxpoints = max(maxpoints , mp[slope]);
        }
        mp.clear();
    }
    return maxpoints+1;
}

int SubarrWithGivenXOR(vector<int> v , int k){
    int ans = 0 , xorr = 0;
    unordered_map<int,int> mp;
    for (int i = 0; i < v.size(); i++)
    {
        xorr ^= v[i];
        int tmp = xorr ^ k;
        ans += mp[tmp];
        if (xorr == k)
        {
            ans++;
        }
        mp[xorr]++;
    }
    return ans;
}

vector<int> TwoToThree(vector<int> A ,  vector<int> B , vector<int> C){
    map<int , set<int>> mp;
    for(int i=0;i<A.size();i++){
        mp[A[i]].insert(0);
    }
    for(int i=0;i<B.size();i++){
        mp[B[i]].insert(1);
    }
    for(int i=0;i<C.size();i++){
        mp[C[i]].insert(2);
    }
    vector<int> ans;
    for(auto it = mp.begin();it != mp.end();it++){
        if(it->second.size() >= 2){
            ans.push_back(it->first);
        }
    }
    return ans;
}

int lengthOfLongestSubstring(string s) {
    vector<int> v(256 , -1);
    int len = 0;
    int left = 0 , right = 0;
    int n = s.length();
    while(right < n){
        if(v[s[right]] != -1){
            left = max(v[s[right]]+1 , left);
        }
        v[s[right]] = right;
        len = max(len , right-left+1);
        right++;
    }
    return len;
}

string minWindow(string s, string t) {
    unordered_map<char , int> mp;
    for(int i=0;i<t.length();i++){
        mp[t[i]]++;
    }
        
    int i = 0 , j = 0;
    int count = mp.size();
    string ans = "" , res = "";
    bool flag = true;
        
    while(j<s.length()){
        if(mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if(mp[s[j]] == 0){
                count--;
            }
        }
        ans += s[j];
        if(count == 0){
            if(flag == true){
                res = ans;
                flag = false;
            }
            if(res.length() > ans.length() && flag == false){
                res = ans;
            }
            while(count == 0){
                if(res.length() > ans.length() && flag == false){
                    res = ans;
                }
                ans = ans.substr(1);
                if(mp.find(s[i]) != mp.end()){
                    mp[s[i]]++;
                    if(mp[s[i]] == 1){
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

int main(){

}