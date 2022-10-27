#include <bits/stdc++.h>
using namespace std;

int ReverseNumber(int n)
{
    int ans = 0;
    while (n)
    {
        ans = ans * 10 + n % 10;
        n = n / 10;
    }
    return ans;
}

string addBinary(string a, string b)
{
    string ans = "";
    int i = a.length() - 1, j = b.length() - 1;
    int carry = 0;
    while (i >= 0 || j >= 0)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += a[i--] - '0';
        }
        if (j >= 0)
        {
            sum += b[j--] - '0';
        }
        carry = sum > 1 ? 1 : 0;
        ans += to_string(sum % 2);
    }
    if (carry)
    {
        ans += to_string(carry);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }
    int a = ReverseNumber(x);
    if (a == x)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int minMoves(vector<int> &nums)
{
    int n = nums.size();
    int sum = nums[0];
    int mn = nums[0];
    for (int i = 1; i < n; i++)
    {
        mn = min(mn, nums[i]);
        sum += nums[i];
    }
    return sum - long(mn) * long(n);
}

string convertToTitle(int columnNumber)
{
    string ans = "";
    while (columnNumber)
    {
        ans += char((columnNumber - 1) % 26 + 'A');
        columnNumber = (columnNumber - 1) / 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int missingNumber(int arr[], int n)
{
    int a = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        a ^= arr[i];
        b ^= (i + 1);
    }
    return a ^ b;
}

int maximumProductofthree(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int temp1 = nums[n - 1] * nums[n - 2] * nums[n - 3];
    int temp2 = nums[0] * nums[1] * nums[n - 1];
    return temp1 > temp2 ? temp1 : temp2;
}

bool isPowerOfTwo(int n)
{
    int ans = 1;
    for (int i = 0; i < 31; i++)
    {
        if (ans == n)
        {
            return true;
        }
        if (ans < INT_MAX / 2)
        {
            ans = ans * 2;
        }
    }
    return false;
}

int myAtoi(string s)
{
    long long int result = 0;
    int indicator = 1;
    int n = s.length();
    if (n == 0)
    {
        return 0;
    }

    int i = 0;
    while ((s[i] == ' ') && i < n)
    {
        i++;
    }
    if (i == n)
    {
        return 0;
    }
    if ((s[i] == '-' || s[i] == '+') && i < n)
        indicator = (s[i++] == '-') ? -1 : 1;

    while ('0' <= s[i] && s[i] <= '9' && i < n)
    {
        result = result * 10 + (s[i++] - '0');
        if (result * indicator >= INT_MAX)
            return INT_MAX;
        if (result * indicator <= INT_MIN)
            return INT_MIN;
    }
    return result * indicator;
}

string multiply(string num1, string num2)
{
    int n = num1.length(), m = num2.length();
    string res((n + m), '0');
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            int num = (num1[i] - '0') * (num2[j] - '0') + res[i + j + 1] - '0';
            res[i + j + 1] = num % 10 + '0';
            res[i + j] += num / 10;
        }
    }
    for (int i = 0; i < res.length(); i++)
    {
        if (res[i] != '0')
        {
            return res.substr(i);
        }
    }
    return "0";
}

double angleClock(int hour, int minutes)
{
    double hour_angle = (hour % 12) * 30 + minutes * 0.5;
    double minute_angle = minutes * 6;
    double diff = abs(hour_angle - minute_angle);
    return min(diff, 360 - diff);
}

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

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}
int maxPoints(vector<vector<int>> &points)
{
    int n = points.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_map<string, int> mp;
        int dup = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (points[j][0] == points[i][0] && points[j][1] == points[i][1])
            {
                dup++;
            }
            else
            {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];
                int g = gcd(dx, dy);
                mp[to_string(dx / g) + "_" + to_string(dy / g)]++;
            }
        }
        ans = max(ans, dup);
        for (auto it : mp)
        {
            ans = max(ans, it.second + dup);
        }
    }
    return ans;
}

int countDigitOne(int n)
{
    int ans = 0;
    if (n <= 0)
    {
        return 0;
    }
    if (n <= 9)
    {
        return 1;
    }
    unordered_map<int, int> mp;
    mp[9] = 1;
    for (int i = 9; i < (INT_MAX - 9) / 10; i = i * 10 + 9)
    {
        mp[i * 10 + 9] = mp[i] * 10 + (i + 1);
    }
    int tmp = n, d = 1;
    while (tmp / 10)
    {
        tmp /= 10;
        d *= 10;
    }
    ans += (n / d) * mp[d - 1];
    ans += (n / d > 1) ? d : 0;
    ans += (n / d == 1) ? n % d + 1 : 0;
    ans += countDigitOne(n % d);
    return ans;
}



int main()
{
}