#include<bits/stdc++.h>
using namespace std;

//-----------------------------11. Cointainer with max water----------------------------------//

int MostWater(int arr[] , int n){
    int i = 0 , j = n-1;
    int ans = 0;
    while (i < j)
    {
        ans = max(ans , (j-i)*min(arr[i] , arr[j]));
        arr[i] > arr[j] ? j-- : i++;
    }
    return ans;
}

//----------------------------12. Integer to Roman Number----------------------------------//

string InttoRoman(int n){
    string s[] = {"M" , "CM" , "D" , "CD" , "C" , "XC" , "L" , "XL" , "X" , "IX" , "V" , "IV" , "I"};
    int val[] = {1000 , 900 , 500 , 400 , 100 , 90 , 50 , 40 , 10 , 9 , 5 , 4 , 1};

    string ans = "";
    for (int i = 0; n != 0; i++)
    {
        while (n > val[i])
        {
            n -= val[i];
            ans += s[i];
        }
    }
    return ans;
}

//---------------------------13. Roman to Integer Number----------------------------------//

int RomantoInt(string s){
    unordered_map<char , int> mp = {{'I' , 1} , {'V' , 5} , {'X' , 10} , {'L' , 50} , {'C' , 100} , {'D' , 500} , {'M' , 1000}};

    int n = s.length();
    int ans = mp[s[n-1]];
    for (int i = n-2; i >= 0; i--)
    {
        if (s[i] < s[i+1])
        {
            ans -= mp[s[i]];
        }
        else
        {
            ans += mp[s[i]];
        }
    }
    return ans;
}

//---------------------------14. Longest Common Prefix----------------------------//

string LongestCommonPrefix(vector<string> v){
    int n = v.size();
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

//---------------------------------15. 3 Sum Problem------------------------------//

vector<vector<int>> ThreeSum_M1(vector<int> v){
    vector<vector<int>> ans;
    int n = v.size();
    for (int i = 0; i < n-2; i++)
    {
        for (int j = 1; j < n-1; j++)
        {
            for (int k = 2; k < n; k++)
            {
                if (v[i]+v[j]+v[k] == 0)
                {
                    ans.push_back({v[i] , v[j] , v[k]});
                }
            }
        }
    }
    return ans;
}

vector<vector<int>> ThreeSum_M2(vector<int> v){
    vector<vector<int>> ans;
    int n = v.size();
    sort(v.begin() , v.end());
    for (int i = 0; i < n-2; i++)
    {
        if (i > 0 && v[i] == v[i-1])
        {
            continue;
        }
        int j = i+1 , k = n-1;
        while (j<k)
        {
            int sum = v[i]+v[j]+v[k];
            if (sum == 0)
            {
                ans.push_back({v[i] , v[j] , v[k]});
                while (j+1 < k && v[j] == v[j+1])
                {
                    j++;
                }
                while (j < k-1 && v[k] == v[k-1])
                {
                    k--;
                }
                j++;
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return ans;
}

//-----------------------------------16. 3Sum Closet---------------------------//

int ThreeSumCloset(vector<int> v , int target){
    int n = v.size();
    sort(v.begin() , v.end());
    int ans = v[0]+v[1]+v[2];
    for (int i = 0; i < n-2; i++)
    {
        int j = i+1 , k = n-1;
        while (j<k)
        {
            int sum = v[i]+v[j]+v[k];
            if (abs(ans-target) >= abs(sum-target))
            {
                ans = sum;
            }
            if (sum == target)
            {
                break;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                j++;
            }
        }
    }
    return ans;
}

//--------------------------------17. Letter Combinations----------------------------//

void helper(string s , int idx , string tmp , vector<string> &ans , vector<string> chrs){
    if (idx == s.length())
    {
        ans.push_back(tmp);
        return;
    }
    int d = s[idx] - '0';
    for(char ch : chrs[d]){
        helper(s , idx+1 , tmp+ch , ans , chrs);
    }
}

vector<string> LetterCombination(string s){
    if (s.length() == 0)
    {
        return {};
    }
    vector<string> ans;
    vector<string> chrs = {"0" , "1" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
    string tmp = "";
    helper(s , 0 , tmp , ans , chrs);
    return ans;
}

//-------------------------------18. 4 sum problem-------------------------------------//

vector<vector<int>> FourSumPr(vector<int> v , int target){
    sort(v.begin() , v.end());
    int n = v.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n-3; i++)
    {
        for (int j = i+1; j < n-2; j++)
        {
            int k = j+1 , l = n-1;
            while (k < l)
            {
                int sum = v[i] + v[j] + v[k] + v[l];
                if (sum == target)
                {
                    ans.push_back({v[i] , v[j] , v[k] , v[l]});
                    while (k+1 < l && v[k] == v[k+1])
                    {
                        k++;
                    }
                    while (k < l-1 && v[l] == v[l-1])
                    {
                        l--;
                    }
                    k++;
                    l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                {
                    l--;
                }
            }
        }
    }
    return ans;
}

//------------------------------19. Remove Nth Node from end------------------------------//

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

node* RemoveNthNodefromend(node* head , int n){
    node* curr = head;
    node* slow = head;
    for (int i = 0; i < n; i++)
    {
        curr = curr->next;
    }
    if (curr == NULL)
    {
        return head->next;
    }
    while (curr->next != NULL)
    {
        slow = slow->next;
        curr = curr->next;
    }
    slow->next = slow->next->next;
    return head;
}

//-------------------------------20. Valid Parenthesis---------------------------//

bool ValidParenthesis(string s){
    stack<char> st;
    int n = s.length();
    for (int i = 0; i < n; i++)
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

//-------------------------------21. Merge 2 sorted List-----------------------//

node* merge2sortedlist(node* h1 , node* h2){
    node* newnode = NULL;
    if (h1 == NULL)
    {
        return h2;
    }
    if (h2 == NULL)
    {
        return h1;
    }
    if (h1->data < h2->data)
    {
        newnode = h1;
        newnode->next = merge2sortedlist(h1->next , h2);
    }
    else
    {
        newnode = h2;
        newnode->next = merge2sortedlist(h1 , h2->next);
    }
    return newnode;
}

//-------------------------------22. Generate Parenthesis--------------------------//

void helper1(vector<string> &ans , string s , int a , int b){
    if (a == 0 && b == 0)
    {
        ans.push_back(s);
        return;
    }
    if (b > 0)
    {
        helper1(ans , s+')' , a , b-1);
    }
    if (a > 0)
    {
        helper1(ans , s+'(' , a-1 , b+1);
    }
}

vector<string> GeneratePaenthesis(int n){
    vector<string> ans;
    string s = "";
    helper1(ans , "" , n , 0);
    return ans;
}

//-------------------------------23. Merge K sorted List---------------------------//

node* mergeksortedlist(vector<node*> v){
    node* ans = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        ans = merge2sortedlist(ans , v[i]);
    }
    return ans;
}

//-----------------------------------24. Swap Pairs----------------------------------//

node* swapPairs(node* head){
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node* tmp = head->next;
    head->next = swapPairs(tmp->next);
    tmp->next = head;

    return tmp;
}

//---------------------------------25. Reverse Nodes in k grp----------------------//

node* reveknodeingrp(node* head , int k){
    if (head == NULL || k == 1)
    {
        return head;
    }
    
    node* curr = head;
    node* tmp = NULL;
    node* prev = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
        count++;
    }
    
    if (tmp != NULL)
    {
        head->next = reveknodeingrp(tmp , k);
    }
    return prev;
}

//------------------------------26. Remove Duplicates in sorted array--------------------//

int RemoveDuplicates_M1(int arr[] , int n){
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    int i = 0;
    for(auto it : s){
        arr[i++] = it;
    }
    return s.size();
}

int RemoveDuplicates_M2(int arr[] , int n){
    int i = 0 , j = 0;
    while (j < n)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
            j++;
        }
        else
        {
            j++;
        }
    }
    return i+1;
}

//-------------------------------27. Remove Elements----------------------------//

int RemoveElements_M1(vector<int> arr , int x){
    int n = arr.size();
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != x)
        {
            a.push_back(arr[i]);
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        arr[i] = a[i];
    }
    return a.size();
}

int RemoveElements_M2(vector<int> arr , int x){
    int i = 0;
    for (int j = 0; j < arr.size(); j++)
    {
        if (arr[j] != x)
        {
            arr[i] = arr[j];
            i++;
        }
    }
    return i;
}

//-----------------------28. Find the first Index of the first occurence-----------------------//

int strstr(string haystack , string needle){
    int n = haystack.length();
    int m = needle.length();

    if (needle == "")
    {
        return 0;
    }
    if (n > m)
    {
        return -1;
    }
    for (int i = 0; i < m-n+1; i++)
    {
        if (haystack.substr(i , i+m) == needle)
        {
            return i;
        }
    }
    return -1;
}

//---------------------------------29. Divide 2 Numbers-------------------------------//

int divide2numbers(int a, int b){
    if (a == INT_MIN && b == -1)
    {
        return INT_MAX;
    }
    if (a == INT_MAX && b == 1)
    {
        return INT_MIN;
    }
    int sign = a < 0 ^ b < 0 ? -1 : 1;

    int n = abs(a) , m = abs(b);
    int res = 0;
    while (m <= n)
    {
        long int divi = m;
        int tmp = 1;
        while (divi <= n-divi)
        {
            divi += divi;
            tmp += tmp;
        }
        res += tmp;
        n -= divi;
    }
    if (sign < 0)
    {
        res *= -1;
    }
    return res >= INT_MAX || res <= INT_MIN ? INT_MAX : res;
}

//----------------------------30. Substring with Concatenation of all words-----------------------//

vector<int> FindStrings(string s , vector<string> v){
    vector<int> ans;
    int n = v.size();
    int m = v[0].length();
    int tot = n*m;
    if (s.length() < tot)
    {
        return {};
    }
    
    for (int i = 0; i < s.length()-tot; i++)
    {
        unordered_map<string , int> mp;
        for (int j = 0; j < v.size(); j++)
        {
            mp[v[j]]++;
        }
        int k = 0;
        for (k = 0; k < n; k++)
        {
            string tmp = s.substr(i+k*m , m);
            if (mp.count(tmp) == 0)
            {
                break;
            }
            else
            {
                if (mp[tmp] != 0)
                {
                    mp[tmp]--;
                }
                else
                {
                    break;
                }
            }
        }
        if (k == n)
        {
            ans.push_back(i);
        }
    }
    return ans;
}

//--------------------------31. NEXT PERMUTATION-------------------------//

void NextPermutation(vector<int> &v){
    int k,l;
    int n = v.size();
    for(k = n-2;k >= 0;k--){
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
        for(l = n-1;l>k;l--){
            if (v[l] > v[k])
            {
                break;
            }
        }
        swap(v[l] , v[k]);
        reverse(v.begin()+k+1 , v.end());
    }
}

//-----------------------------32. Longest Valid Parenthesis---------------------------------//

int LongestValidParenthesis(string s){
    stack<int> st;
    st.push(-1);
    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int a = st.top();
        if (a != -1 && s[i] == ')' && s[a] == '(')
        {
            st.pop();
            ans = max(ans , i-st.top());
        }
        else
        {
            st.push(i);
        }
    }
    return ans;
}

int main(){

}