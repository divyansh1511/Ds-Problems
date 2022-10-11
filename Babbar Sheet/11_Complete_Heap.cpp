#include <bits/stdc++.h>
using namespace std;

void Heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        Heapify(arr, n, largest);
    }
}

void buildHeap(int arr[], int n)
{
    int stidx = (n / 2) - 1;
    for (int i = stidx; i >= 0; i--)
    {
        Heapify(arr, n, i);
    }
}

void HeapSort(int arr[], int n)
{
    for (int i = n / 2; i >= 0; i--)
    {
        Heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0);
    }
}

vector<int> MaxSubarrSum(int arr[], int n, int k)
{
    vector<int> ans;
    deque<pair<int, int>> dq;
    for (int i = 0; i < n; i++)
    {
        if (!dq.empty() && dq.front().second <= (i - k))
        {
            dq.pop_front();
        }
        while (!dq.empty() && dq.back().first < arr[i])
        {
            dq.pop_back();
        }
        dq.push_back({arr[i], i});
        if (i >= k - 1)
        {
            ans.push_back(dq.front().first);
        }
    }
    return ans;
}

int KthLargetsElement(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

int kthSmallestElement(int arr[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

vector<int> MergeKsortedArray(vector<vector<int>> v, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            pq.push(v[i][j]);
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

void heapinsert(int b, vector<int> &a)
{
    int len = a.size();
    a.push_back(b);
    while (a[len] > a[(len - 1) / 2])
    {
        swap(a[len], a[(len - 1) / 2]);
        len = (len - 1) / 2;
    }
}

vector<int> Merge2BinaryHeap(vector<int> a, vector<int> b, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        heapinsert(b[i], a);
    }
    return a;
}

int kthLargestContigousSubarrsum(vector<int> &Arr, int N, int K)
{
    priority_queue<int> pq;
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += Arr[j];
            pq.push(sum);
        }
    }
    while (K > 1)
    {
        pq.pop();
        K--;
    }
    return pq.top();
}

string ReorganizeString(string s)
{
    vector<int> v(26, 0);
    int mostfreq = 0;
    int i = 0;
    for (char c : s)
    {
        v[c - 'a']++;
        if (v[c - 'a'] > v[mostfreq])
        {
            mostfreq = c - 'a';
        }
    }
    if (2 * v[mostfreq] - 1 > s.size())
    {
        return "";
    }
    while (v[mostfreq])
    {
        s[i] = 'a' + mostfreq;
        i += 2;
        v[mostfreq]--;
    }
    for (int j = 0; j < 26; j++)
    {
        while (v[j])
        {
            if (i >= s.size())
            {
                i = 1;
            }
            s[i] = 'a' + j;
            v[j]--;
            i += 2;
        }
    }
    return s;
}

class Solution
{
public:
    priority_queue<int> maxHeap;                            // creating a maxHeap
    priority_queue<int, vector<int>, greater<int>> minHeap; // creating a min Heap
    void insertHeap(int &x)
    {
        if (maxHeap.size() == 0 || maxHeap.top() >= x)
            maxHeap.push(x);
        else
            minHeap.push(x);

        balanceHeaps();
    }

    // Function to balance heaps.
    void balanceHeaps()
    {
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }

        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    // Function to return Median.
    double getMedian()
    {
        if (maxHeap.size() == minHeap.size())
            return ((double)maxHeap.top() + (double)minHeap.top()) / 2.0;

        return (double)maxHeap.top();
    }
};

long long minCost(long long arr[], long long n)
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

int main()
{
    
}