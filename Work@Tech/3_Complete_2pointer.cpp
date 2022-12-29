#include <bits/stdc++.h>
using namespace std;

int RemoveOccurence(vector<int> v, int k)
{
    int n = v.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (v[i] != k)
        {
            v[j++] = v[i];
        }
    }
    return j;
}

bool HasTwoSumZero(vector<int> &v)
{
    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        int sum = v[i] + v[j];
        if (sum == 0)
        {
            return true;
        }
        else if (sum < 0)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    return false;
}

vector<int> Merge2sortedarr(vector<int> v1, vector<int> v2)
{
    vector<int> ans;
    int i = 0, j = 0;
    int n = v1.size(), m = v2.size();
    while (i < n && j < m)
    {
        if (v1[i] < v2[j])
        {
            ans.push_back(v1[i]);
            i++;
        }
        else
        {
            ans.push_back(v2[j]);
            j++;
        }
    }
    while (i < n)
    {
        ans.push_back(v1[i]);
        i++;
    }
    while (j < n)
    {
        ans.push_back(v2[j]);
        j++;
    }
}

vector<int> ksubarrsum(vector<int> v, int k)
{
    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += v[i];
    }
    ans.push_back(sum);
    for (int i = k; i < v.size(); i++)
    {
        sum -= v[i - k];
        sum += v[i];
        ans.push_back(sum);
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

vector<vector<int>> threeSum(vector<int> &A)
{
    sort(A.begin(), A.end());
    vector<vector<int>> v;
    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && (A[i] == A[i - 1]))
        {
            continue;
        }
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = A[i] + A[j] + A[k];
            if (sum == 0)
            {
                v.push_back({A[i], A[j], A[k]});
                while (j + 1 < k && A[j] == A[j + 1])
                {
                    j++;
                }
                while (j < k - 1 && A[k] == A[k - 1])
                {
                    k--;
                }
                j++;
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return v;
}

int kDiffPairs(vector<int> &A, int k)
{
    int n = A.size();
    int i = 0, j = 1;
    int count = 0;
    while (j < n)
    {
        while (j < n - 1 && A[j] == A[j + 1])
        {
            j++;
        }
        int diff = A[j] - A[i];
        if (diff == k)
        {
            count++;
            i++;
            j++;
        }
        else if (diff < k)
        {
            j++;
        }
        else
        {
            i++;
        }
        if (i == j)
        {
            j++;
        }
    }
    return count;
}

int getKthElement(vector<int> &firstArr, vector<int> &secondArr, int k)
{
    int ans = -1;
    int i = 0, j = 0;
    int n = firstArr.size(), m = secondArr.size();
    while (i < n && j < m && k > 0)
    {
        if (firstArr[i] < secondArr[j])
        {
            ans = firstArr[i];
            i++;
        }
        else
        {
            ans = secondArr[j];
            j++;
        }
        k--;
    }
    return ans;
}

vector<int> intersection(vector<int> &A, vector<int> &B)
{
    int n = A.size(), m = B.size();
    vector<int> v;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[A[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        if (mp[B[i]] > 0)
        {
            v.push_back(B[i]);
            mp[B[i]]--;
        }
    }
    return v;
}

void sort012(vector<int> &A)
{
    int z = 0, o = 0, t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
        {
            z++;
        }
        else if (A[i] == 1)
        {
            o++;
        }
        else
        {
            t++;
        }
    }
    int i = 0;
    while (i < z)
    {
        A[i] = 0;
        i++;
    }
    while (i < (z + o))
    {
        A[i] = 1;
        i++;
    }
    while (i < A.size())
    {
        A[i] = 2;
        i++;
    }
}

int volumeOfTrappedRainWater(vector<int> &arr)
{
    int lo = 0, hi = arr.size() - 1;
    int mi = 0, ma = 0;
    int ans = 0;
    while (lo <= hi)
    {
        if (arr[lo] < arr[hi])
        {
            if (arr[lo] > mi)
            {
                mi = arr[lo];
            }
            else
            {
                ans += (mi - arr[lo]);
            }
            lo++;
        }
        else
        {
            if (arr[hi] > ma)
            {
                ma = arr[hi];
            }
            else
            {
                ans += (ma - arr[hi]);
            }
            hi--;
        }
    }
    return ans;
}

int maxKSubarraySum(vector<int> &A, int k)
{
    int a = 0, maxa = 0;
    int i;
    for (i = 0; i < k; i++)
    {
        a += A[i];
    }
    maxa = max(maxa, a);
    for (i; i < A.size(); i++)
    {
        a -= A[i - k];
        a += A[i];
        maxa = max(maxa, a);
    }
    return maxa;
}

int isVowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
    {
        return 1;
    }
    return 0;
}
vector<int> kSubstringVowels(string s, int k)
{
    int n = s.length();
    vector<int> vowels(n + 1 - k);
    int count = 0;
    for (int i = 0; i < k; i++)
    {
        count += isVowel(s[i]);
    }
    vowels[0] = count;
    for (int i = k; i < n; i++)
    {
        count = count - isVowel(s[i - k]) + isVowel(s[i]);
        vowels[i - k + 1] = count;
    }
    return vowels;
}

int maxKSubstringVowels(string s, int k)
{
    int n = s.length();
    int c = 0;
    for (int i = 0; i < k; i++)
    {
        c += isVowel(s[i]);
    }
    int mxc = c;
    for (int i = k; i < n; i++)
    {
        c = c - isVowel(s[i - k]) + isVowel(s[i]);
        mxc = max(c, mxc);
    }
    return mxc;
}

int main()
{
}