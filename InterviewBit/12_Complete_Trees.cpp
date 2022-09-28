#include<bits/stdc++.h>
using namespace std;

class treenode{
    public:
    int data;
    treenode* left;
    treenode* right;
    treenode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~treenode(){
        delete left;
        delete right;
    }
};

bool IsValidBSTpreoder(vector<int> &v){
    stack<int> st;
    int root = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < root)
        {
            return 0;
        }
        while (st.size() && st.top() < v[i])
        {
            root = st.top();
            st.pop();
        }
        st.push(v[i]);
    }
    return 1;
}

void helper(treenode* root , int k , int &ans , int count){
    if (root == NULL)
    {
        return;
    }
    helper(root->left , k , ans , count);
    count++;
    if (count == k)
    {
        ans = root->data;
        return;
    }
    helper(root->right , k , ans , count);
}

int KthSmallestElementinBST(treenode* root , int k){
    int ans = 0;
    helper(root , k , ans , 0);
    return ans;
}

void inorder(treenode* root , vector<int> &v){
    if (root == NULL)
    {
        return;
    }
    inorder(root->left , v);
    v.push_back(root->data);
    inorder(root->right , v);
}

bool TwoSumBST(treenode* root , int k){
    vector<int> v;
    inorder(root , v);
    int i = 0 , j = v.size()-1;
    while (i <= j)
    {
        if (v[i] + v[j] < k)
        {
            i++;
        }
        else if (v[i] + v[j] > k)
        {
            j--;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

class BSTIterator {
    private:
        stack<treenode*> st;
public:
    BSTIterator(treenode* root) {
        find_left(root);
    }
    
    int next() {
        treenode* top = st.top();
        st.pop();
        if (top->right != NULL)
            find_left(top->right);
            
        return top->data;
    }
    
    bool hasNext() {
        if(st.empty()){
            return false;
        }
        return true;
    }
    void find_left(treenode* root)
    {
        treenode* p = root;
        while (p != NULL)
        {
            st.push(p);
            p = p->left;
        }
    }
};

void find(treenode* root , vector<int> &ans , int &prev){
    if (root == NULL)
    {
        return;
    }
    find(root->left , ans , prev);
    if (prev != -1)
    {
        if (prev > root->data)
        {
            ans[0] = min({ans[0] , prev , root->data});
            ans[1] = max({ans[1] , prev , root->data});
        }
    }
    prev = root->data;
    find(root->right , ans , prev);
}

vector<int> RecoverTree(treenode* root){
    vector<int> ans(2, -1);
    ans[0] = INT_MAX;
    ans[1] = INT_MIN;
    int prev = -1;
    find(root , ans , prev);
    return ans;
}

treenode* merge2binaryTree(treenode* a , treenode* b){
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    a->data += b->data;
    a->left = merge2binaryTree(a->left , b->left);
    a->right = merge2binaryTree(a->right , b->right);
    return a;
}

bool helper1(treenode* h1 , treenode* h2){
    if (h1 == NULL && h2 == NULL)
    {
        return true;
    }
    if (h1 == NULL || h2 == NULL)
    {
        return false;
    }
    if (h1->data != h2->data)
    {
        return false;
    }
    return helper1(h1->left , h2->right) && helper1(h1->right , h2->left);
}

bool IsSymetric(treenode* root){
    return helper1(root , root);
}

bool IsSameTree(treenode* h1 , treenode* h2){
    if (h1 == NULL && h2 == NULL)
    {
        return true;
    }
    if (h1 == NULL || h2 == NULL)
    {
        return false;
    }
    if (h1->data != h2->data)
    {
        return false;
    }
    return IsSameTree(h1->left , h2->left) && IsSameTree(h1->right , h2->right);
}

treenode* helper2(vector<int> v , int &i , int maxi){
    if (i == v.size() && v[i] > maxi)
    {
        return NULL;
    }
    treenode* root = new treenode(v[i++]);
    root->left = helper2(v , i , root->data);
    root->right = helper2(v , i , maxi);
    return root;
}

treenode* constructBSTfromPreorder(vector<int> v){
    int i = 0;
    treenode* root = helper2(v , i , INT_MAX);
    return root;
}

treenode* helper3(vector<int> v , int i , int j){
    if (i > j)
    {
        return NULL;
    }
    int mid = (i+j)/2;
    treenode* root = new treenode(v[mid]);
    root->left = helper3(v , i , mid-1);
    root->right = helper3(v , mid+1 , j);
    return root;
}

treenode* sortedArraytoBST(vector<int> v){
    int n = v.size()-1;
    return helper3(v , 0 , n);
}

treenode* helper4(vector<int> pre , int prest , int preend , vector<int> in , int inst , int inend){
    if (prest > preend && inst > inend)
    {
        return NULL;
    }
    treenode* root = new treenode(pre[prest]);
    int k = 0;
    for (int i = inst; i <= inend; i++)
    {
        if (in[inst] == pre[prest])
        {
            k = i;
            break;
        }
    }
    root->left = helper4(pre , prest+1 , prest + k - inst , in , inst , k-1);
    root->right = helper4(pre , prest+k-inst+1 , preend , in , k+1 , inend);
    return root;
}

treenode* BinaryTreefromPreAndIn(vector<int> pre , vector<int> in){
    if (pre.size() <= 0)
    {
        return NULL;
    }
    int n = pre.size();
    return helper4(pre , 0 , n-1 , in , 0 , n-1);
}

treenode* helper5(vector<int> post , int postart , int poend , vector<int> in , int inst , int inend){
    if (inst > inend && postart > poend)
    {
        return NULL;
    }
    treenode* root = new treenode(post[poend]);
    int s1 = inst;
    while (root->data != in[s1])
    {
        s1++;
    }
    root->left = helper5(post , postart , postart+s1-inst-1 , in , inst , s1-1);
    root->right = helper5(post , postart+s1-inst , poend , in , s1+1 , inend);
    return root;
}

treenode* BinaryTreefromPostandIn(vector<int> post , vector<int> in){
    return helper5(post , 0 , post.size()-1 , in , 0 , in.size()-1);
}

void traverse(treenode* root , int i , int j , map<int , map<int,multiset<int>>> &mp){
    if (root)
    {
        mp[i][j].insert(root->data);
        traverse(root->left , i-1 , j+1 , mp);
        traverse(root->right , i+1 , j+1 , mp);
    }
}

vector<vector<int>> VerticalOrderTraversal(treenode* root){
    map<int, map<int, multiset<int>>> mp;
    vector<vector<int>> ans;
    traverse(root , 0 , 0 , mp);
    for(auto it : mp){
        vector<int> col;
        for(auto it1 : it.second){
            col.insert(col.end() , it1.second.begin() , it1.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

vector<int> DiagonalTraversal(treenode* root){
    if (root == NULL)
    {
        return {};
    }
    queue<treenode*> pendingnodes;
    vector<int> ans;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        treenode* curr = pendingnodes.front();
        pendingnodes.pop();
        while (curr != NULL)
        {
            if (curr->left != NULL)
            {
                pendingnodes.push(curr->left);
            }
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }
    return ans;
}

void Inorder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout<<root->left<<" ";
    Inorder(root->right);
}

void Preorder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}

void Postorder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->data<<" ";
}

void RightViewOfBinaryTree(treenode* root){
    if (root == NULL)
    {
        return;
    }
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode* curr = pendingnodes.front();
            pendingnodes.pop();
            if (i == n-1)
            {
                cout<<curr->data<<" ";
            }
            if (curr->left != NULL)
            {
                pendingnodes.push(curr->left);
            }
            if (curr->right != NULL)
            {
                pendingnodes.push(curr->right);
            }
        }
    }
}

vector<int> CousinsofGivenNode(treenode* A, int B) {
    queue<treenode*>q;
    vector<int>v;
    if(A==NULL)
    return v;
    q.push(A);
    bool flag=false;
    while(!q.empty())
    {
        int n=q.size();
        for(int i=0;i<n;i++)
        {
            treenode* temp=q.front();
            q.pop();
            if((temp->left&&temp->left->data==B)||(temp->right&&temp->right->data==B))
            flag=true;
            else
            {
                if(temp->left)q.push(temp->left);
                if(temp->right)q.push(temp->right);
            }
        }
        if(flag)
        {
            while(!q.empty())
            {
                v.push_back(q.front()->data);
                q.pop();
            }
            return v;
        }
    }
    return v;
}

int height(treenode* root){
    if(root == NULL){
        return 0;
    }
    return 1+max(height(root->left) , height(root->right));
}
    
void noofnodesatk(treenode* root ,int k , vector<int> &v){
    if(root == NULL){
        return;
    }
    if(k == 0){
        v.push_back(root->data);
    }
    noofnodesatk(root->left , k-1 , v);
    noofnodesatk(root->right , k-1 , v);
}

vector<int> ReverseLevelOrder(treenode* A) {
    vector<int> v;
    int n = height(A);
    for(int i=n-1;i>=0;i--){
        noofnodesatk(A , i , v);
    }
    return v;
}

vector<vector<int> > zigzagLevelOrder(treenode* root) {
    vector<vector<int>> ans;
    queue<treenode*> q;
    if(root == NULL){
        return ans;
    }
    q.push(root);
    int f = 1;
    while(!q.empty()){
        vector<int> temp;
        int n = q.size();
        while(n--){
            treenode* t = q.front();
            temp.push_back(t->data);
            q.pop();
            if(t->left != NULL){
                q.push(t->left);
            }
            if(t->right != NULL){
                q.push(t->right);
            }
        }
        if(f%2 == 0){
            reverse(temp.begin() , temp.end());
        }
        ans.push_back(temp);
        f = !f;
    }
    return ans;
}

// NEXT RIGHT POINTER

int solve2(treenode* A,int B,int &curr)
{
    if(A==NULL) return 0;
    if(!A->left&&!A->right&&A->data==B) return 1000000000;
    int l=solve2(A->left,B,curr);
    int r=solve2(A->right,B,curr);
    int ans=1+max(l,r);
    curr=max(curr,max(l+r+1,ans));
    return ans;
}
int BurnaTree(treenode* A, int B) 
{
    int diameter=0;
    solve2(A,B,diameter);
    return diameter-1000000000;
}

void helper7(treenode* root, int cur_sum, int &sum){
    if(!root) return;
    if(!root->left && !root->right){
        sum+=(cur_sum%1003+root->data);
        return;
    }
    helper7(root->left, ((cur_sum+root->data)*10)%1003, sum);
    helper7(root->right, ((cur_sum+root->data)*10)%1003, sum);
}

int sumNumbers(treenode* A) {
    if(!A) return 0;
    int sum=0;
    helper7(A, 0, sum);
    return sum%1003;
}

void helper6(treenode* root , vector<int> v , vector<vector<int>> &ans){
    if (root == NULL)
    {
        return;
    }
    v.push_back(root->data);
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(v);
    }
    helper6(root->left , v , ans);
    helper6(root->right , v , ans);
}

vector<vector<int>> PathSum(treenode* root , int k){
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }
    vector<int> v;
    helper6(root , v , ans);
    vector<vector<int>> res;
    for(auto x : ans){
        int sum = 0;
        for(auto y : x){
            sum += y;
        }
        if (sum == k)
        {
            res.push_back(x);
        }
    }
    return res;
}

treenode* mirror(treenode* root){
    if (root == NULL)
    {
        return root;
    }
    treenode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    mirror(root->left);
    mirror(root->right);
}

treenode* LCA(treenode* root , int k1 , int k2){
    if (root == NULL || (root->data == k1 || root->data == k2))
    {
        return root;
    }
    treenode* l = LCA(root->left , k1 , k2);
    treenode* r = LCA(root->right , k1 , k2);
    if (l != NULL && r != NULL)
    {
        return root;
    }
    if (l == NULL && r == NULL)
    {
        return NULL;
    }
    if (l != NULL)
    {
        return LCA(root->left , k1 , k2);
    }
    return LCA(root->right , k1 , k2);
}

// FLATTEN A BINARY TREE TO LINKED LIST

int helper8(treenode* root , int k , vector<int> &ans){
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == k)
    {
        ans.push_back(root->data);
        return k;
    }
    ans.push_back(root->data);
    int a = helper8(root->left , k , ans);
    if (a != -1)
    {
        return a;
    }
    int b = helper8(root->right , k , ans);
    if (b != -1)
    {
        return b;
    }
    ans.pop_back();
    return -1;
}

vector<int> PathToGivenNode(treenode* root , int k){
    vector<int> ans;
    helper8(root , k , ans);
    return ans;
}

int main(){

}