#include<bits/stdc++.h>
using namespace std;

int helper(double mid , int n){
    double ans = 1.0;
    for (int i = 1; i < n; i++)
    {
        ans *= mid;
    }
    return ans;
}

double GetNthRoot(int n , int m){
    double low = 0;
    double high = m;
    double eps = 1e-7;
    
    while ((high - low) > eps)
    {
        double mid = (low+high)/2.0;
        if (helper(mid , n) < m)
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

int MedianofRowwisesorted(vector<vector<int>> &v , int r , int c){
    int minelement = INT_MAX;
    int maxelement = INT_MIN;

    for (int i = 0; i < r; i++)
    {
        minelement = min(minelement , v[i][0]);
        maxelement = max(maxelement , v[i][c-1]);
    }
    
    int n = (r*c+1)/2;
    while (minelement < maxelement)
    {
        int mid = minelement + (maxelement-minelement)/2;
        int place = 0;
        for (int i = 0; i < r; i++)
        {
            place += upper_bound(v[i].begin() , v[i].end() , mid) - v[i].begin();
        }
        if (place < n)
        {
            minelement = mid;
        }
        else
        {
            maxelement = mid;
        }
    }
    return minelement;
}

int singleElement(int arr[] , int n){
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr^arr[i];
    }
    return xorr;
}

int SearchInRotatedSortedArray(int arr[] , int n , int key){
    int lo = 0 , hi = n-1;

    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[lo] <= arr[mid])
        {
            if (key >= arr[lo] && key < arr[mid])
            {
                lo = mid+1;
            }
            else
            {
                hi = mid-1;
            }
        }
        if (arr[mid] <= arr[hi])
        {
            if (key > arr[mid] && key <= arr[hi])
            {
                lo = mid+1;
            }
            else
            {
                hi = mid-1;
            }
        }
    }
    return -1;
}

double medianof2sortedArr(int arr1[] , int n , int arr2[] , int m){
    if (n > m)
    {
        return medianof2sortedArr(arr2 , m , arr1 , n);
    }
    int lo = 0 , hi = n-1;
    while (lo <= hi)
    {
        int cut1 = lo + (hi-lo)/2;
        int cut2 = (n+m+1)/2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2-1];
        int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((n+m)%2 == 0)
            {
                return (double)(max(l1 , l2) + min(r1 , r2))/2.0;
            }
            else
            {
                return (double)min(l1 , l2);
            }
        }
        if (l1 > r2)
        {
            hi = cut1-1;
        }
        if (l2 > r1)
        {
            lo = cut1+1;
        }
    }
    return -1.0;
}

int kthElement(int arr1[], int arr2[], int n, int m, int k)
{
    if(n>m){
        return kthElement(arr2,arr1,m,n,k);
    }
    int s=max(0,k-m);
    int e=min(n,k);
    while(s<=e){
        int curr1 = (s+e)>>1;
        int curr2 = k-curr1;
        int l1=curr1==0?INT_MIN:arr1[curr1-1];
        int l2=curr2==0?INT_MIN:arr2[curr2-1];
        int r1=curr1==n?INT_MAX:arr1[curr1];
        int r2=curr2==m?INT_MAX:arr2[curr2];
        if(l1<=r2&&l2<=r1){
            return max(l1,l2);
        }
        if(l1>r2) e=curr1-1;
        else s=curr1+1;
    }
    return 1;
}

bool isPossible(int arr[] , int n , int m , int mid){
    int pages = 0;
    int s = 1;
    for (int i = 0; i < n; i++)
    {
        if (pages+arr[i] <= mid)
        {
            pages += arr[i];
        }
        else
        {
            s++;
            if (s > m && arr[i] > mid)
            {
                return false;
            }
            pages = arr[i];
        } 
    }
    return true;
}

int AllocatePages(int arr[] , int n , int m){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int s = 0 , e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;
    while (s <= e)
    {
        if (isPossible(arr , n , m , mid))
        {
            ans = mid;
            e = mid-1;
        }
        else
        {
            s = mid+1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

bool isPossibleCows(int arr[] , int n , int cows , int mid){
    int count = 1;
    int lastPlace = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - lastPlace >= mid)
        {
            count++;
            lastPlace = arr[i];
        }
    }
    if (count >= cows)
    {
        return true;
    }
    return false;
}

int AggressiveCows(int arr[] , int n , int cows){
    int lo = 0 , hi = arr[n-1] - arr[0];

    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if (isPossibleCows(arr , n , cows , mid))
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
    return hi;
}

int main(){

}