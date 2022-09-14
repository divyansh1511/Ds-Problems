#include<bits/stdc++.h>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){           //T.C :-> O(log N)
        size = size+1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index/2;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deletefromheap(){
        if (size == 0)
        {
            cout<<"heap is empty"<<endl;
            return;
        }
        
        arr[1] = arr[size];
        size--;
        int i = 1;
        while (i < size)
        {
            int leftchild = 2*i;
            int rightchild = 2*i+1;
            if (leftchild < size && arr[i] < arr[leftchild])
            {
                swap(arr[i] , arr[leftchild]);
                i = leftchild;
            }
            else if (rightchild < size && arr[i] < arr[rightchild])
            {
                swap(arr[i] , arr[rightchild]);
                i = rightchild;
            }
            else
            {
                return;
            }
        }
    }

    void print(){
        for (int i = 1; i <= size; i++)
        {
            cout<<arr[i]<<" ";
        }
    }
};

void heapify(int arr[] , int n , int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;
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
        swap(arr[largest] , arr[i]);
        heapify(arr , n , largest);
    }
}

void converttoheap(int arr[] , int n){
    for (int i = n/2; i > 0; i--)
    {
        heapify(arr , n , i);
    }
}

void HeapSort(int arr[] , int n){
    int size = n;

    while (size > 1)
    { 
        swap(arr[size] , arr[1]);
        size--;
        heapify(arr , size ,  1);
    }
}

int kthlargestElement(int arr[] , int n , int k){
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

vector<int> MaximumSumCombination(vector<int> a , vector<int> b , int k){
    sort(a.begin() , a.end() , greater<int>());
    sort(b.begin() , b.end() , greater<int>());
    priority_queue<int , vector<int> , greater<int>> pq;

    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if ((a[i] + b[j]) >= pq.top())
            {
                pq.pop();
                pq.push(a[i]+b[j]);
            }
            else
            {
                break;
            }
        }
    }
    
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    sort(ans.begin() , ans.end() , greater<int>());
    return ans;
}

class MedianStream{
    public:
    priority_queue<int> maxheap;
    priority_queue<int,vector<int> , greater<int>> minheap;
    MedianStream(){

    }

    void insert(int val){
        if (maxheap.empty() || maxheap.top() > val)
        {
            maxheap.push(val);
        }
        else
        {
            minheap.push(val);
        }
        if (maxheap.size() > minheap.size()+1)
        {
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if (minheap.size() > maxheap.size()+1)
        {
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }

    double findMedian(){
        if (maxheap.size() == minheap.size())
        {
            return maxheap.size() ? 0 : (minheap.top() + maxheap.top())/2.0;
        }
        return maxheap.size() > minheap.size() ? maxheap.top() : minheap.top();
    }
};

vector<int> merge(vector<int> a , vector<int> b){
    vector<int> ans;
    int n = a.size() , m = b.size();
    int i = 0 , j = 0;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            ans.push_back(a[i++]);
        }
        else
        {
            ans.push_back(a[j++]);
        }
    }
    while (i < n)
    {
        ans.push_back(a[i++]);
    }
    while (j < m)
    {
        ans.push_back(b[j++]);
    }
    return ans;
}

vector<int> helper(vector<vector<int>> &v , int st , int en){
    if (st == en)
    {
        return v[st];
    }
    if (st+1 == en)
    {
        return merge(v[st] , v[en]);
    }
    int mid = st + (en-st)/2;

    vector<int> f = helper(v , st , mid);
    vector<int> s = helper(v , mid+1 , en);

    return merge(f , s);
}

vector<int> mergeKsortedArray(vector<vector<int>> &v , int k){
    vector<int> res = helper(v , 0 , k-1);
    return res;
}

vector<int> TopKfrequentele(vector<int> nums , int k){
    unordered_map<int,int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    priority_queue<pair<int,int>, vector<pair<int ,int>> , greater<pair<int , int>>> pq;
    for(auto it : mp){
        pq.push({it.first , it.second});
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

int main(){

}