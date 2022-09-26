#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1){
        return false;
    }
    for (int i = 2; i < n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int discountAMT(int n){
    vector<int> v;
    while( n )
    {
        int a = n%10;
        if (isPrime(a))
        {
            v.push_back(a);
        }
        n = n/10;
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++)
    {
        ans += v[i];
    }
    return ans;
}

vector<int> funcDistance(vector<int> inputDist , int start , int end){
    vector<int> ans;
    for (int i = 0; i < inputDist.size(); i++)
    {
        if (inputDist[i] >= start && inputDist[i] <= end)
        {
            ans.push_back(inputDist[i]);
        }
    }
    return ans;
}

int main(){
    cout<<discountAMT(578)<<endl;
}