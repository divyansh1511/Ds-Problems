#include<bits/stdc++.h>
using namespace std;

int RowWiseSortedMatrixMedian(vector<vector<int>> v){
    int n = v.size();
    int m = v[0].size();
    int minelement = INT_MAX;
    int maxelement = INT_MIN;
    
    for (int i = 0; i < n; i++)
    {
        minelement = min(minelement , v[i][0]);
        maxelement = max(maxelement , v[i][m-1]);
    }
    int a = (n*m+1)/2;
    while (minelement <= maxelement)
    {
        int mid = minelement + (maxelement-minelement)/2;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            p += upper_bound(v[i].begin() , v[i].end() , mid) - v[i].begin();
        }
        if (p < n)
        {
            minelement = mid+1;
        }
        else
        {
            maxelement = mid;
        }
    }
    return minelement;
}

int main(){

}