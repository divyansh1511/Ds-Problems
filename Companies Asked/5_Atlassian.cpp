#include<bits/stdc++.h>
using namespace std;

vector<int> BallCollision(vector<int> direction , vector<int> strength){
    stack<int> st;
    int n = direction.size();
    for (int i = 0; i < n; i++)
    {
        if (direction[i] > 0 || st.empty())
        {
            st.push(i);
        }
        else
        {
            while (!st.empty() && direction[st.top()] > 0 && strength[i] > strength[st.top()])
            {
                st.pop();
            }
            if (st.empty() || direction[st.top()] < 0)
            {
                st.push(i);
            }
            else if (strength[st.top()] == strength[i])
            {
                st.pop();
            }
        }
    }
    vector<int> ans;
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

vector<int> QuizCompetition(vector<int> &arr , int k){
    int n = arr.size();
    vector<int> ans;
    for (int j = 0; j <= n-k; j++)
    {
        unordered_map<int,int> mp;
        int count = 0;
        for (int i = j; i < n; i++)
        {
            if (mp[arr[i]] == 0)
            {
                count++;
            }
            mp[arr[i]]++;
            if (count == k)
            {
                ans.push_back(i-j+1);
                break;
            }
        }
    }
    for (int i = n-k+1; i < n; i++)
    {
        ans.push_back(-1);
    }
    return ans;
}

int main(){

}