#include<bits/stdc++.h>
using namespace std;

class trienode{
    public:
    int data;
    unordered_map<char , trienode*> children;
    bool isterminating;
    bool isroot;
    
    trienode(int data){
        this->data = data;
        isterminating = false;
        isroot = false;
    }
};

class Trie {
    trienode* root;
    int count;
public:
    Trie() {
        root = new trienode(' ');
        root->isroot = true;
        count = 0;
    }
    void insertwordhelper(string word , trienode* root){
        if (word.length() == 0)
        {
            root->isterminating = true;
            return;
        }
        trienode* child;
        if (root->children.count(word[0]) > 0)
        {
            child = root->children[word[0]];
        }
        else
        {
            trienode* newnode = new trienode(word[0]);
            root->children[word[0]] = newnode;
            child = newnode;
        }
        
        insertwordhelper(word.substr(1) , child);
    }
    void insert(string word) {
        if(!search(word)){
            return insertwordhelper(word , root);
        }
    }
    bool searchhelper(string word , trienode* root){
        if (word.length() == 0)
        {
            if(root->isterminating){
                return true;
            }
            else{
                return false;
            }
        }
        if (root->children.count(word[0]) == 0)
        {
            return false;
        }
        trienode* child = root->children[word[0]];
        return searchhelper(word.substr(1) , child);
    }
    bool search(string word) {
        return searchhelper(word , root);
    }
    bool startsWithhelper(string word , trienode* root){
        if (word.length() == 0)
        {
            return true;
        }
        if (root->children.count(word[0]) == 0)
        {
            return false;
        }
        trienode* child = root->children[word[0]];
        return startsWithhelper(word.substr(1) , child);
    }
    bool startsWith(string prefix) {
        return startsWithhelper(prefix , root);
    }
};

class TrieNode{
public:
    TrieNode *child[2];
    
    TrieNode(){
        this->child[0] = NULL; //for 0 bit 
        this->child[1] = NULL; //for 1 bit
    }
};
class Solution {
    TrieNode *newNode;
    
    void insert(int x){   //to insert each element into the Trie
        TrieNode *t = newNode;
        bitset<32> bs(x);
        
        for(int j=31; j>=0; j--){
            if(!t->child[bs[j]]) t->child[bs[j]] = new TrieNode(); //start from the MSB =, move to LSB using bitset
            t = t->child[bs[j]];
        }    
    }
    
public:
    int findMaximumXOR(vector<int>& nums) {
        newNode = new TrieNode();
        for(auto &n : nums) insert(n); //insert all the elements into the Trie
        
        int ans=0; //Stores the maximum XOR possible so far
        for(auto n : nums){
            ans = max(ans, maxXOR(n));  //updates the ans as we traverse the array & compute max XORs at each element.
        }
        return ans;
    }
    
    int maxXOR(int n){
        TrieNode *t = newNode;
        bitset<32> bs(n);
        int ans=0; 
        for(int j=31; j>=0; j--){
            if(t->child[!bs[j]]) ans += (1<<j), t = t->child[!bs[j]]; //Since 1^0 = 1 & 1^1 = 0, 0^0 = 0
           
            else t = t->child[bs[j]];
        }
        return ans;
    }
};


int main(){

}