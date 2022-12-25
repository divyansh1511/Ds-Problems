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

treenode *lca(treenode *root, int maxi, int mini)
{
    while (root != NULL)
    {
        if (root->data > maxi)
        {
            root = root->left;
        }
        else if (root->data < mini)
        {
            root = root->right;
        }
        else
        {
            return root;
        }
    }
    return NULL;
}

treenode *insert(treenode *root, int Key)
{
    treenode *newnode = new treenode(Key);
    if (root == NULL)
    {
        return newnode;
    }
    else if (root->data < Key)
    {
        root->right = insert(root->right, Key);
    }
    else if (root->data > Key)
    {
        root->left = insert(root->left, Key);
    }
    return root;
}

int minval(treenode *root)
{
    if (root == NULL)
    {
        return -1;
    }
    int mini = root->data;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return min(mini, root->data);
}

void findPreSuc(treenode *root, treenode *&pre, treenode *&suc, int key)
{

    if (!root)
        return;
    if (root->data == key)
    {
        if (root->left)
        {
            auto temp = root->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            pre = temp;
        }

        if (root->right)
        {
            auto temp = root->right;
            while (temp->left)
            {
                temp = temp->left;
            }
            suc = temp;
        }
    }

    else if (root->data < key)
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
}

void helper(treenode *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    helper(root->left, v);
    v.push_back(root->data);
    helper(root->right, v);
}

int kthLargest(treenode *root, int K)
{
    vector<int> v;
    helper(root, v);
    int n = v.size();
    return v[n - K];
}

bool helper(treenode *root, long min, long max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data <= min || root->data >= max)
    {
        return false;
    }
    bool leftbst = helper(root->left, min, root->data);
    bool rightbst = helper(root->right, root->data, max);
    return leftbst && rightbst;
}

bool isValidBST(treenode *root)
{
    return helper(root, LONG_MIN, LONG_MAX);
}

treenode *helper(int pre[], int n, int bound, int &i)
{
    if (i == n || pre[i] > bound)
        return NULL;
    treenode *root = new treenode(pre[i]);
    i++;
    root->left = helper(pre, n, root->data, i);
    root->right = helper(pre, n, bound, i);
    return root;
}

treenode *post_order(int pre[], int n)
{
    int i = 0;
    return helper(pre, n, INT_MAX, i);
}

void Inorder(treenode* root , vector<int> &v){
    if(root == NULL){
        return;
    }
    Inorder(root->left , v);
    v.push_back(root->data);
    Inorder(root->right , v);
}

treenode* helper(vector<int> &v , int i , int j){
    if(i > j){
        return NULL;
    }
    int mid = (i+j)/2;
    treenode* root = new treenode(v[mid]);
    root->left = helper(v , i , mid-1);
    root->right = helper(v , mid+1 , j);
    return root;
}

treenode* buildBalancedTree(treenode* root)
{
	vector<int> v;
	Inorder(root , v);
	return helper(v , 0 , v.size()-1);
}

int main()
{
}