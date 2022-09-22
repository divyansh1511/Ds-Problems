#include<bits/stdc++.h>
using namespace std;

int TotalMoveOfBishop(int A , int B){
    int count = 0;
    int a = A , b = B;
    while (a > 1 && b > 1)
    {
        a--;
        b--;
        count++;
    }
    a = A;
    b = B;
    while (a < 8 && b < 8)
    {
        a++;
        b++;
        count++;
    }
    a = A;
    b = B;
    while (a > 1 && b < 8)
    {
        a--;
        b++;
        count++;
    }
    a = A;
    b = B;
    while (a < 8 && b > 1)
    {
        a++;
        b--;
        count++;
    }
    return count;
}

int solve(int a , int b , int c){
    int index = (c+a%b)%b - 1;
    return index;
}

bool isPrime(int n){
    for (int i = 2; i < sqrt(n); i++)
    {
        if (n%i == 0)
        {
            return false;
        }
    }
    return true;
}

vector<int> PrimeSum(int A){
    vector<int> v;
    for (int i = 2; i <= A/2; i++)
    {
        if (isPrime(i) && isPrime(A-i))
        {
            v.push_back(i);
            v.push_back(A-i);
            return v;
        }
    }
    return {-1};
}

vector<string> FizzBuzz(int n){
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        if (i%3 == 0 && i%5 == 0)
        {
            ans.push_back("FizzBuzz");
        }
        else if (i%3 == 0)
        {
            ans.push_back("Fizz");
        }
        else if (i%5 == 0)
        {
            ans.push_back("Buzz");
        }
        else
        {
            ans.push_back(to_string(i));
        }
    }
    return ans;
}

bool isRectangle(int a , int b , int c , int d){
    if (a == b)
    {
        return c == d;
    }
    else if (a == c)
    {
        return b == d;
    }
    else if (a == d)
    {
        return b == c;
    }
    else
    {
        return false;
    }
}

int solve(int a){
    a = abs(a);
    if (a == 0)
    {
        return 0;
    }
    int step = 0;
    int sum = 0;
    while (true)
    {
        step++;
        sum += step;
        if (sum == a)
        {
            return step;
        }
        if (sum > a && (sum-a)%2 == 0)
        {
            return step;
        }
    }
}

int PowerOf2Integer(int n){
    if (n == 0)
    {
        return 0;
    }
    for (int i = 2; i < n; i++)
    {
        if (n%i == 0)
        {
            for (int j = 2; j < 32; j++)
            {
                if (pow(i , j) > n)
                {
                    break;
                }
                if (pow(i , j) == n)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int ExcelColumnNumber(string s){
    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        ans += pow(26 , n-i-1)*(s[i]-'A'+1);
    }
    return ans;
}

string ConvertToTitle(int n){
    string ans = "";
    while (n)
    {
        ans += char((n-1)%26 + 'A');
        n = (n-1)/26;
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

bool IsPalindromeNumber(int n){
    int a = n;
    int ans = 0;
    while (a)
    {
        ans = ans*10 + (a%10);
        a = a/10;
    }
    if (ans == n)
    {
        return true;
    }
    return false;
}

string NextSmallestPalindrome(string s){
    int n = s.length();
    int mid = (n+1)/2;

    bool incr = true;
    for (int i = 0; i < n; i++)
    {
        if (s[n-i-1] == s[i])
        {
            continue;
        }
        if (s[n-i-1] < s[i])
        {
            incr = true;
        }
        if (s[n-i-1] > s[i])
        {
            incr = false;
        }
        break;
    }
    
    s = s.substr(0 , mid);

    if (incr)
    {
        int carry = 1;

        for (int i = mid-1; i >= 0 && carry == 1; i--)
        {
            s[i] = (s[i] == '9' ? '0' : s[i] + carry--);
        }
        if (carry)
        {
            return "1" + string(n-1 , '0') + "1";
        }
    }
    for(int i = n-s.size()-1; i >= 0; i--)
        s.push_back(s[i]);
    return s;
}

int gcd(int a , int b){
    if (a == 0)
    {
        return b;
    }
    return gcd(b%a , a);
}

int DivisibleBy60(vector<int> v){
    int sum = 0;
    int z = 0;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        if (v[i] == 0)
        {
            z = 1;
        }
    }
    
    if (v.size() <= 2)
    {
        if (z == 0)
        {
            return 0;
        }
        if (v.size() == 1 && v[0] == 0)
        {
            return 1;
        }
        else if ((v[0] == 0 && v[1] == 6) || (v[1] == 0 && v[0] == 6))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    
    if ((sum%3 == 0 || sum%9 == 0) && z == 1)
    {
        return 1;
    }
    return 0;
}

int main(){

}