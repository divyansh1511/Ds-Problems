#include <bits/stdc++.h>
using namespace std;

bool static cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second < b.second;
}

int MaxMettings(int start[], int end[], int n)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({start[i], end[i]});
    }
    sort(v.begin(), v.end(), cmp);
    int a = v[0].second;
    int c = 1;
    for (int i = 1; i < n; i++)
    {
        if (v[i].first > a)
        {
            c++;
            a = v[i].second;
        }
    }
    return c;
}

bool static cmp1(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.second.second > b.second.second;
}

vector<int> JobScheduling(vector<pair<int, pair<int, int>>> Jobs, int n)
{
    sort(Jobs.begin(), Jobs.end(), cmp1);
    int a = 0;
    int sum = 0;
    vector<int> tmp(101, -1);
    for (int i = 0; i < n; i++)
    {
        int j = Jobs[i].second.first - 1;
        while (j >= 0 && tmp[j] != -1)
        {
            j--;
        }
        if (j >= 0 && tmp[j] == -1)
        {
            a++;
            sum += Jobs[i].second.second;
            tmp[j] = 1;
        }
    }
    return {a, sum};
}

vector<vector<int>> WaterConnectionProblem(int n, int p, vector<int> a, vector<int> b, vector<int> d)
{
    vector<int> inDeg(n + 1, 0);
    vector<pair<int, int>> adj(n + 1, {-1, -1});

    for (int i = 0; i < p; i++)
    {
        adj[a[i]] = {b[i], d[i]};
        inDeg[b[i]]++;
    }

    vector<vector<int>> ans;
    for (int i = 1; i <= n; i++)
    {
        if (inDeg[i] == 0 && adj[i].first != -1)
        {
            int lastNode = adj[i].first;
            int minDia = adj[i].second;

            while (adj[lastNode].first != -1)
            {
                minDia = min(minDia, adj[lastNode].second);
                lastNode = adj[lastNode].first;
            }

            ans.push_back({i, lastNode, minDia});
        }
    }

    return ans;
}

bool static cmp2(pair<int, int> &a, pair<int, int> &b)
{
    double l1 = (double)a.second / (double)a.first;
    double l2 = (double)b.second / (double)b.first;

    return l1 > l2;
}

double FractionalKnapsack(int wt[], int val[], int n, int W)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({wt[i], val[i]});
    }
    sort(v.begin(), v.end(), cmp2);
    double sum = 0.0;
    double we = 0.0;
    for (int i = 0; i < n; i++)
    {
        if (we >= W)
        {
            break;
        }
        if (we + v[i].first <= W)
        {
            sum = sum + v[i].second;
            we = we + v[i].first;
        }
        else if (we < W)
        {
            double d = (double)v[i].second / (double)v[i].first;
            sum += (W - we) * d;
            we = W;
        }
    }
    return sum;
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

// ---- maximum trains stopped on given number of platforms

int FindMinPlatforms(int arrival[], int depature[], int n)
{
    int i = 1;
    int j = 0;
    sort(arrival, arrival + n);
    sort(depature, depature + n);
    int maxm = 1;
    int platform = 1;
    while (i < n && j < n)
    {
        if (arrival[i] <= depature[j])
        {
            platform++;
            i++;
        }
        else
        {
            platform--;
            j++;
        }
        maxm = max(maxm, platform);
    }
    return maxm;
}

int buyMaximumProducts(int n, int k, int arr[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    for (int i = 0; i < n; i++)
    {
        q.push({arr[i], i + 1});
    }
    int count = 0;
    while (k > 0 && q.size())
    {
        pair<int, int> temp = q.top();
        q.pop();
        if (temp.first * temp.second <= k)
        {
            count += temp.second;
            k -= temp.first * temp.second;
        }
        else
        {
            count += k / temp.first;
            k = 0;
        }
    }
    return count;
}

vector<int> candyStore(int a[], int N, int K)
{
    int cnt = ceil(N * 1.0 / (K + 1));
    sort(a, a + N);
    int s1 = 0, s2 = 0;
    for (int i = 0; i < cnt; i++)
    {
        s1 += a[i];
        s2 += a[N - 1 - i];
    }
    return {s1, s2};
}

int MaxSumDiff(int arr[], int n)
{
    vector<int> v;
    sort(arr, arr + n);
    for (int i = 0; i < n / 2; i++)
    {
        v.push_back(arr[i]);
        v.push_back(arr[n - i - 1]);
    }
    if (n % 2 != 0)
    {
        v.push_back(arr[n / 2]);
    }
    int maxsum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        maxsum = maxsum + abs(arr[i] - arr[i + 1]);
    }
    maxsum = maxsum + abs(arr[n - 1] - arr[0]);
    return maxsum;
}

long long ChoclateDistributionProblem(vector<long long> a, long long n, long long m)
{
    sort(a.begin(), a.end());
    int i = 0;
    int j = m - 1;
    long long mini = INT_MAX;
    while (j < n)
    {
        long long diff = a[j] - a[i];
        mini = min(mini, diff);
        i++;
        j++;
    }
    return mini;
}

long long minCostToRopes(long long arr[], long long n)
{
    long long sum = 0;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (long long i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    while (pq.size() > 1)
    {
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        sum += (a + b);
        pq.push(a + b);
    }
    return sum;
}

string smallestNumber(int S, int D)
{
    if (S > D * 9)
    {
        return "-1";
    }
    S--;
    int res = (int)pow(10, D - 1);
    int d = 1;
    while (S > 0)
    {
        res += d * min(S, 9);
        S -= min(S, 9);
        d *= 10;
    }
    return to_string(res);
}

int main()
{
}