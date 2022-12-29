#include <bits/stdc++.h>
using namespace std;

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

treenode *searchBst(treenode *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    treenode *t = searchBst(root->left, key);
    if (t == NULL)
    {
        return searchBst(root->right, key);
    }
    return t;
}

treenode *insertBst(treenode *root, int key)
{
    treenode *newnode = new treenode(key);
    if (root == NULL)
    {
        return newnode;
    }
    if (root->data > key)
    {
        root->left = insertBst(root->left, key);
    }
    if (root->data <= key)
    {
        root->right = insertBst(root->right, key);
    }
    return root;
}

treenode *insertBst(treenode *root, int key)
{
    treenode *newnode = new treenode(key);
    if (root == NULL)
    {
        return newnode;
    }
    if (root->data > key)
    {
        root->left = insertBst(root->left, key);
    }
    if (root->data <= key)
    {
        root->right = insertBst(root->right, key);
    }
    return root;
}

treenode *removeFromBst(treenode *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == key)
    {
        if (root->right == NULL)
        {
            treenode *t = root->left;
            delete root;
            return t;
        }
        else
        {
            treenode *t = root->right;
            while (t->left != NULL)
            {
                t = t->left;
            }
            swap(root->data, t->data);
        }
    }
    root->left = removeFromBst(root->left, key);
    root->right = removeFromBst(root->right, key);
    return root;
}

bool findpair(treenode *root, int k, unordered_map<int, int> &mp)
{
    if (root == NULL)
    {
        return false;
    }
    if (findpair(root->left, k, mp))
    {
        return true;
    }
    if (mp[k - root->data] == 1)
    {
        return true;
    }
    mp[root->data] = 1;
    if (findpair(root->right, k, mp))
    {
        return true;
    }
    return false;
}

bool pairExists(treenode *root, int k)
{
    unordered_map<int, int> mp;
    return findpair(root, k, mp);
}

bool helper(treenode *root, int mini, int maxi)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < mini || root->data > maxi)
    {
        return false;
    }
    return helper(root->left, mini, root->data) && helper(root->right, root->data, maxi);
}

bool isBst(treenode *root)
{
    if (root == NULL)
    {
        return true;
    }
    return helper(root, INT_MIN, INT_MAX);
}

void helper2(treenode *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    helper2(root->left, v);
    v.push_back(root->data);
    helper2(root->right, v);
}

int findKthLargest(treenode *root, int k)
{
    vector<int> v;
    helper2(root, v);
    return v[v.size() - k];
}

class KthLargest
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k)
    {
        while (!pq.empty())
        {
            pq.pop();
        }
        K = k;
    }

    int add(int num)
    {
        pq.push(num);
        if (pq.size() < K)
        {
            return -1;
        }
        while (pq.size() > K)
        {
            pq.pop();
        }
        return pq.top();
    }
};

class MedianCalculator
{
public:
    priority_queue<int> large;
    priority_queue<int, vector<int>, greater<int>> small;
    MedianCalculator()
    {
        while (!large.empty())
        {
            large.pop();
        }
        while (!small.empty())
        {
            small.pop();
        }
    }

    void addNum(int num)
    {
        large.push(num);
        small.push(large.top());
        large.pop();
        if (large.size() < small.size())
        {
            large.push(small.top());
            small.pop();
        }
    }

    float getMedian()
    {
        return large.size() > small.size() ? large.top() : (large.top() + small.top()) / 2.0f;
    }
};

vector<int> mergeKArrays(vector<vector<int>> &arr)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            pq.push(arr[i][j]);
        }
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

vector<int> sortAlmostSorted(vector<int> &arr, int k)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i <= k; i++)
    {
        minHeap.push(arr[i]);
    }
    int indx = 0;
    for (int i = k + 1; i < n; i++)
    {
        arr[indx++] = minHeap.top();
        minHeap.pop();
        minHeap.push(arr[i]);
    }
    while (!minHeap.empty())
    {
        arr[indx++] = minHeap.top();
        minHeap.pop();
    }
    return arr;
}

int main()
{
}