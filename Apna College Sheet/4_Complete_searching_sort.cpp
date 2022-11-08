#include <bits/stdc++.h>
using namespace std;

bool isPossible(long long arr1[], long long arr2[], int n, long long K)
{
    long long a = *max_element(arr1, arr1 + n);
    long long b = *max_element(arr2, arr2 + n);

    long long ans = a + b;

    return ans >= K;
}

string countSort(string arr)
{
    map<char, int> mp;
    string ans = "";
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]]++;
    }
    for (auto x : mp)
    {
        while (x.second > 0)
        {
            ans.push_back(x.first);
            x.second--;
        }
    }
    return ans;
}

vector<int> commonElements(int a[], int b[], int c[], int n1, int n2, int n3)
{
    vector<int> v;
    unordered_set<int> uset, uset2, uset3;
    for (int i = 0; i < n1; i++)
    {
        uset.insert(a[i]);
    }
    for (int i = 0; i < n2; i++)
    {
        uset2.insert(b[i]);
    }

    for (int i = 0; i < n3; i++)
    {
        if (uset.find(c[i]) != uset.end() && uset2.find(c[i]) != uset.end())
        {
            if (uset3.find(c[i]) == uset3.end())
                v.push_back(c[i]);
            uset3.insert(c[i]);
        }
    }
    return v;
}

int ceilSearch(int arr[], int low, int high, int x)
{
    if (x == 0)
    {
        return -1;
    }
    int mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}

bool findPair(int arr[], int size, int n)
{
    sort(arr, arr + size);
    int i = 0, j = 1;
    while (i < size && j < size)
    {
        if ((arr[j] - arr[i]) == n && i != j)
        {
            return true;
        }
        else if ((arr[j] - arr[i]) < n || i == j)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return false;
}

int majorityElement(int a[], int size)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < size; i++)
    {
        mp[a[i]]++;
    }
    int c = -1;
    for (auto it : mp)
    {
        if (it.second > size / 2)
        {
            c = it.first;
            break;
        }
    }
    return c;
}

long long countTriplets(long long arr[], int n, long long sum)
{
    sort(arr, arr + n);
    long long ans = 0;
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;
        long long a = sum - arr[i];
        while (j < k)
        {
            if (arr[j] + arr[k] < a)
            {
                ans += (k - j);
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return ans;
}

int FindMaxSum(int arr[], int n)
{
    int a = arr[0];
    int b = 0;
    int temp = 0;
    for (int i = 1; i < n; i++)
    {
        temp = (a > b) ? a : b;
        a = b + arr[i];
        b = temp;
    }
    return (a > b) ? a : b;
}

void merge(long long arr1[], long long arr2[], int n, int m)
{
    int i = 0, j = 0, k = n - 1;
    while (i <= k && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[k], arr2[j]);
            k--;
            j++;
        }
        else
        {
            i++;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

void merge(long long arr[], long long l, long long mid, long long r, long long &count)
{
    long long int i = l;
    long long int j = mid + 1;
    long long int k = l;
    long long int B[r + 1];

    while (i <= mid && j <= r)
    {
        if (arr[i] > arr[j])
        {
            count += mid - i + 1; // extra line added in merge sort
            B[k++] = arr[j++];
        }
        else
            B[k++] = arr[i++];
    }

    while (i <= mid)
    {
        B[k++] = arr[i++];
    }
    while (j <= r)
    {
        B[k++] = arr[j++];
    }

    for (int k = l; k <= r; k++)
    {
        arr[k] = B[k];
    }
}

void mergeSort(long long arr[], long long l, long long r, long long count)
{

    if (l >= r)
        return;

    int mid = (l + r) / 2;
    mergeSort(arr, l, mid, count);
    mergeSort(arr, mid + 1, r, count);
    merge(arr, l, mid, r, count);

    return;
}

long long int inversionCount(long long arr[], long long N)
{
    long long count = 0; // reini
    mergeSort(arr, 0, N - 1, count);
    return count;
}

vector<long long int> productExceptSelf(vector<long long int> &arr, int n)
{
    vector<long long int> ans(n);
    long long int pro = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] = pro;
        pro *= arr[i];
    }
    pro = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] *= pro;
        pro *= arr[i];
    }
    return ans;
}

bool checkReverse(int arr[], int n)
{
    int temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];
    sort(temp, temp + n);
    int front;
    for (front = 0; front < n; front++)
        if (temp[front] != arr[front])
            break;
    int back;
    for (back = n - 1; back >= 0; back--)
        if (temp[back] != arr[back])
            break;
    if (front >= back)
        return true;

    do
    {
        front++;
        if (arr[front - 1] < arr[front])
            return false;
    } while (front != back);

    return true;
}

double MedianOfArrays(vector<int> &array1, vector<int> &array2)
{
    int m = array1.size();
    int n = array2.size();
    vector<int> C;

    int i, j;
    i = j = 0;

    while (i < m && j < n)
    {
        if (array1[i] < array2[j])
        {
            C.push_back(array1[i]);
            i++;
        }
        else
        {
            C.push_back(array2[j]);
            j++;
        }
    }

    while (i < m)
    {
        C.push_back(array1[i]);
        i++;
    }

    while (j < n)
    {
        C.push_back(array2[j]);
        j++;
    }

    int s = C.size();
    if (s % 2 == 0)
    {
        return float(C[s / 2] + C[s / 2 - 1]) / 2;
    }
    else
    {
        return C[s / 2];
    }
}

bool isPossible(int A[], int n, int m, int mid)
{
    int pages = 0;
    int s = 1;
    for (int i = 0; i < n; i++)
    {
        if (pages + A[i] <= mid)
        {
            pages += A[i];
        }
        else
        {
            s++;
            if (s > m || A[i] > mid)
            {
                return false;
            }
            pages = A[i];
        }
    }
    return true;
}

int findPages(int A[], int N, int M)
{
    // code here
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += A[i];
    }
    int s = 0, e = sum;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (isPossible(A, N, M, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int minSwaps(vector<int> &nums)
{
    int n = nums.size();
    vector<int> temp = nums;
    sort(temp.begin(), temp.end());
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[nums[i]] = i;
    }
    int swaps = 0;
    for (int i = 0; i < n;)
    {
        if (mp[temp[i]] != i)
        {
            swap(temp[i], temp[mp[temp[i]]]);
            swaps++;
        }
        else
        {
            i++;
        }
    }
    return swaps;
}

int main()
{
}