#include <bits/stdc++.h>
using namespace std;

bool cointainele(int arr[], int n, int k)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        int mid = (i + j) / 2;
        if (arr[mid] == k)
        {
            return true;
        }
        else if (arr[mid] < k)
        {
            i = mid + 1;
        }
        else
        {
            j = mid;
        }
    }
    return false;
}

int binarySearch(vector<int> &arr, int low, int high, int key)
{
    int mid = low + (high - low) / 2;
    int ans = -1;
    while (low < high)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            high = mid;
        }
        else if (arr[mid] > key)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return ans;
}

int binarySearch1(vector<int> &arr, int low, int high, int key)
{
    int mid = low + (high - low) / 2;
    int ans = -1;
    while (low < high)
    {
        if (arr[mid] == key)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] > key)
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
        mid = low + (high - low) / 2;
    }
    return ans;
}

vector<int> searchRange(vector<int> &arr, int key)
{
    int i = 0, j = arr.size();
    int a = binarySearch(arr, i, j, key);
    if (a == -1)
    {
        return {-1, -1};
    }
    int b = binarySearch1(arr, i, j, key);
    return {a, b};
}

int getNegativeNumbersCount(vector<int> &arr)
{
    int countNegative = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] < 0)
        {
            countNegative++;
        }
    }
    return countNegative;
}

int getNextGreaterElement(vector<int> &arr, int key)
{
    int n = arr.size();
    if (arr[n - 1] <= key)
    {
        return key;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > key)
        {
            return arr[i];
        }
    }
}

int getInsertPosition(vector<int> &arr, int key)
{
    int n = arr.size();
    if (key >= arr[n - 1])
    {
        return n;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < key)
        {
            ans = i + 1;
        }
    }
    return ans;
}

bool isPerfectSquare(int num)
{
    int low = 0, high = num;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long a = mid * mid;
        if (a == num)
        {
            return true;
        }
        else if (a < num)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return false;
}

int getElementIndex(vector<int> &arr, int k)
{
    int i = 0, j = arr.size() - 1;
    int n = j + 1;
    int mid = i + (j - i) / 2;
    while (i <= j)
    {
        if (arr[mid] == k)
        {
            return mid;
        }
        if (arr[0] <= arr[mid])
        {
            if (arr[mid] > k && k >= arr[0])
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        else
        {
            if (arr[mid] < k && k <= arr[n - 1])
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        mid = i + (j - i) / 2;
    }
    return -1;
}

int findNonRepeatingElement(vector<int> &arr)
{
    int ans = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        ans ^= arr[i];
    }
    return ans;
}

int searchRoot(int x)
{
    if (x <= 1)
        return x;
    int l = 0, r = x;
    while (l <= r)
    {
        int m = l + (r - l) / 2;
        if (x / m == m)
            return m;
        else if (x / m < m)
            r = m - 1;
        else
            l = m + 1;
    }
    return r;
}

bool searchMatrix(vector<vector<int>> &matrix, int key)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int lo = 0, hi = n * m - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        int a = mid / m;
        int b = mid % m;
        if (matrix[a][b] == key)
        {
            return true;
        }
        else if (matrix[a][b] < key)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return false;
}

int calculateMedianOfMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size(), m = matrix[0].size();
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (matrix[i][0] < mini)
        {
            mini = matrix[i][0];
        }
        if (matrix[i][m - 1] > maxi)
        {
            maxi = matrix[i][m - 1];
        }
    }
    int d = (n * m + 1) / 2;
    while (mini < maxi)
    {
        int mid = mini + (maxi - mini) / 2;
        int p = 0;
        for (int i = 0; i < n; i++)
        {
            p += (upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin());
        }
        if (p < d)
        {
            mini = mid + 1;
        }
        else
        {
            maxi = mid;
        }
    }
    return mini;
}

int main()
{
}