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
    treenode(int data, treenode *left, treenode *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
    ~treenode()
    {
        delete left;
        delete right;
    }
};

//----------------------------------94. Binary Tree Inorder Traversal -----------------------------//

void helper(treenode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    helper(root->left, ans);
    ans.push_back(root->data);
    helper(root->right, ans);
}

vector<int> Inoder_M1(treenode *root)
{
    vector<int> ans;
    helper(root, ans);
    return ans;
}

vector<int> Inorder_M2(treenode *root)
{
    stack<treenode *> st;
    treenode *curr = root;
    vector<int> ans;

    while (!st.empty() || curr != NULL)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }
    return ans;
}

//-------------------------------95. Unique Binary Search Tree II --------------------------------//

vector<treenode *> helper2(int st, int en)
{
    vector<treenode *> ans;
    if (st > en)
    {
        return {NULL};
    }
    if (st == en)
    {
        return {new treenode(st)};
    }
    for (int i = st; i <= en; i++)
    {
        vector<treenode *> left = helper2(st, i - 1);
        vector<treenode *> right = helper2(i + 1, en);

        for (auto l : left)
        {
            for (auto r : right)
            {
                ans.push_back(new treenode(i, l, r));
            }
        }
    }
    return ans;
}

vector<treenode *> UniqueBST(int n)
{
    vector<treenode *> ans = helper2(1, n);
    return ans;
}

//-----------------------------------96. Unique Binary Search Tree -----------------------------//

int NumTrees(int n)
{
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i < n; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            dp[i] += dp[j] * dp[i - j - 1];
        }
    }
    return dp[n];
}

//---------------------------------97. Interleaving String --------------------------------//

bool InterleavingString(string s1, string s2, string s)
{
    int n = s1.length();
    int m = s2.length();
    if (n + m != s.length())
    {
        return false;
    }
    bool dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[i][j] = true;
            }
            else if (i == 0)
            {
                dp[i][j] = (dp[i][j - 1] && s2[j - 1] == s[i + j - 1]);
            }
            else if (j == 0)
            {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s[i + j - 1]);
            }
            else
            {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s[i + j - 1]) || (dp[i][j - 1] && s2[j - 1] == s[i + j - 1]);
            }
        }
    }
    return dp[n][m];
}

//--------------------------------98. Validate BST -----------------------------//

bool helper3(treenode *root, int mini, int maxi)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->data < mini || root->data > maxi)
    {
        return false;
    }
    return helper3(root->left, mini, root->data) && helper3(root->right, root->data, maxi);
}

bool isBST(treenode *root)
{
    return helper3(root, INT_MIN, INT_MAX);
}

//-----------------------------------99. Recover BST -----------------------------//

void helper4(treenode *root, vector<pair<treenode *, treenode *>> &v, treenode *&prev)
{
    if (root == NULL)
    {
        return;
    }
    helper4(root->left, v, prev);
    if (prev && prev->data > root->data)
    {
        v.push_back({prev, root});
    }
    prev = root;
    helper4(root->right, v, prev);
}

void RecoverBST(treenode *root)
{
    vector<pair<treenode *, treenode *>> v;
    treenode *prev = NULL;
    helper4(root, v, prev);
}

//----------------------------------100. Same Tree -----------------------------//

bool isSameTree(treenode *p, treenode *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL || q == NULL)
    {
        return false;
    }
    return (p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

//--------------------------------101. Symetric Tree -------------------------//

bool helper5(treenode* h1 , treenode* h2){
    if (h1 == NULL && h2 == NULL)
    {
        return true;
    }
    if (h1 == NULL || h2 == NULL)
    {
        return false;
    }
    return (h1->data == h2->data) && helper5(h1->left , h2->right) && helper5(h1->right , h2->left);
}

bool isSymetricTree(treenode* root){
    if (root == NULL)
    {
        return true;
    }
    return helper5(root->left , root->right);
}

//--------------------------------102. Binary Tree Level Order Traversal ----------------------//

vector<vector<int>> LevelOrderTraversal(treenode* root){
    vector<vector<int>> ans;
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            treenode* curr = pendingnodes.front();
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
        ans.push_back(v);
    }
    return ans;
}

//--------------------------------103. Zig-Zag Level Order Traversal----------------------------//

vector<vector<int>> ZigzagTraversal(treenode* root){
    vector<vector<int>> ans;
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);
    bool flag = true;
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            treenode* curr = pendingnodes.front();
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
        if (!flag)
        {
            reverse(v.begin() , v.end());
        }
        ans.push_back(v);
        flag = !flag;
    }
    return ans;
}

//---------------------------------104. Maximum Depth of tree -----------------------//

int MaximumDepthTree(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return max(MaximumDepthTree(root->left) , MaximumDepthTree(root->right));
}

//---------------------105. Construct Binary Tree from preorder and Inorder --------------------//

treenode* helper6(vector<int> &pre , vector<int> &in , int inst , int inend , int &prest){
    if (inst > inend)
    {
        return NULL;
    }
    int idx = inst;
    while (in[idx] != pre[prest])
    {
        idx++;
    }
    prest++;
    treenode* root = new treenode(in[idx]);
    root->left = helper6(pre , in , inst , idx-1 , prest);
    root->right = helper6(pre , in , idx+1 , inend , prest);
    return root;
}

treenode* BuildTree(vector<int> &pre , vector<int> &in){
    int prest = 0;
    return helper6(pre , in , 0 , in.size()-1 , prest);
}

//------------------106. Construct Binary Tree from postorder and Inorder -------------------//

treenode* helper7(vector<int> &in , int inst , int inend , vector<int> &pos , int post , int poend){
    if (inst > inend || post > poend)
    {
        return NULL;
    }
    treenode* root = new treenode(pos[poend]);
    int idx = inst;
    while (root->data != in[idx])
    {
        idx++;
    }
    root->left = helper7(in , inst , idx-1 , pos, post , post+idx-inst-1);
    root->right = helper7(in , idx+1 , inend , pos , post+idx-inst , poend-1);
    return root;
}

treenode* BuildTree2(vector<int> &in , vector<int> &pos){
    return helper7(in , 0 , in.size()-1 , pos , 0 , pos.size()-1);
}

//----------------------107. Binary Tree Level Order Traversal II ---------------------------//

vector<vector<int>> LevelOrderTraversalII(treenode* root){
    vector<vector<int>> ans;
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            treenode* curr = pendingnodes.front();
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
        ans.push_back(v);
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

//----------------------108. Convert Sorted Array to binary search tree ------------------//

treenode* helper8(vector<int> v , int st , int end){
    if (st > end)
    {
        return NULL;
    }
    int mid = (st+end)/2;
    treenode* root = new treenode(v[mid]);
    root->left = helper8(v , st , mid-1);
    root->right = helper8(v , mid+1 , end);
    return root;
}

treenode* BinarySearchTree(vector<int> v){
    int st = 0 , end = v.size()-1;
    return helper8(v , st , end);
}

//----------------------------109. Convert Sorted List to BST------------------------------//

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data = data;
        next = NULL;
    }
};

treenode* ConvertlisttoBST(node* head){
    if (head == NULL)
    {
        return NULL;
    }
    if (head->next == NULL)
    {
        return new treenode(head->data);
    }
    node* slow = head;
    node* fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    node* mid = slow->next;
    slow->next = NULL;
    treenode* root = new treenode(mid->data);
    root->left = ConvertlisttoBST(head);
    root->right = ConvertlisttoBST(mid->next);
    return root;
}

//-------------------------------110. Balanced Binary Tree ---------------------------//

bool IsbalancedBT(treenode* root){
    if (root == NULL)
    {
        return true;
    }
    return IsbalancedBT(root->left) && IsbalancedBT(root->right) && abs(MaximumDepthTree(root->right) - MaximumDepthTree(root->left)) <= 1;
}

//--------------------------------111. Minimum Depth of Binary Tree -------------------//

int MinDepth(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return min(MinDepth(root->left) , MinDepth(root->right)) + 1;
}

//-------------------------------112. Path Sum ---------------------------------------//

bool hasPathSum(treenode* root , int sum){
    if (root == NULL)
    {
        return false;
    }
    if (root->data == sum && root->left == NULL && root->right == NULL)
    {
        return true;
    }
    return hasPathSum(root->left , sum-root->data) || hasPathSum(root->right , sum-root->data);
}

//--------------------------------113. Path Sum II -------------------------------//

void helper9(treenode* root , int sum , vector<int> tmp , vector<vector<int>> &ans){
    if (root == NULL)
    {
        return;
    }
    tmp.push_back(root->data);
    if (root->data == sum && root->left == NULL && root->right == NULL)
    {
        ans.push_back(tmp);
        return;
    }
    helper9(root->left , sum-root->data , tmp , ans);
    helper9(root->right , sum-root->data , tmp , ans);
    tmp.pop_back();
}

vector<vector<int>> PathSum(treenode* root , int sum){
    vector<vector<int>> ans;
    vector<int> tmp;
    helper9(root , sum , tmp , ans);
    return ans;
}

//------------------------------114. Flatten a Linked list from BT------------------------//

void FlattenLL(treenode* root){
    while (root)
    {
        if (root->left && root->right)
        {
            treenode* tmp = root->left;
            while (tmp->right)
            {
                tmp = tmp->right;
            }
            tmp->right = root->right;
        }
        else if (root->left)
        {
            root->right = root->left;
        }
        root->left = NULL;
        root = root->right;
    }
}

//--------------------------------115. Distinct Sunsequence -----------------------------//

int NumDistinct(string s , string t){
    vector<vector<int>> dp(t.length()+1 , vector<int>(s.length()+1));

    for (int i = 0; i <= s.length(); i++)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i <= t.length(); i++)
    {
        for (int j = 1; j <= s.length(); j++)
        {
            if (t[i-1] == s[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
            }
            else
            {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    return dp[t.length()-1][s.length()-1];
}

//----------------------------------116. , 117. NEXT RIGHT POINTER ----------------------------//

int main()
{
}