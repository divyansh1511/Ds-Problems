#include <bits/stdc++.h>
using namespace std;

//--------------------------------Get Nth root ------------------------------//

double multiply(double num, int n)
{
    double ans = 1.0;
    for (int i = 1; i <= n; i++)
    {
        ans *= num;
    }
    return ans;
}

int GetNthRoot(int n, int m)
{
    double low = 1, high = m;
    double eps = 1e-7;
    while ((high - low) > eps)
    {
        double mid = (high + low) / 2.0;
        if (multiply(mid, n) < m)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

//-------------------------------Matrix Median --------------------------------//

int matrixmedian(vector<vector<int>> matrix, int r, int c)
{
    int minele = INT_MAX;
    int maxele = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        minele = min(minele, matrix[i][0]);
        maxele = max(maxele, matrix[i][c - 1]);
    }

    int n = (r * c + 1) / 2;
    while (minele < maxele)
    {
        int mid = (minele + maxele) / 2;
        int p = 0;
        for (int i = 0; i < r; i++)
        {
            p += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }
        if (p < n)
        {
            minele = mid + 1;
        }
        else
        {
            maxele = mid;
        }
    }
    return minele;
}

//--------------------------Single Element in sorted array ---------------------------------//

int Singleele(int arr[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        int mid = (i + j) / 2;
        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 1 && arr[mid] == arr[mid - 1]))
        {
            i = mid + 1;
        }
        else
        {
            j = mid;
        }
    }
    return arr[i];
}

//----------------------------search in rotated sorted array ----------------------------//

int search(vector<int> &arr, int key)
{
    int n = arr.size();
    int lo = 0, hi = n - 1;
    while (lo <= hi)
    {
        int mid = (lo + hi) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[lo] <= arr[mid])
        {
            if (key >= arr[lo] && key <= arr[mid])
            {
                hi = mid - 1;
            }
            else
            {
                lo = mid + 1;
            }
        }
        else
        {
            if (key >= arr[mid] && key <= arr[hi])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
    }
    return -1;
}

//-------------------------------Kth element in 2 sorted array ---------------------------//

int kthElement(int arr1[], int arr2[], int end1, int end2, int k)
{
    int i = 0, j = 0;
    while (i < end1 && j < end2 && k >= 0)
    {
        if (k == 1)
        {
            return min(arr1[i], arr2[j]);
        }
        if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
        k--;
    }
    while (i < end1 && k >= 0)
    {
        if (k == 1)
        {
            return arr1[i];
        }
        k--;
        i++;
    }
    while (j < end2 && k >= 0)
    {
        if (k == 1)
        {
            return arr2[j];
        }
        k--;
        j++;
    }
    return -1;
}

//------------------------------Allocate Books ---------------------------//

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

//---------------------------

int main()
{
}