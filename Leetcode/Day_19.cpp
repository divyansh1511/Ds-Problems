#include <bits/stdc++.h>
using namespace std;

//------------------------------------701. Insert in BST --------------------------------//

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

treenode *InsertinBST(treenode *root, int k)
{
    if (root == NULL)
    {
        root = new treenode(k);
        return root;
    }
    treenode *tmp = new treenode(k);
    if (root->data > k)
    {
        root->left = InsertinBST(root->left, k);
    }
    if (root->data <= k)
    {
        root->right = InsertinBST(root->right, k);
    }
    return root;
}

//-------------------------------703. Kth largest element --------------------------------//

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    KthLargest(int k, vector<int> nums)
    {
        size = k;
        for (int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            if (pq.size() > k)
                pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > size)
            pq.pop();
        return pq.top();
    }
};

//--------------------------------704. Binary Search ---------------------------------//

int search(vector<int> &nums, int target)
{
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[mid] == target)
        {
            return mid;
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

//----------------------------------705. Design Hashset -------------------------------//

class MyHashSet
{
public:
    set<int> s;
    MyHashSet()
    {
    }

    void add(int key)
    {
        s.insert(key);
    }

    void remove(int key)
    {
        set<int>::iterator it = s.find(key);
        if (it != s.end())
        {
            s.erase(it);
        }
    }

    bool contains(int key)
    {
        set<int>::iterator it = s.find(key);
        if (it != s.end())
        {
            return true;
        }
        return false;
    }
};

//-------------------------------707. Design Linked List ------------------------------------//

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        next = NULL;
    }
};

class MyLinkedList
{
public:
    /** Initialize your data structure here. */
    int size = 0;
    Node *head = new Node(0);
    MyLinkedList()
    {
    }

    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index)
    {
        if (index >= size)
            return -1;
        Node *temp = head->next;
        for (int i = 0; i < index; i++)
            temp = temp->next;
        return temp->val;
    }

    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val)
    {
        Node *temp = head->next;
        head->next = new Node(val);
        head->next->next = temp;
        size++;
    }

    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val)
    {
        Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new Node(val);
        size++;
    }

    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        Node *temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;
        Node *temp1 = temp->next;
        temp->next = new Node(val);
        temp->next->next = temp1;
        size++;
    }

    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index)
    {
        if (index >= size)
            return;
        Node *temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;
        Node *temp1 = temp->next;
        temp->next = temp1->next;
        temp1->next = NULL;
        size--;
        delete temp1;
    }
};

//---------------------------------712. Min ascii values --------------------//

int gg(string s, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += (int)s[i];
    }
    return sum;
}
int minimumDeleteSum(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (j == 0)
            {
                dp[i][j] = gg(s1, i);
            }
            else if (i == 0)
            {
                dp[i][j] = gg(s2, j);
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                int a1 = s1[i - 1] + dp[i - 1][j];
                int a2 = s2[j - 1] + dp[i][j - 1];
                dp[i][j] = min(a1, a2);
            }
        }
    }
    return dp[n][m];
}

//----------------------------------714. Best time to buy with 2 transactions -------------------//

int maxProfit(vector<int> &prices, int fee)
{
    int s0 = 0, s1 = INT_MIN;
    for (auto it : prices)
    {
        int tmp = s0;
        s0 = max(s0, s1 + it);
        s1 = max(s1, tmp - it - fee);
    }
    return s0;
}

//----------------------------------718. Max length of repeated subarray ---------------------//

int findLength(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size(), m = nums2.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (nums1[i - 1] == nums2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                // cout<<dp[i][j]<<" ";
                ans = max(ans, dp[i][j]);
                // cout<<ans<<endl;
            }
        }
    }
    return ans;
}

//---------------------------------733. Flood Fill ----------------------------------//

void dfs(vector<vector<int>> &image, int i, int j, int val, int newColor)
{
    if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] == newColor || image[i][j] != val)
    {
        return;
    }
    image[i][j] = newColor;
    dfs(image, i - 1, j, val, newColor);
    dfs(image, i + 1, j, val, newColor);
    dfs(image, i, j - 1, val, newColor);
    dfs(image, i, j + 1, val, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int val = image[sr][sc];
    dfs(image, sr, sc, val, newColor);
    return image;
}

//------------------------------735. Asteroids Collisions -------------------------//

vector<int> AsteroidCollion(vector<int> v)
{
    vector<int> ans;
    stack<int> st;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > 0)
        {
            st.push(v[i]);
        }
        else
        {
            while (st.size() > 0 && st.top() > 0 && st.top() < abs(v[i]))
            {
                st.pop();
            }
            if (st.size() > 0 && st.top() == v[i])
            {
                st.pop();
            }
            else if (st.size() > 0 && st.top() > -v[i])
            {
            }
            else
            {
                st.push(v[i]);
            }
        }
    }
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

//--------------------------------738. Monotone Increasing Digits ---------------------------//

int monotoneIncreasingDigits(int n)
{
    if (n < 10)
    {
        return n;
    }
    string s = to_string(n);
    int index = s.length();
    int i;
    for (i = index - 1; i > 0; i--)
    {
        if (s[i - 1] > s[i])
        {
            s[i - 1]--;
            index = i;
        }
    }
    for (i = index; i < s.length(); i++)
    {
        s[i] = '9';
    }
    n = stoi(s);
    return n;
}

//---------------------------------739. Daily Temperatures ------------------------------//

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    if (temperatures.empty())
    {
        return {};
    }
    stack<pair<int, int>> st;
    st.push(make_pair(temperatures.back(), 0));
    vector<int> v(temperatures.size(), 0);
    for (int i = temperatures.size() - 2; i >= 0; i--)
    {
        int count = 1;
        while (!st.empty() && temperatures[i] >= st.top().first)
        {
            count += st.top().second;
            st.pop();
        }
        if (st.empty())
        {
            st.push(make_pair(temperatures[i], 0));
        }
        else
        {
            st.push(make_pair(temperatures[i], count));
            v[i] = count;
        }
    }
    return v;
}

//------------------------------------740. Delete And Earn ---------------------------------//

int deleteAndEarn(vector<int> &nums)
{
    int n = 10001;
    vector<int> values(n, 0);
    for (int num : nums)
        values[num] += num;

    int take = 0, skip = 0;
    for (int i = 0; i < n; i++)
    {
        int takei = skip + values[i];
        int skipi = max(skip, take);
        take = takei;
        skip = skipi;
    }
    return max(take, skip);
}

int main()
{
}