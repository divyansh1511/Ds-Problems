#include <bits/stdc++.h>
using namespace std;

int SetBitsInNumber(int n)
{
    int c = 0;
    while (n)
    {
        if (n & 1)
        {
            c++;
        }
        n >>= 1;
    }
    return c;
}

vector<int> TwoNonRepeatingElement(vector<int> nums)
{
    int a = 0, x = 0, y = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        a = a ^ nums[i];
    }
    int k = a ^ (~(a - 1));
    for (int i = 0; i < nums.size(); i++)
    {
        if (k & nums[i])
        {
            x ^= nums[i];
        }
        else
        {
            y ^= nums[i];
        }
    }
    if (x < y)
    {
        return {x, y};
    }
    else
    {
        return {y, x};
    }
}

int countBitFlips(int a, int b)
{
    int c = 0;
    while (a || b)
    {
        int n1 = a & 1;
        int n2 = b & 1;
        if (n1 != n2)
        {
            c++;
        }
        a >>= 1;
        b >>= 1;
    }
    return c;
}

bool isPower2(int n)
{
    return n && (!(n & (n - 1)));
}

int countSetBits(int n)
{
    n++;
    int po2 = 2;
    int cnt = n / 2;
    while (po2 <= n)
    {
        int tp = n / po2;
        cnt += (tp / 2) * po2;
        cnt += (tp & 1) ? (n % po2) : 0;
        po2 <<= 1;
    }
    return cnt;
}

int findPosition(int N)
{
    if (N == 0)
    {
        return -1;
    }
    if (!isPower2(N))
    {
        return -1;
    }
    int count = 0;
    while (N)
    {
        int lbit = N & 1;
        N >>= 1;
        count++;
        if (lbit == 1)
        {
            break;
        }
    }
    return count;
}

int copysetbits(int x, int y, int l, int r)
{
    int cnt = 0;
    for (int i = l - 1; i < r; i++)
    {
        if ((y & (1 << i)) != 0)
        {
            x = (x | (1 << i));
        }
    }
    return x;
}

int square(int n)
{
    if (n < 0)
        n = -n;
 
    int res = n;
    for (int i = 1; i < n; i++)
        res += n;
 
    return res;
}

int main()
{
    
}