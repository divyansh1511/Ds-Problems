#include <bits/stdc++.h>
using namespace std;

int getColumnNumber(string excelColumnNumber)
{
    int ans = 0;
    int n = excelColumnNumber.length();
    for (int i = 0; i < n; i++)
    {
        ans += pow(26, n - i - 1) * (excelColumnNumber[i] - 'A' + 1);
    }
    return ans;
}

int trailingZeroesInFactorial(int n)
{
    int ans = 0;
    int b = 5;
    while (b <= n)
    {
        ans += (n / b);
        b *= 5;
    }
    return ans;
}

int gcd(int firstNum, int secondNum)
{
    if (secondNum == 0)
    {
        return firstNum;
    }
    return gcd(secondNum, firstNum % secondNum);
}

vector<int> primesUptoN(int n)
{
    bool isPrime[n + 1];
    for (int i = 2; i <= n; i++)
    {
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        for (int j = i * i; j <= n; j += i)
        {
            if (isPrime[i] == true)
            {
                isPrime[j] = false;
            }
        }
    }
    vector<int> answer;
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i] == true)
        {
            answer.push_back(i);
        }
    }
    return answer;
}

int getNumPaths(int rows, int columns)
{
    vector<vector<int>> v(rows, vector<int>(columns, 1));
    for (int i = 1; i < rows; i++)
    {
        for (int j = 1; j < columns; j++)
        {
            v[i][j] = v[i - 1][j] + v[i][j - 1];
        }
    }
    return v[rows - 1][columns - 1];
}

int getModulatedPower(int x, int y, int z)
{
    int res = 1;
    x %= z;
    if (x == 0)
    {
        return 0;
    }
    while (y > 0)
    {
        if (y % 2 != 0)
        {
            res = (res * x) % z;
        }
        y /= 2;
        x = (x * x) % z;
    }
    return res;
}

int msbSignificance(int n)
{
    int a = 1;
    int ans = 0;
    while (n != 0)
    {
        if (n & 1)
        {
            ans = a;
        }
        n >>= 1;
        a *= 2;
    }
    return ans;
}

bool isPowerOfTwo(int n)
{
    return n && !(n & (n - 1));
}

int countSetBits(int n)
{
    int ans = 0;
    while (n != 0)
    {
        if (n & 1)
        {
            ans++;
        }
        n >>= 1;
    }
    return ans;
}

int findTheMissingNumber(vector<int> &nums)
{
    int a = 0;
    int b = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        a ^= nums[i];
        b ^= (i + 1);
    }
    b ^= (n + 1);
    return a ^ b;
}

vector<int> findRepeatAndMissingNumber(vector<int> &nums)
{
    int sum = 0;
    int squaresum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        sum -= (i + 1);
        squaresum += (nums[i] * nums[i]);
        squaresum -= ((i + 1) * (i + 1));
    }
    squaresum /= sum;
    int a = (sum + squaresum) / 2;
    int b = squaresum - a;
    return {a, b};
}

int divide(int a, int b) {
	int sign = 1;
	if((a > 0 && b < 0) || (a < 0 && b > 0)) {
		sign = - 1;
	}
	a = abs(a);
	b = abs(b);
    int quotient = 0;
	for (int i = 30; i >= 0; i--) {
		long long temp = (long long)b << (long long)i;
		if(temp <= a) {
			a -= temp;
			quotient += 1 << i;
		}
	}
	return sign * quotient;
}

void helper(vector<vector<int>> &ans , vector<int> t , int st , vector<int> nums){
	if(st == nums.size()){
		if(t.size() != 0){
			ans.push_back(t);
		}
		return;
	}
	t.push_back(nums[st]);
	helper(ans , t , st+1 , nums);
	t.pop_back();
	helper(ans , t , st+1 , nums);
}

vector<vector<int>> getPowerSet(vector<int> &nums) {
	vector<vector<int>> ans;
	vector<int> t;
	ans.push_back(t);
	helper(ans , t , 0 , nums);
	sort(ans.begin() , ans.end());
	return ans;
}

int main()
{
}