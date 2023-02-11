#include<bits/stdc++.h>
using namespace std;

//---------------------------n meeting in one room ------------------------------//

bool static cmp(pair<int,int> &a , pair<int,int> &b){
    return a.second < b.second;
}

int Noofmeetings(int st[] , int en[] , int n){
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({st[i] , en[i]});
    }
    sort(v.begin() , v.end() , cmp);
    int ans = 1;
    int tmp = v[0].second;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first > tmp)
        {
            ans++;
            tmp = v[i].second;
        }
    }
    return ans;
}

//---------------------------------Minimum Platforms --------------------------------//

int MinPlatforms(int arr[] , int dep[] , int n){
    int i = 1 , j = 0;
    sort(arr , arr+n);
    sort(dep , dep+n);
    int maxm = 1;
    int platform = 1;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            platform++;
            i++;
        }
        else
        {
            platform--;
            j++;
        }
        maxm = max(maxm , platform);
    }
    return maxm;
}

//----------------------------------Job Scheduling -------------------------------//

bool static cmp1(vector<int> &a , vector<int> &b){
    return a[2] > b[2];
}

vector<int> JobScheduling(vector<vector<int>> v , int n){
    sort(v.begin() , v.end() , cmp1);

    vector<int> tmp(101 , -1);
    int jobs = 0 , profit = 0;

    for (int i = 0; i < n; i++)
    {
        int j = v[i][1] - 1;
        while (j >= 0 && tmp[j] != -1)
        {
            j--;
        }
        if (j >= 0 && tmp[j] == -1)
        {
            jobs++;
            profit += v[i][2];
            tmp[j] = 1;
        }
    }
    return {jobs , profit};
}

//-------------------------------Fractional Knapsack -------------------------------------//

bool static cmp2(pair<int,int> &a , pair<int,int> &b){
    double x = a.first/a.second;
    double y = b.first/b.second;

    return x>y;

}

double fractionalKnapsack(vector<pair<int,int>> v , int n , int W){
    sort(v.begin() , v.end() , cmp2);

    double sum = 0.0;
    double weight = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (weight >= W)
        {
            break;
        }
        if (weight + v[i].second < W)
        {
            sum += v[i].first;
            weight = v[i].second;
        }
        else if(weight<W)
        {
            double d=(double)v[i].first/(double)v[i].second;
            sum=sum+(W-weight)*d;
            weight=W;
        }
    }
    return sum;
}

//----------------------------Bulbs------------------------------//

int bulbs(int arr[] , int n){
    int k = 0 , ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (k == arr[i])
        {
            if (k == 0)
            {
                k = 1;
            }
            else
            {
                k = 0;
            }
            ans++;
        }
    }
    return ans;
}

//---------------------------------Distribute Candy ------------------------------//

int Candy(int arr[] , int n){
    vector<int> ans(n , 1);
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > arr[i-1])
        {
            ans[i] = ans[i-1]+1;
        }
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (arr[i-1] > arr[i])
        {
            ans[i-1] = max(ans[i-1] , ans[i]+1);
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += ans[i];
    }
    return res;
}

//--------------------------------Gas Stations ------------------------------//

int GasStations(int gas[] , int cost[] , int n){
    int g = 0 , c = 0;
    for (int i = 0; i < n; i++)
    {
        g += gas[i];
        c += cost[i];
    }
    if (c > g)
    {
        return -1;
    }
    int st = 0;
    int tot = 0;
    for (int i = 0; i < n; i++)
    {
        tot += (gas[i]-cost[i]);
        if (tot < 0)
        {
            st = i+1;
            tot = 0;
        }
    }
    return st;
}

vector<int> MinNumberOfCoins(int N)
{
    vector<int> v = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> ans;
    int i = 9;
    while (N != 0)
    {
        if (v[i] <= N)
        {
            N -= v[i];
            ans.push_back(v[i]);
        }
        else
        {
            i--;
        }
    }
    return ans;
}

int main(){

}