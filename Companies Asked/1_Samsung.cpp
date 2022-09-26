#include<bits/stdc++.h>
using namespace std;

int MaximumIndexDiff(int arr[] , int n){
    int left[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = min(left[i-1] , arr[i]);
    }
    // left -> 3 , 3 , 3 , 3 , 1 , 1
    int maxdist = INT_MIN;
    int i = n-1 , j = n-1;
    while (i >= 0 && j >= 0)
    {
        if (arr[j] >= left[i])
        {
            maxdist = max(maxdist , j-i);
            i--;
        }
        else
        {
            j--;
        }
    }
    return maxdist;
}

int main(){
    int arr[] = {3,4,42,30,1,21};
    cout<<MaximumIndexDiff(arr , 6)<<endl;
}