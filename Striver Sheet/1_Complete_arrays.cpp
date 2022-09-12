#include<bits/stdc++.h>
using namespace std;

void setMatrixZero(vector<vector<int>> &v){
    bool firstrow = false;
    bool firstcol = false;
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        if (v[i][0] == 0)
        {
            firstcol = true;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (v[0][i] == 0)
        {
            firstrow = true;
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                v[i][0] = 0;
                v[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][0] == 0 || v[0][j] == 0)
            {
                v[i][j] = 0;
            }
        }
    }
    if (firstrow)
    {
        for (int i = 0; i < m; i++)
        {
            v[0][i] = 0;
        }
    }
    if (firstcol)
    {
        for (int i = 0; i < n; i++)
        {
            v[i][0] = 0;
        }
    }
}

vector<vector<int>> PascalsTriangle(int n){
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].resize(i+1);
        v[i][0] = v[i][i] = 0;
        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }
    return v;
}

vector<int> NextPermutation(vector<int> v){
    int k , l;
    int n = v.size();
    for (k = n-2; k >= 0; k--)
    {
        if (v[k] > v[k+1])
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
        for (l = n-1; l >= k; l--)
        {
            if (v[l] > v[k])
            {
                break;
            }
        }
        swap(v[l] , v[k]);
        reverse(v.begin()+k+1 , v.end());
    }
    return v;
}

int maxsubarrsum(int arr[] , int n){
    int maxsum = 0;
    int currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        maxsum = max(maxsum , currsum);
        if (currsum < 0)
        {
            currsum = 0;
        }
    }
    return maxsum;
}

void Sort012(vector<int> &v){
    int n = v.size();
    int ones = 0 , zeros = 0 , twos = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            zeros++;
        }
        else if (v[i] == 1)
        {
            ones++;
        }
        else
        {
            twos++;
        }
    }
    int i;
    for (i = 0; i < zeros; i++)
    {
        v[i] = 0;
    }
    for (i = zeros; i < (ones+zeros); i++)
    {
        v[i] = 1;
    }
    for (i = (ones+zeros); i < n; i++)
    {
        v[i] = 2;
    }
}

int StockBuySell(vector<int> v){
    int minval = INT_MAX;
    int maxval = 0;
    for (int i = 0; i < v.size(); i++)
    {
        minval = min(minval , v[i]);
        maxval = max(maxval , v[i]-minval);
    }
    return maxval;
}

void RotateMatrix(vector<vector<int>> v){
    int n = v.size();
    int m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(v[i] , v[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(v[i].begin() , v[i].end());
    }
}

vector<vector<int>> MergeOverlappingIntervals(vector<vector<int>> &v){
    int n = v.size();
    if(n == 0){
        return {{}};
    }
    vector<vector<int>> ans;
    ans.push_back(v[0]);
    for (int i = 1; i < n; i++)
    {
        if (ans[ans.size()-1][1] > v[i][0])
        {
            ans[ans.size()-1][1] = max(ans[ans.size()-1][1] , v[i][1]);
        }
        else
        {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

void Merge2sortedArray(int arr1[] , int n , int arr2[] , int m){
    int i = 0 , j = 0;
    int k = n-1;
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

int FindDuplicate(int arr[] , int n){
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

vector<int> RepeatAndMissingNumber(vector<int> v){
    int sum = 0;
    int squaresum = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        sum -= (i+1);
        squaresum += (v[i] * v[i]);
        squaresum -= ((i+1)*(i+1));
    }
    squaresum /= sum;
    int a = (sum+squaresum)/2;
    int b = squaresum-a;
    return {a,b};
}

void merge(int arr[] , int st , int mid , int en , int &count){
    int tmp[en-st+1];
    int i = st , j = mid , k = 0;
    while (i<mid && j < en)
    {
        if (arr[i] <= arr[j])
        {
            tmp[k++] = arr[i++];
        }
        else
        {
            count += (mid-i);
            tmp[k++] = arr[j++];
        }
    }
    while (i < mid)
    {
        tmp[k++] = arr[i++];
    }
    while (j < en)
    {
        tmp[k++] = arr[j++];
    }
    for (i = st , k = 0; i <= en; i++,k++)
    {
        arr[i] = tmp[k];
    }
}

void mergesort(int arr[] , int st , int en , int &count){
    if (en > st)
    {
        return;
    }
    int mid = (st+en)/2;
    mergesort(arr , st , mid , count);
    mergesort(arr , mid , en , count);
    merge(arr , st , mid , en , count);
}

int GetInversions(int arr[] , int n){
    int count = 0;
    mergesort(arr , 0 , n-1 , count);
    return count;
}

int SearchIn2dMatrix(vector<vector<int>> v , int key){
    int n = v.size() , m = v[0].size();
    int i = 0 , j = n*m-1;
    while (i<=j)
    {
        int mid = (i+j)/2;
        int x = mid%n;
        int y = mid/m;
        if (v[x][y] == key)
        {
            return true;
        }
        else if (v[x][y] < key)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
    }
    return false;
}

double powerofx(double x , int n){
    double res = 1;
    while (n)
    {
        if (n % 2 == 0)
        {
            res = n > 0 ? res*x : res/x;
        }
        x = x*x;
        n /= 2;
    }
    return res;
}

int MajorityElementN2(int arr[] , int n){
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] > n/2)
        {
            return arr[i];
        }
    }
    return -1;
}

int MajorityElementN3(int arr[] , int n){
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
        if (mp[arr[i]] > n/3)
        {
            return arr[i];
        }
    }
    return -1;
}

int UniquePath(int n , int m){
    vector<vector<int>> v(n , vector<int>(m , 1));
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            v[i][j] = v[i-1][j] + v[i][j-1];
        }
    }
    return v[n-1][m-1];
}

// REVERSE PAIRS ---> SAME AS COUNT INVERSIONS

vector<int> TwoSum(int arr[] , int n , int target){
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(target-arr[i]) != mp.end())
        {
            return {mp[target-arr[i]] , i};
        }
        mp[arr[i]] = i;
    }
    return {-1};
}

vector<vector<int>> FourSum(vector<int> v , int target){
    sort(v.begin() , v.end());
    int n = v.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n-3; i++)
    {
        if (i == 0 || (i > 0 && v[i] != v[i-1]))
        {
            for (int j = i+1; j < n-2; j++)
            {
                if (j == i+1 || (j > i+1 && v[j] != v[j-1]))
                {
                    int lo = j+1 , hi = n-1;
                    int sum = target-v[i]-v[j];
                    while (lo < hi)
                    {
                        if (v[lo] + v[hi] == sum)
                        {
                            ans.push_back({v[i] , v[j] , v[lo] , v[hi]});
                            while (lo < hi && v[lo] == v[lo+1])
                            {
                                lo++;
                            }
                            while (lo<hi && v[hi] == v[hi-1])
                            {
                                hi--;
                            }
                            lo++;
                            hi--;
                        }
                        else if (v[lo] + v[hi] < sum)
                        {
                            lo++;
                        }
                        else
                        {
                            hi--;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int longestConsequtiveSequence(int arr[] , int n){
    sort(arr , arr+n);
    int c = 1;
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == arr[i-1])
        {
            continue;
        }
        else if (arr[i] == arr[i-1]+1)
        {
            c++;
        }
        else
        {
            ans = max(ans , c);
            c = 1;
        }
    }
    return max(ans,c);
}

int largestSubarrwithSumZero(int arr[] , int n){
    unordered_map<int,int> mp;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            ans = max(ans , i+1);
        }
        else if (mp.find(sum) != mp.end())
        {
            ans = max(ans , i-mp[sum]);
        }
        else
        {
            mp[sum] = i;
        }
    }
    return ans;
}

int subarrwithGivenXOR(int arr[] , int n , int x){
    int xorr = 0 , ans = 0;
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        xorr ^= arr[i];
        int tmp = xorr^x;
        ans += mp[tmp];
        if (xorr == x)
        {
            ans++;
        }
        mp[xorr]++;
    }
    return ans;
}

int lengthOfLongestSubstring(string s) {
    vector<int> v(256 , -1);
    int len = 0;
    int left = 0 , right = 0;
    int n = s.length();
    while(right < n){
        if(v[s[right]] != -1){
            left = max(v[s[right]]+1 , left);
        }
        v[s[right]] = right;
        len = max(len , right-left+1);
        right++;
    }
    return len;
}

vector<vector<int>> ThreeSum(vector<int> v , int target){
    sort(v.begin() , v.end());
    int n = v.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n-2; i++)
    {
        if (i > 0 && v[i] == v[i-1])
        {
            continue;
        }
        int j = i+1 , k = n-1;
        while (j < k)
        {
            int sum = v[i]+v[j]+v[k];
            if (sum == target)
            {
                ans.push_back({v[i] , v[j] , v[k]});
                while (j < k && v[j] == v[j+1])
                {
                    j++;
                }
                while (j < k && v[k] == v[k-1])
                {
                    k--;
                }
                j++;
                k--;
            }
            else if (sum < target)
            {
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

int TrappingRainWater(int arr[] , int n){
    int left[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1] , arr[i]);
    }
    int right[n];
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

int removeDuplicate(vector<int> v){
    int j = 0;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[j])
        {
            v[j++] = v[i];
        }
    }
    return j;
}

int maxConsequtiveOnes(vector<int> v){
    int c = 0;
    int mx = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != 1)
        {
            mx = max(c , mx);
            c = 0;
        }
        else
        {
            c++;
        }
    }
    return max(c , mx);
}

int main(){

}