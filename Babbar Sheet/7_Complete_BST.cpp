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

bool FindValue(treenode* root , int key){
    if (root == NULL)
    {
        return false;
    }
    if (root->data == key)
    {
        return true;
    }
    if (root->data < key)
    {
        return FindValue(root->right , key);
    }
    return FindValue(root->left , key);
}

treenode* DeleteNode(treenode* root , int key){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        if (root->right == NULL)
        {
            treenode* tmp = root->left;
            delete root;
            return tmp;
        }
        else
        {
            treenode* r = root->right;
            while (r->left)
            {
                r = r->left;
            }
            swap(r->data , root->data);
        }
    }
    root->left = DeleteNode(root->left , key);
    root->right = DeleteNode(root->right , key);
    return root;
}

int MinElement(treenode* root){
    if (root == NULL)
    {
        return -1;
    }
    int mini = INT_MAX;
    while (root->left != NULL)
    {
        root = root->left;
    }
    return min(mini , root->data);
}

void findPreSuc(treenode* root, treenode*& pre, treenode*& suc, int key)
{
    if(!root) return;
    if(root->data == key){
        if(root->left){
            auto temp = root->left;
            while(temp->right){
                temp = temp->right;
            }
            pre = temp;
        }
        
        if(root->right){
            auto temp = root->right;
            while(temp->left){
                temp = temp->left;
            }
            suc = temp;
        }
    }
    
    else if(root->data < key){
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else{
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
}

bool helper(treenode* root , int mini , int maxi){
    if (root == NULL)
    {
        return true;
    }
    if (root->data < mini || root->data > maxi)
    {
        return false;
    }
    return helper(root->left , mini , root->data) && helper(root->right , root->data , maxi);
}

bool isBst(treenode* root){
    return helper(root , INT_MIN , INT_MAX);
}

// Populate Inorder Successor for all nodes : https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

treenode* LCA(treenode* root , int n1 , int n2){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data > n1 && root->data > n2)
    {
        return LCA(root->left , n1 , n2);
    }
    else if (root->data < n1 && root->data < n2)
    {
        return LCA(root->right , n1 , n2);
    }
    return root;
}

treenode* helper1(int pre[] , int &preindex , int mini , int maxi , int n){
    if (preindex >= n)
    {
        return NULL;
    }
    treenode* root = NULL;
    int a = pre[preindex];
    if (a > mini && a < maxi)
    {
        root = new treenode(a);
        preindex++;

        if (preindex < n)
        {
            root->left = helper1(pre , preindex , mini , a , n);
        }
        if (preindex < n)
        {
            root->right = helper1(pre , preindex , a , maxi , n);
        }
    }
    return root;
}

treenode* ConstructBSTfromPreorder(int pre[] , int n){
    int preindex = 0;
    return helper1(pre , preindex , INT_MIN , INT_MAX , n);
}

void Inorder(treenode* root , vector<int> &v){
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left , v);
    v.push_back(root->data);
    Inorder(root->right , v);
}

treenode* helper2(vector<int> v , int i , int j){
    if (i > j)
    {
        return NULL;
    }
    int mid = (i+j)/2;
    treenode* root = new treenode(v[mid]);
    root->left = helper2(v , i , mid-1);
    root->right = helper2(v , mid+1 , j);
    return root;
}

treenode* ConvertBTtoBST(treenode* root){
    vector<int> v;
    Inorder(root , v);
    sort(v.begin() , v.end());
    return helper2(v , 0 , v.size()-1);
}

treenode* BuildBalncedBST(treenode* root){
    vector<int> v;
    Inorder(root , v);
    return helper2(v , 0 , v.size()-1);
}

// --- merge 2bst---1 using vectors , second without space using Linked list 

void bstTodll(treenode* root, treenode*& head)
{
    if (!root)
        return;
    bstTodll(root->right, head);
    root->right = head;
 
    if (head) {
        head->left = root;
    }
    head = root;
    bstTodll(root->left, head);
}

int KthLargestandSmallest(treenode* root){
    vector<int> v;
    Inorder(root , v);
    return v[v.size()-1]; // for smallest v[0];
}

void inorder(treenode* root , map<int,int> &m){
    if(!root)return;
    inorder(root->left,m);
    m[root->data]++;
    inorder(root->right,m);
}

int countPairs(treenode* root1, treenode* root2, int x)
{
    map<int,int> m,p;
    inorder(root1,m);
    inorder(root2,p);
    int c=0;
    for(auto it:m){
        int y=x-it.first;
        if(p[y]>0)c++;
    }
    return c;
}

void fun(treenode *root,int x,int &count,int &res)
{
    if(root==NULL) return;
    fun(root->left,x,count,res);
    count++;
    if(count==x) res=root->data;
    fun(root->right,x,count,res);
}

int size(treenode *root)
{
    if(root==NULL) return 0;
    else return 1+size(root->left)+size(root->right);
}

float findMedian(treenode *root)
{
    int n=size(root);
    int res=-1,count=0;
    if(n%2==1)
    {
        fun(root,n/2+1,count,res);
        return res;
    }
    else 
    {
        fun(root,n/2,count,res);
        int n1=res;
        res=-1;count=0;
        fun(root,n/2+1,count,res);
        int n2=res;
        return float(n1+n2)/2;
    }
}

void PostOrder(treenode* root , int l , int r , int &c){
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left , l , r , c);
    PostOrder(root->right , l , r , c);
    if (root->data > l && root->data < r)
    {
        c++;
    }
}

int CountNodesInRange(treenode* root , int l , int r){
    int c = 0;
    PostOrder(root , l , r , c);
    return c;
}

vector<int> findLeastGreater(vector<int>& arr, int n) {
    set <int> s;
    for(int i = n-1;i >= 0;i--){
        auto it = s.upper_bound(arr[i]);
        s.insert(arr[i]);
        arr[i] = it != s.end()?*it:-1;
    }
    return arr;
}

//----Largest BST in BT
//----Flatten BST in LL

int main(){

}