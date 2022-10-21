#include<bits/stdc++.h>
using namespace std;

int MinimumUniqueArraySum(int arr[] , int n){
    sort(arr , arr+n);
    int sum = arr[0];
    int prev = arr[0];

    for (int i = 1; i < n; i++)
    {
        int curr = arr[i];
        if (prev >= curr)
        {
            curr = prev+1;
        }
        sum += curr;
        prev = curr;
    }
    return sum;
}

string UniquePath(string n , string m){
    int n1 = stoi(n);
    int m1 = stoi(m);

    vector<vector<int>> dp(n1+1 , vector<int>(m1+1 , 1));
    for (int i = 1; i <= n1; i++)
    {
        for (int j = 1; j <= m1; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return to_string(dp[n1][m1]);
}

//----------max connected components graphs--------------------// ---> Done using adjacency list

int main(){

}