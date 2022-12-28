#include <bits/stdc++.h>
using namespace std;

vector<int> CummulativeSum(vector<int> v)
{
    int sum = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        sum += v[i];
        v[i] = sum;
    }
    return v;
}

vector<int> PositiveCumulativeSum(vector<int> v)
{
    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if (sum > 0)
        {
            ans.push_back(sum);
        }
    }
    return ans;
}

int GetIdenticalTwins(vector<int> arr)
{
    unordered_map<int, int> mp;
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] > 1)
        {
            ans += (mp[arr[i]] - 1);
        }
    }
    return ans;
}

int helper(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int c = 0;
    while (n)
    {
        c++;
        n /= 10;
    }
    return c;
}

vector<int> GetEvenNumberofDigits(vector<int> v)
{
    vector<int> ans;
    for (int i = 0; i < v.size(); i++)
    {
        int a = helper(v[i]);
        if (a % 2 == 0)
        {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

vector<int> Merge2sortedarr(vector<int> v1, vector<int> v2)
{
    vector<int> ans;
    int i = 0, j = 0;
    int n = v1.size(), m = v2.size();
    while (i < n && j < m)
    {
        if (v1[i] < v2[j])
        {
            ans.push_back(v1[i]);
            i++;
        }
        else
        {
            ans.push_back(v2[j]);
            j++;
        }
    }
    while (i < n)
    {
        ans.push_back(v1[i]);
        i++;
    }
    while (j < m)
    {
        ans.push_back(v2[j]);
        j++;
    }
    return ans;
}

void merge(vector<int> &arr, int endIndex)
{
    int subarr1Current = 0, subarr2Current = endIndex + 1;
    vector<int> ans;
    while (subarr1Current <= endIndex && subarr2Current < arr.size())
    {
        if (arr[subarr1Current] < arr[subarr2Current])
        {
            ans.push_back(arr[subarr1Current++]);
        }
        else
        {
            ans.push_back(arr[subarr2Current++]);
        }
    }
    while (subarr1Current <= endIndex)
    {
        ans.push_back(arr[subarr1Current++]);
    }
    while (subarr2Current < arr.size())
    {
        ans.push_back(arr[subarr2Current++]);
    }
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = ans[i];
    }
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    int n = mid - low + 1, m = high - mid;
    vector<int> subArr1(n), subArr2(m);
    for (int i = 0; i < n; i++)
    {
        subArr1[i] = arr[low + i];
    }
    for (int i = 0; i < m; i++)
    {
        subArr2[i] = arr[mid + 1 + i];
    }
    int i = 0, j = 0, k = low;
    while (i < n && j < m)
    {
        if (subArr1[i] <= subArr2[j])
        {
            arr[k] = subArr1[i];
            i++;
        }
        else
        {
            arr[k] = subArr2[j];
            j++;
        }
        k++;
    }
    while (i < n)
    {
        arr[k++] = subArr1[i++];
    }
    while (j < m)
    {
        arr[k++] = subArr2[j++];
    }
}

void helper1(vector<int> &arr, int i, int j)
{
    if (i >= j)
    {
        return;
    }
    int mid = (i + j) / 2;
    helper1(arr, i, mid);
    helper1(arr, mid + 1, j);
    merge(arr, i, mid, j);
}

void mergeSort(vector<int> &arr)
{
    helper1(arr, 0, arr.size() - 1);
}

int makePartition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    int currentIndx = low - 1;
    for (int i = low; i < high; i++)
    {
        if (arr[i] < pivot)
        {
            currentIndx++;
            int temp = arr[i];
            arr[i] = arr[currentIndx];
            arr[currentIndx] = temp;
        }
    }
    int temp = arr[high];
    arr[high] = arr[currentIndx + 1];
    arr[currentIndx + 1] = temp;
    return currentIndx + 1;
}

void quicksort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = makePartition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

void quickSort(vector<int> &arr)
{
    int n = arr.size();
    quicksort(arr, 0, n - 1);
}

vector<int> SquareSortedArr(vector<int> arr)
{
    vector<int> ans;
    for (int i = 0; i < arr.size(); i++)
    {
        ans.push_back(arr[i] * arr[i]);
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int GetMaxConsequtiveone(int arr[], int n)
{
    int mx = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 1)
        {
            mx = max(mx, c);
            c = 0;
        }
        else
        {
            c++;
        }
    }
    mx = max(mx, c);
    return mx;
}

bool isArthematicSequence(vector<int> v)
{
    if (v.size() <= 2)
    {
        return true;
    }
    sort(v.begin(), v.end());
    int d = v[1] - v[0];
    for (int i = 1; i < v.size() - 1; i++)
    {
        if (v[i + 1] - v[i] != d)
        {
            return false;
        }
    }
    return true;
}

int largestContiguousSum(vector<int> &arr)
{
    int sum = 0;
    int maxsum = 0;
    int maxval = INT_MIN, minval = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        maxval = max(maxval, arr[i]);
        minval = min(minval, arr[i]);
    }
    if (maxval < 0)
    {
        return minval;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
        }
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}

vector<int> PascalsTriangle(int n)
{
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].resize(i + 1);
        v[i][0] = v[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i - 1][j] + v[i - 1][j - 1];
        }
    }
    return v[n - 1];
}

void setRowColumnZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    bool firstrow = false, firstcol = false;
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] == 0)
        {
            firstcol = true;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (matrix[0][i] == 0)
        {
            firstrow = true;
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (firstrow)
    {
        for (int i = 0; i < m; i++)
        {
            matrix[0][i] = 0;
        }
    }
    if (firstcol)
    {
        for (int i = 0; i < n; i++)
        {
            matrix[i][0] = 0;
        }
    }
}

vector<vector<int>> MatrixRotation(vector<vector<int>> v)
{
    int n = v.size(), m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(v[i], v[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(v[i].begin(), v[i].end());
    }
    return v;
}

vector<int> primesUptoN(int n)
{
    bool isPrime[n + 1];
    for (int i = 2; i <= n; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j += i)
        {
            if (isPrime[i] == true)
            {
                isPrime[j] = false;
            }
        }
    }
    vector<int> answer;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] == true)
        {
            answer.push_back(i);
        }
    }
    return answer;
}

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    if (intervals.size() < 2)
    {
        return intervals;
    }

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    ans.push_back(intervals[0]);
    int j = 0;
    for (int i = 1; i < intervals.size(); i++)
    {
        if (ans[j][1] >= intervals[i][0])
        {
            ans[j][1] = max(ans[j][1], intervals[i][1]);
        }
        else
        {
            j++;
            ans.push_back(intervals[i]);
        }
    }
    return ans;
}

int getKthLargestElement(vector<int> &list, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < list.size(); i++)
    {
        pq.push(list[i]);
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    return pq.top();
}

void nextGreaterPermutation(vector<int> &arr)
{
    int k, l;
    int n = arr.size();
    for (k = n - 2; k >= 0; k--)
    {
        if (arr[k] < arr[k + 1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(arr.begin(), arr.end());
    }
    else
    {
        for (l = n - 1; l >= k; l--)
        {
            if (arr[l] > arr[k])
            {
                break;
            }
        }
        swap(arr[l], arr[k]);
        reverse(arr.begin() + k + 1, arr.end());
    }
}



int main()
{
}