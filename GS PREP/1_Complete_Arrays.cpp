#include<bits/stdc++.h>
using namespace std;

//----------------------------set matrix zero -----------------------------//

void SetMatrixZero(vector<vector<int>> &arr){
    bool firstrow = false;
    bool firstcol = false;

    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i][0] == 0)
        {
            firstcol = true;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (arr[0][i] == 0)
        {
            firstrow = true;
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                arr[i][0] = 0;
                arr[0][j] = 0;
            }
        }
    }
    
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][0] == 0 || arr[0][j] == 0)
            {
                arr[i][j] = 0;
            }
        }
    }
    if (firstrow)
    {
        for (int i = 0; i < m; i++)
        {
            arr[0][i] = 0;
        }
    }
    if (firstcol)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i][0] = 0;
        }
    }
}

//----------------------------Pascal's Triangle -------------------------//

vector<vector<int>> PascalsTriangle(int n){
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i].resize(i+1);
        v[i][0] = v[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            v[i][j] = v[i-1][j] + v[i-1][j-1];
        }
    }
    return v;
}

//-------------------------------Next Permutation ---------------------------------//

void NextPermutation(vector<int> &v){
    int n = v.size();
    int k , l;
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
        for (l = n-1; l > k; l--)
        {
            if (v[l] > v[k])
            {
                break;
            }
        
        }
        swap(v[l] , v[k]);
        reverse(v.begin()+k+1 , v.end());
    }
}

//-------------------------------Kadanes Algo --------------------------//

int MaxSubarraySum(vector<int> v){
    int sum = 0;
    int maxsum = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        maxsum = max(maxsum , sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxsum;
}

//-------------------------------SORT 012 ---------------------------------//

void sort012(vector<int> v){
    int zero = 0 , ones = 0 , twos = 0;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            zero++;
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
    int i = 0;
    for (i = 0; i < zero; i++)
    {
        v[i] = 0;
    }
    for (i ; i < (zero+ones); i++)
    {
        v[i] = 1;
    }
    for (i ; i < n; i++)
    {
        v[i] = 2;
    }
}

//---------------------------------Buy and Sell stock -------------------------//

int BuyandSell(int arr[] , int n){
    int minval = INT_MAX;
    int profit = 0;
    for (int i = 0; i < n; i++)
    {
        minval = min(minval , arr[i]);
        profit = max(profit , arr[i]-minval);
    }
    return profit;
}

//---------------------------------Rotate Matrix --------------------------//

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

//-------------------------------Merge Overlapping Intervals ------------------------//

vector<vector<int>> merge(vector<vector<int>> v){
    vector<vector<int>> ans;
    sort(v.begin() , v.end());
    ans.push_back(v[0]);
    for (int i = 1; i < v.size(); i++)
    {
        if (ans.back()[1] > v[i][0])
        {
            ans.back()[1] = max(ans.back()[1] , v[i][1]);
        }
        else
        {
            ans.push_back(v[i]);
        }
    }
    return ans;
}

//--------------------------------Merge 2 sorted array without extra space --------------------------//

void Merge2sortedarr(int arr1[] , int n , int arr2[] , int m){
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
    sort(arr2 , arr2+m);
}

//----------------------------------Find Duplicate Number -----------------------------------//

int Finddup(int arr[] , int n){
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

//-------------------------------Repeated and missing number -----------------------------//

vector<int> RepeatedAndMissingNum(vector<int> v){
    int n = v.size();
    int sum = 0;
    int squaresum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        sum -= (i+1);
        squaresum += (v[i]*v[i]);
        squaresum -= ((i+1) * (i+1));
    }
    squaresum /= sum;
    int a = (sum+squaresum)/2;
    int b = squaresum-a;
    return {a,b};
}

//--------------------------------Count Inversions --------------------------------//

void merge(int arr[] , int s , int mid , int e , int &ans){
    int tmp[e-s+1];
    int i = s , j = mid , k = 0;
    while (i < mid && j <= e)
    {
        if (arr[i] > arr[j])
        {
            ans += (mid-i);
            tmp[k] = arr[j];
            k++;
            j++;
        }
        else
        {
            tmp[k] = arr[i];
            i++;
            k++;
        }
    }
    while (i < mid)
    {
        tmp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= e)
    {
        tmp[k] = arr[j];
        k++;
        j++;
    }
    for (int i = 0; i < e-s+1; i++)
    {
        arr[i] = tmp[i];
    }
}

void mergesort(int arr[] , int s , int e , int &ans){
    if(s > e){
        return;
    }
    int mid = (s+e)/2;
    mergesort(arr , s , mid , ans);
    mergesort(arr , mid+1 , e , ans);
    merge(arr , s , mid , e , ans);
}

int CountInversions(int arr[] , int n){
    int ans = 0;
    mergesort(arr , 0 , n-1 , ans);
    return ans;
}

//--------------------------------Search in 2d matrix -------------------------------//

bool seachMatrix(vector<vector<int>> v , int target){
    int n = v.size() , m = v[0].size();

    int lo = 0 , hi = n*m-1;
    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        if (v[mid/m][mid%m] == target)
        {
            return true;
        }
        else if (v[mid/m][mid%m] < target)
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
    return false;
}

//----------------------------------Pow X and N ------------------------------//

double pow(double x , int n){
    double res = 1;
    while (n)
    {
        if (n % 2)
        {
            res = n > 0 ? res*x : res/x;
        }
        x = x*x;
        n /= 2;
    }
    return res;
}

//---------------------------------Majority Element N/2----------------------------//

int Majority_element(int arr[] , int n){
    int count = 0;
    int candidate = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            candidate = arr[i];
        }
        if (candidate == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return candidate;
}

//---------------------------------Majority Element N/3 --------------------------//

vector<int> Majority_element_N3(int arr[] , int n){
    int num1 = -1 , num2 = -1 , count1 = 0 , count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (num1 == arr[i])
        {
            count1++;
        }
        else if (num2 == arr[i])
        {
            count2++;
        }
        else if (count1 == 0)
        {
            num1 = arr[i];
        }
        else if(count2 == 0)
        {
            num2 = arr[i];
        }
        else
        {
            count1--;
            count2--;
        }
    }
    vector<int> ans;
    count1 = count2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == num1)
        {
            count1++;
        }
        else if (arr[i] == num2)
        {
            count2++;
        }
    }
    if (count1 > n/3)
    {
        ans.push_back(num1);
    }
    if (count2 > n/3)
    {
        ans.push_back(num2);
    }
    return ans;
}

//-------------------------------Grid Unique Paths --------------------------//

int uniquePath(int n , int m){
    vector<vector<int>> dp(n , vector<int>(m , 1));
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[n-1][m-1];
}

//--------------------------------2 SUM Problem --------------------------------//

vector<int> TwoSum(vector<int> v , int target){
    int n = v.size();
    unordered_map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(target - v[i]) != mp.end())
        {
            return {mp[target - v[i]] , i};
        }
        mp[v[i]] = i;
    }
    return {};
}

//------------------------------4 Sum Problem -----------------------------//

vector<vector<int>> FourSum(vector<int> v , int target){
    sort(v.begin() , v.end());
    int n = v.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n-3; i++)
    {
        if ((i == 0) || (i > 0 && v[i] != v[i-1]))
        {
            for (int j = i+1; j < n-2; j++)
            {
                if ((j == i+1) || (j > i+1 && v[j] != v[j-1]))
                {
                    int k = j+1 , l = n-1;
                    int t = target - v[i] - v[j];
                    while (k < l)
                    {
                        int sum = v[k] + v[l];
                        if (sum == t)
                        {
                            ans.push_back({v[i] , v[j] , v[k] , v[l]});
                            
                            while (k < l && v[k] == v[k+1])
                            {
                                k++;
                            }
                            while (k < l && v[l] == v[l-1])
                            {
                                l--;
                            }
                            k++;
                            l--;
                        }
                        else if (sum < t)
                        {
                            k++;
                        }
                        else
                        {
                            l--;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

//-------------------------------Longest consequtive Sequence ---------------------------//

int LongestConsequtiveSequence(vector<int> v){
    int n = v.size();
    int ans = 0;
    int c = 1;
    sort(v.begin() , v.end());
    for (int i = 1; i < n; i++)
    {
        if (v[i] == v[i-1])
        {
            continue;
        }
        if (v[i] != v[i-1]+1)
        {
            ans = max(ans , c);
            c = 1;
        }
        else
        {
            c++;
        }
    }
    return max(ans , c);
}

//-------------------------------Largest Subarr with sum 0 ------------------------------//

int LargestSubarr(int arr[] , int n){
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

//-------------------------------no of subarr with given xor -------------------------------//

int Subarrwithxor(int arr[] , int n , int t){
    int ans = 0;
    int xorr = 0;

    map<int,int> mp;
    for (int i = 0; i < n; i++)
    {
        xorr ^= arr[i];
        int tmp = xorr^t;
        ans += mp[tmp];
        if (xorr == t)
        {
            ans++;
        }
        mp[xorr]++;
    }
    return ans;
}

//-----------------------------longest substring without repeating character -----------------------//

int lengthofsubstring(string s){
    vector<int> v(256 , -1);
    int len = 0;
    int left = 0 , right = 0;
    while (right < s.length())
    {
        if (v[s[right]] != -1)
        {
            left = max(left , v[s[right]]+1);
        }
        v[s[right]] = right;
        len = max(len , right-left+1);
        right++;
    }
    return len;
}

//-------------------------------Three Sum -------------------------------//

vector<vector<int>> ThreeSum(vector<int> v){
    int n = v.size();
    sort(v.begin() , v.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n-2; i++)
    {
        if ((i == 0) || (i > 0 && v[i] != v[i-1]))
        {
            int j = i+1 , k = n-1;
            while (j < k)
            {
                int sum = v[i]+v[j]+v[k];
                if (sum == 0)
                {
                    ans.push_back({v[i] , v[j] , v[k]});
                    while (j<k && v[j] == v[j+1])
                    {
                        j++;
                    }
                    while (j<k && v[k] == v[k-1])
                    {
                        k--;
                    }
                    j++;
                    k--;
                }
                else if (sum < 0)
                {
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
    }
    return ans;
}

//----------------------------Trapping Rain Water ---------------------------//

int trappingrainwater(vector<int> v){
    int n = v.size();
    int lo = 0 , hi = n-1;
    int ml = 0 , mr = 0;
    int ans = 0;

    while (lo <= hi)
    {
        if (v[lo] < v[hi])
        {
            if (v[lo] > ml)
            {
                ml = v[lo];
            }
            else
            {
                ans += (ml-v[lo]);
            }
            lo++;
        }
        else
        {
            if (v[hi] > mr)
            {
                mr = v[hi];
            }
            else
            {
                ans += (mr - v[hi]);
            }
            hi--;
        }
    }
    return ans;
}

//-----------------------------Remove Duplicate from sorted array ---------------------------//

int removeDuplicate(vector<int> arr){
    int n = arr.size();
    int i = 0 , j = 0;
    while (j < n)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
            j++;
        }
        else
        {
            j++;
        }
    }
    return i+1;
}

//------------------------------Max consequtive ones -----------------------------//

int FindMaxOnes(vector<int> nums){
    int n = nums.size();
    int count = 0;
    int maxcount = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            maxcount = max(maxcount , count);
            count = 0;
        }
        else
        {
            count++;
        }
    }
    return maxcount;
}

//-------------------------------Pick From both sides ------------------------------//

int Pickfrombothsides(int arr[] , int n , int b){
    int ans = INT_MIN;
    int sum1 = 0;
    for (int i = 0; i < b; i++)
    {
        sum1 += arr[i];
    }
    ans = max(ans , sum1);
    int i = b-1;
    int j = n-1;
    while (i >= 0)
    {
        sum1 -= arr[i--];
        sum1 += arr[j--];
        if (sum1 > ans)
        {
            ans = sum1;
        }
    }
    return ans;
}

//--------------------------------Minimum lights to activate ---------------------------//

int Lightstoactivate(int arr[] , int n , int b){
    int i = 0 , idx = -1;

    int cnt = 0;

    while (i < n)
    {
        idx = -1;
        for (int j = max(0 , i-b+1); j < min(n , i+b); j++)
        {
            if (arr[j] == 1)
            {
                idx = j;
            }
        }
        if (idx == -1)
        {
            return -1;
        }
        cnt++;
        i = idx+b;
    }
    return cnt;
}

//------------------------------ Add one to number ------------------------------//

vector<int> PlusOne(vector<int> v){
    int carry = 1;
    reverse(v.begin() , v.end());
    for (int i = 0; i < v.size(); i++)
    {
        int sum = v[i]+carry;
        v[i] = sum%10;
        carry = sum/10;
    }
    if (carry != 0)
    {
        v.push_back(carry);
    }
    reverse(v.begin() , v.end());
    int k = 0;
    while (v.front() == 0)
    {
        auto it = v.begin();
        v.erase(it);
    }
    return v;
}

//------------------------------Partitions ------------------------------//

int solve(int arr[] , int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    if (sum%3 != 0)
    {
        return 0;
    }
    int s = 0;
    int count = 0;
    int left = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (s == (2*sum))
        {
            count += left;
        }
        if (s == sum)
        {
            left++;
        }
    }
    return count;
}

//-------------------------------Flips -----------------------------//

vector<int> flips(string s){
    int n = s.length();
    int curr = 0 , maxsofar = 0;

    int l = -1 , r = -1 , si = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            curr++;
        }
        else
        {
            curr--;
        }
        if (curr > maxsofar)
        {
            maxsofar = curr;
            l = si;
            r = i;
        }
        if (curr < 0)
        {
            si = i+1;
            curr = 0;
        }
    }
    
    if (l == -1)
    {
        return {};
    }
    return {l+1 , r+1};
}

//----------------------------Perfect Peak of array ---------------------------//

int PerfectPeak(int arr[] , int n){
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
        right[i] = min(right[i+1] , arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > left[i-1] && arr[i] < right[i+1])
        {
            return 1;
        }
    }
    return 0;
}

//------------------------------Largest Number ------------------------------//

bool static cmp(int &a , int &b){
    string s1 = to_string(a);
    string s2 = to_string(b);

    return s1 + s2 > s2 + s1;
}

string LargestNum(vector<int> v){
    vector<int> num = v;
    sort(num.begin() , num.end() , cmp);
    int n = v.size();

    int c = 0;
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        ans += to_string(v[i]);
        if (v[i] == 0)
        {
            c++;
        } 
    }
    if (c == n)
    {
        return "0";
    }
    return ans;
}

//------------------------------sort array with squares ---------------------------//

vector<int> sortsquares(vector<int> v){
    int n = v.size();
    int i = 0 , j = n-1;
    vector<int> ans(n);
    for (int k = n-1; k >= 0; k--)
    {
        if (abs(v[i]) > abs(v[j]))
        {
            ans[k] = v[i]*v[i];
            i++;
        }
        else
        {
            ans[k] = v[j]*v[j];
            j--;
        }
    }
    return ans;
}

//--------------------------------Min Jumps to reach end --------------------------//

int MinJumps(int arr[] , int n){
    int steps = arr[0];
    int maxreach = arr[0];
    int jumps = 1;

    for (int i = 1; i < n; i++)
    {
        if (i == n-1)
        {
            return jumps;
        }
        steps--;
        if (steps == 0)
        {
            jumps++;
            maxreach = max(maxreach , i+arr[i]);
            if (i >= maxreach)
            {
                return -1;
            }
            steps = maxreach-i;
        }
    }
    return -1;
}

//------------------------------Buy and sell stock twice transactions--------------------//

int MaximizeProfit(int arr[] , int n){
    int mini1 = INT_MAX;
    int profit1 = 0;
    int mini2 = INT_MAX;
    int profit2 = 0;

    for (int i = 0; i < n; i++)
    {
        mini1 = min(mini1 , arr[i]);
        profit1 = max(profit1 , arr[i]-mini1);
        mini2 = min(mini2 , arr[i] - profit1);
        profit2 = max(profit2 , arr[i] - mini2);
    }
    return profit2;
}

//-----------------------------Median of 2 sorted arrays -------------------------//

double medianofSortedArray(int arr1[] , int n , int arr2[] , int m){
    if (n > m)
    {
        return medianofSortedArray(arr2 , m , arr1 , n);
    }
    int lo = 0 , hi = n;
    while (lo <= hi)
    {
        int cut1 = (lo+hi)/2;
        int cut2 = (n+m)/2 - cut1;

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