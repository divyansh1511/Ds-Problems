#include<bits/stdc++.h>
using namespace std;

vector<int> NmaxPairCombination(vector<int> v1 , vector<int> v2){
    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> s;

    sort(v1.begin() , v1.end());
    sort(v2.begin() , v2.end());

    int n = v1.size();
    pq.push({v1[n-1]+v2[n-1] , {n-1 , n-1}});
    s.insert({n-1 , n-1});

    vector<int> ans;
    int k = n;
    while (k--)
    {
        pair<int , pair<int,int>> p;
        p = pq.top();
        pq.pop();
        ans.push_back(p.first);
        int l = p.second.first;
        int r = p.second.second;

        if (l >= 0 && r > 0 && s.find({l , r-1}) == s.end())
        {
            pq.push({v1[l]+v2[r-1] , {l , r-1}});
            s.insert({l , r-1});
        }
        
        if (l > 0 && r >= 0 && s.find({l-1 , r}) == s.end())
        {
            pq.push({v1[l-1] + v2[r] , {l-1 , r}});
            s.insert({l-1 , r});
        }
    }
    return ans;
}

vector<int> kLargestElements(vector<int> v , int k){
    priority_queue<int , vector<int> , greater<int>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int ProfitMaximization(vector<int> v , int k){
    priority_queue<int> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
    }
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        int a = pq.top();
        pq.pop();
        ans += a;
        a--;
        pq.push(a);
    }
    return ans;
}

vector<int> MergeKsortedArray(vector<vector<int>> v){
    priority_queue<int , vector<int> , greater<int>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); i++)
        {
            pq.push(v[i][j]);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int ConnectRopes(vector<int> v){
    priority_queue<int , vector<int> , greater<int>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
    }
    int sum = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        sum += (a+b);
        pq.push(a+b);
    }
    return sum;
}

int MagicianAndChoclates(vector<int> v , int k){
    priority_queue<int> maxheap;
    for (int i = 0; i < v.size(); i++)
    {
        maxheap.push(v[i]);
    }
    int ans = 0;
    int mod = 1000000007;
    for (int i = 0; i < k; i++)
    {
        int a = maxheap.top();
        maxheap.pop();
        ans = ans%mod + a%mod;
        ans = ans%mod;
        a = a/2;
        maxheap.push(a);
    }
    return ans;
}

bool static cmp(int &a , int &b){
    return b < a;
}

vector<int> MaximumSumCombination(vector<int> &a , vector<int> &b , int c){
    sort(a.begin() , a.end() , cmp);
    sort(b.begin() , b.end() , cmp);
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0; i < a.size(); i++)
    {
        pq.push(a[i]+b[i]);
    }
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (i != j)
            {
                if ((a[i] + b[j]) >= pq.top())
                {
                    pq.pop();
                    pq.push(a[i]+b[j]);
                }
                else
                {
                    break;
                }
            }
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.begin() , ans.end() , cmp);
    return ans;
}

// MERGE K SORTED LIST --> SIMPLE MIN HEAP

vector<int> DistinctNumber(vector<int> &v , int k){
    unordered_map<int,int> mp;
    
    for (int i = 0; i < k; i++)
    {
        mp[v[i]]++;
    }
    
    vector<int> v;
    v.push_back(mp.size());
    for (int i = k; i < v.size(); i++)
    {
        mp[v[i-k]]--;
        if (mp[v[i-k]] == 0)
        {
            mp.erase(v[i-k]);
        }
        mp[v[i]]++;
        v.push_back(mp.size());
    }
    return v;
}

class LRUCache {
public:
    class node {
        public:
            int key;
            int val;
            node* next;
            node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val; 
        }
    };
    
    node* head = new node(-1,-1);
    node* tail = new node(-1,-1);
    
    int cap;
    unordered_map<int, node*>m;
    
    LRUCache(int capacity) {
        cap = capacity;    
        head->next = tail;
        tail->prev = head;
    }
    
    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }
    
    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res; 
        }
    
        return -1;
    }
    
    void put(int key_, int value) {
        if(m.find(key_) != m.end()) {
            node* existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if(m.size() == cap) {
          m.erase(tail->prev->key);
          deletenode(tail->prev);
        }
        
        addnode(new node(key_, value));
        m[key_] = head->next; 
    }
};

int main(){

}