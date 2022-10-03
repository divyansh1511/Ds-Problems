#include<bits/stdc++.h>
using namespace std;

void SpiralTraversalMatrix(vector<vector<int>> v){
    int n = v.size() , m = v[0].size();
    int i = 0 , j = 0;

    while (i < n && j < m)
    {
        for (int k = j; k < m; k++)
        {
            cout<<v[i][k]<<" ";
        }
        i++;
        for (int k = i; k < n; k++)
        {
            cout<<v[k][m-1]<<" ";
        }
        m--;
        if (j < m)
        {
            for (int k = m-1; k >= j; k--)
            {
                cout<<v[n-1][k]<<" ";
            }
            n--;
        }
        if (i < n)
        {
            for (int k = n-1; k >= i; k--)
            {
                cout<<v[k][j]<<" ";
            }
            j++;
        }
    }
}

bool SearchInRowWiseSortedMatrix(vector<vector<int>> v , int k){
    int n = v.size();
    int m = v[0].size();
    
    int lo = 0 , hi = n*m-1;
    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        int x = mid/m;
        int y = mid%m;
        if (v[x][y] == k)
        {
            return true;
        }
        else if (v[x][y] < k)
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
    return false;
}

int MedianInRowWiseSortedMatrix(vector<vector<int>> v){
    int n = v.size();
    int m = v[0].size();

    int minele = INT_MAX;
    int maxele = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        minele = min(minele , v[i][0]);
        maxele = max(maxele , v[i][m-1]);
    }
    
    int n = (n*m+1)/2;
    while (minele < maxele)
    {
        int mid = (minele+maxele)/2;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            p += upper_bound(v[i].begin() , v[i].end() , mid) - v[i].begin();
        }
        if (p < n)
        {
            minele = mid+1;
        }
        else
        {
            maxele = mid;
        }
    }
    return minele;
}

int RowWithMaxOnes(vector<vector<int>> v){          //T.C : O(N+M)
    int n = v.size();
    int m = v[0].size();
    
    int maxrow = -1;
    int i = 0 , j = m-1;
    while (i < n && j >= 0)
    {
        if (v[i][j] == 1)
        {
            maxrow = i;
            j--;
        }
        else
        {
            i++;
        }
    }
    return maxrow;
}

void helper(vector<vector<int>> &v , int i , int j , int n){
    int downval = (i+1) < n ? v[i+1][j] : INT_MAX;
    int rightval = (j+1) < n ? v[i][j+1] : INT_MAX;

    if (downval == INT_MAX && rightval == INT_MAX)
    {
        return;
    }
    
    if (downval < rightval)
    {
        v[i][j] = downval;
        v[i+1][j] = INT_MAX;
        helper(v , i+1 , j , n);
    }
    else
    {
        v[i][j] = rightval;
        v[i][j+1] = INT_MAX;
        helper(v , i , j+1 , n);
    }
}

vector<vector<int>> SortMatrix(vector<vector<int>> v){
    int n = v.size();
    helper(v , 0 , 0 , n);
    return v;
}

int LargestRectangleArea(vector<int> v){
    stack<int> st;
    int ans = 0;
    v.push_back(0);
    for (int i = 0; i < v.size(); i++)
    {
        while (!st.empty() && v[st.top()] > v[i])
        {
            int tp = st.top();
            st.pop();
            int tmp = st.empty() ? -1 : st.top();
            ans = max(ans , tp*(i-tmp-1));
        }
        st.push(i);
    }
    return ans;
}

int maxRectangle(vector<vector<int>> v){
    int maxarea = 0;
    int m = v[0].size();
    vector<int> tmp(m , 0);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 1)
            {
                tmp[j]++;
            }
            else
            {
                tmp[j] = 1;
            }
        }
        maxarea = max(maxarea , LargestRectangleArea(tmp));
    }
    return maxarea;
}

int findMaxValue(vector<vector<int>> mat , int N)
{
    int maxValue = INT_MIN;

    for (int a = 0; a < N - 1; a++)
        for (int b = 0; b < N - 1; b++)
            for (int d = a + 1; d < N; d++)
            for (int e = b + 1; e < N; e++)
                if (maxValue < (mat[d][e] - mat[a][b]))
                    maxValue = mat[d][e] - mat[a][b];
    return maxValue;
}

void RotateMatrixBy90degree(vector<vector<int>> &v){
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(v[i][j] , v[j][i]);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        reverse(v[i].begin() , v[i].end());
    }
}

int kthElementinMatrix(vector<vector<int>> v , int k){
    priority_queue<int> pq;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            pq.push(v[i][j]);
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
    }
    return pq.top();
}

vector<int> CommonElementsInAllRows(vector<vector<int>> v){
    unordered_map<int,int> mp;
    vector<int> ans;
    int n = v.size();
    int m = v[0].size();
    for (int j = 0; j < m; j++)
    {
        mp[v[0][j]] = 1;
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[v[i][j]] == i)
            {
                mp[v[i][j]] = i+1;

                if (i == m-1 && mp[v[i][j]] == m)
                {
                    ans.push_back(v[i][j]);
                }
            }
        }
    }
    return ans;
}

int main(){

}