#include <bits/stdc++.h>
using namespace std;

//----------------------------------402. Remove K digits -------------------------------//

string RemoveKdigits(string num, int k)
{
    string ans = "";
    for (auto it : num)
    {
        while (ans.size() && ans.back() > it && k)
        {
            ans.pop_back();
            k--;
        }
        if (ans.size() || it != '0')
        {
            ans.push_back(it);
        }
    }
    while (ans.size() && k--)
    {
        ans.pop_back();
    }
    return ans == "" ? "0" : ans;
}

//----------------------------------403. Frog Jump ----------------------------------//

bool canCross(vector<int> &stones)
{
    int n = stones.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(n + 1, false));
    dp[0][1] = true;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int d = stones[i] - stones[j];
            if (d > 0 && d < n && dp[j][d])
            {
                if (i == n - 1)
                {
                    return true;
                }
                dp[i][d] = true;
                if (d + 1 < n)
                {
                    dp[i][d + 1] = true;
                }
                if (d - 1 < n)
                {
                    dp[i][d - 1] = true;
                }
            }
        }
    }
    return false;
}

//---------------------------------404. Sum Leaf -----------------------------------//

class treenode
{
public:
    int data;
    treenode *left;
    treenode *right;
    treenode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~treenode()
    {
        delete left;
        delete right;
    }
};

void helper(treenode *root, int &sum)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left && root->left == NULL && root->right == NULL)
    {
        sum += root->left->data;
        helper(root->right, sum);
    }
    else
    {
        helper(root->left, sum);
        helper(root->right, sum);
    }
}

int sumleaf(treenode *root)
{
    int sum = 0;
    helper(root, sum);
    return sum;
}

//----------------------------405. Convert a number to hexadecimal  ---------------------------//

string tohex(int num)
{
    unsigned int n = num;
    string str = "";
    string chrarr = "0123456789abcdef";
    do
    {
        str += chrarr[n % 16];
        n /= 16;
    } while (n);
    reverse(str.begin(), str.end());
    return str;
}

//-----------------------------406. Queue Reconstruction ---------------------------//

bool static cmp(vector<int> &p1, vector<int> &p2)
{
    if (p1[0] != p2[0])
    {
        return p1[0] > p2[0];
    }
    return p1[1] < p2[1];
}
vector<vector<int>> reconstructQueue(vector<vector<int>> &people)
{
    sort(people.begin(), people.end(), cmp);
    vector<vector<int>> res;
    for (int i = 0; i < people.size(); i++)
    {
        res.insert(res.begin() + people[i][1], people[i]);
    }
    return res;
}

//-----------------------------409. Longest Palindrome ------------------------------//

int longestPalindrome(string s)
{
    int arr[128] = {};
    for (auto it : s)
    {
        arr[it]++;
    }
    int odd = 0;
    for (auto it : arr)
    {
        odd += it & 1;
    }
    return s.size() - odd + (odd > 0);
}

//-----------------------------410. Split array largest sum --------------------------//

int splitarrsum(vector<int> nums, int m)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    int l = *max_element(nums.begin(), nums.end());
    int r = sum;
    int ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        int tmp = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (tmp + nums[i] <= mid)
            {
                tmp += nums[i];
            }
            else
            {
                count++;
                tmp = nums[i];
            }
        }
        count++;
        if (count <= m)
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

//-----------------------------------412. FIZZ BUZZ ------------------------------------//

vector<string> fizzBuzz(int n)
{
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        if ((i + 1) % 15 == 0)
        {
            v.push_back("FizzBuzz");
        }
        else if ((i + 1) % 3 == 0)
        {
            v.push_back("Fizz");
        }
        else if ((i + 1) % 5 == 0)
        {
            v.push_back("Buzz");
        }
        else
        {
            v.push_back(to_string(i + 1));
        }
    }
    return v;
}

//-----------------------------------413. Arthematic Slices -------------------------------//

int noofarthematicslices(vector<int> nums)
{
    int n = nums.size();
    if (n < 3)
    {
        return 0;
    }
    vector<int> dp(n, 0);
    if (nums[2] - nums[1] == nums[1] - nums[0])
    {
        dp[2] = 1;
    }
    int ans = dp[2];
    for (int i = 3; i < n; i++)
    {
        if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
        {
            dp[i] = dp[i - 1] + 1;
        }
        ans += dp[i];
    }
    return ans;
}

//-----------------------------------414. Third maximum number ------------------------//

int thirdMax(vector<int> &nums)
{

    long one = LONG_MIN, two = LONG_MIN, three = LONG_MIN;
    for (int num : nums)
    {
        if (num == one || num == two || num == three)
            continue;

        if (num > one)
        {
            three = two;
            two = one;
            one = num;
        }
        else if (num > two)
        {
            three = two;
            two = num;
        }
        else if (num > three)
        {
            three = num;
        }
    }
    return three == LONG_MIN ? one : three;
}

//------------------------------------415. add strings------------------------------//

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
    // reverse(res.begin() , res.end());
    return res;
}

//---------------------------------416. Partition Equal Subsetsum problem ---------------------------//

bool subsetsum(int arr[] , int n , int sum){
    bool dp[n+1][sum+1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }
    for (int i = 0; i <= sum; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (arr[i-1] <= j)
            {
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][sum];
}

bool canpartition(int arr[] , int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum % 2 != 0)
    {
        return false;
    }
    return subsetsum(arr , n , sum/2);
}

//--------------------------------------------------------------------------------------

int main()
{
}