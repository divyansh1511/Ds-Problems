#include<bits/stdc++.h>
using namespace std;

bool BalancedParenthesis(string s){
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
    if (st.empty())
    {
        return true;
    }
    return false;
}

string SimplfyDirectoryPath(string a){
    stringstream ss(a);
    string token;
    stack<string> st;

    while (getline(ss , token , '/'))
    {
        if (token == "..")
        {
            if (!st.empty())
            {
                if (st.top() != "/")
                {
                    st.pop();
                }
            }
        }
        else if (token == "" || token == ".")
        {
            continue;
        }
        else
        {
            st.emplace(string(token.rbegin() , token.rend()));
        }
    }
    string ans = "";
    if (st.empty())
    {
        return "/";
    }
    while (!st.empty())
    {
        if (st.top() != "")
        {
            ans += st.top() + "/";
        }
        st.pop();
    }
    return string(ans.rbegin() , ans.rend());
}

bool Braces(string a){
    int sign = 0 , pr = 0;
    bool f = false;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
        {
            sign++;
        }
        else if (a[i] == '(')
        {
            pr++;
            if (i+2 < a.length() && a[i+2] == ')')
            {
                f = true;
            }
        }
    }
    if (pr <= sign && f == false)
    {
        return 0;
    }
    return 1;
}

class MinStack{
    stack<int> s1;
    stack<int> s2;
    public:
    void push(int element){
        s1.push(element);
        if (s2.empty() || getmin() >= element)
        {
            s2.push(element);
        }
    }
    void pop(){
        if (s1.top() == getmin())
        {
            s2.pop();
        }
        s1.pop();
    }
    int top(){
        return s1.top();
    }
    int getmin(){
        return s2.top();
    }
};

vector<int> NearestSmallerElement(vector<int> &A) {
    int n = A.size();
    vector<int> v(n);
    stack<int> s;
    s.push(-1);
    for(int i=0;i<n;i++){
        while(s.top() >= A[i]){
            s.pop();
        }
        v[i] = s.top();
        s.push(A[i]);
    }
    return v;
}

int largestRectangleArea(vector<int> &heights) {
    stack<int> st;
    int ans = 0;
    heights.push_back(0);
    for(int i=0;i<heights.size();i++){
        while(!st.empty() && heights[st.top()]>heights[i]){
            int top=heights[st.top()];
            st.pop();
            int ran=st.empty()?-1:st.top();
            ans=max(ans,top*(i-ran-1));
        }
        st.push(i);
    }
    return ans;
}

string FirstNonRepeating(string A) {
    string B ="";
    queue<char> q;
    int count[26] = {0};
    int n = A.length();
    for(int i=0;i<n;i++){
        q.push(A[i]);
        count[A[i]-'a']++;
        while(!q.empty()){
            if(count[q.front()-'a']>1){
                q.pop();
            }
            else{
                B.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            B.push_back('#');
        }
    }
    return B;
}

vector<int> slidingMaximum(const vector<int> &A, int B) {
    int n = A.size();
    deque<int> dq;
    vector<int> v;
    for(int i=0;i<n;i++){
        if(!dq.empty() && dq.front() == i-B){
            dq.pop_front();
        }
        while(!dq.empty() && A[dq.back()] < A[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i >= B-1){
            v.push_back(A[dq.front()]);
        }
    }
    return v;
}

int evaluateExpression(vector<string> &A) {
    stack<int> s;
    int n = A.size();
    for(int i=0;i<n;i++){
        if(A[i] == "+" || A[i] == "-" || A[i] == "*" || A[i] == "/"){
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(A[i] == "+"){
                s.push(a+b);
            }
            if(A[i] == "-"){
                s.push(b-a);
            }
            if(A[i] == "*"){
                s.push(a*b);
            }
            if(A[i] == "/"){
                s.push(b/a);
            }
        }
        else{
            s.push(stoi(A[i]));
        }
    }
    return s.top();
}

int trapingRainWater(const vector<int> &A) {
    int n = A.size();
    vector<int> left(n);
    vector<int> right(n);
    int ml = left[0] = A[0];
    int mr = right[n-1] = A[n-1];
    for(int i=1;i<n;i++){
        if(A[i] > ml){
            ml = A[i];
            left[i] = A[i];
        }
        else{
            left[i] = left[i-1];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(A[i] > mr){
            mr = A[i];
            right[i] = A[i];
        }
        else{
            right[i] = right[i+1];
        }
    }
    int s = 0;
    for(int i=0;i<n;i++){
        s += min(left[i] , right[i]) - A[i];
    }
    return s;
}


int main(){

}