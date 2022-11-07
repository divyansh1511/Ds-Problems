#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> FourSumProblem(vector<int> v , int sum){
    sort(v.begin() , v.end());
    int n = v.size();
    vector<vector<int>> ans;

    for (int i = 0; i < n-3; i++)
    {
        if (i == 0 || (i > 0 && v[i] != v[i-1]))
        {
            for (int j = i+1; j < n-2; j++)
            {
                if (j == i+1 || (j > 0 && v[j] != v[j-1]))
                {
                    int lo = j+1 , hi = n-1;
                    int key = sum - v[i] - v[j];
                    while (lo < hi)
                    {
                        if (v[lo] + v[hi] == key)
                        {
                            ans.push_back({v[i] , v[j] , v[lo] , v[hi]});
                            while (lo < hi && v[lo] == v[lo+1])
                            {
                                lo++;
                            }
                            while (lo < hi && v[hi] == v[hi-1])
                            {
                                hi--;
                            }
                            lo++;
                            hi--;
                        }
                        else if (v[lo]+v[hi] < key)
                        {
                            lo++;
                        }
                        else
                        {
                            hi--;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

bool DFS(vector<vector<char>> v , string word , int i , int j){
    if (!word.size())
    {
        return true;
    }
    if (i < 0 || i == v.size() || j < 0 || j == v[0].size() || v[i][j] != word[0])
    {
        return false;
    }
    char c = v[i][j];
    v[i][j] = '*';
    string s = word.substr(1);
    bool ans = DFS(v , s , i+1 , j) || DFS(v , s , i , j+1) || DFS(v , s , i-1 , j) || DFS(v , s , i , j-1);
    v[i][j] = c;
    return ans;
}

bool WordSearch(vector<vector<char>> v , string word){
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (DFS(v , word , i , j))
            {
                return true;
            }
        }
    }
    return false;
}

//------------------VERTICAL ORDER TRAVERSAL-----------------//

void helper(vector<vector<char>> &grid , int i , int j){
    if (i < 0 || i == grid.size() || j < 0 || j == grid[i].size() || grid[i][j] == '0')
    {
        return;
    }
    grid[i][j] = '0';
    helper(grid , i+1 , j);
    helper(grid , i , j+1);
    helper(grid , i-1 , j);
    helper(grid , i , j-1);
}

int numofIslands(vector<vector<char>> grid){
    int ans = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); i++)
        {
            if (grid[i][j] == '1')
            {
                ans++;
                helper(grid , i , j);
            }
        }
    }
    return ans;
}

//  CLONE A LINKED LIST WITH RANDOM POINTER

int main(){

}