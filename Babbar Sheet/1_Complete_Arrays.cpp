#include<bits/stdc++.h>
using namespace std;

void reversearr(int arr[] , int n){
    reverse(arr , arr+n);
}

pair<int,int> MaxAndMinElement(int arr[] , int n){
    int minele = INT_MAX;
    int maxele = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        minele = min(minele , arr[i]);
        maxele = max(maxele , arr[i]);
    }
    
    return {minele , maxele};
}

int KthSmallestElement(int arr[] , int n , int k){
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

void Sort012(int arr[] , int n){
    int z = 0 , o = 0 , t = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            z++;
        }
        else if (arr[i] == 1)
        {
            o++;
        }
        else
        {
            t++;
        }
    }
    int i = 0;
    for (i = 0; i < z; i++)
    {
        arr[i] = 0;
    }
    for (i ; i < (z+o); i++)
    {
        arr[i] = 1;
    }
    for (i ; i < n; i++)
    {
        arr[i] = 2;
    }
}

void MoveallNegativeNumberstobegin(int arr[] , int n){
    int i = 0 , j = 0;
    for (j; j < n; j++)
    {
        if (arr[j] < 0)
        {
            if (i != j)
            {
                swap(arr[i] , arr[j]);
            }
            i++;
        }
    }
}

int UnionOf2arrays(int arr1[] , int n , int arr2[] , int m){
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s.insert(arr2[i]);
    }
    return s.size();
}

void rotateArray(int arr[] , int n){
    int t = arr[n-1];
    for (int i = n-1; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[0] = t;
}

long long KadanesAlgo(int arr[] , int n){     // Largest Contigous Sum
    long long sum = 0 , maxsum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxsum = max(maxsum , sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxsum;
}

int MinimizetheHeightDiff(int arr[] , int n , int k){
    int ans = INT_MAX;
    sort(arr , arr+n);
    for (int i = 0; i < n; i++)
    {
        int maxele = max(arr[i]+k , arr[n-1]-k);
        int minele = min(arr[0]+k , arr[i]-k);

        ans = min(ans , maxele-minele);
    }
    return ans;
}

int MinJumpsToreachEnd(int arr[] , int n){
    if (n <= 1)
    {
        return 0;
    }
    if (arr[0] == -1)
    {
        return -1;
    }
    int maxreach = arr[0];
    int steps = arr[0];
    int jumps = 1;
    for (int i = 1; i < n; i++)
    {
        if (i == n-1)
        {
            return jumps;
        }
        maxreach = max(maxreach , i+arr[i]);
        steps--;
        if (steps == 0)
        {
            jumps++;
            if (i >= maxreach)
            {
                return -1;
            }
            steps = maxreach-i;
        }
    }
    return -1;
}

int FindTheDuplicateNumber(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        int ind = abs(arr[i]) - 1;
        arr[ind] *= -1;
        if (arr[ind] > 0)
        {
            return abs(arr[i]);
        }
    }
    return -1;
}

void Merge2sortedArrays(int arr1[] , int n , int arr2[] , int m){
    int i = 0 , j = 0 , k = n-1;
    while (i <= k && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[k] , arr2[j]);
            k--;
            j++;
        }
        else
        {
            i++;
        }
    }
    sort(arr1 , arr1+n);
    sort(arr2 , arr2+n);
}

vector<vector<int>> MergeIntervals(vector<vector<int>> Intervals){
    vector<vector<int>> ans;
    if (Intervals.size() == 0)
    {
        return ans;
    }
    sort(Intervals.begin() , Intervals.end());
    ans.push_back(Intervals[0]);
    int j = 0;
    for (int i = 1; i < Intervals.size(); i++)
    {
        if (ans[j][1] > Intervals[i][0])
        {
            ans[j][1] = max(ans[j][1] , Intervals[i][1]);
        }
        else
        {
            ans.push_back(Intervals[i]);
            j++;
        }
    }
    return ans;
}

void NextPermutation(vector<int> &v){
    int n = v.size();
    int k,l;
    for (k = n-2; k >= 0; k--)
    {
        if (v[k] < v[k+1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(v.begin() , v.end());
    }
    else
    {
        for(l = n-1; l > k ; l--){
            if (v[l] > v[k])
            {
                break;
            }
        }
        swap(v[l] , v[k]);
        reverse(v.begin()+k+1 , v.end());
    }
}

void merge(int arr[] , int l , int mid , int r , int &count){
    int i = l , j = mid+1;
    int k = l;
    int tmp[r+1];

    while (i <= mid && j <= r)
    {
        if (arr[i] > arr[j])
        {
            count += (mid-i+1);
            tmp[k++] = arr[j++];
        }
        else
        {
            tmp[k++] = arr[i++];
        }
    }
    while (i <= mid)
    {
        tmp[k++] = arr[i++];
    }
    while (j <= r)
    {
        tmp[k++] = arr[j++];
    }
    for (int a = l; a <= r; a++)
    {
        arr[a] = tmp[a];
    }
}

void mergesort(int arr[] , int i , int j , int &count){
    if (i >= j)
    {
        return;
    }
    int mid = (i+j)/2;
    mergesort(arr , i , mid , count);
    mergesort(arr , mid+1 , j , count);
    merge(arr , i , mid , j , count);
}

int CountInversion(int arr[] , int n){
    int count = 0;
    mergesort(arr , 0 , n-1 , count);
    return count;
}

int MaxProfit(int arr[] , int n){
    int minele = INT_MAX;
    int maxans = 0;
    for (int i = 0; i < n; i++)
    {
        minele = min(minele , arr[i]);
        maxans = max(maxans , arr[i]-minele);
    }
    return maxans;
}

int CountPairWithGivenSum(int arr[] , int n , int k){
    unordered_map<int,int> mp;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(arr[i]) != mp.end())
        {
            c += mp[k-arr[i]];
        }
        mp[arr[i]]++;
    }
    return c;
}

vector<int> CommonElements(int arr1[] , int arr2[] , int arr3[] , int n , int m , int k){
    vector<int> v;
    unordered_set<int> s1 , s2 , s3;
    for (int i = 0; i < n; i++)
    {
        s1.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        s2.insert(arr2[i]);
    }
    for (int i = 0; i < k; i++)
    {
        if (s1.find(arr3[i]) != s1.end() && s2.find(arr3[i]) != s2.end())
        {
            if (s3.find(arr3[i]) == s3.end())
            {
                v.push_back(arr3[i]);
            }
            s3.insert(arr3[i]);
        }
    }
    return v;
}

void rightrotate(int arr[], int n, int outofplace, int cur)
{
    char tmp = arr[cur];
    for (int i = cur; i > outofplace; i--)
        arr[i] = arr[i - 1];
    arr[outofplace] = tmp;
}

void rearrangealternately(int arr[] , int n){
    int tmp = -1;

    for (int i = 0; i < n; i++)
    {
        if (tmp >= 0)
        {
            if ((arr[i] >= 0 && arr[tmp] < 0) || (arr[i] < 0 && arr[tmp] >= 0))
            {
                rightrotate(arr , n , tmp , i);

                if (i - tmp >= 2)
                {
                    tmp = tmp+2;
                }
                else
                {
                    tmp = -1;
                }
            }
        }
        if (tmp == -1)
        {
            if ((arr[i] >= 0 && !(i&1)) && (arr[i] < 0 && (i&1)))
            {
                tmp = i;
            }
        }
    }
}

bool SubarrwithSumZero(int arr[] , int n){
    unordered_set<int> s;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0 || s.find(sum) != s.end())
        {
            return true;
        }
        s.insert(sum);
    }
    return false;
}

vector<int> FactoriolOfLargeNumber(int n){
    if (n <= 0)
    {
        return {};
    }
    vector<int> ans;
    ans.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        int carry = 0;
        for (int j = 0; j < ans.size(); j++)
        {
            int p = ans[j]*i + carry;
            ans[j] = p%10;
            carry = p/10;
        }
        while (carry > 0)
        {
            ans.push_back(carry%10);
            carry /= 10;
        }
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

long long MaxProductSubarr(int arr[] , int n){
    long long minele = arr[0];
    long long maxele = arr[0];
    long long ans = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(maxele , minele);
        }
        maxele = max((long long)arr[i] , arr[i]*maxele);
        minele = min((long long)arr[i] , arr[i]*minele);

        ans = max(ans , maxele);
    }
    return ans;
}

int LongestConsequtive(int arr[] , int n){
    vector<int> v(10000000 , -1);
    for (int i = 0; i < n; i++)
    {
        v[arr[i]]++;
    }
    int c = 0;
    int mxc = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != -1)
        {
            c++;
        }
        else
        {
            mxc = max(mxc , c);
            c = 0;
        }
    }
    return mxc;
}

int ElementMoreThanKtime(int arr[] , int n , int k){
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    for(auto it : mp){
        if (it.second > k)
        {
            return it.first;
        }
    }
    return -1;
}

int MaxProfitTwiceBuy(int arr[] , int n){
    int mini1 = INT_MAX;
    int profit1 = 0;
    int mini2 = INT_MAX;
    int profit2 = 0;
    for (int i = 0; i < n; i++)
    {
        mini1 = min(mini1 , arr[i]);
        profit1 = max(profit1 , arr[i]-mini1);
        mini2 = min(mini2 , arr[i]-profit1);
        profit2 = max(profit2 , arr[i]-mini2);
    }
    return profit2;
}

bool isSubset(int arr1[] , int n , int arr2[] , int m){
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr1[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        mp[arr2[i]]--;
        if (mp[arr2[i]] < 0)
        {
            return false;
        }
    }
    return true;
}

bool ThreeSum(int arr[] , int n , int sum){
    sort(arr , arr+n);

    for (int i = 0; i < n-2; i++)
    {
        int j = i+1 , k = n-1;
        while (j < k)
        {
            int tmp = arr[i]+arr[j]+arr[k];
            if (tmp == sum)
            {
                return true;
            }
            else if (tmp < sum)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return false;
}

int TrappingRainWater(int arr[] , int n){
    int left[n] , right[n];
    int ans = 0;
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1] , arr[i]);
    }
    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        right[i] = max(right[i+1] , arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += (min(left[i] , right[i]) - arr[i]);
    }
    return ans;
}

int ChoclateDistribution(int arr[] , int n , int m){
    sort(arr , arr+n);
    int i = 0;
    int j = m-1;

    long long mini = INT_MAX;

    while (j < n)
    {
        long long diff = arr[j] - arr[i];
        mini = min(mini , diff);
        i++;
        j++;
    }
    return mini;
}

int SmallestSubarrwithsumgreater(int arr[] , int n , int x){
    int sum = 0;
    int ans = INT_MAX;
    int i = 0 , j = 0;
    while (j < n)
    {
        sum += arr[j];
        if (sum > x)
        {
            ans = min(ans , j-i+1);
            while (sum > x && i < j)
            {
                ans = min(ans , j-i+1);
                sum -= arr[i++];
            }
        }
        j++;
    }
    return ans;
}

void ThreeWayPartition(int arr[] , int n , int a , int b){
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < a)
        {
            swap(arr[++j] , arr[i]);
        }
    }
    j = n;
    for (int i = n-1; i >= 0 ; i--)
    {
        if (arr[i] > b)
        {
            swap(arr[--j] , arr[i]);
        }
    }
}

int MinSwaps(int arr[] , int n , int k){
    int a = 0 , b = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= k)
        {
            a++;
        }
    }
    for (int i = 0; i < a; i++)
    {
        if (arr[i] <= k)
        {
            b++;
        }
    }
    int ans = a-b;
    for (int i = 1; i <= n-a; i++)
    {
        if (arr[i] <= k)
        {
            b--;
        }
        if (arr[i+a-1] <= k)
        {
            b++;
        }
        ans = min(ans , a-b);
    }
    return ans;
}

int FindMinOperationsToMakePalindromearr(int arr[] , int n){
    int ans = 0;
    int i = 0 , j = n-1;
    while (i <= j)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }
        else if (arr[i] > arr[j])
        {
            j--;
            arr[j] += arr[j+1];
            ans++;
        }
        else
        {
            i++;
            arr[i] += arr[i-1];
            ans++;
        }
    }
    return ans;
}

double MedianOf2SortedArray(int arr1[] , int n , int arr2[] , int m){
    if (n > m)
    {
        return MedianOf2SortedArray(arr2 , m , arr1 , n);
    }
    int lo = 0 , hi = n;
    while (lo <= hi)
    {
        int cut1 = (lo + hi)/2;
        int cut2 = (n+m+1)/2 - cut1;

        int l1 = (cut1 == 0) ? INT_MIN : arr1[cut1-1];
        int l2 = (cut2 == 0) ? INT_MIN : arr2[cut2-1];
        int r1 = (cut1 == n) ? INT_MAX : arr1[cut1];
        int r2 = (cut2 == m) ? INT_MAX : arr2[cut2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((n+m)%2 == 0)
            {
                return (double)(max(l1 , l2) + min(r1 , r2))/2;
            }
            else
            {
                return (double)max(l1 , l2);
            }
        }
        else if (l1 > r2)
        {
            hi = cut1-1;
        }
        else
        {
            lo = cut1+1;
        }
    }
    return -1.0;
}

int main(){

}