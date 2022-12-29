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

vector<int> getInorderTraversal(treenode *root)
{
    vector<int> v;
    helper(root, v);
    return v;
}

void helper1(treenode *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    v.push_back(root->data);
    helper1(root->left, v);
    helper1(root->right, v);
}

vector<int> getPreorderTraversal(treenode *root)
{
    vector<int> v;
    helper1(root, v);
    return v;
}

void helper2(treenode *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    helper2(root->left, v);
    helper2(root->right, v);
    v.push_back(root->data);
}

vector<int> getPostorderTraversal(treenode *root)
{
    vector<int> v;
    helper2(root, v);
    return v;
}

vector<int> getLevelOrderTraversal(treenode *root)
{
    queue<treenode *> pendingnodes;
    pendingnodes.push(root);
    vector<int> v;
    while (!pendingnodes.empty())
    {
        int n = pendingnodes.size();
        for (int i = 0; i < n; i++)
        {
            treenode *currnode = pendingnodes.front();
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
    }
    return v;
}

bool areIdenticalTrees(treenode* root1, treenode* root2) {
	if(root1 == NULL && root2 == NULL){
		return true;
	}
	if(root1 == NULL || root2 == NULL){
		return false;
	}
	if(root1->data != root2->data){
		return false;
	}
	return areIdenticalTrees(root1->left , root2->left) && areIdenticalTrees(root1->right , root2->right);
}

bool helper3(treenode* r1 , treenode* r2){
	if(!r1 && !r2){
		return true;
	}
	if(!r1 || !r2){
		return false;
	}
	return (r1->data == r2->data) && helper3(r1->left , r2->right) && helper3(r1->right , r2->left);
}

bool isSymmetric(treenode* root) {
	if(root == NULL){
		return true;
	}
	return helper3(root->left , root->right);
}

int getMaxDepth(treenode* root) {
	if(root == NULL){
		return 0;
	}
	return max(getMaxDepth(root->left) , getMaxDepth(root->right)) + 1;
}

int rec(treenode* root, int &d) {
    if(root == NULL) return 0;
    int ld = rec(root->left, d);
    int rd = rec(root->right, d);
    d=max(d,ld+rd);
    return max(ld,rd)+1;
}

int getDiameter(treenode* root) {
	int d = 0;
	rec(root , d);
	return d;
}

void invertTree(treenode* root) {
	if(root == NULL){
		return;
	}
	treenode* temp = root->left;
	root->left = root->right;
	root->right = temp;
	invertTree(root->left);
	invertTree(root->right);
}

bool isBinaryTreeBalanced(treenode* root) {
	if(root == NULL){
		return true;
	}
	int lh = getMaxDepth(root->left);
	int rh = getMaxDepth(root->right);
	return abs(lh - rh) <= 1 && isBinaryTreeBalanced(root->left) && isBinaryTreeBalanced(root->right);
}

vector<int> ZigZagOrderTraversal(treenode* root){
    if (root == NULL)
    {
        return {};
    }
    queue<treenode*> pendingnodes;
    vector<int> ans;
    pendingnodes.push(root);
    ans.push_back(root->data);
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
        if (flag)
        {
            reverse(v.begin() , v.end());
        }
        flag = !flag;
        for (int i = 0; i < v.size(); i++)
        {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

treenode* helper5(vector<int> &pre , vector<int> &in , int inst , int inend , int &prest){
	if(inst > inend){
		return NULL;
	}
	int ind = inst;
	while(in[ind] != pre[prest]){
		ind++;
	}
	treenode* root = new treenode(in[ind]);
	prest++;
	root->left = helper5(pre , in , inst , ind-1 , prest);
	root->right = helper5(pre , in , ind+1 , inend , prest);
	return root;
}

treenode* constructTreefrompreandin(vector<int> &preorder, vector<int> &inorder) {
	int n = inorder.size();
	int t = 0;
	return helper5(preorder , inorder , 0 , n-1 , t);
}

treenode* helper6(vector<int> &in , int s1 , int s2 , vector<int> &post , int p1 , int p2){
	if(s1 > s2 || p1 > p2){
		return NULL;
	}
	treenode* newnode = new treenode(post[p2]);
	int x = s1;
	while(newnode->data != in[x]){
		x++;
	}
	newnode->left = helper6(in , s1 , x-1 , post , p1 , p1+x-s1-1);
	newnode->right = helper6(in , x+1 , s2 , post , p1+x-s1 , p2-1);
	return newnode;
}

treenode* constructTree(vector<int> &postorder, vector<int> &inorder) {
	return helper6(inorder , 0 , inorder.size()-1 , postorder , 0 , postorder.size() -1);
}

vector<int> leftView(treenode* root) {
	vector<int> v;
	queue<treenode*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		int n = pendingnodes.size();
		for(int i=0;i<n;i++){
			treenode* currnode = pendingnodes.front();
			pendingnodes.pop();
			if(i == 0){
				v.push_back(currnode->data);
			}
			if(currnode->left != NULL){
				pendingnodes.push(currnode->left);
			}
			if(currnode->right != NULL){
				pendingnodes.push(currnode->right);
			}
		}
	}
	return v;
}

vector<int> rightView(treenode* root) {
	vector<int> v;
	queue<treenode*> pendingnodes;
	pendingnodes.push(root);
	while(!pendingnodes.empty()){
		int n = pendingnodes.size();
		for(int i=0;i<n;i++){
			treenode* currnode = pendingnodes.front();
			pendingnodes.pop();
			if(i == n-1){
				v.push_back(currnode->data);
			}
			if(currnode->left != NULL){
				pendingnodes.push(currnode->left);
			}
			if(currnode->right != NULL){
				pendingnodes.push(currnode->right);
			}
		}
	}
	return v;
}

vector<int> topView(treenode* root) {
	map<int, int> mp;
	queue<pair<treenode* , int>> q;
	q.push({root , 0});
	while(!q.empty()){
		treenode* curr = q.front().first;
		int h = q.front().second;
		q.pop();
		if(mp[h] == 0){
			mp[h] = curr->data;
		}
		if(curr->left != NULL){
			q.push({curr->left , h-1});
		}
		if(curr->right != NULL){
			q.push({curr->right , h+1});
		}
	}
	vector<int> ans;
	for(auto it : mp){
		ans.push_back(it.second);
	}
	return ans;
}

vector<int> bottomView(treenode* root) {
	map<int, int> mp;
	queue<pair<treenode* , int>> q;
	q.push({root , 0});
	while(!q.empty()){
		treenode* curr = q.front().first;
		int h = q.front().second;
		q.pop();
		mp[h] = curr->data;
		if(curr->left != NULL){
			q.push({curr->left , h-1});
		}
		if(curr->right != NULL){
			q.push({curr->right , h+1});
		}
	}
	vector<int> ans;
	for(auto it : mp){
		ans.push_back(it.second);
	}
	return ans;
}

treenode* lowestCommonAncestor(treenode* root, treenode* p, treenode* q) {
	if (!root || !p || !q) {
        return NULL;
    }
    
    if (root == p || root == q) {
        return root;
    }
    
    treenode* l = lowestCommonAncestor(root->left, p, q);
    treenode* r = lowestCommonAncestor(root->right, p, q);
    
    if (l && r) {
        return root;
    }
    
    return l? l : r;
}

void flatten(treenode* root) {
	while(root != NULL){
		if(root->left != NULL && root->right != NULL){
			treenode* t = root->left;
			while(t->right != NULL){
				t = t->right;
			}
			t->right = root->right;
		}
		if(root->left != NULL){
			root->right = root->left;
		}
		root->left = NULL;
		root = root->right;
	}
}

int helper7(treenode* root , int &ans){
	if(root == NULL){
		return 0;
	}
	int lsum = root->data + helper7(root->left , ans);
	int rsum = root->data + helper7(root->right , ans);
	ans = max({ans , lsum , rsum , lsum+rsum-root->data , root->data});
	return max({lsum , rsum , root->data});
}

int maxPathSum(treenode *root) {
	int ans = INT_MIN;
	helper7(root , ans);
	return ans;
}

int main()
{
}