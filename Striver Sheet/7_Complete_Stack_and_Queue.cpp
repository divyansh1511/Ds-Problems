#include<bits/stdc++.h>
using namespace std;

class StackUsingArray{
    public:
    int* arr;
    int lastelementindex;
    int capacity;
    StackUsingArray(){
        arr = new int[20];
        lastelementindex = -1;
        capacity = 20;
    }
    bool isempty(){
        return lastelementindex == -1;
    }
    int size(){
        return lastelementindex + 1;
    }
    void push(int val){
        if (lastelementindex == capacity)
        {
            int* newarr = new int[2*capacity];
            for (int i = 0; i < capacity; i++)
            {
                newarr[i] = arr[i];
            }
            arr = newarr;
            capacity *= 2;
            delete[] newarr;
        }
        arr[++lastelementindex] = val;
    }
    void pop(){
        if (lastelementindex == -1)
        {
            cout<<"stack is empty"<<endl;
            return;
        }
        lastelementindex--;
    }
    int top(){
        if (lastelementindex == -1)
        {
            cout<<"stack is empty"<<endl;
            return - 1;
        }
        return arr[lastelementindex];
    }
};

class queueusingarr{
    public:
    int* arr;
    int front1;
    int rear;
    int capacity;
    queueusingarr(){
        arr = new int[20];
        front1 = 0;
        rear = 0;
        capacity = 20;
    }
    void enqueue(int val){
        if (rear == capacity)
        {
            cout<<"queue is full"<<endl;
            return;
        }
        else
        {
            arr[rear] = val;
            rear++;
        }
        return;
    }
    void dequeue(){
        if (front1 == rear)
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        else
        {
            front1++;
        }
    }
    void front(){
        if (front1 == rear)
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        else
        {
            cout<<arr[front1]<<endl;
        }
    }
};

class StackUsingQueue{
    public:
    queue<int> q;
    StackUsingQueue(){

    }
    bool empty(){
        return q.empty();
    }
    int size(){
        return q.size();
    }
    void push(int element){
        q.push(element);
        for (int i = 1; i < q.size(); i++)
        {
            q.push(q.front());
            q.pop();
        }
    }
    void pop(){
        q.pop();
    }
    int top(){
        return q.front();
    }
};

class QueueUsingStack{
    public:
    stack<int> s1;
    stack<int> s2;
    QueueUsingStack(){

    }
    bool isempty(){
        return s1.empty();
    }
    void push(int element){
        if (s1.empty())
        {
            s1.push(element);
        }
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(element);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int front(){
        return s1.top();
    }
    void pop(){
        s1.pop();
    }
};

bool BalancedParenthesis(string s){
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            if (st.empty())
            {
                return false;
            }
            char a = st.top();
            st.pop();
            if (a != '(')
            {
                return false;
            }
        }
        else if (s[i] == ']')
        {
            if (st.empty())
            {
                return false;
            }
            char a = st.top();
            st.pop();
            if (a != '[')
            {
                return false;
            }
        }
        else if (s[i] == '}')
        {
            if (st.empty())
            {
                return false;
            }
            char a = st.top();
            st.pop();
            if (a != '{')
            {
                return false;
            }
        }
    }
    return true;
}

vector<int> NextGreaterElement(int arr[] , int n){
    vector<int> ans(n, -1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        if (st.empty())
        {
            st.push(i);
            continue;
        }
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            ans[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return ans;
}

void addsortedly(stack<int> &st , int x){
    if (st.empty() || st.top() > x)
    {
        st.push(x);
        return;
    }
    int a = st.top();
    st.pop();
    addsortedly(st , x);
    st.push(x);
}

void sortStack(stack<int> &st){
    if (st.empty())
    {
        return;
    }
    int x = st.top();
    st.pop();
    sortStack(st);
    addsortedly(st , x);
}

vector<int> nextSmallerelement(int arr[] , int n){
    vector<int> ans;
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (st.top() > arr[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(arr[i]);
    }
    return ans;
}

class LRUcache{
    public:
    class node{
        public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int key , int val){
            this->key = key;
            this->val = val;
        }
    };

    node* head = new node(-1 , -1);
    node* tail = new node(-1 , -1);

    int cap;
    unordered_map<int, node*> mp;
    LRUcache(int capacity){
        cap = capacity;
        head->next = tail;
        tail->next = head;
    }

    void addnode(node* newnode){
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node* n){
        node* delprev = n->prev;
        node* delnext = n->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key1){
        if (mp.find(key1) != mp.end())
        {
            node* resnode = mp[key1];
            int resval = resnode->val;
            mp.erase(key1);
            deletenode(resnode);
            addnode(resnode);
            mp[key1] = head->next;
            return resval;
        }
        return -1;
    }

    int put(int key1 , int value){
        if (mp.find(key1) != mp.end())
        {
            node* existnode = mp[key1];
            mp.erase(key1);
            deletenode(existnode);
        }
        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key1 , value));
        mp[key1] = head->next;
    }
};

int largestRectangleArea(vector<int> arr , int n){
    stack<int> st;
    int ans = 0;
    arr.push_back(0);
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            int tp = arr[st.top()];
            st.pop();
            int ran = st.empty() ? -1 : st.top();
            ans = max(ans , tp*(i-ran-1));
        }
        st.push(i);
    }
    return ans;
}

vector<int> slidingWindow(vector<int> nums, int k){
    deque<int> dq;
    vector<int> v;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() == i-k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()] < nums[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k-1)
        {
            v.push_back(nums[dq.front()]);
        }
    }
    return v;
}

class minstack{
    public:
    stack<int> s1;
    stack<int> s2;

    void push(int x){
        s1.push(x);
        if (s2.empty() || x <= getmin())
        {
            s2.push(x);
        }
    }
    void pop(){
        int a = s1.top();
        s1.pop();
        if (a == s2.top())
        {
            s2.pop();
        }
    }
    int top(){
        return s1.top();
    }
    int getmin(){
        return s2.top();
    }
};

int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int tot = 0 , cnt = 0 , days = 0;
    queue<pair<int,int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] != 0){
                tot++;
            }
            if(grid[i][j] == 2){
                q.push({i,j});
            }
        }
    }
    int dx[] = {0 , 0 , -1 , 1};
    int dy[] = {1 , -1 , 0 , 0};
    while (!q.empty())
    {
        int k = q.size();
        cnt += k;
        while (k--)
        {
            int x = q.front().first , y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i] , ny = y + dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] != 1)
                {
                    continue;
                }
                grid[nx][ny] = 2;
                q.push({nx , ny});
            }
        }
        if (!q.empty())
        {
            days++;
        }
    }
    return tot == cnt ? days : -1;
}

class StockSpanner {
public:
    StockSpanner() {
        
    }
    stack<pair<int, int>> s;
    int next(int price) {
        int res = 1;
        while (!s.empty() && s.top().first <= price) {
            res += s.top().second;
            s.pop();
        }
        s.push({price, res});
        return res;
    }
};

class LFUCache {
public:
    LFUCache(int capacity) {
        this -> capacity = capacity;
        size = 0;
    }
    
    int get(int key) {
        if (values.find(key) == values.end()) {
            return -1;
        }
        update(key);
        return values[key].first;
    }
    
    void put(int key, int value) {
        if (!capacity) {
            return;
        }
        if (values.find(key) != values.end()) {
            values[key].first = value;
            update(key);
        } else {
            if (size == capacity) {
                int evict = keys[lfu].front();
                keys[lfu].pop_front();
                values.erase(evict);
                iters.erase(evict);
            } else {
                size++;
            }
            values[key] = {value, 1};
            keys[1].push_back(key);
            iters[key] = --keys[1].end();
            lfu = 1;
        }
    }
private:
    int capacity, size, lfu = 0;
    unordered_map<int, list<int>> keys;
    unordered_map<int, pair<int, int>> values;
    unordered_map<int, list<int>::iterator> iters;
    
    void update(int key) {
        int freq = values[key].second;
        auto iter = iters[key];
        values[key].second++;
        keys[freq].erase(iter);
        keys[freq + 1].push_back(key);
        iters[key] = --keys[freq + 1].end();
        if (keys[lfu].empty()) {
            lfu++;
        }
    }
};

void printMaxOfMin(int arr[], int n)
{
    stack<int> s;
    int left[n+1]; 
    int right[n+1];
    for (int i=0; i<n; i++)
    {
        left[i] = -1;
        right[i] = n;
    }
    for (int i=0; i<n; i++)
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
 
        if (!s.empty())
            left[i] = s.top();
 
        s.push(i);
    }
    while (!s.empty())
        s.pop();

    for (int i = n-1 ; i>=0 ; i-- )
    {
        while (!s.empty() && arr[s.top()] >= arr[i])
            s.pop();
 
        if(!s.empty())
            right[i] = s.top();
 
        s.push(i);
    }

    int ans[n+1];
    for (int i=0; i<=n; i++)
        ans[i] = 0;

    for (int i=0; i<n; i++)
    {
        int len = right[i] - left[i] - 1;
        ans[len] = max(ans[len], arr[i]);
    }

    for (int i=n-1; i>=1; i--)
        ans[i] = max(ans[i], ans[i+1]);

    for (int i=1; i<=n; i++)
        cout << ans[i] << " ";
}

int celebrity(vector<vector<int> >& M, int n) 
{
    int left=0, right=n-1;
    while (left < right) {
        if (M[left][right] == 1) left++;
        else right--;
    }
       
    int potentialCandidate=left;
       
    for (int i=0; i<n; i++) {
        if (i != potentialCandidate) {
            if (M[potentialCandidate][i] == 1 || M[i][potentialCandidate] == 0) return -1;    
        }
    }   
    return potentialCandidate;
}

int main(){
    int arr[] = {11 ,13 , 21 , 3};
    vector<int> a = NextGreaterElement(arr , 4);
    for (int i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<endl;
    }
    
}