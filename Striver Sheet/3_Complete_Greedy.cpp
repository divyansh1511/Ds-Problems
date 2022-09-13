#include<bits/stdc++.h>
using namespace std;

static bool cmp(vector<int> &a , vector<int> &b){
    if (a[0] == b[0])
    {
        return a[1] < b[1];
    }
    return a[0] < b[0];
}

int NmeetinginOneroom(vector<vector<int>> v){
    int n = v.size();
    sort(v.begin() , v.end() , cmp);
    vector<vector<int>> ans;
    ans.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        if (ans[ans.size()-1][1] < v[i][0])
        {
            ans.push_back(v[i]);
        }
    }
    return ans.size();
}

int NoofPlatforms(int arrival[] , int departure[] , int n){
    int i=1 , j=0;
    sort(arrival , arrival+n);
    sort(departure , departure+n);
    int ans = 1;
    int platform = 1;
    while (i < n && j < n)
    {
        if (arrival[i] < departure[j])
        {
            platform++;
            i++;
        }
        else
        {
            platform--;
            j++;
        }
        ans = max(ans , platform);
    }
    return ans;
}

vector<int> JobScheduling(vector<vector<int>> &v){
    int n = v.size();
    sort(v.begin() , v.end());
    int a = 0;
    int sum = 0;
    vector<int> tmp(101,-1);
    for (int i = 0; i < n; i++)
    {
        int j = v[i][1] - 1;
        while (j >= 0 && tmp[j] != -1)
        {
            j--;
        }
        if (j >= 0 && tmp[j] == -1)
        {
            a++;
            sum += v[i][2];
            tmp[j] = 1;
        }
    }
    return {a , sum};
}

static bool cmp2(vector<int> &a , vector<int> &b){
    double x = (double)a[1]/(double)a[0];
    double y = (double)b[1]/(double)b[0];

    return x > y;
}

double FractionalKnapsack(vector<vector<int>> &v , int W){
    sort(v.begin() , v.end() , cmp2);
    double sum = 0.0;
    double wei = 0.0;
    for (int i = 0; i < v.size(); i++)
    {
        if (wei >= W)
        {
            break;
        }
        else if (wei+v[i][0] <= W)
        {
            sum += v[i][1];
            wei += v[i][0];
        }
        else if (wei < W)
        {
            double a = (double)v[i][1]/(double)v[i][0];
            sum += (W-wei)*a;
            wei = W;
        }
    }
    return sum;
}

int minnumberofcoins(int arr[] , int n , int sum){
    sort(arr , arr+n , greater<int>());
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        while (sum > arr[i])
        {
            sum -= arr[i];
            c++;
        }
    }
    return c;
}

int main(){

}