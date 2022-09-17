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

treenode* takeinput(){
    queue<treenode*> pendingnodes;
    int rootdata;
    cin>>rootdata;
    treenode* root = new treenode(rootdata);
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        treenode* currnode = pendingnodes.front();
        pendingnodes.pop();
        cout<<"enter left child data"<<endl;
        int leftchilddata;
        cin>>leftchilddata;
        if (leftchilddata != -1)
        {
            treenode* leftchild = new treenode(leftchilddata);
            currnode->left = leftchild;
            pendingnodes.push(leftchild);
        }
        cout<<"enter right child data"<<endl;
        int rightchilddata;
        cin>>rightchilddata;
        if (rightchilddata != -1)
        {
            treenode* rightchild = new treenode(rightchilddata);
            currnode->right = rightchild;
            pendingnodes.push(rightchild);
        }
    }
    return root;
}

void inorderTraversal(treenode* root){
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left);
    cout<<root->data<<" ";
    inorderTraversal(root->right);
}

void preorderTraversal(treenode* root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(treenode* root){
    if (root == NULL)
    {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<endl;
}

void inorderIterative(treenode* root){
    stack<treenode*> st;
    treenode* curr = root;
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
            cout<<curr->data<<" ";
            curr = curr->right;
        }
    }
}

void preorderIterative(treenode* root){
    stack<treenode*> st;
    treenode* curr = root;
    while (!st.empty() || curr != NULL)
    {
        while (curr != NULL)
        {
            cout<<curr->data<<" ";
            if (curr->right != NULL)
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

void leftviewofBinaryTree(treenode* root){
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode* currnode = pendingnodes.front();
            pendingnodes.pop();
            if (i == 0)
            {
                cout<<currnode->data<<" ";
            }
            if (currnode->left != NULL)
            {
                pendingnodes.push(currnode->left);
            }
            if (currnode->right != NULL)
            {
                pendingnodes.push(currnode->right);
            }
        }
    }
}

void BottomView(treenode* root){
    queue<pair<treenode* , int>> pendingnodes;
    unordered_map<int,int> mp;
    pendingnodes.push({root , 0});
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode* currnode = pendingnodes.front().first;
            int h = pendingnodes.front().second;
            pendingnodes.pop();
            mp[h] = currnode->data;
            if (currnode->left != NULL)
            {
                pendingnodes.push({currnode->left , h-1});
            }
            if (currnode->right != NULL)
            {
                pendingnodes.push({currnode->right , h+1});
            }
        }
    }
    for(auto it : mp){
        cout<<it.second<<" ";
    }
}

void topview(treenode* root){
    queue<pair<treenode*,int>> pendingnodes;
    unordered_map<int,int> mp;
    pendingnodes.push({root , 0});
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode* currnode = pendingnodes.front().first;
            int h = pendingnodes.front().second;
            if (mp[h] == 0)
            {
                mp[h] = currnode->data;
            }
            if (currnode->left != NULL)
            {
                pendingnodes.push({currnode->left , h-1});
            }
            if (currnode->right != NULL)
            {
                pendingnodes.push({currnode->right , h+1});
            }
        }
    }
}

void AllTraversals(treenode* root , vector<int> &pre , vector<int> &in , vector<int> &post){
    stack<pair<treenode* , int>> st;
    st.push({root , 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it.first->left , 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
            {
                st.push({it.first->right , 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
}

void traverse(treenode* root , map<int,map<int,multiset<int>>> &mp , int x , int y){
    if (root != NULL)
    {
        mp[x][y].insert(root->data);
        traverse(root->left , mp , x-1 , y+1);
        traverse(root->right , mp , x+1 , y+1);
    }
}

vector<vector<int>> VerticalOrderTraversalTraversal(treenode* root){
    map<int,map<int,multiset<int>>> mp;
    traverse(root , mp , 0 , 0);
    vector<vector<int>> ans;
    for(auto it1 : mp){
        vector<int> col;
        for(auto it2 : it1.second){
            col.insert(col.end() , it2.second.begin() , it2.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}

int helper(treenode* root , int B , vector<int> &ans){
    if (root == NULL)
    {
        return -1;
    }
    if (root->data == B)
    {
        ans.push_back(root->data);
        return 1;
    }
    ans.push_back(root->data);
    int a = helper(root->left , B , ans);
    if (a != -1)
    {
        return a;
    }
    int b = helper(root->right , B , ans);
    if (b != -1)
    {
        return b;
    }
    ans.pop_back();
    return -1;
}

vector<int> PathToGivenNode(treenode* root , int B){
    vector<int> ans;
    helper(root , B , ans);
    return ans;
}

int height(treenode* root){
    if (root == NULL)
    {
        return 0;
    }
    return 1 + max(height(root->left) , height(root->right));
}

int pascaltriangle(int n){
    int arr[n][n];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == i || i == 0)
            {
                arr[i][j] = 1;
            }
            else
            {
                arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[n-1][i];
    }
    return sum;
}

int MaximumWidthofBinaryTree(treenode* root){
    int n = height(root);
    return pascaltriangle(n);
}

vector<vector<int>> LevelOrderTraversal(treenode* root){
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);
    vector<vector<int>> ans;
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            treenode* currnode = pendingnodes.front();
            pendingnodes.pop();
            v.push_back(currnode->data);
            if (currnode->left != NULL)
            {
                pendingnodes.push(currnode->left);
            }
            if (currnode->right != NULL)
            {
                pendingnodes.push(currnode->right);
            }
        }
        ans.push_back(v);
    }
    return ans;
}

int diameter(treenode* root){
    if (root == NULL)
    {
        return;
    }
    int leftdiameter = diameter(root->left);
    int rightdiameter = diameter(root->right);

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    return max(max(leftdiameter , rightdiameter) , leftheight+rightheight+1);
}

bool isBalanced(treenode* root){
    if (root == NULL)
    {
        return true;
    }
    return isBalanced(root->left) && isBalanced(root->right) && abs(height(root->left) - height(root->right)) <= 1;
}

treenode* LCA(treenode* root , int a , int b){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == a || root->data == b)
    {
        return root;
    }
    treenode* l = LCA(root->left , a , b);
    treenode* r = LCA(root->right , a , b);
    if (l && r)
    {
        return root;
    }
    return l ? l : r;
}

bool isSameTree(treenode* root1 , treenode* root2){
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    return (root1->data == root2->data) && isSameTree(root1->left , root2->left) && isSameTree(root1->right , root2->right);
}

vector<vector<int>> Zigzaglevelorder(treenode* root){
    queue<treenode*> pendingnodes;
    pendingnodes.push(root);
    bool flag = true;
    vector<vector<int>> ans;
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            treenode* currnode = pendingnodes.front();
            pendingnodes.pop();
            v.push_back(currnode->data);
            if (currnode->left != NULL)
            {
                pendingnodes.push(currnode->left);
            }
            if (currnode->right != NULL)
            {
                pendingnodes.push(currnode->right);
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

void leftnode(treenode* root , vector<int> &v){
    if (root == NULL)
    {
        return;
    }
    if (root->left)
    {
        v.push_back(root->data);
        leftnode(root->left , v);
    }
    else if (root->right)
    {
        v.push_back(root->data);
        leftnode(root->right , v);
    }
}

void rightnode(treenode* root , vector<int> &v){
    if (root == NULL)
    {
        return;
    }
    if (root->right != NULL)
    {
        rightnode(root->right , v);
        v.push_back(root->data);
    }
    else if (root->left)
    {
        rightnode(root->left , v);
        v.push_back(root->data);
    }
}

void leafnodes(treenode* root , vector<int> &v){
    if (root == NULL)
    {
        return;
    }
    leafnodes(root->left , v);
    if (root->left == NULL && root->right == NULL)
    {
        v.push_back(root->data);
        return;
    }
    leafnodes(root->right , v);
}

vector<int> BoundaryTraversal(treenode* root){
    vector<int> v;
    v.push_back(root->data);
    leftnode(root->left , v);
    leafnodes(root , v);
    rightnode(root->right , v);
    return v;
}

int helperpathsum(treenode* root , int &ans){
    if (root == NULL)
    {
        return 0;
    }
    int leftsum = root->data + helperpathsum(root->left , ans);
    int rightsum = root->data + helperpathsum(root->right , ans);

    ans = max({ans , root->data , leftsum , rightsum , leftsum+rightsum-root->data});

    return max({leftsum , rightsum , root->data});
}

int maxPathSum(treenode* root){
    int ans = INT_MIN;
    helperpathsum(root , ans);
    return ans;
}

treenode* helperbuild(vector<int> &pre , vector<int> &in , int inst , int inend , int &preindex){
    if (inst > inend)
    {
        return NULL;
    }
    int index = inst;
    while (in[index] != pre[preindex])
    {
        index++;
    }
    preindex++;
    treenode* newnode = new treenode(in[index]);
    newnode->left = helperbuild(pre , in , inst , index-1 , preindex);
    newnode->right = helperbuild(pre , in , index+1 , inend , preindex);
    return newnode;
}

treenode* buildtree(vector<int> &preorder , vector<int> &inorder){
    int preindex = 0;
    return helperbuild(preorder , inorder , 0 , inorder.size()-1 , preindex);
}

treenode* helperposttree(vector<int> &in , int inst , int inend , vector<int> &postorder , int post , int poend){
    if (inst > inend && post > poend)
    {
        return NULL;
    }
    treenode* newnode = new treenode(postorder[post]);
    int x = inst;
    while (newnode->data != in[x])
    {
        x++;
    }
    newnode->left = helperposttree(in , inst , x-1 , postorder , post , post+x-inst-1);
    newnode->right = helperposttree(in , x+1 , inend , postorder , post+x-inst , poend-1);
    return newnode;
}

treenode* buildtreepost(vector<int> &postorder , vector<int> &inorder){
    int n = inorder.size();
    return helperposttree(inorder , 0 , n-1 , postorder , 0 , n-1);
}

bool symhelper(treenode* root1 , treenode* root2){
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    return (root1->data == root2->data) && symhelper(root1->left , root2->right) && symhelper(root1->right , root2->left);
}

bool isSymetric(treenode* root){
    if (root == NULL)
    {
        return true;
    }
    return symhelper(root->left , root->right);
}

void FlattenBinaryTree(treenode* root){
    while (root != NULL)
    {
        if (root->left != NULL && root->right != NULL)
        {
            treenode* t = root->left;
            while (t->right != NULL)
            {
                t = t->right;
            }
            t->right = root->right;
        }
        else if (root->left != NULL)
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

bool check(treenode* root1 , treenode* root2){
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL || root2 == NULL)
    {
        return false;
    }
    return (root1->data == root2->data) && check(root1->left , root2->right) && check(root1->right , root2->left);
}

void ChildrenSumtree(treenode* root){
    if (root == NULL) return;
    int child = 0;
    if (root -> left) {
        child += root -> left -> data;
    }
    if (root -> right) {
        child += root -> right -> data;
    }

    if (child < root -> data) {
        if (root -> left) root -> left -> data = root -> data;
        else if (root -> right) root -> right -> data = root -> data;
    }

    ChildrenSumtree(root -> left);
    ChildrenSumtree(root -> right);

    int tot = 0;
    if (root -> left) tot += root -> left -> data;
    if (root -> right) tot += root -> right -> data;
    if (root -> left || root -> right) root -> data = tot;
}

//----> POPULATING NEXT RIGHT POINTER

treenode* searchinBST(treenode* root , int key){
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data = key)
    {
        return root;
    }
    if (root->data > key)
    {
        return searchinBST(root->left , key);
    }
    if (root->data < key)
    {
        return searchinBST(root->right , key);
    }
}

treenode* BSThelper(int arr[] , int i , int j){
    if (i > j)
    {
        return NULL;
    }
    int mid = (i+j)/2;
    treenode* newnode = new treenode(arr[mid]);
    newnode->left = BSThelper(arr , i , mid-1);
    newnode->right = BSThelper(arr , mid+1 , j);
    return newnode;
}

treenode* sortedArrtoBST(int arr[] , int n){
    int i = 0;
    int j = n-1;
    return BSThelper(arr , i , j);
}

treenode* BSTprehelper(int preorder[] , int &i , int n , int maxi){
    if (i == n || preorder[i] > maxi)
    {
        return NULL;
    }
    treenode* root = new treenode(preorder[i++]);
    root->left = BSTprehelper(preorder , i , n , root->data);
    root->right = BSTprehelper(preorder , i , n , maxi);
    return root;
}

treenode* BSTfrompreorder(int preorder[] , int n){
    int i = 0;
    return BSTprehelper(preorder , i , n , INT_MAX);
}

bool isBST(treenode* root , int mini , int maxi){
    if (root == NULL)
    {
        return true;
    }
    if (root->data <= mini || root->data >= maxi)
    {
        return false;
    }
    bool leftBST = isBST(root->left , mini , root->data);
    bool rightBST = isBST(root->right , root->data , maxi);

    return leftBST && rightBST;
}

treenode* LCAinBST(treenode* root , int p , int q){
    int small = min(p , q);
    int large = max(p , q);

    while (root != NULL)
    {
        if (root->data > large)
        {
            root = root->left;
        }
        else if (root->data < small)
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

void pre_and_succ(treenode* root , int &pre , int &suc , int key){
    if (root == NULL)
    {
        return;
    }
    if (root->data == key)
    {
        if (root->left)
        {
            auto tmp = root->left;
            while (tmp->right)
            {
                tmp = tmp->right;
            }
            pre = tmp->data;
        }
        if (root->right)
        {
            auto tmp = root->right;
            while (tmp->left)
            {
                tmp = tmp->left;
            }
            suc = tmp->data;
        }
    }
    else if (root->data < key)
    {
        pre = root->data;
        pre_and_succ(root->right , pre , suc , key);
    }
    else
    {
        suc = root->data;
        pre_and_succ(root->left , pre , suc , key);
    }
}

int floor(treenode* root , int key){
    if (root == NULL)
    {
        return INT_MAX;
    }
    if (root->data == key)
    {
        return root->data;
    }
    if (root->data > key)
    {
        return floor(root->left , key);
    }
    
    int floorval = floor(root->right , key);
    return (floorval <= key) ? floorval : root->data;
}

int helperceilBST(treenode* root , int key , int ans){
    if (root == NULL)
    {
        return ans;
    }
    if(root->data > key){
        ans = root->data;
        helperceilBST(root->left , key , ans);
    }
    else if(root->data < key){
        helperceilBST(root->right , key , ans);
    }
    else{
        return key;
    }
}

int ceilBST(treenode* root , int key){
    if (root == NULL)
    {
        return -1;
    }
    return helperceilBST(root , key , root->data);
}

void helperkthsmallest(treenode* root , vector<int> &ans){
    if (root == NULL)
    {
        return;
    }
    helperkthsmallest(root->left , ans);
    ans.push_back(root->data);
    helperkthsmallest(root->right , ans);
}

int kthsmallest(treenode* root , int k){
    vector<int> ans;
    helperkthsmallest(root , ans);
    return ans[k-1];
}

int kthlargest(treenode* root , int k){
    vector<int> ans;
    helperkthsmallest(root , ans);
    return ans[ans.size()-k];
}

bool pairwithgivensum(treenode* root , int sum){
    vector<int> ans;
    helperkthsmallest(root , ans);
    int i = 0 , j = ans.size()-1;
    while (i < j)
    {
        if (ans[i] + ans[j] < sum)
        {
            i++;
        }
        else if (ans[i]+ans[j] > sum)
        {
            j--;
        }
        else
        {
            return true;
        }
    }
    return false;
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

vector<int> traverseSumBST(treenode* root , int &ans){
    if (!root)
    {
        return {INT_MAX , INT_MIN , 0};
    }
    vector<int> left(traverseSumBST(root->left , ans));
    vector<int> right(traverseSumBST(root->right , ans));

    if (left.empty() || right.empty() || root->data <= left[1] || root->data >= right[0])
    {
        return {};
    }
    int currsum = left[2] + right[2] + root->data;
    ans = max(ans , currsum);
    return {min(left[0] , root->data) , max(right[1] , root->data) , currsum};
}

int maxsumBST(treenode* root){
    int ans = 0;
    traverseSumBST(root , ans);
    return ans;
}

class Codec {
public:
    string serialize(treenode* root) {
        if (root == nullptr) return "#";
        return to_string(root->data)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    treenode* deserialize(string data) {
        return mydeserialize(data);
    }
    treenode* mydeserialize(string& data) {
        if (data[0]=='#') {
            if(data.size() > 1) data = data.substr(2);
            return nullptr;
        } else {
            treenode* node = new treenode(helper(data));
            node->left = mydeserialize(data);
            node->right = mydeserialize(data);
            return node;
        }
    }
private:
    int helper(string& data) {
        int pos = data.find(',');
        int val = stoi(data.substr(0,pos));
        data = data.substr(pos+1);
        return val;
    }
};

void dfs(vector<vector<int>>& image, int i, int j , int val, int newColor){
    if(i<0 || i>=image.size() || j<0 || j>= image[0].size() || image[i][j] == newColor || image[i][j] != val)
    {
        return;
    }
    image[i][j] = newColor;
    dfs(image,i-1,j,val,newColor);
    dfs(image,i+1,j,val,newColor);
    dfs(image,i,j-1,val,newColor);
    dfs(image,i,j+1,val,newColor);
}

vector<vector<int>> Floodfill(vector<vector<int>>& image, int sr, int sc, int newColor){
    int val = image[sr][sc];
    dfs(image , sr , sc , val , newColor);
    return image;
}

int main(){

}