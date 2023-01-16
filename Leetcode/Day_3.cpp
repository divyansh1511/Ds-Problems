#include<bits/stdc++.h>
using namespace std;

//---------------------------------33. Search in rotated sorted array---------------------------//

int SearchinRotatedarr(int arr[] , int n , int key){
    int i = 0 , j = n-1;
    while (i <= j)
    {
        int mid = (i+j)/2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[i] <= arr[mid])
        {
            if (key >= arr[i] && key <= arr[mid])
            {
                j = mid-1;
            }
            else
            {
                i = mid+1;
            }
        }
        else
        {
            if (key >= arr[mid] && key <= arr[j])
            {
                i = mid+1;
            }
            else
            {
                j = mid-1;
            }
        }
    }
    return -1;
}

//------------------------------34. Find First and Last Index--------------------------------//

int Firstindex(vector<int> v , int key){
    int i = 0 , j = v.size()-1;
    int ans = -1;
    while (i <= j)
    {
        int mid = (i+j)/2;
        if (v[mid] == key)
        {
            ans = mid;
            j = mid-1;
        }
        else if (v[mid] < key)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
    }
    return ans;
}

int lastindex(vector<int> v , int key){
    int i = 0 , j = v.size()-1;
    int ans = -1;
    while (i <= j)
    {
        int mid = (i+j)/2;
        if (v[mid] == key)
        {
            ans = mid;
            i = mid+1;
        }
        else if (v[mid] < key)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
    }
    return ans;
}

vector<int> FirstAndLastIndex(vector<int> v , int key){
    int a = Firstindex(v , key);
    if (a == -1)
    {
        return {-1 , -1};
    }
    int b = lastindex(v , key);
    return {a,b};
}

//-------------------------------35. Search Inserting Elements----------------------------//

int Searchinsertingelement(vector<int> v , int key){
    int lo = 0 , hi = v.size()-1;

    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if (v[mid] < key)
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
    return lo;
}

//------------------------------36. Valid Sudoku---------------------------------//

bool ValidSudoku(vector<vector<char>> &board){
    int count1[9][9] = {0};
    int count2[9][9] = {0};
    int count3[9][9] = {0};
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] != '0'){
                int num = board[i][j] - '0' - 1;
                int k = (i/3) * 3 + j/3;
                if (count1[i][num] || count2[j][num] || count3[k][num])
                {
                    return false;
                }
                count1[i][num] = count2[j][num] = count3[k][num] = 1;
            }
        }
    }
    return true;
}

//-----------------------------37. Solve Sudoku----------------------------------//

bool issafe(vector<vector<char>> &board , int i , int j , char c){
    int row = i - i%3 , col = j - j%3;
    
    for (int x = 0; x < 9; x++)
    {
        if (board[i][x] == c)
        {
            return false;
        }
    }
    
    for (int x = 0; x < 9; x++)
    {
        if (board[x][j] == c)
        {
            return false;
        }
    }
    
    for (int x = 0; x < 3; x++)
    {
        for (int y = 0; y < 3; y++)
        {
            if (board[row + x][col + y] == c)
            {
                return false;
            }
        }
    }
    return true;
}

bool solve(vector<vector<char>> &board , int i , int j){
    if (i == 9)
    {
        return true;
    }
    if (j == 9)
    {
        return solve(board , i+1 , 0);
    }
    if (board[i][j] != '.')
    {
        return solve(board , i , j+1);
    }
    for(char c = '1';c<='9';c++){
        if (issafe(board , i , j , c))
        {
            board[i][j] = c;
            if (solve(board , i , j+1))
            {
                return true;
            }
            board[i][j] = '.';
        }
    }
    return false;
}

void SolveSudoku(vector<vector<char>> &board){
    solve(board , 0 , 0);
}

//--------------------------------38. Count and Say------------------------------------//

string CountandSay(int n){
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
        string tmp = "";
        s += "&";
        int c = 1;
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

//----------------------------------39. Combination Sum------------------------------//

void helper(vector<int> v , int idx , int target , vector<int> tmp , vector<vector<int>> &ans){
    if (idx == v.size())
    {
        if (target == 0)
        {
            ans.push_back(tmp);
        }
        return;
    }
    if (v[idx] <= target)
    {
        tmp.push_back(v[idx]);
        helper(v , idx , target-v[idx] , tmp , ans);
        tmp.pop_back();
    }
    helper(v , idx+1 , target , tmp , ans);
}

vector<vector<int>> CombinationSum(vector<int> v , int target){
    vector<vector<int>> ans;
    vector<int> tmp;
    helper(v , 0 , target , tmp , ans);
    return ans;
}

//--------------------------------40. Combination Sum II -------------------------------//

void helper2(vector<int> v , int idx , int target , vector<int> tmp , vector<vector<int>> &ans){
    if (target == 0)
    {
        ans.push_back(tmp);
        return;
    }
    for (int i = idx; i < v.size(); i++)
    {
        if (i > idx && v[i] == v[i-1])
        {
            continue;
        }
        if (v[i] > target)
        {
            break;
        }
        tmp.push_back(v[idx]);
        helper2(v , idx+1 , target-v[idx] , tmp , ans);
        tmp.pop_back();
    }
}

vector<vector<int>> CombinationSumII(vector<int> v , int target){
    sort(v.begin() , v.end());
    vector<vector<int>> ans;
    vector<int> tmp;
    helper2(v , 0 , target , tmp , ans);
    return ans;
}

//-----------------------------41. First Missing Possitive Number---------------------------//

int FirstMissingNumber(vector<int> v){
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            v[i] = n+1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (abs(v[i]) <= n && v[abs(v[i]) - 1] > 0)
        {
            v[abs(v[i]) - 1] *= -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0)
        {
            return i+1;
        }
    }
    return n+1;
}

//--------------------------42. Trapping Rain water pr--------------------------------//

int TrappingRainWater_M1(int arr[] , int n){
    int left[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1] , arr[i]);
    }
    int right[n];
    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        right[i] = max(right[i+1] , arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (min(left[i] , right[i]) - arr[i]);
    }
    return ans;
}

int TrappingRainWater_M2(int arr[] , int n){
    int lo = 0 , hi = n-1;
    int ml = 0 , mr = 0;
    int ans = 0;
    while (lo <= hi)
    {
        if (arr[lo] <= arr[hi])
        {
            if (arr[lo] > ml)
            {
                ml = arr[lo];
            }
            else
            {
                ans += (ml - arr[lo]);
            }
            lo++;
        }
        else
        {
            if (arr[hi] > mr)
            {
                mr = arr[hi];
            }
            else
            {
                ans += (mr - arr[hi]);
            }
            hi--;
        }
    }
    return ans;
}

//--------------------------------43. Multiply Strings-----------------------------------//

string MultiplyString(string a , string b){
    int n = a.length() , m = b.length();
    string ans(n+m , '0');

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = m-1; j >= 0; j--)
        {
            int sum = (a[i]-'0') * (b[j]-'0') + ans[i+j+1]-'0';
            ans[i+j+1] = sum%10;
            ans[i+j] += sum/10;
        }
    }
    for (int i = 0; i < ans.length(); i++)
    {
        if (ans[i] != '0')
        {
            return ans.substr(i);
        }
    }
    return "0";
}

//--------------------------------44. Wildcard Matching-----------------------------------//

bool isMatch(string str , string pattern){
    int n = str.length();
    int m = pattern.length();

    vector<vector<bool>> dp(n+1 , vector<bool>(m+1 , false));
    
    dp[0][0] = true;
    for (int j = 1; j <= m; j++)
    {
        bool flag = true;
        for (int k = 1; k <= j; k++)
        {
            if (pattern[k-1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str[i-1] == pattern[j-1] || pattern[j-1] == '?')
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else if (pattern[j-1] == '*')
            {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }
    return dp[n][m];
}

//-----------------------------45. Jump Games -------------------------------//

int Jumps(vector<int> &v){
    int n = v.size();
    if (n <= 1)
    {
        return 0;
    }
    if (v[0] == 0)
    {
        return -1;
    }
    int maxreach = v[0];
    int steps = v[0];
    int jumps = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == n-1)
        {
            return jumps;
        }
        maxreach = max(maxreach , i+v[i]);
        steps--;
        if (steps == 0)
        {
            jumps++;
            if (i >= maxreach)
            {
                return -1;
            }
            steps = maxreach-i;
        }
    }
    return -1;
}

//------------------------------46. Permutations------------------------------//

void helper3(vector<int> v , int idx , vector<vector<int>> &ans){
    if (idx == v.size())
    {
        ans.push_back(v);
        return;
    }
    for (int i = idx; i < v.size(); i++)
    {
        swap(v[idx] , v[i]);
        helper3(v , idx+1 , ans);
        swap(v[idx] , v[i]);
    }
}

vector<vector<int>> Permutations(vector<int> v){
    vector<vector<int>> ans;
    helper3(v , 0 , ans);
    return ans;
}

//---------------------------47. Permutations II -----------------------------------//

void helper4(vector<int> v , int idx , vector<vector<int>> &ans){
    if (idx == v.size()-1)
    {
        ans.push_back(v);
        return;
    }
    for (int i = idx; i < v.size(); i++)
    {
        if (i > idx && v[i] == v[i-1])
        {
            continue;
        }
        swap(v[idx] , v[i]);
        helper4(v , idx+1 , ans);
    }
}

vector<vector<int>> PermutationsII(vector<int> v){
    vector<vector<int>> ans;
    helper4(v , 0 , ans);
    return ans;
}

//--------------------------------48. Rotate Image----------------------------//

void RotateImage(vector<vector<int>> &v){
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(v[i][j] , v[j][i]);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        reverse(v[i].begin() , v[i].end());
    }
}

//------------------------------49. Group Anagrams-----------------------------//

vector<vector<string>> GroupAnagrams(vector<string> &v){
    unordered_map<string , vector<string>> mp;
    for (int i = 0; i < v.size(); i++)
    {
        string s = v[i];
        sort(s.begin() , s.end());
        mp[s].push_back(v[i]);
    }
    vector<vector<string>> ans;
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

//-------------------------------50. Power of X and N--------------------------//

double MyPower(double x , int n){
    double res = 1;
    while (n)
    {
        if (n%2)
        {
            res = n>0 ? res*x : res/x;
        }
        x = x*x;
        n /= 2;
    }
    return res;
}

int main(){

}