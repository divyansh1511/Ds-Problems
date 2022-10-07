#include<bits/stdc++.h>
using namespace std;

int FindPeak(int arr[] , int n){
    int i = 0 , j = n-1;
    while (i < j)
    {
        int mid = (i+j)/2;
        if (arr[mid] < arr[mid+1])
        {
            i = mid+1;
        }
        else
        {
            j = mid;
        }
    }
    return i;
}

int BinarySearchfirsthalf(int arr[] , int st , int end , int key){
    int i = st , j = end;
    int mid = i + (j-i)/2;
    while (i <= j)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            i = mid+1;
        }
        else
        {
            j = mid;
        }
        mid = i + (j-i)/2;
    }
    return -1;
}

int BinarySearchSecondhalf(int arr[] , int st , int end , int key){
    int i = st , j = end;
    int mid = i + (j-i)/2;
    while (i <= j)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            i = mid+1;
        }
        else
        {
            j = mid;
        }
        mid = i + (j-i)/2;
    }
    return -1;
}


int SearchInBitonicArr(int arr[] , int n , int key){
    int peak = FindPeak(arr , n);
    int a = BinarySearchfirsthalf(arr , 0 , peak-1 , key);
    if (a != -1)
    {
        return a;
    }
    return BinarySearchSecondhalf(arr , peak , n-1 , key);
}

int SmallerOrEqualelements(int arr[] , int n , int k){
    int i = 0 , j = n-1;
    while (i <= j)
    {
        int mid = (i+j)/2;
        if (arr[mid] > k)
        {
            j = mid-1;
        }
        else
        {
            i = mid+1;
        }
    }
    return i;
}

bool MatrixSearch(vector<vector<int>> v , int k){
    int n = v.size();
    int m = v[0].size();
    int st = 0 , end = n*m-1;
    while (st <= end)
    {
        int mid = st + (end-st)/2;
        int x = mid/m;
        int y = mid%m;
        if (v[x][y] == k)
        {
            return true;
        }
        if (k < v[x][y])
        {
            end = mid-1;
        }
        else
        {
            st = mid+1;
        }
    }
    return false;
}

int firstpos(vector<int> v , int k){
    int i = 0 , j = v.size()-1;
    int ans = -1;
    while (i <= j)
    {
        int mid = (i+j)/2;
        if (v[mid] == k)
        {
            ans = mid;
            j = mid-1;
        }
        if (v[mid] < k)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
    }
    return ans;
}

int Lastpos(vector<int> v , int k){
    int i = 0 , j = v.size()-1;
    int ans = -1;
    while (i <= j)
    {
        int mid = (i+j)/2;
        if (v[mid] == k)
        {
            ans = mid;
            j = mid-1;
        }
        if (v[mid] < k)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
    }
    return ans;
}

vector<int> SearchRange(vector<int> v , int k){
    int a = firstpos(v , k);
    if (a == -1)
    {
        return {-1 , -1};
    }
    int b = Lastpos(v , k);
    return {a , b};
}

int sortedInsertPos(vector<int> v , int k){
    int i = 0 , j = v.size()-1;
    int mid = (i+j)/2;
    while (i <= j)
    {
        if (v[mid] == k)
        {
            return mid;
        }
        if (v[mid] < k)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
        mid = (i+j)/2;
    }
    return i;
}

int MatrixMedian(vector<vector<int>> arr , int r , int c){
    int maxelement = INT_MIN;
    int minelement = INT_MAX;

    for (int i = 0; i < r; i++)
    {
        minelement = min(minelement , arr[i][0]);
        maxelement = max(maxelement , arr[i][c-1]);
    }
    int n = (r*c+1)/2;
    while (minelement < maxelement)
    {
        int mid = (minelement + maxelement)/2;
        int place = 0;
        for (int i = 0; i < n; i++)
        {
            place += upper_bound(arr[i].begin() , arr[i].end() , mid) - arr[i].begin();
        }
        if (place < n)
        {
            minelement = mid+1;
        }
        else
        {
            maxelement = mid;
        }    
    }
    return minelement;
}

int squareroot(int A) {
    long long int i = 0 , j = A;
    long long int mid = i+(j-i)/2;
    long long int ans = -1;
    while(i <= j){
        long long int sq = mid*mid;
        if(sq == A){
            return mid;
        }
        if(sq > A){
            j = mid-1;
        }
        else{
            ans = mid;
            i = mid+1;
        }
        mid = i+(j-i)/2;
    }
    return ans;
}

bool isPossible(int arr[] , int n , int m , int mid){
    int student = 1;
    int currsum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
        {
            return false;
        }
        if (currsum + arr[i] > mid)
        {
            student++;
            currsum = arr[i];
            if (student > m)
            {
                return false;
            }
        }
        else
        {
            currsum += arr[i];
        }
    }
    return true;
}

int FindPages(int arr[] , int n , int m){
    long long sum = 0;

    if (n < m)
    {
        return -1;
    }
    
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    
    int st = 0 , end = sum;
    int res = INT_MAX;

    while (st <= end)
    {
        int mid = (st+end)/2;
        if (isPossible(arr , n , m , mid))
        {
            res = mid;
            end = mid-1;
        }
        else
        {
            st = mid+1;
        }
    }
    return res;
}

int PowerFunction(int x , int n , int d){
    if (x == 0)
    {
        return 0;
    }
    if (n == 1 && x < 0)
    {
        return d+x;
    }
    if (n == 1)
    {
        return x;
    }
    if (n == 0)
    {
        return 1;
    }
    
    long long int ans = 1;
    long long h = x%d;
    while (n > 0)
    {
        if (n&1)
        {
            ans = (ans*h)%d;
        }
        h = (h*h)%d;
        n /= 2;
    }
    if (ans < 0)
    {
        return d+ans;
    }
    return ans;
}

double MedianOfArray(vector<int> &v1 , vector<int> &v2){
    int n = v1.size() , m = v2.size();
    if (n > m)
    {
        return MedianOfArray(v2 , v1);
    }
    
    int lo = 0 , hi = n;
    int l1 , l2 , r1 , r2;
    while (lo <= hi)
    {
        int cut1 = (lo+hi)/2;
        int cut2 = (n+m)/2 - cut1;
        l1 = (cut1 == 0) ? INT_MIN : v1[cut1-1];
        l2 = (cut2 == 0) ? INT_MIN : v2[cut2-1];
        r1 = (cut1 == n) ? INT_MAX : v1[cut1];
        r2 = (cut2 == m) ? INT_MAX : v2[cut2];

        if (l1 > r2)
        {
            hi = cut1-1;
        }
        else if (l2 > r1)
        {
            lo = cut1+1;
        }
        else
        {
            return (n+m)%2 == 0 ? (max(l1 , l2) + min(r1 , r2))/2.0 : (double)min(r1 , r2);
        }
    }
}

int RotatedSortedsearch(const vector<int> &v, int B) {
    int n = v.size();
    int i = 0 , j = n - 1;
    int mid = i + (j-i)/2;
    while(i<=j){
        if(v[mid] == B){
            return mid;
        }
        else if(v[0] <= v[mid]){
            if(v[0] <= B && B < v[mid]){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
        }
        else{
            if(v[mid] < B && B <= v[n-1]){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        mid = i + (j-i)/2;
    }
    return -1;
}


bool isPackages(vector<int> &a, int &b, int c) 
{
    int bi  = 1;
    int cursum = 0;
    for(int i =0; i<a.size(); i++) {
        if(cursum + a[i] > c) 
        {
            bi++;
            cursum = a[i];
            if(bi > b) return false;
        }
        else cursum += a[i];
    }
    return true;
}


int paintersPartitionProblem(int A, int B, vector<int> &C) 
{
    int mod = 10000003;
    int maxCapacity = 0;
    int minCapacity = 0;
    for(int i = 0; i < C.size(); i++)
    {
        maxCapacity += C[i];
        minCapacity = max(C[i],minCapacity);
    } 
    int start = minCapacity;
    int end = maxCapacity;
    long long int ans = 0;
    while(start <= end)
    {
        int mid = (start + end)/2;
        if(isPackages(C,A,mid))
        {
            end = mid - 1;
            ans = mid;
        }
        else start = mid + 1;
    }
    ans = ((ans%mod)*(B%mod))%mod;
    return ans;
}

int main(){

}