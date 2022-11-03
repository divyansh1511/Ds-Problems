#include <bits/stdc++.h>
using namespace std;

vector<int> SlidingWindowMaximum(vector<int> v, int k)
{
    deque<int> dq;
    int n = v.size();
    int i = 0;
    vector<int> ans;
    for (i = 0; i < k; i++)
    {
        while (!dq.empty() && v[i] >= v[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for (i; i < n; i++)
    {
        ans.push_back(v[dq.front()]);
        while (!dq.empty() && dq.front() <= i - k)
        {
            dq.pop_front();
        }
        while (!dq.empty() && v[i] >= v[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    ans.push_back(v[dq.front()]);
    return ans;
}

void insertatbottom(stack<int> &st, int a)
{
    if (st.empty())
    {
        st.push(a);
        return;
    }
    int b = st.top();
    st.pop();
    insertatbottom(st, a);
    st.push(b);
}

void ReverseStack(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int a = st.top();
    st.pop();
    ReverseStack(st);
    insertatbottom(st, a);
}

bool subarrwithSumZero(int arr[], int n)
{
    unordered_map<int, int> mp;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0 || mp.find(sum) != mp.end())
        {
            return true;
        }
        mp[sum]++;
    }
    return false;
}

int maxCandy(int height[], int n)
{
    int i = 0, j = n - 1;
    int res = (j - i - 1) * min(height[i], height[j]);
    while (j > i)
    {
        if (height[j] > height[i])
        {
            i++;
        }
        else
            j--;
        res = max(res, (j - i - 1) * min(height[i], height[j]));
    }
    if (res < 0)
        return 0;
    return res;
}

int main()
{
}