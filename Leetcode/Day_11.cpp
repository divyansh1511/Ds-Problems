#include <bits/stdc++.h>
using namespace std;

//----------------------------------301. Remove Invalid Parenthesis----------------------------------//

void helper(string s, int idx, int lr, int rr, int pair, string tmp, unordered_set<string> &st)
{
    if (idx == s.length())
    {
        if (lr == 0 && rr == 0 && pair == 0)
        {
            st.insert(tmp);
        }
        return;
    }
    if (s[idx] != ')' && s[idx] != '(')
    {
        helper(s, idx + 1, lr, rr, pair, tmp + s[idx], st);
    }
    else
    {
        if (s[idx] == '(')
        {
            if (lr > 0)
            {
                helper(s, idx + 1, lr - 1, rr, pair, tmp, st);
            }
            helper(s, idx + 1, lr, rr, pair + 1, tmp + '(', st);
        }
        if (s[idx] == ')')
        {
            if (rr > 0)
            {
                helper(s, idx + 1, lr, rr - 1, pair, tmp, st);
            }
            if (pair > 0)
            {
                helper(s, idx + 1, lr, rr, pair - 1, tmp + s[idx], st);
            }
        }
    }
}

vector<string> RemoveParenthesis(string s)
{
    unordered_set<string> st;
    int left_remove = 0;
    int right_remove = 0;
    for (char c : s)
    {
        if (c == '(')
        {
            left_remove++;
        }
        if (c == ')')
        {
            if (left_remove != 0)
            {
                left_remove--;
            }
            else
            {
                right_remove++;
            }
        }
    }
    helper(s, 0, left_remove, right_remove, 0, "", st);
    return vector<string>(st.begin(), st.end());
}

//----------------------------------303. Range sum query ----------------------------------//

int givesum(int arr[], int left, int right)
{
    int sum = 0;
    for (int i = left; i <= right; i++)
    {
        sum += arr[i];
    }
    return sum;
}

//----------------------------------304. Range Sum Query II --------------------------------//

class NumMatrix
{
private:
    int row, col;
    vector<vector<int>> sums;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        row = matrix.size();
        col = row > 0 ? matrix[0].size() : 0;
        sums = vector<vector<int>>(row + 1, vector<int>(col + 1, 0));
        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                sums[i][j] = matrix[i - 1][j - 1] +
                             sums[i - 1][j] + sums[i][j - 1] - sums[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        return sums[row2 + 1][col2 + 1] - sums[row2 + 1][col1] - sums[row1][col2 + 1] + sums[row1][col1];
    }
};

//---------------------------------306. Additive Number -----------------------------------//

bool getFibo(string &s, int i, long long a, long long b, int n)
{
    if (i == s.length())
        return n > 2;

    long long num = 0;
    for (int x = i; x < s.length(); x++)
    {

        if (num > pow(10, 17))
            break;
        num = num * 10 + s[x] - '0';

        bool chk = false;
        if (n < 2)
            chk = getFibo(s, x + 1, b, num, n + 1);
        else if (a + b == num)
            chk = getFibo(s, x + 1, b, num, n + 1);
        if (chk)
            return true;

        if (num == 0)
            break;
    }
    return false;
}

bool isAdditiveNumber(string num)
{
    return getFibo(num, 0, 0, 0, 0);
}

//---------------------------------309. best time to buy and sell --------------------------//

int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int has1_donothing = -prices[0];
    int has1_sell = 0;
    int has0_donothing = 0;
    int has0_buy = -prices[0];
    for (int i = 1; i < n; i++)
    {
        has1_donothing = has1_donothing > has0_buy ? has1_donothing : has0_buy;
        has0_buy = -prices[i] + has0_donothing;
        has0_donothing = has0_donothing > has1_sell ? has0_donothing : has1_sell;
        has1_sell = prices[i] + has1_donothing;
    }
    return has1_sell > has0_donothing ? has1_sell : has0_donothing;
}

//---------------------------------310. Min height tree -- graph ------------------------//

vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
{
    vector<vector<int>> graph(n);
    vector<int> indegree(n, 0), ans;
    for (auto &e : edges)
    {
        graph[e[0]].push_back(e[1]);
        graph[e[1]].push_back(e[0]);
        indegree[e[0]]++;
        indegree[e[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 1)
            q.push(i), indegree[i]--;
    }

    while (!q.empty())
    {
        int s = q.size();
        ans.clear();
        for (int i = 0; i < s; i++)
        {
            int curr = q.front();
            q.pop();
            ans.push_back(curr);
            for (auto child : graph[curr])
            {
                indegree[child]--;
                if (indegree[child] == 1)
                    q.push(child);
            }
        }
    }
    if (n == 1)
        ans.push_back(0);
    return ans;
}

//------------------------------313. Super Ugly Number --------------------------------//

int nthSuperUglyNumber(int n, vector<int> &primes)
{
    int k = primes.size();
    vector<int> pos(k, 0);
    vector<int> res(n);
    res[0] = 1;
    for (int i = 1; i < n; i++)
    {
        long temp = INT_MAX;
        for (int j = 0; j < k; j++)
            temp = min(temp, (long)res[pos[j]] * primes[j]);
        for (int j = 0; j < k; j++)
        {
            if (temp == (long)res[pos[j]] * primes[j])
                pos[j]++;
        }
        res[i] = temp;
    }
    return res[n - 1];
}

//------------------------------316. Remove Duplicate Letters ---------------------------//

string removeDuplicateLetters(string s)
{
    int len = s.size();
    string res = "";
    unordered_map<char, int> M;
    unordered_map<char, bool> V;
    stack<int> S;

    for (auto c : s)
    {
        if (M.find(c) == M.end())
            M[c] = 1;
        else
            M[c]++;
    }
    for (unordered_map<char, int>::iterator iter = M.begin(); iter != M.end(); iter++)
        V[iter->first] = false;

    cout << M.size() << V.size() << endl;
    for (int i = 0; i < len; i++)
    {
        M[s[i]]--;
        if (V[s[i]] == true)
            continue;

        while (!S.empty() and s[i] < s[S.top()] and M[s[S.top()]] > 0)
        {
            V[s[S.top()]] = false;
            S.pop();
        }
        S.push(i);
        V[s[i]] = true;
    }
    while (!S.empty())
    {
        res = s[S.top()] + res;
        S.pop();
    }
    return res;
}

//----------------------------------318. Maximum Word Length-------------------------------//

int maxProduct(vector<string> &words)
{
    vector<int> mask(words.size());
    int result = 0;
    for (int i = 0; i < words.size(); ++i)
    {
        for (char c : words[i])
            mask[i] |= 1 << (c - 'a');
        for (int j = 0; j < i; ++j)
            if (!(mask[i] & mask[j]))
                result = max(result, int(words[i].size() * words[j].size()));
    }
    return result;
}

//--------------------------------322. Coin change ---------------------------------//

int coinchange(vector<int> coins, int amount)
{
    int n = coins.size();
    int dp[n + 1][amount + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= amount; i++)
    {
        dp[0][i] = INT_MAX;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i - 1] <= j)
            {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i][j - coins[i - 1]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n][amount] == INT_MAX - 1 ? -1 : dp[n][amount];
}

//----------------------------------324. Wiggle Sort II ----------------------------------//

void wiggleSort(vector<int> &nums)
{
    vector<int> sorted(nums);
    sort(sorted.begin(), sorted.end());
    for (int i = nums.size() - 1, j = 0, k = i / 2 + 1; i >= 0; i--)
    {
        if (i & 1)
        {
            nums[i] = sorted[k];
            k++;
        }
        else
        {
            nums[i] = sorted[j];
            j++;
        }
    }
}

//---------------------------------326. Power of 3 ----------------------------------//

bool isPowerOfThree(int n)
{
    int i = 0;
    while (i < n)
    {
        if (pow(3, i) == n)
        {
            return true;
        }
        else if (pow(3, i) < n)
        {
            i++;
        }
        else
        {
            return false;
        }
    }
    return false;
}

//-----------------------------------328. Odd Even Linked List---------------------------//

class node
{
public:
    int data;
    node *next;
    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

node *oddevenll(node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    node *odd = head;
    node *even = head->next;
    node *evst = even;

    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evst;
    return head;
}

//----------------------------------334. Increasing Triplet Subsequence -----------------------//

bool increasingTriplet(vector<int> &nums)
{
    int n = nums.size(), left = INT_MAX, mid = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] <= left)
            left = nums[i];
        else if (nums[i] <= mid)
            mid = nums[i];
        else
            return true;
    }
    return false;
}

//---------------------------------338. Counting Bits --------------------------------//

vector<int> countBits(int n)
{
    vector<int> ret(n + 1, 0);
    for (int i = 1; i <= n; ++i)
        ret[i] = ret[i & (i - 1)] + 1;
    return ret;
}

//--------------------------------341. Nested List Iterator ---------------------------//

class NestedInteger
{
public:
    bool isInteger() const;
    int getInteger() const;
    vector<NestedInteger> &getList() const;
};

class NestedIterator
{
public:
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        begins.push(nestedList.begin());
        ends.push(nestedList.end());
    }

    int next()
    {
        hasNext();
        return (begins.top()++)->getInteger();
    }

    bool hasNext()
    {
        while (begins.size())
        {
            if (begins.top() == ends.top())
            {
                begins.pop();
                ends.pop();
            }
            else
            {
                auto x = begins.top();
                if (x->isInteger())
                    return true;
                begins.top()++;
                begins.push(x->getList().begin());
                ends.push(x->getList().end());
            }
        }
        return false;
    }

private:
    stack<vector<NestedInteger>::iterator> begins, ends;
};

//-------------------------------342. Power of 4 ---------------------------------//

bool isPowerOfFour(int n)
{
    int i = 0;
    while (i < n)
    {
        if (pow(4, i) == n)
        {
            return true;
        }
        else if (pow(4, i) < n)
        {
            i++;
        }
        else
        {
            return false;
        }
    }
    return false;
}

//------------------------------------343. Integer Break --------------------------------//

int integerBreak(int n)
{
    if (n <= 2)
    {
        return 1;
    }
    vector<int> dp(n + 1, 0);
    dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
        }
    }
    return dp[n];
}

//-------------------------------------344. Reverse String ----------------------------//

void reverseString(vector<char> &s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        int temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

//--------------------------------------345. Reverse vowels of string ----------------------//

string reverseVowels(string s)
{
    int dict[256] = {0};
    dict['a'] = 1, dict['A'] = 1;
    dict['e'] = 1, dict['E'] = 1;
    dict['i'] = 1, dict['I'] = 1;
    dict['o'] = 1, dict['O'] = 1;
    dict['u'] = 1, dict['U'] = 1;
    int start = 0, end = s.length() - 1;
    while (start < end)
    {
        while (start < end && dict[s[start]] == 0)
            start++;
        while (start < end && dict[s[end]] == 0)
            end--;
        swap(s[start], s[end]);
        start++;
        end--;
    }
    return s;
}

//---------------------------------347. Top k frequent elements ---------------------------//

vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> mp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        pq.push({it->second, it->first});
        if (pq.size() > k)
        {
            pq.pop();
        }
    }
    vector<int> ans;
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

//---------------------------------349. Intersection of 2 arrays ----------------------------//

vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
{
    unordered_set<int> m(nums1.begin(), nums1.end());
    vector<int> res;
    for (auto a : nums2)
        if (m.count(a))
        {
            res.push_back(a);
            m.erase(a);
        }
    return res;
}

//---------------------------------350. Intersection of 2 arrays II --------------------------//

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<int, int> dict;
    vector<int> res;
    for (int i = 0; i < (int)nums1.size(); i++)
        dict[nums1[i]]++;
    for (int i = 0; i < (int)nums2.size(); i++)
        if (dict.find(nums2[i]) != dict.end() && --dict[nums2[i]] >= 0)
            res.push_back(nums2[i]);
    return res;
}

//--------------------------------357. Count Number with Unique digits ------------------------//

int permutation(int n, int i)
{
    if (i == 0)
    {
        return 1;
    }
    return n * permutation(n - 1, i - 1);
}
int countNumbersWithUniqueDigits(int n)
{
    int sum = 1;
    if (n > 0)
    {
        int end = (n > 10) ? 10 : n;
        for (int i = 0; i < end; i++)
        {
            sum += 9 * permutation(9, i);
        }
    }
    return sum;
}

//----------------------------------367. Valid perfect square------------------------------//

bool isPerfectSquare(int num)
{
    long long i;
    for (i = 0; i * i <= num; i++)
    {
        if (i * i == num)
            return i;
    }
    return false;
}

//-------------------------------------------------------------------------------------------

int main()
{
}