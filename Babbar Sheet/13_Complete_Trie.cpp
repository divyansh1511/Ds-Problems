#include<bits/stdc++.h>
using namespace std;

class trienode{
    public:
    char data;
    unordered_map<char , trienode*> children;
    bool isroot;
    bool isterminating;
    trienode(char data){
        this->data = data;
    }
};

class trie{
    trienode* root;
    int count;

    public:
    trie(){
        root = new trienode(' ');
        root->isroot = true;
        count = 0;
    }
    int size(){
        return count;
    }
    bool isempty(){
        return size() == 0;
    }

    bool helper1(string word , trienode* root){
        if (word.length() == 0)
        {
            return root->isterminating;
        }
        if (root->children.count(word[0]) == 0)
        {
            return false;
        }
        trienode* child = root->children[word[0]];
        return helper1(word.substr(1) , child);
    }

    bool isWordPresent(string word){
        return helper1(word , root);
    }

    void helper2(string word , trienode* root){
        if (word.length() == 0)
        {
            root->isterminating = true;
            return;
        }
        trienode* child;
        if (root->children.count(word[0]) != 0)
        {
            child = root->children[word[0]];
        }
        else
        {
            trienode* newnode = new trienode(word[0]);
            root->children[word[0]] = newnode;
            child = newnode;
        }
        helper2(word.substr(1) , child);
    }

    void InsertWord(string word){
        if (!isWordPresent(word))
        {
            helper2(word , root);
            count++;
        }
    }

    bool helper3(string word , trienode* root){
        if (word.length() == 0)
        {
            root->isterminating = false;
            return root->children.size() == 0;
        }
        trienode* child = root->children[word[0]];
        if (helper3(word.substr(1) , child))
        {
            root->children.erase(word[0]);
        }
        return root->isterminating || root->children.size();
    }

    void DeleteWord(string word){
        if (isWordPresent(word))
        {
            helper3(word , root);
            count--;
        }
    }

    vector<string> findPrefixes(string arr[], int n)
    {
        // trienode *root = new trienode();
        for(int i=0;i<n;i++)
        {
            InsertWord(arr[i]);
        }
        vector<string> res(n);
        for(int i=0;i<n;i++)
        {
            res[i] = isWordPresent(arr[i]);
        }
        return res;
    }
};

int main(){

}