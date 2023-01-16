#include <bits/stdc++.h>
using namespace std;

//-----------------------------556. Next Greater Element III -------------------------//

string helper(string s)
{
    int k, l;
    int n = s.length();
    for (k = n - 2; k >= 0; k--)
    {
        if (s[k] < s[k + 1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(s.begin(), s.end());
    }
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (s[l] > s[k])
            {
                break;
            }
        }
        swap(s[l], s[k]);
        reverse(s.begin() + k + 1, s.end());
    }
    return s;
}

int nextelement(int n)
{
    string s = to_string(n);
    string str = helper(s);

    long int ans = 0;
    int st = 1;
    for (int i = 0; i < str.length(); i++)
    {
        if (i == 0 && str[i] == '-')
        {
            st = -1;
        }
        else
        {
            ans = ans * 10 + (str[i] - '0');
            if (ans > INT_MAX)
            {
                return -1;
            }
        }
    }
    return ans * st;
}

//------------------------------557. Reverse words in string III ------------------------//

string reversestring(string s)
{
    string ans = "";
    string tmp = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            tmp += s[i];
        }
        else
        {
            reverse(tmp.begin(), tmp.end());
            ans += " ";
            ans += tmp;
            tmp = "";
        }
    }
    if (tmp != "")
    {
        reverse(tmp.begin(), tmp.end());
        ans += " ";
        ans += tmp;
    }
    return ans;
}

//--------------------------------560. Subarray sum equals K -----------------------------//

int Subarrsumk(vector<int> v, int k)
{
    int sum = 0;
    int n = v.size();
    map<int, int> mp;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        if (sum == k)
        {
            count++;
        }
        if (mp.find(sum - k) != mp.end())
        {
            count += mp[sum - k];
        }
        mp[sum]++;
    }
    return count;
}

//---------------------------------561. Array Partition ------------------------------//

int arrayPairSum(vector<int> &nums)
{
    int sum = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i += 2)
    {
        sum += nums[i];
    }
    return sum;
}

//----------------------------563. Binary Tree Tilt ----------------------------//

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

int post(treenode *root, int sum)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftsum = post(root->left, sum);
    int rightsum = post(root->right, sum);
    sum += abs(rightsum - leftsum);
    return leftsum + rightsum + root->data;
}

int Findtilt(treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int sum = 0;
    post(root, sum);
    return sum;
}

//-------------------------------567. Permutation in string ----------------------------//

bool check(vector<int> v1, vector<int> v2)
{
    for (int i = 0; i < 26; i++)
    {
        if (v1[i] != v2[i])
        {
            return false;
        }
    }
    return true;
}

bool checkInclustion(string s1, string s2)
{
    int n1 = s1.length();
    int n2 = s2.length();
    if (n1 > n2)
    {
        return false;
    }
    vector<int> v1(26, 0);
    for (int i = 0; i < n1; i++)
    {
        v1[s1[i] - 'a']++;
    }
    vector<int> v2(26, 0);
    int i = 0, j = 0;
    while (j < n2)
    {
        v2[s2[j] - 'a']++;
        if (j - i + 1 == n1)
        {
            if (check(v1, v2))
            {
                return true;
            }
        }
        if (j - i + 1 < n1)
        {
            j++;
        }
        else
        {
            v2[s2[i] - 'a']--;
            i++;
            j++;
        }
    }
    return false;
}

//---------------------------572. Subtree of another tree ------------------------//

bool checkroot(treenode *root, treenode *subroot)
{
    if (root == NULL && subroot == NULL)
    {
        return true;
    }
    if (root == NULL || subroot == NULL)
    {
        return false;
    }
    if (root->data != subroot->data)
    {
        return false;
    }
    bool leftt = checkroot(root->left, subroot->left);
    bool rightt = checkroot(root->right, subroot->right);

    return leftt && rightt;
}

bool isSubtree(treenode *root, treenode *subroot)
{
    if (root == NULL)
    {
        return false;
    }
    if (checkroot(root, subroot))
    {
        return true;
    }
    return isSubtree(root->left, subroot) || isSubtree(root->right, subroot);
}

//----------------------------581. Shortest Unsorted contigous subarray ----------------------//

int findUnsortedSubarray(vector<int> &nums)
{
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    int n = nums.size(), i = 0, j = n - 1;
    while (i < n && nums[i] == sorted[i])
    {
        i++;
    }
    while (j > i && nums[j] == sorted[j])
    {
        j--;
    }
    return j + 1 - i;
}

//-------------------------------583. delete operation for 2 string  ----------------------//

int minoperation(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (!i || !j)
            {
                dp[i][j] = i + j;
            }
            else
            {
                dp[i][j] = s1[i - 1] == s2[j - 1] ? dp[i - 1][j - 1] : 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

//-----------------------------589 , 590 N-ary tree traversal ---------------DONE --------//

//---------------------------605. Can plase flower ---------------------//

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    flowerbed.insert(flowerbed.begin(), 0);
    flowerbed.push_back(0);
    for (int i = 1; i < flowerbed.size() - 1; ++i)
    {
        if (flowerbed[i - 1] + flowerbed[i] + flowerbed[i + 1] == 0)
        {
            --n;
            ++i;
        }
    }
    return n <= 0;
}

//------------------------606. construct string from bt -------------------------//

string tree2str(treenode *t)
{
    if (t == NULL)
        return "";
    string s = to_string(t->data);
    if (t->left)
        s += '(' + tree2str(t->left) + ')';
    else if (t->right)
        s += "()";
    if (t->right)
        s += '(' + tree2str(t->right) + ')';
    return s;
}

//----------------------------617. Merge 2 Binary Tree -----------------------//

treenode *merge2bt(treenode *h1, treenode *h2)
{
    if (h1 && h2)
    {
        treenode *root = new treenode(h1->data + h2->data);
        root->left = merge2bt(h1->left, h2->left);
        root->right = merge2bt(h1->right, h2->right);
        return root;
    }
    else
    {
        return h1 ? h1 : h2;
    }
}

//---------------------------621. Task Scheduler -------------------------------//

int leastInterval(vector<char> &tasks, int n)
{
    unordered_map<char, int> mp;
    int count = 0;
    for (int i = 0; i < tasks.size(); i++)
    {
        mp[tasks[i]]++;
        count = max(count, mp[tasks[i]]);
    }
    int ans = (count - 1) * (n + 1);
    for (auto it : mp)
    {
        if (it.second == count)
        {
            ans++;
        }
    }
    return max(ans, (int)tasks.size());
}

//-------------------------------623. Add one row to tree ------------------------------//

treenode *addOneRow(treenode *root, int val, int d)
{
    if (d == 0 || d == 1)
    {
        treenode *newroot = new treenode(val);
        (d ? newroot->left : newroot->right) = root;
        return newroot;
    }
    if (root && d >= 2)
    {
        root->left = addOneRow(root->left, val, d > 2 ? d - 1 : 1);
        root->right = addOneRow(root->right, val, d > 2 ? d - 1 : 0);
    }
    return root;
}

//------------------------

int main()
{
}