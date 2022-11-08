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

int Depth(treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(Depth(root->left), Depth(root->right));
}

void helper(treenode *root, vector<int> ans, queue<treenode *> q)
{
    if (q.empty())
    {
        return;
    }
    treenode *root = q.front();
    q.pop();
    if (root->right)
    {
        q.push(root->right);
    }
    if (root->left)
    {
        q.push(root->left);
    }
    helper(root, ans, q);
    ans.push_back(root->data);
}

vector<int> ReverseLevelOrder(treenode *root)
{
    vector<int> ans;
    queue<treenode *> q;
    q.push(root);
    helper(root, ans, q);
    return ans;
}

bool check(treenode *root, treenode *sub)
{
    if (root == NULL && sub == NULL)
    {
        return true;
    }
    if (root == NULL || sub == NULL)
    {
        return false;
    }
    if (root->data != sub->data)
    {
        return false;
    }
    return check(root->left, sub->left) && check(root->right, sub->right);
}

bool isSubtree(treenode *root, treenode *sub)
{
    if (root == NULL)
    {
        return false;
    }
    if (check(root, sub))
    {
        return true;
    }
    return isSubtree(root->left, sub) || isSubtree(root->right, sub);
}

void mirror(treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    treenode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    mirror(root->left);
    mirror(root->right);
}

vector<int> LevelOrderTraversal(treenode *root)
{
    queue<treenode *> pendingnodes;
    pendingnodes.push(root);
    vector<int> v;
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode *curr = pendingnodes.front();
            pendingnodes.pop();
            v.push_back(curr->data);
            if (curr->left)
            {
                pendingnodes.push(curr->left);
            }
            if (curr->right)
            {
                pendingnodes.push(curr->right);
            }
        }
    }
    return v;
}

vector<int> LeftViewOfTree(treenode *root)
{
    vector<int> ans;
    queue<treenode *> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode *curr = pendingnodes.front();
            pendingnodes.pop();
            if (i == 0)
            {
                ans.push_back(curr->data);
            }
            if (curr->left)
            {
                pendingnodes.push(curr->left);
            }
            if (curr->right)
            {
                pendingnodes.push(curr->right);
            }
        }
    }
    return ans;
}

vector<int> RightViewOfTree(treenode *root)
{
    vector<int> ans;
    queue<treenode *> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode *curr = pendingnodes.front();
            pendingnodes.pop();
            if (i == n - 1)
            {
                ans.push_back(curr->data);
            }
            if (curr->left)
            {
                pendingnodes.push(curr->left);
            }
            if (curr->right)
            {
                pendingnodes.push(curr->right);
            }
        }
    }
    return ans;
}

vector<int> zigZagTraversal(treenode *root)
{
    queue<treenode *> q;
    q.push(root);
    int k = 0;
    vector<int> ret;
    while (!q.empty())
    {
        int n = q.size();
        int n1 = n;
        vector<int> temp;
        while (n--)
        {
            treenode *t = q.front();
            q.pop();
            ret.push_back(t->data);
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        if (k & 1)
            reverse(ret.end() - n1, ret.end());
        k++;
    }
    return ret;
}

void helper1(treenode *root, set<int> &s, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL || root->right == NULL)
    {
        s.insert(level);
    }
    helper1(root->left, s, level + 1);
    helper1(root->right, s, level + 1);
}

bool LeafAtSame(treenode *root)
{
    set<int> s;
    helper1(root, s, 0);
    return s.size() == 1;
}

bool isBalanced(treenode *root)
{
    if (root == NULL)
    {
        return true;
    }
    int lh = Depth(root->left);
    int rh = Depth(root->right);

    return abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

int transformsumtree(treenode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int oldval = node->data;
    node->data = transformsumtree(node->left) + transformsumtree(node->right);
    return node->data + oldval;
}

bool isIsomorphic(treenode *root1, treenode *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    if (root1->data != root2->data)
    {
        return false;
    }
    treenode *l1 = root1->left ? root1->left : NULL;
    treenode *r1 = root1->right ? root1->right : NULL;
    treenode *l2 = root2->left ? root2->left : NULL;
    treenode *r2 = root2->right ? root2->right : NULL;
    return (isIsomorphic(l1, l2) && isIsomorphic(r1, r2)) || (isIsomorphic(l1, r2) && isIsomorphic(r1, l2));
}

treenode *build(vector<int> &preorder, vector<int> &inorder, int instart, int inend, int &preindex)
{
    if (instart > inend)
        return NULL;
    int index = instart; // find the root from inorder
    while (inorder[index] != preorder[preindex])
        index++;

    preindex++;
    treenode *newNode = new treenode(inorder[index]);
    newNode->left = build(preorder, inorder, instart, index - 1, preindex);
    newNode->right = build(preorder, inorder, index + 1, inend, preindex);
    return newNode;
}

treenode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preindex = 0;
    return;
}

vector<int> topView(treenode *root)
{
    queue<pair<treenode *, int>> q;
    q.push({root, 0});
    map<int, int> mp;
    while (!q.empty())
    {
        treenode *currnode = q.front().first;
        int h = q.front().second;
        q.pop();
        if (mp[h] == 0)
        {
            mp[h] = currnode->data;
        }
        if (currnode->left != NULL)
        {
            q.push({currnode->left, h - 1});
        }
        if (currnode->right != NULL)
        {
            q.push({currnode->right, h + 1});
        }
    }
    vector<int> v;
    for (auto it : mp)
    {
        v.push_back(it.second);
    }
    return v;
}

vector<int> bottomView(treenode *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    map<int, int> mp;
    queue<pair<treenode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            treenode *ff = q.front().first;
            int h = q.front().second;
            q.pop();
            mp[h] = ff->data;
            if (ff->left != NULL)
            {
                q.push({ff->left, h - 1});
            }
            if (ff->right != NULL)
            {
                q.push({ff->right, h + 1});
            }
        }
    }
    for (auto it : mp)
    {
        ans.push_back(it.second);
    }
    return ans;
}

vector<int> diagonal(treenode *root)
{
    vector<int> diagonalVals;
    if (!root)
        return diagonalVals;

    queue<treenode *> leftQueue;
    treenode *node = root;

    while (node)
    {
        diagonalVals.push_back(node->data);
        if (node->left)
            leftQueue.push(node->left);

        if (node->right)
            node = node->right;

        else
        {
            if (!leftQueue.empty())
            {
                node = leftQueue.front();
                leftQueue.pop();
            }
            else
            {
                node = NULL;
            }
        }
    }
    return diagonalVals;
}

treenode *lca(treenode *root, int n1, int n2)
{
    if (root == NULL)
    {
        return root;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    treenode *leftt = lca(root->left, n1, n2);
    treenode *rightt = lca(root->right, n1, n2);

    if (leftt != NULL && rightt != NULL)
    {
        return root;
    }
    if (leftt == NULL && rightt == NULL)
    {
        return NULL;
    }
    if (leftt != NULL)
    {
        return lca(root->left, n1, n2);
    }
    return lca(root->right, n1, n2);
}

treenode *temp = NULL;
treenode *kthAncestorDFS(treenode *root, int node, int &k)
{
    if (!root)
        return NULL;

    if (root->data == node || (temp = kthAncestorDFS(root->left, node, k)) || (temp = kthAncestorDFS(root->right, node, k)))
    {
        if (k > 0)
            k--;

        else if (k == 0)
        {
            cout << "Kth ancestor is: " << root->data;
            return NULL;
        }
        return root;
    }
}

int help(treenode *root, int &ans)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftsum = root->data + help(root->left, ans);
    int rightsum = root->data + help(root->right, ans);

    ans = max({ans, leftsum, rightsum, leftsum + rightsum - root->data, root->data});

    return max({leftsum, rightsum, root->data});
}

int maxPathSum(treenode *root)
{
    int ans = INT_MIN;
    help(root, ans);
    return ans;
}

int main()
{
}