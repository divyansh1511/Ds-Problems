#include <bits/stdc++.h>
using namespace std;

//----------------------------------371. Sum of 2 Integers ------------------------------//

int sumof2int(int a, int b)
{
    while (b != 0)
    {
        unsigned carry = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

//----------------------------------372. Super Pow -------------------------------------//

long long int powr(long long int a, long long int b, int m)
{
    long long int ans = 1;
    while (b > 0)
    {
        if (b & 1)
            ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return (ans % m);
}
int superPow(int a, vector<int> &b)
{
    int m_a = 1337, m_b = 1140; // cause ETF Value(m_a) = 1140
    long long int b_value = 0;
    for (auto i : b)
        b_value = ((b_value * 10) + i) % m_b;
    return powr(a % m_a, b_value, m_a);
}

//----------------------------------374. Guess The Number -------------------------------//
int guess(int num);
int guessNumber(int n)
{
    int maxNumber = n, minNumber = 1;
    while (true)
    {
        int meanNumber = (maxNumber - minNumber) / 2 + minNumber;
        int res = guess(meanNumber);
        if (res == 0)
        {
            return meanNumber;
        }
        else if (res == 1)
        {
            minNumber = meanNumber + 1;
        }
        else
        {
            maxNumber = meanNumber - 1;
        }
    }
}

//------------------------------------375. Guess The Number II---------------------------//

int solveMem(int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
    {
        return 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solveMem(start, i - 1, dp), solveMem(i + 1, end, dp)));
    }
    return dp[start][end] = ans;
}
int getMoneyAmount(int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solveMem(1, n, dp);
}

//-----------------------------------376. Wiggle Subsequence -----------------------------------//

int wiggleMaxLength(vector<int> &nums)
{
    int n = nums.size();
    vector<int> up(n, 0);
    vector<int> down(n, 0);
    up[0] = 1;
    down[0] = 1;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] > nums[i - 1])
        {
            up[i] = down[i - 1] + 1;
            down[i] = down[i - 1];
        }
        else if (nums[i] < nums[i - 1])
        {
            down[i] = up[i - 1] + 1;
            up[i] = up[i - 1];
        }
        else
        {
            up[i] = up[i - 1];
            down[i] = down[i - 1];
        }
    }
    return max(up[n - 1], down[n - 1]);
}

//------------------------------------377. Combination Sum IV --------------------------------//

int combinationSum4_M1(vector<int> &nums, int target)
{
    vector<unsigned int> result(target + 1);
    result[0] = 1;
    for (int i = 1; i <= target; ++i)
    {
        for (int x : nums)
        {
            if (i >= x)
                result[i] += result[i - x];
        }
    }

    return result[target];
}

int check(vector<int> &nums, int target, vector<int> &dp, int n)
{
    if (target == 0)
        return 1;

    if (n == 0 || target < 0)
        return 0;

    if (dp[target] != -1)
        return dp[target];

    if (nums[n - 1] <= target)
    {
        return dp[target] = check(nums, target - nums[n - 1], dp, nums.size()) + check(nums, target, dp, n - 1);
    }
    else
    {
        return dp[target] = check(nums, target, dp, n - 1);
    }
}
int combinationSum4_M2(vector<int> &nums, int target)
{
    int n = nums.size();
    vector<int> dp(target + 1, -1);
    return check(nums, target, dp, n);
}

//------------------------------378. Kth smallest element sorted matrix ------------------------//

int kthSmallest(vector<vector<int>> &arr, int k)
{
    priority_queue<int> maxheap;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            maxheap.push(arr[i][j]);
            if (maxheap.size() > k)
            {
                maxheap.pop();
            }
        }
    }
    return maxheap.top();
}

//-----------------------------383. Ransom number -----------------------------//

bool canConstruct(string ransomNote, string magazine)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < magazine.length(); i++)
    {
        mp[magazine[i]]++;
    }
    for (int i = 0; i < ransomNote.length(); i++)
    {
        if (mp.find(ransomNote[i]) == mp.end())
        {
            return false;
        }
        mp[ransomNote[i]]--;
        if (mp[ransomNote[i]] == 0)
        {
            mp.erase(ransomNote[i]);
        }
    }
    return true;
}

//------------------------------384. shuffle array ----------------------------//

class Solution
{
    vector<int> nums;

public:
    Solution(vector<int> &nums)
    {
        this->nums = nums;
    }

    vector<int> reset()
    {
        return nums;
    }

    vector<int> shuffle()
    {
        vector<int> temp = nums;
        int ln = nums.size();
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int j = rand() % ln;
            swap(temp[i], temp[j]);
            ln--;
        }
        return temp;
    }
};

//----------------------------------------386. Lexiographical order-----------------------------//

vector<int> lexicalOrder(int n)
{
    vector<int> res(n);
    int cur = 1;
    for (int i = 0; i < n; i++)
    {
        res[i] = cur;
        if (cur * 10 <= n)
        {
            cur *= 10;
        }
        else
        {
            if (cur >= n)
                cur /= 10;
            cur += 1;
            while (cur % 10 == 0)
                cur /= 10;
        }
    }
    return res;
}

//-----------------------------------387. First Unique character -----------------------------//

int firstUniqChar(string s)
{
    unordered_map<char, int> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (mp[s[i]] == 1)
        {
            return i;
        }
    }
    return -1;
}

//----------------------------------389. Find the differnce -------------------------------//

char findTheDifference(string s, string t)
{
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != t[i])
        {
            return t[i];
        }
    }
    return t[t.length() - 1];
}

//---------------------------------390. Eleminating Game -------------------------------//

int lastRemaining(int n)
{
    int head = 1;
    int step = 1;
    int remain = n;
    bool left = true;

    while (remain > 1)
    {
        if (left || remain % 2 == 1)
        {
            head += step;
        }
        remain /= 2;
        step *= 2;
        left = !left;
    }
    return head;
}

//--------------------------------392. Subsequence ----------------------------//

bool isSubsequence(string s, string t)
{
    if (s.length() > t.length())
    {
        return false;
    }
    int j = 0, i = 0;
    while (j < s.length() && i < t.length())
    {
        if (s[j] == t[i])
        {
            j++;
        }
        i++;
    }
    if (j < s.length())
    {
        return false;
    }
    return true;
}

//------------------------------------393. UTF validation ----------------------------//

bool validUtf8(vector<int> &data)
{
    int count = 0;
    for (auto c : data)
    {
        if (count == 0)
        {
            if ((c >> 5) == 0b110)
                count = 1;
            else if ((c >> 4) == 0b1110)
                count = 2;
            else if ((c >> 3) == 0b11110)
                count = 3;
            else if ((c >> 7))
                return false;
        }
        else
        {
            if ((c >> 6) != 0b10)
                return false;
            count--;
        }
    }
    return count == 0;
}

//-------------------------------------394. Decode ways -----------------------------//

string decodeString(string s)
{
    stack<int> stnum;
    stack<string> ststr;
    string res = "";
    int num = 0;
    for (char it : s)
    {
        if (isdigit(it))
        {
            num = num * 10 + it - '0';
        }
        else if (isalpha(it))
        {
            res += it;
        }
        else if (it == '[')
        {
            ststr.push(res);
            stnum.push(num);
            res = "";
            num = 0;
        }
        else if (it == ']')
        {
            string temp = res;
            for (int i = 1; i < stnum.top(); i++)
            {
                res += temp;
            }
            res = ststr.top() + res;
            ststr.pop();
            stnum.pop();
        }
    }
    return res;
}

//--------------------------395. Longest Substring with At Least K Repeating Characters-------------//

int longestSubstring(string s, int k)
{
    if (s.size() == 0 || k > s.size())
        return 0;
    if (k == 0)
        return s.size();

    unordered_map<char, int> Map;
    for (int i = 0; i < s.size(); i++)
    {
        Map[s[i]]++;
    }

    int idx = 0;
    while (idx < s.size() && Map[s[idx]] >= k)
        idx++;
    if (idx == s.size())
        return s.size();

    int left = longestSubstring(s.substr(0, idx), k);
    int right = longestSubstring(s.substr(idx + 1), k);

    return max(left, right);
}

//----------------------------400. Nth digit ------------------------------//

int findNthDigit(int n)
{
    // step - 1 ---
    long base = 9, digit = 1;
    while (n - base * digit > 0)
    {
        n -= base * digit;
        base *= 10;
        digit++;
    }

    // step - 2 ---
    int index = n % digit;
    if (index == 0)
    {
        index = digit;
    }
    long num = 1;
    for (int i = 1; i < digit; i++)
    {
        num *= 10;
    }
    num += (index == digit) ? n / digit - 1 : n / digit;

    // step - 3 ---
    for (int i = index; i < digit; i++)
    {
        num /= 10;
    }
    return num % 10;
}

int main()
{
}