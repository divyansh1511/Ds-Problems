#include <bits/stdc++.h>
using namespace std;

//------------------------------451. Sort Characters by frequency ---------------------------------//

string frequencysort(string s)
{
    unordered_map<char, int> mp;
    vector<string> v(s.length() + 1, "");
    string ans = "";
    for (char c : s)
    {
        mp[c]++;
    }
    for (auto it : mp)
    {
        int n = it.second;
        char a = it.first;
        v[n].append(n, a);
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (!v[i].empty())
        {
            ans += v[i];
        }
    }
    return ans;
}

//-------------------------------452. Min number of ballons to burst ---------------------------//

bool static cmp(vector<int> &a, vector<int> &b)
{
    if (a[1] == b[1])
    {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

int MinArrows(vector<vector<int>> ballons)
{
    int c = 0, arrow = INT_MIN;
    sort(ballons.begin(), ballons.end(), cmp);
    for (int i = 0; i < ballons.size(); i++)
    {
        if (arrow != INT_MIN && ballons[i][0] <= arrow)
        {
            continue;
        }
        c++;
        arrow = ballons[i][1];
    }
    return c;
}

//----------------------------453. Min Moves to make array equal ------------------------------//

int minMoves(vector<int> nums)
{
    int n = nums.size();
    int mn = nums[0];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        mn = min(mn, nums[i]);
        sum += nums[i];
    }
    return sum - mn * n;
}

//------------------------------------454. 4 SUM II ---------------------------------//

int FourSumII(vector<int> v1, vector<int> v2, vector<int> v3, vector<int> v4)
{
    int n = v1.size();
    int c = 0;
    unordered_map<int, int> mp;
    for (auto it1 : v1)
    {
        for (auto it2 : v2)
        {
            mp[it1 + it2]++;
        }
    }
    for (auto it3 : v3)
    {
        for (auto it4 : v4)
        {
            if (mp.find(0 - it3 - it4) != mp.end())
            {
                c += mp[0 - it3 - it4];
            }
        }
    }
    return c;
}

//-----------------------------------455. Assign cookies ------------------------------//

int findchild(vector<int> g, vector<int> s)
{
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int i = 0, j = 0;
    while (i < g.size() && j < s.size())
    {
        if (g[i] <= s[j])
        {
            i++;
        }
        j++;
    }
    return i;
}

//-------------------------------------456. 132 Pattern ---------------------------//

bool findPattern(vector<int> nums)
{
    int n = nums.size();
    int s = INT_MIN;
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        if (nums[i] < s)
        {
            return true;
        }
        while (!st.empty() && nums[i] > st.top())
        {
            s = st.top();
            st.pop();
        }
        st.push(nums[i]);
    }
    return false;
}

//---------------------------------457. Circular array Loop ----------------------//

bool circularArrayLoop(vector<int> &nums)
{
    int n = nums.size();
    for (int j = 0; j < n; ++j)
        nums[j] %= n; // After this, no number is > n or < -n.
    for (int j = 0; j < n; ++j)
    {
        int i = j, last_i = 0;
        bool is_forward = nums[i] > 0;
        while (nums[i] % n != 0 && nums[i] > 0 == is_forward)
        {
            last_i = i;
            i = (i + nums[i] + n) % n;
            nums[last_i] = (j + 1) * n;
            if (nums[i] == (j + 1) * n) // each round, use a different number as the "visited marker".
                return true;
        }
    }
    return false;
}

//------------------------------458. Poor Pigs -----------------------------//

int poorPigs(int buckets, int minutesToDie, int minutesToTest)
{
    return ceil(log(buckets) / log(minutesToTest / minutesToDie + 1));
}

//-------------------------------459. Repeated Substring Pattern --------------------//

bool repeatedstring(string s)
{
    string str = s + s;
    string t = str.substr(1, 2 * s.length() - 2);
    if (t.find(s) != -1)
    {
        return true;
    }
    return false;
}

//-------------------------------460. LFU CACHE -----NOT DONE ---------------//

//---------------------------461. Hamming Distances ----------------------------//

int hammingDistance(int x, int y)
{
    int ans = 0;
    int n = x ^ y;
    while (n)
    {
        ans++;
        n &= n - 1;
    }
    return ans;
}

//--------------------------------462. Min moves to equal array element II--------------------//

int minmivesII(vector<int> v)
{
    int n = v.size();
    sort(v.begin(), v.end());
    int median = v[n / 2];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += abs(v[i] - median);
    }
    return ans;
}

//-------------------------------463. Island Perimeter --------------------------//

int Perimeter(vector<vector<int>> &grid)
{
    int c = 0, r = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); i++)
        {
            if (grid[i][j] == 1)
            {
                c++;
                if (i != 0 && grid[i - 1][j] == 1)
                {
                    r++;
                }
                if (j != 0 && grid[i][j - 1] == 1)
                {
                    r++;
                }
            }
        }
    }
    return 4 * c - 2 * r;
}

//------------------------------467. Unique Substring in wraparound string ------------------------//

int Findstring(string s)
{
    vector<int> v(26, 0);
    int mx = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (i > 0 && (s[i] - s[i - 1] == 1 || s[i - 1] - s[i] == 25))
        {
            mx++;
        }
        else
        {
            mx = 1;
        }
        v[s[i] - 'a'] = max(mx, v[s[i] - 'a']);
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        ans += v[i];
    }
    return ans;
}

//-----------------------------468. Valid IP --------------------------//

class Solution
{
public:
    string validIPAddress(string IP)
    {
        return validIPv4(IP) ? "IPv4" : (validIPv6(IP) ? "IPv6" : "Neither");
    }

private:
    bool validIPv4(string IP)
    {
        if (count(IP.begin(), IP.end(), '.') != 3)
        {
            return false;
        }
        vector<string> parts = split(IP, '.');
        if (parts.size() != 4)
        {
            return false;
        }
        for (string part : parts)
        {
            if (part.empty() || part.size() > 3 || part.size() > 1 && part[0] == '0')
            {
                return false;
            }
            for (char c : part)
            {
                if (!isdigit(c))
                {
                    return false;
                }
            }
            if (stoi(part) > 255)
            {
                return false;
            }
        }
        return true;
    }

    bool validIPv6(string IP)
    {
        if (count(IP.begin(), IP.end(), ':') != 7)
        {
            return false;
        }
        vector<string> parts = split(IP, ':');
        if (parts.size() != 8)
        {
            return false;
        }
        for (string part : parts)
        {
            if (part.empty() || part.size() > 4)
            {
                return false;
            }
            for (char c : part)
            {
                if (!isdigit(c) && (!isalpha(c) || toupper(c) > 'F'))
                {
                    return false;
                }
            }
        }
        return true;
    }

    vector<string> split(string s, char c)
    {
        vector<string> parts;
        string part;
        istringstream in(s);
        while (getline(in, part, c))
        {
            parts.push_back(part);
        }
        return parts;
    }
};

//------------------------------470. Implement rand10() using rand7() ------------------------//

int rand7() {}

int rand10(int n)
{
    int rand40 = 40;
    while (rand40 >= 40)
    {
        rand40 = (rand7() - 1) * 7 + rand7() - 1;
    }
    return rand40 % 10 + 1;
}

//-----------------------------474. Ones and Zeros ---------------------------//

int findmaxform(vector<string> v, int m, int n)
{
    int dp[m + 1][n + 1];
    memset(dp, 0, sizeof(dp));
    for (auto s : v)
    {
        int a = count(s.begin(), s.end(), '1');
        int b = s.length() - a;
        for (int i = m; i >= b; i--)
        {
            for (int j = n; j >= a; j--)
            {
                dp[i][j] = max(dp[i][j], dp[i - b][j - a] + 1);
            }
        }
    }
    return dp[m][n];
}

//------------------------------------475. Heaters ----------------------------------//

int findRadius(vector<int> &houses, vector<int> &heaters)
{
    if (heaters.size() == 0)
    {
        return 0;
    }
    sort(houses.begin(), houses.end());
    sort(heaters.begin(), heaters.end());
    int radius = 0;
    int index = 0;
    for (int i = 0; i < houses.size(); i++)
    {
        while (index + 1 < heaters.size() && (abs(heaters[index + 1] - houses[i]) <= abs(heaters[index] - houses[i])))
        {
            index++;
        }
        radius = max(radius, abs(heaters[index] - houses[i]));
    }
    return radius;
}

//-----------------------------476. Number Compliment ----------------------------//

int findComplement(int num)
{
    int ans = 0;
    int multi = 1;
    while (num)
    {
        int currBit = num & 1;
        num >>= 1;
        ans += multi * (1 - currBit);
        multi <<= 1;
    }
    return ans;
}

//----------------------------477. Total Hamming Distance -----------------------//

int totalHammingDistance(vector<int> &nums)
{
    int n = nums.size();
    if (n < 2)
    {
        return 0;
    }
    int res = 0;
    for (int i = 0; i < 32; i++)
    {
        int s = 0;
        for (int j = 0; j < n; j++)
        {
            if (nums[j] & (1 << i))
            {
                s++;
            }
        }
        res += s * (n - s);
    }
    return res;
}

int main()
{
}