#include <bits/stdc++.h>
using namespace std;

//------------------------------51. N queen Problem ------------------------------------//

bool is_safe(vector<string> board, int row, int col)
{
    for (int i = row; i >= 0; i--)
    {
        if (board[i][col] == 'Q')
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++)
    {
        if (board[i][j] == 'Q')
        {
            return false;
        }
    }
    return true;
}

void dfs(vector<string> board, int row, vector<vector<string>> &ans)
{
    if (row == board.size())
    {
        ans.push_back(board);
        return;
    }
    for (int i = 0; i < board.size(); i++)
    {
        if (is_safe(board, row, i))
        {
            board[row][i] = 'Q';
            dfs(board, row + 1, ans);
            board[row][i] = '.';
        }
    }
}

vector<vector<string>> Nqueens(int n)
{
    if (n <= 0)
    {
        return {{}};
    }
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    dfs(board, 0, ans);
    return ans;
}

//--------------------------------52. N queens II-------------------------------//

int NqueensII(int n)
{
    if (n <= 0)
    {
        return 0;
    }
    vector<string> board(n, string(n, '.'));
    vector<vector<string>> ans;
    dfs(board, 0, ans);
    return ans.size();
}

//--------------------------------53. Maximum Subarray----------------------------//

int Maxsubarrsum(int arr[], int n)
{
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < arr[i])
        {
            sum = arr[i];
        }
        maxi = max(sum, maxi);
    }
    return maxi;
}

//-------------------------------54. Spiral Matrix------------------------------//

vector<int> SpiralMatrix(vector<vector<int>> &matrix)
{
    vector<int> v;
    int n = matrix.size(), m = matrix[0].size();
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = m - 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            v.push_back(matrix[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            v.push_back(matrix[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                v.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                v.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return v;
}

//----------------------------------55. Jump Game --------------------------------//

bool canJump(vector<int> &nums)
{
    int dis = 0;
    for (int i = 0; i <= dis; i++)
    {
        dis = max(dis, i + nums[i]);
        if (dis >= nums.size() - 1)
        {
            return true;
        }
    }
    return false;
}

//-----------------------------------56. Merge Intervalse -----------------------//

vector<vector<int>> MergeIntervals(vector<vector<int>> Intervals)
{
    vector<vector<int>> ans;
    if (Intervals.size() == 0)
    {
        return {{}};
    }
    sort(Intervals.begin(), Intervals.end());
    ans.push_back(Intervals[0]);
    int j = 0;
    for (int i = 1; i < Intervals.size(); i++)
    {
        if (ans[j][1] > Intervals[i][0])
        {
            ans[j][1] = max(ans[j][1], Intervals[i][1]);
        }
        else
        {
            ans.push_back(Intervals[i]);
        }
    }
    return ans;
}

//-------------------------------------57. Insert Intervals ---------------------------//

vector<vector<int>> InsertIntervals(vector<vector<int>> Intervals, vector<int> v)
{
    Intervals.push_back(v);
    return MergeIntervals(Intervals);
}

//-------------------------------------58. Length of Last Word ------------------------//

int lengthOfLastWord(string s)
{
    int len = 0, tail = s.length() - 1;
    while (tail >= 0 && s[tail] == ' ')
        tail--;
    while (tail >= 0 && s[tail] != ' ')
    {
        len++;
        tail--;
    }
    return len;
}

//-------------------------------------59. Spiral Matrix II---------------------------//

vector<vector<int>> SpiralMatrixII(int n)
{
    vector<vector<int>> v(n, vector<int>(n));
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    int c = 1;
    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            v[top][i] = c;
            c++;
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            v[i][right] = c;
            c++;
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                v[bottom][i] = c;
                c++;
            }
            bottom--;
        }
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                v[i][left] = c;
            }
            left++;
        }
    }
    return v;
}

//--------------------------------------60. Permutation Sequence -----------------------------//

void NextPermutation(string &v)
{
    int k, l;
    int n = v.size();
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
        swap(v[l], v[k]);
        reverse(v.begin() + k + 1, v.end());
    }
}
string getPermutation_M1(int n, int k)
{
    string v = "";
    for (int i = 1; i <= n; i++)
    {
        v += to_string(i);
    }
    for (int i = 0; i < k - 1; i++)
    {
        NextPermutation(v);
    }
    return v;
}

string getPermutation_M2(int n , int k){
    vector<int> v;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        fact *= i;
        v.push_back(i);
    }
    v.push_back(n);
    string ans = "";
    k = k-1;
    while (true)
    {
        ans += to_string(v[k/fact]);
        v.erase(v.begin()+k/fact);
        if (v.size() == 0)
        {
            break;
        }
        k = k%fact;
        fact = fact/v.size();
    }
    return ans;
}

//------------------------------------------61. Rotate List --------------------------------//

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

node* RotateList(node* head , int k){
    if (head == NULL || k == 0)
    {
        return head;
    }
    int c = 0;
    node* tmp = head;
    while (tmp != NULL)
    {
        c++;
        tmp = tmp->next;
    }
    k = k%c;
    if (k == 0)
    {
        return head;
    }
    node* fast = head;
    for (int i = 0; i < k; i++)
    {
        fast = fast->next;
    }
    node* slow = head;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    node* tmp1 = slow->next;
    slow->next = NULL;
    fast->next = head;
    return tmp1;
}

//--------------------------------------62. Unique Paths---------------------------------//

int UniquePaths(int n , int m){
    vector<vector<int>> v(n , vector<int>(m , 1));
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            v[i][j] = v[i-1][j] + v[i][j-1];
        }
    }
    return v[n-1][m-1];
}

//-----------------------------------63. Unique Paths II --------------------------------//

int UniquePathwithobstacles(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n , vector<int>(m , 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 || (i == 0 && j == 0))
            {
                continue;
            }
            else
            {
                dp[i][j] = (i > 0 ? dp[i-1][j] : 0) + (j > 0 ? dp[i][j-1] : 0);
            }
        }
    }
    return dp[n-1][m-1];
}

//---------------------------------64. Minimum Path Sum-------------------------------//

int MinimumPathSum(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int dp[n][m];
    dp[0][0] = grid[0][0];
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = min(dp[i-1][j] , dp[i][j-1]) + grid[i][j];
        }
    }
    return dp[n-1][m-1];
}

//--------------------------------65. Valid Number ------------------------------//

bool isValidNumber(string s){
    bool expression = false;
    bool sign = false;
    bool number = false;
    bool decimal = false;

    for(char c : s){
        if (c >= '0' && c <= '9')
        {
            number = true;
        }
        else if (c == 'e' || c == 'E')
        {
            if (expression || !number)
            {
                return false;
            }
            else
            {
                expression = true;
                number = false;
                sign = false;
                decimal = false;
            }
        }
        else if (c == '+' || c == '-')
        {
            if (sign || number || decimal)
            {
                return false;
            }
            else
            {
                sign = true;
            }
        }
        else if (c == '.')
        {
            if (decimal || expression)
            {
                return false;
            }
            else
            {
                decimal = true;
            }
        }
        else
        {
            return false;
        }
    }
    return number;
}

//------------------------------------66. Plus One-------------------------------//

void helper(vector<int> &v){
    int n = v.size();
    for (int i = n-1; i >= 0; i--)
    {
        if (v[i] == 9)
        {
            v[i] = 0;
        }
        else
        {
            v[i]++;
            return;
        }
    }
    v[0] = 1;
    v.push_back(0);
}

vector<int> PlusOne(vector<int> v){
    helper(v);
    return v;
}

//-----------------------------------67. Add Binary----------------------------//

string AddBinary(string a , string b){
    string ans = "";
    int i = a.length()-1 , j = b.length()-1;
    int carry = 0;
    while (i >= 0 || j >= 0)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += a[i--] - '0';
        }
        if (j >= 0)
        {
            sum += a[j--] - '0';
        }
        carry = sum > 1 ? 1 : 0;
        ans += to_string(sum%2);
    }
    if (carry)
    {
        ans += to_string(carry);
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

//--------------------------------68. TEXT JUSTIFICATION ---------------------//
///----------------------NOT DONE YET--------------------///
//------------------------------------------------------------------------------


//--------------------------------69. Square Root of x--------------------------//

int Sqrt(int x){
    if (x <= 1)
    {
        return x;
    }
    int lo = 0 , hi = x/2;
    int ans = -1;
    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if (mid*mid == x)
        {
            return mid;
        }
        else if (mid*mid < x)
        {
            ans = mid;
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
    return ans;
}

//------------------------------------70. Climbing Stairs ----------------------------------//

int climbStairs_m1(int n){
    if (n <= 2)
    {
        return n;
    }
    return climbStairs_m1(n-1) + climbStairs_m1(n-2);
}

int climbstairs_m2(int n){
    if (n <= 2)
    {
        return n;
    }
    int dp[n];
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n-1];
}

//------------------------------------71. Simplify String ---------------------------------//

string simplifyPath(string s){
    stack<string> st;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '/')
        {
            continue;
        }
        string tmp = "";
        while (i < s.length() && s[i] != '/')
        {
            tmp += s[i];
            i++;
        }
        if (tmp == ".")
        {
            continue;
        }
        else if (tmp == "..")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            st.push(tmp);
        }
    }
    
    string ans = "";
    while (!st.empty())
    {
        ans = "/" + st.top() + ans;
        st.pop();
    }
    if (ans.length() == 0)
    {
        return "/";
    }
    return ans;
}

//---------------------------------72. Edit Distance--------------------------------//

int MinDistance(string word1 , string word2){
    int n = word1.length();
    int m = word2.length();
    int dp[n+1][m+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i-1] == word2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1+min({dp[i-1][j] , dp[i-1][j-1] , dp[i][j-1]});
            }
        }
    }
    return dp[n][m];
}

//---------------------------------73. Set Matrix Zero---------------------------------//

void SetZero(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    bool firstrow = false;
    bool firstcol = false;
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 0)
        {
            firstcol = true;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (grid[0][i] == 0)
        {
            firstrow = true;
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                grid[i][0] = 0;
                grid[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (grid[i][0] == 0 || grid[0][j] == 0)
            {
                grid[i][j] = 0;
            }
        }
    }
    if (firstrow)
    {
        for (int i = 0; i < m; i++)
        {
            grid[0][i] = 0;
        }
    }
    if (firstcol)
    {
        for (int i = 0; i < n; i++)
        {
            grid[i][0] = 0;
        }
    }
}

//-----------------------------------74. Search in a 2d matrix----------------------------//

bool searchMatrix(vector<vector<int>> v , int key){
    int n = v.size();
    int m = v[0].size();
    int lo = 0 , hi = (n*m)-1;

    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if (v[mid/m][mid%m] == key)
        {
            return true;
        }
        if (v[mid/m][mid%m] < key)
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
    return false;
}

//------------------------------------75. Sort Colors -----------------------------//

void SortColors(vector<int> &v){
    int zero = 0 , one = 0 , two = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            zero++;
        }
        else if (v[i] == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }
    int i = 0;
    for (i = 0; i < zero; i++)
    {
        v[i] = 0;
    }
    for (i ; i < (zero+one); i++)
    {
        v[i] = 1;
    }
    for (i; i < v.size(); i++)
    {
        v[i] = 2;
    }
}

int main()
{
}