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

treenode* TakeInput(){
    queue<treenode*> pendingnodes;
    int rootdata;
    cin>>rootdata;
    treenode* root = new treenode(rootdata);
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        treenode* curr = pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter left child data"<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if (leftchilddata != -1)
        {
            treenode* leftchild = new treenode(leftchilddata);
            curr->left = leftchild;
            pendingnodes.push(leftchild);
        }
        cout<<"enter right child data"<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if (rightchilddata != -1)
        {
            treenode* rightchild = new treenode(rightchilddata);
            curr->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}

void LevelOrderTraversal(treenode* root){
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode* curr = pendingnodes.front();
            pendingnodes.pop();
            cout<<curr->data<<" ";
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

void helper(treenode* root , vector<int> &ans , queue<treenode*> &pendingnodes){
    if (pendingnodes.empty())
    {
        return;
    }
    treenode* curr = pendingnodes.front();
    pendingnodes.pop();
    if (curr->left)
    {
        pendingnodes.push(curr->left);
    }
    if (curr->right)
    {
        pendingnodes.push(curr->right);
    }
    helper(root , ans , pendingnodes);
    ans.push_back(curr->data);
}

vector<int> ReverseLevelOrder(treenode* root){
    if (root == NULL)
    {
        return {};
    }
    queue<treenode*> pendingnodes;
    vector<int> ans;
    pendingnodes.push(root);
    helper(root , ans , pendingnodes);
    return ans;
}

int heightTree(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(heightTree(root->left) , heightTree(root->right));
}

int diameter(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    int leftdiameter = diameter(root->left);
    int rightdiameter = diameter(root->right);

    int leftheight = heightTree(root->left);
    int rightheight = heightTree(root->right);

    return max(max(leftdiameter , rightdiameter) , leftheight+rightheight+1);
}

void Mirror(treenode* root){
    if (root == NULL)
    {
        return;
    }
    treenode* tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    Mirror(root->left);
    Mirror(root->right);
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

void InorderItr(treenode* root){
    stack<treenode*> st;
    treenode* curr = root;
    while (!st.empty() && curr != NULL)
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
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }
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

void Preorderitr(treenode* root){
    stack<treenode*> st;
    st.push(root);
    while (!st.empty())
    {
        treenode* curr = st.top();
        st.pop();
        cout<<curr->data<<" ";
        if (curr->right)
        {
            st.push(curr->right);
        }
        if (curr->left)
        {
            st.push(curr->left);
        }
    }
}

void PostOrder(treenode* root){
    if (root == NULL)
    {
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

vector<int> LeftView(treenode* root){
    if (root == NULL)
    {
        return {};
    }
    vector<int> ans;
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode* curr = pendingnodes.front();
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

vector<int> RightView(treenode* root){
    if (root == NULL)
    {
        return {};
    }
    vector<int> ans;
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

vector<int> TopView(treenode* root){
    queue<pair<treenode* , int>> pendingnodes;
    pendingnodes.push({root , 0});
    map<int,int> mp;
    while (!pendingnodes.empty())
    {
        treenode* curr = pendingnodes.front().first;
        int h = pendingnodes.front().second;
        pendingnodes.pop();
        if (mp[h] == 0)
        {
            mp[h] = curr->data;
        }
        if (curr->left)
        {
            pendingnodes.push({curr , h-1});
        }
        if (curr->right)
        {
            pendingnodes.push({curr , h+1});
        }
    }
    vector<int> ans;
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

vector<int> BottomView(treenode* root){
    queue<pair<treenode* , int>> pendingnodes;
    pendingnodes.push({root , 0});
    map<int,int> mp;
    while (!pendingnodes.empty())
    {
        treenode* curr = pendingnodes.front().first;
        int h = pendingnodes.front().second;
        pendingnodes.pop();
        mp[h] = curr->data;
        if (curr->left)
        {
            pendingnodes.push({curr->left , h-1});
        }
        if (curr->right)
        {
            pendingnodes.push({curr->right , h+1});
        }
    }
    vector<int> ans;
    for(auto it : mp){
        ans.push_back(it.second);
    }
    return ans;
}

vector<vector<int>> ZigZagLevelOrder(treenode* root){
    queue<treenode*> pendingnodes;
    vector<vector<int>> ans;
    pendingnodes.push(root);
    bool flag = false;
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
        if (flag)
        {
            reverse(v.begin() , v.end());
        }
        flag = !flag;
    }
    return ans;
}

bool IsBalanced(treenode* root){
    if (root == NULL)
    {
        return true;
    }
    int lh = heightTree(root->left);
    int rh = heightTree(root->right);

    return abs(lh - rh) <= 1 && IsBalanced(root->left) && IsBalanced(root->right);
}

vector<int> DiagonalTraversal(treenode* root){
    queue<treenode*> q;
    q.push(root);
    vector<int> ans;
    while (!q.empty())
    {
        treenode* curr = q.front();
        q.pop();
        while (curr)
        {
            if (curr->left != NULL)
            {
                q.push(curr->left);
            }
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }
    return ans;
}

void left1(treenode* root , vector<int> &v){
    if(root == NULL){
        return;
    }
    if(root->left){
        v.push_back(root->data);
        left1(root->left , v);
    }
    else if(root->right){
        v.push_back(root->data);
        left1(root->right , v);
    }
}
    
void leafnodes(treenode* root , vector<int> &v){
    if(root == NULL){
        return;
    }
        
    leafnodes(root->left , v);
        
    if(root->left == NULL && root->right == NULL){
        v.push_back(root->data);
        return;
    }
    
    leafnodes(root->right , v);
}
    
void right1(treenode* root , vector<int> &v){
    if(root == NULL){
        return;
    }
    if(root->right){
        right1(root->right , v);
        v.push_back(root->data);
    }
    else if(root->left){
        right1(root->left , v);
        v.push_back(root->data);
    }
}
    
vector <int> boundary(treenode *root)
{
    vector<int> v;
    v.push_back(root->data);
    left1(root->left , v);
    leafnodes(root , v);
    right1(root->right , v);
    return v;
}

treenode* solve(string s, int& idx){
    if (idx >= s.size())
        return NULL;
    string num = "";
    while (idx < s.size() && s[idx] != '(' && s[idx] != ')') {
        num += s[idx];
        idx++;
    }
    treenode* node = new treenode(stoi(num));
    if (idx < s.size() && s[idx] == '(') {
        idx++;
        node->left = solve(s, idx);
        idx++;
        if (idx < s.size() && s[idx] == '(') {
            idx++;
            node->right = solve(s, idx);
            idx++;
        }
    }
    return node;
}

treenode* str2tree(string s) {
    int idx = 0;
    treenode* temp = new treenode(-1);
    return solve(s, idx);
}

treenode* prev1 = NULL;
treenode* head1 = NULL;
treenode* BinaryTreeToDLL(treenode* root){
    if (root == NULL)
    {
        return NULL;
    }
    BinaryTreeToDLL(root->left);
    if (prev1)
    {
        root->left = prev1;
        prev1->right = root;
        prev1 = prev1->right;
    }
    if (!head1)
    {
        head1 = prev1 = root;
    }
    BinaryTreeToDLL(root->right);
}

int helper3(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    int ov = root->data;
    root->data = helper3(root->left)+helper3(root->right);
    return root->data+ov;
}

void TransformToTree(treenode* root){
    helper3(root);
}

treenode* helper2(int in[] , int es , int ee , int pre[] , int &ps){
    if (es > ee)
    {
        return NULL;
    }
    int ind = es;
    while (in[ind] != pre[ps])
    {
        ind++;
    }
    ps++;
    treenode* root = new treenode(in[ind]);
    root->left = helper2(in , es , ind-1 , pre , ps);
    root->right = helper2(in , ind+1 , ee , pre , ps);
    return root;
}

treenode* BuildTree(int in[] , int pre[] , int n){
    int ps = 0;
    return helper2(in , 0 , n-1 , pre , ps);
}

int minswaps(treenode* root){
    vector<int> v;
    Inorder(root , v);
    vector<pair<int,int>> t;
    for (int i = 0; i < v.size(); i++)
    {
        t[i].first = v[i];
        t[i].second = i;
    }
    sort(t.begin() , t.end());
    int ans = 0;
    for (int i = 0; i < t.size(); i++)
    {
        if (i == t[i].second)
        {
            continue;
        }
        else
        {
            swap(t[i].first , t[t[i].second].first);
            swap(t[i].second , t[t[i].second].second);
        }
        if (i != t[i].second)
        {
            i--;
        }
        ans++;
    }
    return ans;
}

int sum(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return sum(root->left) + root->data + sum(root->right);
}

bool isSumTree(treenode* root){
    if (root == NULL)
    {
        return true;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    int ls = sum(root->left);
    int rs = sum(root->right);

    if ((root->data == ls+rs) && isSumTree(root->left) && isSumTree(root->right))
    {
        return 1;
    }
    return 0;
}

void trev(treenode* root ,int level,set<int>&s){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right== NULL){
        s.insert(level);
    }
      
    trev(root->left,level+1,s);
    trev(root->right,level+1,s);
}

bool check(treenode *root)
{
    set<int>s;
    trev(root,0,s);
    bool ans=false;
    if(s.size()==1){
        ans= true;
    }
    return ans;
}

string solve(treenode* root , unordered_map<string , int> &mp){
    if (root == NULL)
    {
        return "$";
    }
    string s = "";
    if (root->left == NULL && root->right == NULL)
    {
        s = to_string(root->data);
        return s;
    }
    s = s+to_string(root->data);
    s = s+solve(root->left , mp);
    s = s+solve(root->right , mp);
    mp[s]++;
    return s;
}
    
int dupSub(treenode *root) {
    unordered_map<string , int> mp;
    solve(root , mp);
    for(auto it : mp){
        if (it.second >= 2)
        {
            return true;
        }
    }
    return false;
}

int helper4(treenode* root , int &ans){
    if (root == NULL)
    {
        return 0;
    }
    int currsum = root->data + helper4(root->left , ans) + helper4(root->right , ans);
    ans = max(ans , currsum);
    return currsum;
}

int FindLargestSubtreeSum(treenode* root){
    if(root == NULL){
        return 0;
    }
    int ans = INT_MIN;
    helper4(root , ans);
    return ans;
}

int msum(treenode *root , unordered_map<treenode* , int> mp)
{
    if(!root) return 0;
    if(mp.count(root)) return mp[root];
    int x = root->data;
    if(root->left)
    {
        if(root->left->left) x=x+msum(root->left->left , mp);
        if(root->left->right) x=x+msum(root->left->right , mp);
    }
    if(root->right)
    {
        if(root->right->left) x=x+msum(root->right->left , mp);
        if(root->right->right) x=x+msum(root->right->right , mp);
    }   
    int y=0;
    if(root->left) y=y+msum(root->left , mp);
    if(root->right) y=y+msum(root->right , mp);
    return  mp[root]=max(x,y);
}

int getMaxSum(treenode *root) 
{
    unordered_map<treenode* , int> mp;
    return msum(root , mp); 
}

void helper5(treenode* root , vector<int> &path , int k){
    if (root == NULL)
    {
        return;
    }
    path.push_back(root->data);
    helper5(root->left , path , k);
    helper5(root->right , path , k);
    int a = 0;
    for (int j = path.size(); j >= 0; j--)
    {
        a += path[j];
        if (a == k)
        {
            for (int i = j; i < path.size(); i++)
            {
                cout<<path[i]<<" ";
            }
            cout<<endl;
        }
    }
    path.pop_back();
}

void Printpathwithsumk(treenode* root , int k){
    vector<int> path;
    helper5(root , path , k);
}

treenode* LCA(treenode* root , int n1 , int n2){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == n1 || root->data == n2)
    {
        return root;
    }
    treenode* l = LCA(root->left , n1 , n2);
    treenode* r = LCA(root->right , n1 , n2);
    if (l != NULL && r != NULL)
    {
        return root;
    }
    if (l == NULL && r == NULL)
    {
        return NULL;
    }
    if (l == NULL)
    {
        return LCA(root->right , n1 , n2);
    }
    return LCA(root->left , n1 , n2);
}

int distance(treenode* root , int a , int b){
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == a)
    {
        return b;
    }
    int l = distance(root->left , a , b+1);
    if (l != -1)
    {
        return l;
    }
    return distance(root->right , a , b+1);
}

int FindDistancebtw2(treenode* root , int n1 , int n2){
    treenode* m = LCA(root , n1 , n2);
    return distance(m , n1 , 0) + distance(m , n2 , 0);
}

treenode* temp = NULL;
treenode* kthAncestorDFS(treenode *root, int node , int &k)
{ 
    if (!root)
        return NULL;
     
    if (root->data == node|| (temp =  kthAncestorDFS(root->left,node,k)) || (temp =  kthAncestorDFS(root->right,node,k)))
    {  
        if (k > 0)       
            k--;
         
        else if (k == 0)
        {
            cout<<"Kth ancestor is: "<<root->data;
            return NULL;
        }
        return root;
    }
}

bool isIsomorphic(treenode *root1,treenode *root2)
{
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    if(root1->data != root2->data){
        return false;
    }
    treenode* l1 = root1->left ? root1->left : NULL;
    treenode* r1 = root1->right ? root1->right : NULL;
    treenode* l2 = root2->left ? root2->left : NULL;
    treenode* r2 = root2->right ? root2->right : NULL;
    return (isIsomorphic(l1 , l2) && isIsomorphic(r1 , r2)) || (isIsomorphic(l1 , r2) && isIsomorphic(r1 , l2));
}

int main(){

}