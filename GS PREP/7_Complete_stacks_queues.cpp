#include<bits/stdc++.h>
using namespace std;

class stackusingarr{
    int* arr;
    int lastelement;
    int capacity;
    public:
    stackusingarr(){
        arr = new int[20];
        lastelement = -1;
        capacity = 20;
    }
    bool isEmpty(){
        return lastelement == -1;
    }
    void push(int x){
        if (lastelement == capacity)
        {
            int* tmp = new int[2*capacity];
            for (int i = 0; i < capacity; i++)
            {
                tmp[i] = arr[i];
            }
            capacity = 2*capacity;
            arr = tmp;
            delete[] tmp;
        }
        
        ++lastelement;
        arr[lastelement] = x;
    }
    void pop(){
        if (isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        lastelement--;
    }
    int top(){
        if (isEmpty())
        {
            cout<<"Stack is empty"<<endl;
            return;
        }
        return arr[lastelement];
    }
};

class queueusingarr{
    int* arr;
    int st , end , capacity;
    public:
    queueusingarr(){
        arr = new int[20];
        capacity = 20;
        st = -1;
        end = -1;
    }
    bool isEmpty(){
        return st == end;
    }
    void push(int x){
        end++;
        arr[end] = x;
    }
    void pop(){
        if (isEmpty())
        {
            return;
        }
        end--;
    }
    int front(){
        if (isEmpty())
        {
            return;
        }
        return arr[end];
    }
};

class stackusingqueue{
    public:
    queue<int> q;
    stackusingqueue(){

    }
    void push(int x){
        q.push(x);
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

class queueusingstack{
    stack<int> s1;
    stack<int> s2;
    public:
    queueusingstack(){

    }
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
        int a = s1.top();
        s1.pop();
        return a;
    }
    int peek(){
        return s1.top();
    }
};

bool isValid(string s){
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

vector<int> nextgreatereleII(vector<int> nums){
    int n = nums.size();
    vector<int> ans(n , -1);
    stack<int> st;
    for (int i = 0; i < n*2; i++)
    {
        int a = nums[i%n];
        while (!st.empty() && nums[st.top()] < a)
        {
            ans[st.top()] = a;
            st.pop();
        }
        if (i < n)
        {
            st.push(i);
        }
    }
    return ans;
}

void insertsortedly(stack<int> &st , int a){
    if (st.empty() || st.top() >= a)
    {
        st.push(a);
        return;
    }
    int tmp = st.top();
    st.pop();
    insertsortedly(st , a);
}

void sortstack(stack<int> st){
    if (st.empty())
    {
        return;
    }
    int a = st.top();
    st.pop();
    sortstack(st);
    insertsortedly(st , a);
}

vector<int> PrevSmaller(vector<int> v){
    int n = v.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (st.top() >= v[i])
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(v[i]);
    }
    return ans;
}

int largestRectangleArea(vector<int> &v){
    stack<int> st;
    int ans = 0;
    v.push_back(0);
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[st.top()] > v[i])
        {
            int tmp = v[st.top()];
            st.pop();
            int rn = st.empty() ? -1 : st.top();
            ans = max(ans , tmp*(i-rn-1));
        }
        st.push(i);
    }
    return ans;
}

vector<int> MaxslidingWindow(vector<int> v , int k){
    deque<int> dq;
    vector<int> ans;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front() == i-k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && v[dq.back()] < v[i])
        {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k-1)
        {
            ans.push_back(v[dq.front()]);
        }
    }
    return ans;
}

class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= getMin())  s2.push(x);	    
    }
    void pop() {
	    if (s1.top() == getMin())  s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};

int rottenoranges(vector<vector<int>> v){
    int n = v.size();
    int m = v[0].size();
    int tot = 0 , cnt = 0 , days = 0;
    queue<pair<int,int>> q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] != 0)
            {
                tot++;
            }
            if (v[i][j] == 2)
            {
                q.push({i,j});
            }
        }
    }
    
    int dx[] = {1,-1,0,0};
    int dy[] = {0,0,1,-1};

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
                int nx = x+dx[i] , ny = y+dy[i];
                if (nx < 0 || ny < 0 || nx >= n || ny >= y || v[nx][ny] != 1)
                {
                    continue;
                }
                v[nx][ny] = 2;
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

int main(){

}