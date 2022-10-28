#include<bits/stdc++.h>
using namespace std;

//------------------- https://www.geeksforgeeks.org/find-itinerary-from-a-given-list-of-tickets/ 

void PrintItineray(map<string , string> mp){
    map<string , string> revemp;
    map<string , string> ::iterator it;
    for(it = mp.begin(); it != mp.end() ; it++){
        revemp[it->second] = it->first;
    }
    string st;
    for(it = mp.begin(); it != mp.end() ; it++){
        if (revemp.find(it->first) == revemp.end())
        {
            st = it->first;
            break;
        }
    }
    if (st.empty())
    {
        cout<<"INVALID INPUT"<<endl;
        return;
    }
    it = mp.find(st);
    while(it != mp.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it = mp.find(it->second);
    }
}

//---------- https://www.geeksforgeeks.org/minimum-time-required-so-that-all-oranges-become-rotten/

int RottenOranges(vector<vector<int>> grid){
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0 , tot = 0;
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
    int dx[] = {0 , 0 , 1 , -1};
    int dy[] = {1 , -1 , 0 , 0};
    int day = 0;
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
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 1)
                {
                    continue;
                }
                grid[nx][ny] = 2;
                q.push({nx , ny});
            }
        }
        if (!q.empty())
        {
            day++;
        }
    }
    return cnt == tot ? day : -1;
}

//- https://www.geeksforgeeks.org/reduce-the-string-by-removing-k-consecutive-identical-characters/

string Reduced_string(string s , int k){
    if (k == 1)
    {
        return "";
    }
    stack<pair<int,int>> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (st.empty() || st.top().first != s[i])
        {
            st.push({s[i] , 1});
        }
        else
        {
            st.push({s[i] , st.top().second+1});
            if (st.top().second == k)
            {
                int a = k;
                while (a--)
                {
                    st.pop();
                }
            }
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top().first;
        st.pop();
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

//------- https://www.geeksforgeeks.org/minimum-cost-to-merge-numbers-from-1-to-n/

int MinCostToMerge(int n){
    priority_queue<int,vector<int>,greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(i+1);
    }
    int sum = 0;
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        sum += a*b;
        pq.push(a*b);
    }
    return sum;
}

//------ https://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/

int MaximumIndex(int arr[] , int n){
    int pref[n];
    pref[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = max(pref[i-1] , arr[i]);
    }
    int ans = 0 , j = n-1;
    for (int i = n-1; i >= 0; i--)
    {
        while (j >= 0 && pref[j] <= arr[i])
        {
            j--;
        }
        ans = max(ans , i-j-1);
    }
    return ans;
}

//----------- https://www.geeksforgeeks.org/median-of-stream-of-integers-running-integers/

class Solution
{
    public:
    priority_queue<int> maxHeap; 
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    void insertHeap(int &x)
    {
        if(maxHeap.size() == 0 || maxHeap.top() >= x)
            maxHeap.push(x);
        else
            minHeap.push(x);
            
        balanceHeaps();
        
    }
    void balanceHeaps()
    {
        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    double getMedian()
    {
        if(maxHeap.size() == minHeap.size())
            return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;
            
        return (double)maxHeap.top();
    }
};

int main(){
    // map<string, string> dataSet;
    // dataSet["Chennai"] = "Banglore";
    // dataSet["Bombay"] = "Delhi";
    // dataSet["Goa"] = "Chennai";
    // dataSet["Delhi"] = "Goa";

    // PrintItineray(dataSet);
}