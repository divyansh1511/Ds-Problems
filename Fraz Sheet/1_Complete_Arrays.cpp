#include <bits/stdc++.h>
using namespace std;

//--------------------------------------EASY LEVEL PROBLEMS--------------------------------------//

vector<int> TwoSumProblem(int arr[], int n, int k)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        if (mp.find(k - arr[i]) != mp.end())
        {
            return {mp[k - arr[i]], i};
        }
        mp[arr[i]] = i;
    }
    return {};
}

int BestTimeToBuyAndSellStocks(int arr[], int n)
{
    int minval = INT_MAX;
    int maxval = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        minval = min(arr[i], minval);
        maxval = max(maxval, arr[i] - minval);
    }
    return maxval;
}

void Merge2sortedArray(int arr1[], int n, int arr2[], int m)
{
    int i = 0, j = 0;
    int k = n - 1;
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
}

void MoveZeros(int arr[], int n)
{
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            arr[j] = arr[i];
            j++;
        }
    }
    while (j < n)
    {
        arr[j] = 0;
        j++;
    }
}

int BuyandSellStockII(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            sum += (arr[i + 1] - arr[i]);
        }
    }
    return sum;
}

vector<int> RunningSum(vector<int> v)
{
    int n = v.size();
    vector<int> ans(n);
    ans[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] + v[i];
    }
    return ans;
}

int IndexleftsumEqualRightSum(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    int lsum = 0;
    for (int i = 0; i < n; i++)
    {
        sum -= arr[i];
        if (lsum == sum)
        {
            return i;
        }
        lsum += arr[i];
    }
    return -1;
}

int MajorityElement(int arr[], int n)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }
    int ans = -1;
    int maxval = 0;
    for (auto it : mp)
    {
        if (it.second > maxval)
        {
            maxval = it.second;
            ans = it.first;
        }
    }
    return ans;
}

int FibnocciNumber(int n)
{
    if (n < 2)
    {
        return 1;
    }
    int arr[n];
    arr[0] = 1;
    arr[1] = 1;
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n - 1];
}

vector<int> squareofSortedArray(vector<int> v)
{
    int n = v.size();
    vector<int> ans(n);
    int i = 0, j = n - 1;
    for (int k = n - 1; k >= 0; k--)
    {
        if (abs(v[i]) > abs(v[j]))
        {
            ans[k] = v[i] * v[i];
            i++;
        }
        else
        {
            ans[k] = v[j] * v[j];
            j++;
        }
    }
    return ans;
}

vector<vector<int>> PascalsTriangle(int n)
{
    vector<vector<int>> ans(n);
    for (int i = 0; i < n; i++)
    {
        ans[i].resize(i + 1);
        ans[i][0] = ans[i][i];
        for (int j = 1; j < i; j++)
        {
            ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
    }
    return ans;
}

int removeduplicate(vector<int> v)
{
    set<int> s;
    for (int i = 0; i < v.size(); i++)
    {
        s.insert(v[i]);
    }
    return s.size();
}

//--------------------------------------MEDIUM LEVEL PROBLEMS--------------------------------------//

vector<vector<int>> ThreeSumProblem(vector<int> v, int key)
{
    sort(v.begin(), v.end());
    vector<vector<int>> ans;
    int n = v.size();
    for (int i = 0; i < n - 2; i++)
    {
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = v[i] + v[j] + v[k];
            if (sum == key)
            {
                ans.push_back({v[i], v[j], v[k]});
                j++;
                k--;
            }
            else if (sum < key)
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

vector<int> ProductOfArrayExceptItself(vector<int> v)
{
    int n = v.size();
    vector<int> ans(n);
    int pre = 1;
    for (int i = 0; i < n; i++)
    {
        ans[i] = pre;
        pre *= v[i];
    }
    int pos = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        ans[i] *= pos;
        pos *= v[i];
    }
    return ans;
}

int SubarraySumWithssumK(int arr[], int n, int k)
{
    int sum = 0;
    map<int, int> mp;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            count++;
        }
        if (mp.find(sum - k) != mp.end())
        {
            count += mp[sum - k];
        }
        mp[sum]++;
    }
    return count;
}

void nextPermutation(vector<int> &v)
{
    int n = v.size();
    int k, l;
    for (k = n - 2; k >= 0; k--)
    {
        if (v[k] < v[k + 1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(v.begin(), v.end());
    }
    else
    {
        for (l = n - 1; l >= k; l--)
        {
            if (v[l] > v[k])
            {
                break;
            }
        }
        swap(v[l], v[k]);
        reverse(v.begin() + k + 1, v.end());
    }
}

vector<int> SpiralOrderMatrix(vector<vector<int>> &v)
{
    vector<int> ans;
    int n = v.size();
    int m = v[0].size();
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        for (int k = j; k < m; k++)
        {
            ans.push_back(v[i][k]);
        }
        i++;
        for (int k = i; k < n; k++)
        {
            ans.push_back(v[k][m - 1]);
        }
        m--;
        if (j < m)
        {
            for (int k = m - 1; k >= j; k--)
            {
                ans.push_back(v[n - 1][k]);
            }
            n--;
        }
        if (i < n)
        {
            for (int k = n - 1; k >= i; k--)
            {
                ans.push_back(v[k][i]);
            }
            j++;
        }
    }
    return ans;
}

int MaxArea(vector<int> arr)
{
    int ans = 0;
    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        ans = max(ans, (j - i) * min(arr[i], arr[j]));
        arr[i] > arr[j] ? j-- : i++;
    }
    return ans;
}

void RotateImage(vector<vector<int>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            swap(grid[i][j], grid[j][i]);
        }
    }
    for (int i = 0; i < grid.size(); i++)
    {
        reverse(grid[i].begin(), grid[i].end());
    }
}

bool DFS(vector<vector<char>> &boards, string word, int i, int j)
{
    if (word.size() == 0)
    {
        return true;
    }
    if (i < 0 || i >= boards.size() || j < 0 || j >= boards[i].size() || boards[i][j] != word[0])
    {
        return false;
    }
    char c = boards[i][j];
    boards[i][j] = '*';
    string s = word.substr(1);
    bool res = DFS(boards, s, i - 1, j) || DFS(boards, s, i, j - 1) || DFS(boards, s, i + 1, j) || DFS(boards, s, i, j + 1);
    boards[i][j] = c;
    return res;
}

bool WordSearch(vector<vector<char>> &boards, string word)
{
    for (int i = 0; i < boards.size(); i++)
    {
        for (int j = 0; j < boards[i].size(); j++)
        {
            if (DFS(boards, word, i, j))
            {
                return true;
            }
        }
    }
    return false;
}

void gameOfLife(vector<vector<int>> &board)
{
    int m = board.size(), n = m ? board[0].size() : 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int count = 0;
            for (int ss = max(i - 1, 0); ss < min(i + 2, m); ss++)
            {
                for (int tt = max(j - 1, 0); tt < min(j + 2, n); tt++)
                {
                    count += board[ss][tt] & 1;
                }
            }
            count -= board[i][j];

            if (count == 3 || (board[i][j] && count == 2))
                board[i][j] |= 2;
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] >>= 1;
        }
    }
}

int numPairsDivisibleBy60(vector<int> &time)
{
    int n = time.size();
    vector<int> v(60);
    int res = 0;
    for (int t : time)
    {
        res += v[(600 - t) % 60];
        v[t % 60] += 1;
    }
    return res;
}

vector<vector<int>> FourSum(vector<int> v, int key)
{
    int n = v.size();
    vector<vector<int>> ans;
    for (int i = 0; i < n - 3; i++)
    {
        if (i > 0 && v[i] == v[i - 1])
        {
            continue;
        }
        for (int j = i + 1; j < n - 2; j++)
        {
            if (j > i + 1 && v[j] == v[j - 1])
            {
                continue;
            }
            int k = j + 1, l = n - 1;
            int tmp = key - v[i] - v[j];
            while (k < l)
            {
                int sum = v[k] + v[l];
                if (sum == tmp)
                {
                    ans.push_back({v[i], v[j], v[k], v[l]});
                    while (k < l && v[k] == v[k + 1])
                    {
                        k++;
                    }
                    while (k < l && v[l] == v[l - 1])
                    {
                        l--;
                    }
                    k++;
                    l--;
                }
                else if (sum < tmp)
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
    return ans;
}

int FindDuplicate(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        int pos = abs(v[i]) - 1;
        v[pos] *= -1;
        if (v[pos] > 0)
        {
            return abs(v[i]);
        }
    }
    return -1;
}

void helper(vector<int> v, int target, vector<int> tmp, vector<vector<int>> &ans, int idx)
{
    if (idx == v.size())
    {
        if (target == 0)
        {
            ans.push_back(tmp);
        }
        return;
    }
    if (v[idx] <= target)
    {
        tmp.push_back(v[idx]);
        helper(v, target - v[idx], tmp, ans, idx);
        tmp.pop_back();
    }
    helper(v, target, tmp, ans, idx + 1);
}

vector<vector<int>> CombinationSum(vector<int> v, int target)
{
    vector<vector<int>> ans;
    vector<int> tmp;
    helper(v, target, tmp, ans, 0);
    return ans;
}

int JumpGame(int arr[], int n)
{
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
        if (i == n - 1)
        {
            return jumps;
        }
        maxreach = max(maxreach, i + arr[i]);
        steps--;
        if (steps == 0)
        {
            jumps++;
            if (i >= maxreach)
            {
                return -1;
            }
            steps = maxreach - i;
        }
    }
    return -1;
}

int MaxPointscanObtain(vector<int> &prices, int k)
{
    int res = 0;
    int n = prices.size();
    int s = 0;
    for (int i = n - k; i < n; i++)
    {
        res += prices[i];
    }
    s = res;
    for (int i = 0; i < k; i++)
    {
        s -= prices[n - k + i];
        s += prices[i];
        res = max(res, s);
    }
    return res;
}

int helper2(vector<vector<int>> grid, int i, int j)
{
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0)
    {
        return 0;
    }
    return 1 + helper2(grid, i + 1, j) + helper2(grid, i, j + 1) + helper2(grid, i - 1, j) + helper2(grid, i, j - 1);
}

int MaxAreaofIsland(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res = max(res, helper2(grid, i, j));
        }
    }
    return res;
}

int FindPairsWithKdiff(vector<int> &v, int k)
{
    unordered_map<int, int> mp;
    for (auto it : v)
    {
        mp[it]++;
    }
    int ans = 0;
    for (auto x : mp)
    {
        if (k == 0)
        {
            if (x.second > 1)
            {
                ans++;
            }
        }
        else if (mp.find(x.first + k) != mp.end())
        {
            ans++;
        }
    }
    return ans;
}

void helper3(vector<int> nums, vector<vector<int>> ans, vector<int> tmp, int idx)
{
    ans.push_back(tmp);
    for (int i = idx; i < nums.size(); i++)
    {
        tmp.push_back(nums[i]);
        helper3(nums, ans, tmp, i + 1);
        tmp.pop_back();
    }
}

vector<vector<int>> Subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> tmp;
    helper3(nums, ans, tmp, 0);
    return ans;
}

int SubarrSumDivisibleByK(vector<int> nums, int k)
{
    vector<int> v(k, 0);
    int sum = 0;
    for (auto it : nums)
    {
        sum += (it % k + k) % k;
        v[sum % k]++;
    }
    int res = v[0];
    for (int c : v)
    {
        res += (c * (c - 1)) / 2;
    }
    return res;
}

//--------------------------------------HARD LEVEL PROBLEMS--------------------------------------//

int FirstMissingPossitiveNumber(vector<int> nums)
{
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= 0)
        {
            nums[i] = n + 1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (abs(nums[i]) <= n && nums[abs(nums[i]) - 1] > 0)
        {
            nums[abs(nums[i]) - 1] *= -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            return i + 1;
        }
    }
    return n + 1;
}

int LargestRectangularArea(vector<int> &heights)
{
    stack<int> st;
    int ans = 0;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); i++)
    {
        while (!st.empty() && heights[st.top()] > heights[i])
        {
            int a = st.top();
            st.pop();
            int r = st.empty() ? -1 : st.top();
            ans = max(ans, a * (i - r - 1));
        }
        st.push(i);
    }
    return ans;
}

int BuyAndSellStockIII(vector<int> v)
{
    int buy1 = INT_MAX;
    int profit1 = INT_MIN;
    int buy2 = INT_MAX;
    int profit2 = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        buy1 = min(buy1, v[i]);
        profit1 = max(profit1, v[i] - buy1);
        buy2 = min(buy2, v[i] - profit1);
        profit2 = max(profit2, v[i] - buy2);
    }
    return profit2;
}

int findMaxValueOfEquation(vector<vector<int>> &points, int k)
{
    priority_queue<pair<int, int>> pq;
    int ans = INT_MIN;
    for (int i = 0; i < points.size(); i++)
    {
        while (!pq.empty() && (points[i][0] - pq.top().second > k))
        {
            pq.pop();
        }
        if (!pq.empty())
        {
            ans = max(ans, points[i][0] + points[i][1] + pq.top().first);
        }
        pq.push({points[i][1] - points[i][0], points[i][0]});
    }
    return ans;
}

int main()
{
}