#include<bits/stdc++.h>
using namespace std;

//----------------------------Kth largest Element -----------------------------//

int Kthlargestelement(int arr[] , int n , int k){
    priority_queue<int , vector<int> , greater<int>> pq;
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

//-----------------------------K max sum combinations ------------------------------//

vector<int> KthMaxSumCombinations(vector<int> &a , vector<int> &b , int n , int k){
    sort(a.begin() , a.end() , greater<int>());
    sort(b.begin() , b.end() , greater<int>());

    priority_queue<pair<int,pair<int,int>>> pq;
    set<pair<int,int>> s;
    vector<int> ans;

    pq.push({a[0] + b[0] , {0,0}});
    s.insert({0 , 0});

    for (int i = 0; i < k; i++)
    {
        pair<int,pair<int,int>> t = pq.top();
        pq.pop();
        ans.push_back(t.first);

        int x = t.second.first;
        int y = t.second.second;

        int tmp = a[x+1]+b[y];
        if (s.find({x+1 , y}) == s.end())
        {
            pq.push({tmp , {x+1 , y}});
            s.insert({x+1 , y});
        }
        
        int tmp2 = a[x]+b[y+1];
        if (s.find({x , y+1}) == s.end())
        {
            pq.push({tmp , {x , y+1}});
            s.insert({x , y+1});
        }
    }
    return ans;
}

//-------------------------------find median from data stream----------------------------//

class MedianFinder {
    priority_queue<int> maxheap;
    priority_queue<int , vector<int> , greater<int>> minheap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxheap.empty() || maxheap.top() > num){
            maxheap.push(num);
        }
        else{
            minheap.push(num);
        }
        if(maxheap.size() > minheap.size()+1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size() > maxheap.size()+1){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    double findMedian() {
        if(maxheap.size() == minheap.size()){
            return maxheap.empty() ? 0 : (maxheap.top()+minheap.top())/2.0;
        }
        return (maxheap.size() > minheap.size()) ? maxheap.top() : minheap.top();
    }
};

//----------------------------merge k sorted array -------------------------//

vector<int> MergeKsortedarr(vector<vector<int>> v , int k){
    priority_queue<int , vector<int> , greater<int>> pq;

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

//-----------------------------Top k frequent elements ------------------------------//

vector<int> TopKfrequentelement(vector<int> nums , int k){
    unordered_map<int,int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;

    for(auto it = mp.begin(); it != mp.end(); it++){
        pq.push({it->second , it->first});
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

//--------------------------------Min cost of rod--------------------------------//

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

//-----------------------------Heap Sort-------------------------------//

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

int main(){

}