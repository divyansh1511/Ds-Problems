#include <bits/stdc++.h>
using namespace std;

int setBits(int N)
{
    int count = 0;
    while (N)
    {
        int lbit = N & 1;
        N >>= 1;
        if (lbit == 1)
        {
            count++;
        }
    }
    return count;
}

vector<int> singleNumber(vector<int> nums)
{
    int a = 0, x = 0, y = 0;
    for (int i = 0; i < nums.size(); i++)
        a = a ^ nums[i];

    int k = a & ~(a - 1); // first set bit
    for (int i = 0; i < nums.size(); i++)
    {
        if (k & nums[i])
            x ^= nums[i];
        else
            y ^= nums[i];
    }
    if (x < y)
        return {x, y};
    else
        return {y, x};
}

bool isPowerofTwo(long long n)
{
    return n && (!(n & (n - 1)));
}

int countBitsFlip(int a, int b)
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

int square(int num)
{
    if (num < 0)
        num = -num;
    int power = 0, result = 0;
    int temp = num;

    while (temp)
    {
        if (temp & 1)
        {
            result += (num << power);
        }
        power++;
        temp = temp >> 1;
    }

    return result;
}

long long divide(long long dividend, long long divisor)
{
    long long quotient = 0, sign = ((divisor < 0) ^ (dividend < 0)) ? -1 : 1;
    dividend = abs(dividend), divisor = abs(divisor);
    for (int i = 31; i >= 0; i--)
    {
        long long partDiv = (divisor << i);
        if (partDiv <= dividend)
        {
            dividend -= partDiv;
            quotient |= (1 << i);
        }
    }
    return sign * quotient;
}

int main()
{
}