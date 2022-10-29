#include<bits/stdc++.h>
using namespace std;

int FindSwapValue(int arr1[] , int n , int arr2[] , int m){
    set<int> s;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        sum1 += arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        sum2 += arr2[i];
        s.insert(sum2);
    }
    int totsum = sum1 + sum2;
    if (totsum%2 == 0)
    {
        return -1;
    }
    int desiredsum = totsum>>1;
    for (int i = 0; i < n; i++)
    {
        int diff = desiredsum-sum1;
        int tofind = arr1[i]+diff;
        if (s.find(tofind) != s.end())
        {
            return 1;
        }
    }
    return -1;
}

int main(){

}