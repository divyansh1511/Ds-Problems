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

treenode *takeinput()
{
    queue<treenode *> pendingnodes;
    cout << "enter root node : " << endl;
    int data;
    cin >> data;
    treenode *root = new treenode(data);
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        treenode *curr = pendingnodes.front();
        pendingnodes.pop();
        cout << "enter left child data : " << endl;
        int leftchilddata;
        cin >> leftchilddata;
        if (leftchilddata != -1)
        {
            treenode *leftchild = new treenode(leftchilddata);
            curr->left = leftchild;
            pendingnodes.push(leftchild);
        }
        cout << "enter right child data : " << endl;
        int rightchilddata;
        cin >> rightchilddata;
        if (rightchilddata != -1)
        {
            treenode *rightchild = new treenode(rightchilddata);
            curr->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}

void Inorder(treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Inorderitr(treenode *root)
{
    stack<treenode *> st;
    treenode *curr = root;
    while (curr != NULL || !st.empty())
    {
        if (curr == NULL)
        {
            curr = st.top();
            st.pop();
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            st.push(curr);
            curr = curr->left;
        }
    }
}

void PreOrder(treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    PreOrder(root->left);
    PreOrder(root->right);
}

void PreOrderitr(treenode *root)
{
    stack<treenode *> st;
    treenode *curr = root;

    while (!st.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            cout << curr->data << " ";
            if (curr->right)
            {
                st.push(curr->right);
            }
            curr = curr->left;
        }

        if (!st.empty())
        {
            curr = st.top();
            st.pop();
        }
    }
}

void PostOrder(treenode *root)
{
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout << root->data << " ";
}

vector<int> LeftView(treenode *root)
{
    queue<treenode *> pendingnodes;
    vector<int> ans;
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

vector<int> rightview(treenode *root)
{
    queue<treenode *> pendingnodes;
    vector<int> ans;
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

vector<int> BottomView(treenode *root)
{
    if (root == NULL)
    {
        return {};
    }
    map<int, int> mp;
    queue<pair<treenode *, int>> pendingnodes;
    pendingnodes.push({root, 0});
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode *curr = pendingnodes.front().first;
            int h = pendingnodes.front().second;
            pendingnodes.pop();
            mp[h] = curr->data;

            if (curr->left)
            {
                pendingnodes.push({curr->left, h - 1});
            }
            if (curr->right)
            {
                pendingnodes.push({curr->right, h + 1});
            }
        }
    }
    vector<int> ans;
    for (auto it : mp)
    {
        ans.push_back(it.first);
    }
    return ans;
}

vector<int> TopView(treenode *root)
{
    if (root == NULL)
    {
        return {};
    }
    map<int, int> mp;
    queue<pair<treenode *, int>> pendingnodes;
    pendingnodes.push({root, 0});
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode *curr = pendingnodes.front().first;
            int h = pendingnodes.front().second;
            pendingnodes.pop();
            if (mp[h] == 0)
            {
                mp[h] = curr->data;
            }
            if (curr->left)
            {
                pendingnodes.push({curr->left, h - 1});
            }
            if (curr->right)
            {
                pendingnodes.push({curr->right, h + 1});
            }
        }
    }
    vector<int> ans;
    for (auto it : mp)
    {
        ans.push_back(it.first);
    }
    return ans;
}

void traverse(treenode *root, int x, int y, map<int, map<int, multiset<int>>> &mp)
{
    if (root)
    {
        mp[x][y].insert(root->data);
        traverse(root->left, x - 1, y + 1, mp);
        traverse(root->right, x + 1, y + 1, mp);
    }
}

vector<vector<int>> VerticalOrderTraversal(treenode *root)
{
    map<int, map<int, multiset<int>>> mp;
    traverse(root, 0, 0, mp);
    vector<vector<int>> ans;

    for (auto it : mp)
    {
        vector<int> col;
        for (auto a : it.second)
        {
            col.insert(col.end(), a.second.begin(), a.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int helper(treenode *root, int b, vector<int> &ans)
{
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == b)
    {
        ans.push_back(b);
        return b;
    }
    ans.push_back(root->data);
    int a = helper(root->left, b, ans);
    if (a != -1)
    {
        return a;
    }
    int b = helper(root->right, b, ans);
    if (b != -1)
    {
        return b;
    }
    ans.pop_back();
    return -1;
}

vector<int> PathToNode(treenode *root, int b)
{
    vector<int> ans;
    helper(root, b, ans);
    return ans;
}

int WidthofBT(treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int res = 1;

    queue<pair<treenode *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int cnt = q.size();

        int st = q.front().second;
        int end = q.back().second;

        res = max(res, end - st + 1);

        for (int i = 0; i < cnt; i++)
        {
            pair<treenode *, int> p = q.front();
            q.pop();
            int idx = p.second - st;

            if (p.first->left)
            {
                q.push({p.first->left, 2 * idx + 1});
            }
            if (p.first->right)
            {
                q.push({p.first->right, 2 * idx + 2});
            }
        }
    }
    return res;
}

vector<vector<int>> LevelOrderTraversal(treenode *root)
{
    if (root == NULL)
    {
        return {};
    }
    queue<treenode *> pendingnodes;
    vector<vector<int>> ans;
    pendingnodes.push(root);

    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        vector<int> v;
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
        ans.push_back(v);
    }
    return ans;
}

int heightofBT(treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(heightofBT(root->left), heightofBT(root->right));
}

int DiameterofBT(treenode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftdiameter = DiameterofBT(root->left);
    int rightdiameter = DiameterofBT(root->right);

    int leftheight = heightofBT(root->left);
    int rightheight = heightofBT(root->right);

    return max({leftdiameter, rightdiameter, leftheight + rightheight});
}

bool isBalancedBT(treenode *root)
{
    if (root == NULL)
    {
        return true;
    }
    return isBalancedBT(root->left) || isBalancedBT(root->right) || (abs(heightofBT(root->left) - heightofBT(root->right)) <= 1);
}

treenode *LCA(treenode *root, treenode *p, treenode *q)
{
    if (!root || !p || !q)
    {
        return NULL;
    }
    if (root == p || root == q)
    {
        return root;
    }

    treenode *l = LCA(root->left, p, q);
    treenode *r = LCA(root->right, p, q);

    if (l && r)
    {
        return root;
    }
    return l ? l : r;
}

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
    if (p->data == q->data)
    {
        bool a = isSameTree(p->left, q->left);
        if (a == false)
        {
            return false;
        }
        bool b = isSameTree(p->right, q->right);
        if (b == false)
        {
            return false;
        }
        return true;
    }
    else
    {
        return false;
    }
}

vector<vector<int>> ZigZagLevelOrderTraversal(treenode *root)
{
    if (root == NULL)
    {
        return {};
    }
    queue<treenode *> pendingnodes;
    vector<vector<int>> ans;
    pendingnodes.push(root);
    bool flag = true;

    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        vector<int> v;
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
        if (!flag)
        {
            reverse(v.begin(), v.end());
        }
        flag = !flag;
        ans.push_back(v);
    }
    return ans;
}

bool isLeaf(treenode * root) {
    return !root -> left && !root -> right;
}

void addLeftBoundary(treenode *root, vector<int> &res)
{
    treenode *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            res.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void addRightBoundary(treenode *root, vector<int> &res)
{
    treenode *cur = root->right;
    vector<int> tmp;
    while (cur)
    {
        if (!isLeaf(cur))
            tmp.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for (int i = tmp.size() - 1; i >= 0; --i)
    {
        res.push_back(tmp[i]);
    }
}

void addLeaves(treenode *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}

vector<int> boundary(treenode *root)
{
    // Your code here
    vector<int> res;

    if (!root)
        return res;

    if (!isLeaf(root))
        res.push_back(root->data);

    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}

int helper2(treenode* root , int &ans){
    if (root == NULL)
    {
        return 0;
    }
    int ls = helper2(root->left , ans) + root->data;
    int rs = helper2(root->right , ans) + root->data;

    ans = max({ans , ls , rs , ls+rs-root->data , root->data});

    return max({ls , rs , root->data});
}

int MaxPathSum(treenode* root){
    int ans = INT_MIN;
    helper2(root , ans);
    return ans;
}

treenode* build(vector<int> &pre , vector<int> &in , int inst , int inend , int &preindex){
    if (inst > inend)
    {
        return NULL;
    }
    int ind = inst;
    while (in[ind] != pre[preindex])
    {
        ind++;
    }
    preindex++;
    treenode* root = new treenode(in[ind]);
    root->left = build(pre , in , inst , ind-1 , preindex);
    root->right = build(pre , in , ind+1 , inend , preindex);
    return root;
}

treenode* buildtreefrompreandin(vector<int> &pre , vector<int> &in){
    int preindex = 0;
    return build(pre , in , 0 , in.size()-1 , preindex);
}

treenode* helper3(vector<int> &in , int inst , int inend , vector<int> &pos , int post , int poend){
    if (inst > inend || post > poend)
    {
        return NULL;
    }
    treenode* newnode = new treenode(pos[poend]);
    int x = inst;
    while (newnode->data != in[x])
    {
        x++;
    }
    newnode->left = helper3(in , inst , x-1 , pos , post , post+x-inst-1);
    newnode->right = helper3(in , x+1 , inend , pos , post+x-inst , poend-1);
    return newnode;
}

treenode* buildtreefrompostandin(vector<int> &post , vector<int> &in){
    return helper3(in , 0 , in.size()-1 , post , 0 , post.size()-1);
}

bool helper4(treenode* h1 , treenode* h2){
    if (h1 == NULL && h2 == NULL)
    {
        return true;
    }
    if (h1 == NULL || h2 == NULL)
    {
        return false;
    }
    return (h1->data == h2->data) && helper4(h1->left , h2->right) && helper4(h1->right , h2->left);
}

bool isSymetric(treenode* root){
    if (root == NULL)
    {
        return;
    }
    return helper4(root->left , root->right);
}

void FlattenBT(treenode* root){
    while (root != NULL)
    {
        if (root->left != NULL && root->right != NULL)
        {
            treenode* tmp = root->left;
            while (tmp->right)
            {
                tmp = tmp->right;
            }
            tmp->right = root->right;
        }
        if (root->left != NULL)
        {
            root->right = root->left;
        }
        root->left = NULL;
        root = root->right;
    }
}

void mirror(treenode* root){
    if (root == NULL)
    {
        return;
    }
    treenode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    mirror(root->left);
    mirror(root->right);
}

bool searchinBST(treenode* root , int val){
    if (root == NULL)
    {
        return false;
    }
    if (root->data == val)
    {
        return true;
    }
    else if (root->data > val)
    {
        return searchinBST(root->left , val);
    }
    else
    {
        return searchinBST(root->right , val);
    }    
}

treenode* helper5(vector<int> &v , int st , int end){
    if (st > end)
    {
        return NULL;
    }
    int mid = (st+end)/2;
    treenode* root = new treenode(v[mid]);
    root->left = helper5(v , st , mid-1);
    root->right = helper5(v , mid+1 , end);
    return root;
}

treenode* sortedarrtoBST(vector<int> v){
    int st = 0 , end = v.size()-1;
    return helper5(v , st , end);
}

treenode* helper6(vector<int> pre , int i , int maxi){
    if (i == pre.size() || pre[i] > maxi)
    {
        return NULL;
    }
    treenode* root = new treenode(pre[i++]);
    root->left = helper6(pre , i , root->data);
    root->right = helper6(pre , i , maxi);
    return root;
}

treenode* PreOrdertoBST(vector<int> pre){
    int i = 0;
    return helper6(pre , i , INT_MAX);
}

bool helper7(treenode* root , int mini , int maxi){
    if (root == NULL)
    {
        return true;
    }
    if (root->data <= mini || root->data >= maxi)
    {
        return false;
    }
    bool leftBST = helper7(root->left , mini , root->data);
    bool rightBST = helper7(root->right , root->data , maxi);
    return leftBST && rightBST;
}

bool isValidBST(treenode* root){
    return helper7(root , INT_MIN , INT_MAX);
}

void helper8(treenode* root , vector<int> &ans){
    if (root == NULL)
    {
        return;
    }
    helper8(root->left , ans);
    ans.push_back(root->data);
    helper8(root->right , ans);
}

int KthsmallestElement(treenode* root , int k){
    vector<int> ans;
    helper8(root , ans);
    return ans[k-1];
}

int kthlargestelement(treenode* root , int k){
    vector<int> ans;
    helper8(root , ans);
    return ans[ans.size()-k];
}

int main()
{
}