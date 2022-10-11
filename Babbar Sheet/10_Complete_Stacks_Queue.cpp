#include <bits/stdc++.h>
using namespace std;

class stackusingArr
{
public:
    int *arr;
    int lastelementindex;
    int capacity;
    stackusingArr()
    {
        arr = new int[20];
        lastelementindex = -1;
        capacity = 20;
    }
    int size()
    {
        return 1 + lastelementindex;
    }
    bool empty()
    {
        return lastelementindex == -1;
    }
    void push(int x)
    {
        if (lastelementindex == capacity)
        {
            int *newarr = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newarr[i] = arr[i];
            }
            newarr[lastelementindex++] = x;
            capacity = 2 * capacity;
            arr = newarr;
        }
        else
        {
            arr[lastelementindex++] = x;
        }
    }
    int pop()
    {
        if (lastelementindex == -1)
        {
            return -1;
        }
        return arr[lastelementindex--];
    }
    int top()
    {
        if (lastelementindex == -1)
        {
            return -1;
        }
        return arr[lastelementindex];
    }
};

class QueueUsingArr
{
public:
    int *arr;
    int front;
    int rear;
    int capacity;
    QueueUsingArr()
    {
        arr = new int[20];
        front = 0;
        rear = 0;
        capacity = 20;
    }
    void push(int x)
    {
        if (rear == capacity)
        {
            int *newarr = new int[2 * capacity];
            for (int i = 0; i < capacity; i++)
            {
                newarr[i] = arr[i];
            }
            newarr[rear++] = x;
            capacity = 2 * capacity;
            arr = newarr;
        }
        else
        {
            arr[rear++] = x;
        }
    }
    int pop()
    {
        if (front == rear)
        {
            return -1;
        }
        return arr[front++];
    }
};

bool BalancedParenthesis(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
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
    return st.empty() ? true : false;
}

string ReverseString(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        st.push(s[i]);
    }
    string a = "";
    while (!st.empty())
    {
        a += st.top();
        st.pop();
    }
    return a;
}

vector<int> NextGreaterElement(vector<int> arr, int n)
{
    stack<int> st;
    vector<int> v;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            v[i] = -1;
        }
        else
        {
            while (!st.empty() && st.top() < arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                v[i] = -1;
            }
            else
            {
                v[i] = st.top();
            }
        }
        st.push(arr[i]);
    }
    return v;
}

int CelebrityProblem(vector<vector<int>> &grid, int n)
{
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (grid[left][right] == 1)
        {
            left++;
        }
        else
        {
            right--;
        }
    }
    int p = left;
    for (int i = 0; i < n; i++)
    {
        if (i != p)
        {
            if (grid[p][i] == 1 || grid[i][p] == 0)
            {
                return -1;
            }
        }
    }
    return p;
}

int evaluatePostfix(string S)
{
    stack<int> st;
    for (int i = 0; i < S.length(); i++)
    {
        if (S[i] == '+' || S[i] == '-' || S[i] == '*' || S[i] == '/')
        {
            int a = st.top();
            st.pop();
            int b = st.top();
            st.pop();
            if (S[i] == '+')
            {
                st.push(a + b);
            }
            else if (S[i] == '-')
            {
                st.push(b - a);
            }
            else if (S[i] == '*')
            {
                st.push(a * b);
            }
            else
            {
                st.push(b / a);
            }
        }
        else
        {
            st.push(S[i] - '0');
        }
    }
    int a = st.top();
    return a;
}

void insertatbottom(stack<int> &s, int ele)
{
    if (s.size() == 0)
    {
        s.push(ele);
        return;
    }
    int temp = s.top();
    s.pop();
    insertatbottom(s, ele);
    s.push(temp);
}

stack<int> Reverse(stack<int> s)
{
    if (s.size() == 1)
    {
        return s;
    }
    int temp = s.top();
    s.pop();
    s = Reverse(s);
    insertatbottom(s, temp);
    return s;
}

void sortedinsert(stack<int> &stack, int num)
{
    if (stack.empty() || (!stack.empty() && stack.top() < num))
    {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    sortedinsert(stack, num);
    stack.push(n);
}
void sortStack(stack<int> s)
{
    if (s.empty())
    {
        return;
    }
    int num = s.top();
    s.pop();
    sortStack(s);
    sortedinsert(s, num);
}

int MaxAreaInRectangle(int arr[], int n)
{
    stack<int> st;
    int ma = 0;
    int i = 0;
    while (i < n)
    {
        if (st.empty() || arr[st.top()] <= arr[i])
        {
            st.push(i++);
        }
        else
        {
            int tp = st.top();
            st.pop();
            int ans = arr[tp] * (st.empty() ? i : i - st.top() - 1);
            ma = max(ma, ans);
        }
    }
    while (!st.empty())
    {
        int tp = st.top();
        st.pop();
        int ans = arr[tp] * (st.empty() ? i : i - st.top() - 1);
        ma = max(ma, ans);
    }
    return ma;
}

int ValidSubString(string s)
{
    stack<pair<char, int>> st;
    int ans = INT_MIN;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push({s[i], i + 1});
        }
        else
        {
            st.pop();
            if (st.empty())
            {
                ans = max(ans, i + 1);
            }
            else
            {
                ans = max(ans, i + 1 - st.top().second);
            }
        }
    }
    if (ans == INT_MIN)
    {
        return 0;
    }
    return ans;
}

bool ReductantBracket(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ')')
        {
            char tp = st.top();
            st.pop();

            bool flag = true;

            while (!st.empty() && tp != '(')
            {
                if (tp == '+' || tp == '-' || tp == '*' || tp == '/')
                {
                    flag = false;
                }
                tp = st.top();
                st.pop();
            }
            if (flag)
            {
                return true;
            }
        }
        else
        {
            st.push(s[i]);
        }
    }
    return false;
}

class StackUsing2queues
{
public:
    queue<int> q1;
    queue<int> q2;
    void push(int x)
    {
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop()
    {
        if (q1.empty())
        {
            return -1;
        }
        int a = q1.front();
        q1.pop();
        return a;
    }
};

int isStackPermutation(int n, vector<int> &A, vector<int> &B)
{
    stack<int> a;
    int k = 0;
    for (int i = 0; i <= n; i++)
    {
        while (!a.empty() && a.top() == B[k])
        {
            a.pop();
            k++;
        }
        if (i != n)
        {
            a.push(A[i]);
        }
    }
    if (k != n)
        return 0;
    return 1;
}

class QueueUsingStack{
    public:
    stack<int> s1;
    stack<int> s2;
    void push(int x){
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    int pop(){
        if (s1.empty())
        {
            return -1;
        }
        int a = s1.top();
        s1.pop();
        return a;
    }
};

class CircularQueue{
    public:
    int* arr;
    int front;
    int rear;
    int size;
    CircularQueue(int s){
        arr = new int[s];
        front = -1;
        rear = -1;
        size = s;
    }
    void enqueue(int x){
        if ((front == 0 && rear == size-1) || (rear = (front-1)%(size-1)))
        {
            cout<<"Queue is full"<<endl;
        }
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = x;
        }
        else if (rear == size-1 && front != 0)
        {
            rear = 0;
            arr[rear] = x;
        }
        else
        {
            rear++;
            arr[rear] = x;
        }
    }
    int dequeue(){
        if (front == -1)
        {
            cout<<"queue is empty"<<endl;
            return INT_MIN;
        }
        int data = arr[front];
        arr[front] = -1;
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else if (front == size - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }
        return data;
    }
};

class LRUCache
{
   private:
   struct Node 
   {
       int key;
       int value;
       Node* prev;
       Node* next;
       Node(int key1, int value1)
       {
           key = key1;
           value = value1;
       }
   };
   Node* head = new Node(0,0);
   Node* tail = new Node(0,0);  
   
   unordered_map<int,Node*> map1;
   int capacity;
   public:
   //Constructor for initializing the cache capacity with the given value.
   LRUCache(int cap)
   {
       capacity = cap;
       head->next = tail;
       tail->prev = head;
   }
   
   //Function to return value corresponding to the key.
   int get(int key)
   {
       if(map1.find(key) != map1.end())
       {
           Node* existingNode = map1[key];
           int value = existingNode->value;
           deleteNode(existingNode);
           addNode(key,value);
           map1.erase(key);
           map1[key] = head->next;
           return value;
       }
       return -1;
   }
   
   //Function for storing key-value pair.
   void set(int key, int value)
   {
       if(map1.find(key) != map1.end())
       {
           Node* existingNode = map1[key];
           map1.erase(key);
           deleteNode(existingNode);
       }
       
       if(map1.size() == capacity)
       {
           map1.erase(tail->prev->key);
           deleteNode(tail->prev);
       }
       
       addNode(key,value);
       map1[key]=head->next;

   }
   void addNode(int key,int value)
   {
       Node* createNode = new Node(key,value);
       createNode->next = head->next;
       head->next->prev = createNode;
       head->next = createNode;
       createNode->prev=head;
   }
   
   void deleteNode(Node* deletedNode)
   {
       deletedNode->prev->next = deletedNode->next;
       deletedNode->next->prev = deletedNode->prev;
       delete deletedNode;
   }
};

void rever(queue<int> &q)
{
    if(!q.empty())
    {
        int x=q.front();
        q.pop();
        rever(q);
        q.push(x);
    }
}
queue<int> rev(queue<int> q)
{
    rever(q);
    return q;
}

queue<int> ReverseKelements(queue<int> q, int k) {
    stack<int> s;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    int n = q.size();
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<n;i++){
        q.push(q.front());
        q.pop();
    }
    return q;
}

int RottingOranges(vector<vector<int>> &grid){
    int n = grid.size();
    int m = grid[0].size();
    int tot = 0 , cnt = 0 , days = 0;
    queue<pair<int,int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0)
            {
                tot++;
            }
            if (grid[i][j] == 2)
            {
                q.push({i , j});
            }
        }
    }
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x+dx[i];
            int ny = y+dy[i];

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
    return tot == cnt ? days : -1;
}

vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    queue<long long> q;
    vector<long long> ans;
    long long i = 0,j = 0;
    
    while(j<N){
        if(A[j]<0)
            q.push(A[j]);
        if(j-i+1 < K){
            j++;
        }
        else if(j-i+1==K){
            if(q.empty()) ans.push_back(0);
            else{
                ans.push_back(q.front());
                if(q.front() == A[i])
                    q.pop();
            }
            i++;j++;
        }
    }
    return ans;
}

int minValue(string s, int k){
    unordered_map<char,int> mp;
    for(int i = 0; i<s.size(); i++) mp[s[i]]++;        
    priority_queue<int> pq;
    for(auto x : mp) pq.push(x.second);
        
    for(int i =0; i<k; i++)
    {
        int temp = pq.top();
        pq.pop();
        temp -= 1;
        pq.push(temp);
    }
    int ans = 0;
    while(!pq.empty())
    {
        ans += pow(pq.top(), 2);
        pq.pop();
    }
    return ans;
}

string FirstNonRepeating(string s){
	queue<char> q;
	int mp[256] = {0};
		    
	for(int i=0;i<s.size();i++)
	{
	    char c = s[i];
        mp[c]++;
		if(mp[c]==1) q.push(c);        
		while(q.size() && mp[q.front()]>1) q.pop();        
		if(q.size()) s[i] = q.front();
	    else s[i] = '#';
	}
	return s;
}

vector<int> NextSmallerElement(vector<int> v){
    stack<int> st;
    int n = v.size();
    vector<int> ans(n , -1);
    for (int i = n-1; i >= 0; i--)
    {
        int k = v[i];
        while (!st.empty() && st.top() >= v[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = st.top();
        }
        st.push(k);
    }
    return ans;
}

int main()
{
    
}