#include <bits/stdc++.h>
using namespace std;

vector<int> MaxelementandMinelement(int arr[], int n)
{
    int maxi = INT_MIN;
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        maxi = max(maxi, arr[i]);
    }
    return {mini, maxi};
}

void reverse(int arr[], int n)
{
    reverse(arr, arr + n);
}

int MaximumSubarrSum(int arr[], int n)
{
    int maxsum = 0;
    int currsum = 0;
    for (int i = 0; i < n; i++)
    {
        currsum += arr[i];
        maxsum = max(maxsum, currsum);
        if (currsum < 0)
        {
            currsum = 0;
        }
    }
    return maxsum;
}

bool cointainsDuplicate(int arr[], int n)
{
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    return !(s.size() == n);
}

int ChoclateDistribution(int arr[], int n, int m)
{
    if (m == 0 || n == 0)
    {
        return 0;
    }
    sort(arr, arr + n);
    if (n < m)
    {
        return -1;
    }
    int ans = INT_MAX;
    for (int i = 0; i + m - 1 < n; i++)
    {
        int diff = arr[i + m - 1] - arr[i];
        if (diff < ans)
        {
            ans = diff;
        }
    }
    return ans;
}

int searchInRoatatedSortedarr(int arr[], int n, int key)
{
    int i = 0, j = n - 1;
    while (i <= j)
    {
        int mid = (i + j) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[i] <= arr[mid])
        {
            if (key >= arr[i] && key < arr[mid])
            {
                j = mid - 1;
            }
            else
            {
                i = mid + 1;
            }
        }
        if (arr[mid] <= arr[j])
        {
            if (key > arr[mid] && key <= arr[j])
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
    }
    return -1;
}

void NextPermutation(int arr[], int n)
{
    int k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (arr[k] < arr[k + 1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(arr, arr + n);
    }
    else
    {
        for (l = n - 1; l > k; l--)
        {
            if (arr[l] > arr[k])
            {
                break;
            }
        }
        swap(arr[l], arr[k]);
        reverse(arr + k + 1, arr + n);
    }
}

int MaxProfit(int arr[], int n)
{
    int mini = INT_MAX;
    int maxele = 0;
    for (int i = 0; i < n; i++)
    {
        mini = min(arr[i], mini);
        maxele = max(maxele, arr[i] - mini);
    }
    return maxele;
}

vector<int> RepeatedAndMissingNumber(int arr[], int n)
{
    int sum = 0;
    int squaresum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        sum -= (i + 1);
        squaresum += arr[i] * arr[i];
        squaresum -= (i + 1) * (i + 1);
    }
    squaresum /= sum;
    int a = (squaresum + sum) / 2;
    int b = squaresum - a;

    return {a, b};
}

int KthLargestElement(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
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

int TrappingRainWater(int arr[], int n)
{
    int left[n];
    int right[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], arr[i]);
    }
    right[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], arr[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += min(left[i], right[i]) - arr[i];
    }
    return ans;
}

vector<int> ProductOfArrayExceptItself(int arr[], int n)
{
    int pro = 1;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        v[i] = pro;
        pro *= arr[i];
    }
    pro = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        v[i] *= pro;
        pro *= arr[i];
    }
    return v;
}

int maxProductSubarr(int arr[], int n)
{
    int pro = 1;
    int currmax = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        pro *= arr[i];
        currmax = max(currmax, pro);
        if (pro == 0)
        {
            pro = 1;
        }
    }
    pro = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        pro *= arr[i];
        currmax = max(currmax, pro);
        if (pro == 0)
        {
            pro = 1;
        }
    }
    return currmax;
}

int FindMinInRotatedSortedArray(int arr[], int n)
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (arr[l] < arr[r])
        {
            return arr[l];
        }
        else if (arr[mid] >= arr[l])
        {
            l = mid + 1;
        }
        else
        {
            r = mid;
        }
    }
    return arr[l];
}

int RotatedSortedarr(int arr[], int n, int key)
{
    int low = 0, high = n - 1;
    while (low < high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > arr[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    int rot = low;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int realmid = (mid + rot) % n;
        if (arr[realmid] == key)
        {
            return realmid;
        }
        if (arr[realmid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    vector<vector<int>> res;
    for (int i = 0; i < n - 2; i++)
    {
        if (i > 0 && (nums[i] == nums[i - 1]))
        {
            continue;
        }
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if (sum < 0)
            {
                l++;
            }
            else if (sum > 0)
            {
                r--;
            }
            else
            {
                res.push_back(vector<int>{nums[i], nums[l], nums[r]});
                while (l + 1 < r && nums[l] == nums[l + 1])
                {
                    l++;
                }
                while (l < r - 1 && nums[r] == nums[r - 1])
                {
                    r--;
                }
                l++;
                r--;
            }
        }
    }
    return res;
}

int maxArea(vector<int> &height)
{
    int ans = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i < j)
    {
        ans = max(ans, (j - i) * min(height[i], height[j]));
        height[i] > height[j] ? j-- : i++;
    }
    return ans;
}

int maxArea(vector<int> &height)
{
    int ans = 0;
    int i = 0;
    int j = height.size() - 1;
    while (i < j)
    {
        ans = max(ans, (j - i) * min(height[i], height[j]));
        height[i] > height[j] ? j-- : i++;
    }
    return ans;
}

bool pairInSortedRotated(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n - 1; i++)
        if (arr[i] > arr[i + 1])
            break;

    int l = (i + 1) % n;
    int r = i;

    while (l != r)
    {

        if (arr[l] + arr[r] == x)
            return true;

        if (arr[l] + arr[r] < x)
            l = (l + 1) % n;

        else
            r = (n + r - 1) % n;
    }
    return false;
}

int Kthsmallest(int arr[], int n, int k)
{
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

vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int x = 0; x < n;)
    {
        int start = x, final = intervals[x][1];
        while (x + 1 < n and intervals[x + 1][0] <= final)
        {
            final = max(final, intervals[x + 1][1]);
            x++;
        }
        vector<int> v = {intervals[start][0], final};
        ans.push_back(v);
        x++;
    }
    return ans;
}

int findMinOps(int arr[], int n)
{
    int ans = 0;
    for (int i = 0, j = n - 1; i <= j;)
    {
        if (arr[i] == arr[j])
        {
            i++;
            j--;
        }

        else if (arr[i] > arr[j])
        {
            j--;
            arr[j] += arr[j + 1];
            ans++;
        }

        else
        {
            i++;
            arr[i] += arr[i - 1];
            ans++;
        }
    }

    return ans;
}

static bool cmp(string &a, string &b)
{
    return a + b < b + a;
}

string printLargest(vector<string> &arr)
{
    string ans = "";
    sort(arr.begin(), arr.end(), cmp);
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        ans += arr[i];
    }
    return ans;
}

int longSubarrWthSumDivByK(int arr[], int n, int k)
{
    int sum = 0, dist = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        int rem = sum % k;
        if (rem < 0)
            rem += k;
        if (mp.find(rem) != mp.end())
        {
            dist = max(dist, i - mp[rem]);
            continue;
        }
        mp[rem] = i;
    }
    return dist;
}

int main()
{
}