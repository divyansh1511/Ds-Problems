#include <bits/stdc++.h>
using namespace std;

int mindiffamongk(int arr[], int n, int k)
{
    int mini = INT_MAX;
    sort(arr, arr + n);
    for (int i = 0; i < n - k + 1; i++)
    {
        mini = min(mini, arr[i + k - 1] - arr[i]);
    }
    return mini;
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, n, i);
    }
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        pq.push({it->second, it->first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int kthlargestelement(vector<int> v, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

vector<long long> nextLargerElement(vector<long long> arr, int n)
{
    stack<long long> st;
    vector<long long> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (st.empty())
        {
            ans[i] = -1;
            st.push(arr[i]);
        }
        else
        {
            while (!st.empty() && st.top() < arr[i])
            {
                st.pop();
            }
            if (st.empty())
            {
                ans[i] = -1;
            }
            else
            {
                ans[i] = st.top();
            }
            st.push(arr[i]);
        }
    }
    return ans;
}

vector<int> kclosestno(int arr[], int n, int x, int k)
{
    priority_queue<pair<int, int>> pq;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {

        if (x - arr[i] != 0)

            pq.push({-1 * abs(x - arr[i]), arr[i]});
    }

    for (int i = 0; i < k; i++)
    {

        v.push_back(pq.top().second);

        pq.pop();
    }

    return v;
}

vector<int> kthLargest(int k, int arr[], int n)
{
    // code here
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
        if (i != k - 1)
            ans.push_back(-1);
    }
    for (int i = k; i < n; i++)
    {
        ans.push_back(pq.top());
        if (ans.back() < arr[i])
        {
            pq.push(arr[i]);
            pq.pop();
        }
    }
    ans.push_back(pq.top());
    return ans;
}

int connectingropes(vector<int> v)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        pq.push(v[i]);
    }
    while (pq.size() > 1)
    {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + b);
    }
    return pq.top();
}

int largestsubarrsum(vector<int> &A, int n)
{
    unordered_map<int, int> mp;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sum == 0)
        {
            ans = max(ans, i + 1);
        }
        else if (mp.find(sum) != mp.end())
        {
            ans = max(ans, i - mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return ans;
}

class MedianFinder
{
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

public:
    MedianFinder()
    {
    }

    void addNum(int num)
    {
        if (maxheap.empty() || maxheap.top() > num)
        {
            maxheap.push(num);
        }
        else
        {
            minheap.push(num);
        }
        if (maxheap.size() > minheap.size() + 1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (minheap.size() > maxheap.size() + 1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian()
    {
        if (maxheap.size() == minheap.size())
        {
            return maxheap.empty() ? 0 : (maxheap.top() + minheap.top()) / 2.0;
        }
        return (maxheap.size() > minheap.size()) ? maxheap.top() : minheap.top();
    }
};

void KMaxCombinations(int A[], int B[], int N, int K)
{
    priority_queue<int> pq;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            pq.push(A[i] + B[j]);
            
    int count = 0;
    while (count < K)
    {
        cout << pq.top() << endl;
        pq.pop();
        count++;
    }
}

int main()
{
}