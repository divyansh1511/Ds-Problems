#include<bits/stdc++.h>
using namespace std;

int PickFromBothSides(int arr[] , int n , int k){
    int ans = INT_MIN;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i];
    }
    ans = max(ans , sum);
    int i = k-1;
    int j = n-1;
    while (i >= 0)
    {
        sum = sum - arr[i--] + arr[j--];
        if (ans < sum)
        {
            ans = sum;
        }
    }
    return ans;
}

int MinStepsToInfiniteGrid(vector<int> v1 , vector<int> v2){
    int ans = 0;
    int n = v1.size();
    for (int i = 0; i < n-1; i++)
    {
        if (abs(v1[i] - v1[i+1]) <= abs(v2[i] - v2[i+1]))
        {
            ans += abs(v2[i] - v2[i+1]);
        }
        else
        {
            ans += abs(v1[i] - v1[i+1]);
        }
    }
    return ans;
}

int MinLightsToActivate(vector<int> a , int b){
    int n = a.size();
    int curr = -1;
    int cnt = 0;
    int i = 0;
    while (i < n)
    {
        curr = -1;
        for (int j = max(0 , i-b+1); j < min(n , i+b); j++)
        {
            if (a[j] == 1)
            {
                curr = j;
            }
        }
        if (curr == -1)
        {
            return -1;
        }
        cnt++;
        i = curr+b;
    }
    return cnt;
}

int MaxSumTriplet(vector<int> &v){
    int n = v.size();
    int right[n];
    right[n-1] = v[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        right[i] = max(right[i+1] , v[i]);
    }
    
    set<int> s;
    s.insert(v[0]);
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        s.insert(v[i]);
        auto it = s.find(v[i]);
        if (it != s.begin() && right[i] != v[i])
        {
            ans = max(ans , (*--it) + v[i] + right[i]);
        }
    }
    return ans;
}

int MaximumContingousSubarr(int arr[] , int n){
    int sum = arr[0];
    int maxsum = arr[0];
    for (int i = 1; i < n; i++)
    {
        sum = max(arr[i] , sum+arr[i]);
        maxsum = max(maxsum , sum);
    }
    return maxsum;
}

vector<int> AddOneTwoNumber(vector<int> v){
    int carry = 1;
    reverse(v.begin() , v.end());
    for (int i = 0; i < v.size(); i++)
    {
        int sum = v[i] + carry;
        v[i] = sum%10;
        carry = sum/10;
    }
    if (carry != 0)
    {
        v.push_back(carry);
    }
    reverse(v.begin() , v.end());
    while (v.front())
    {
        auto it = v.begin();
        v.erase(it);
    }
    return v;
}

int MaximumAbsoluteDifference(vector<int> &v){
    int max1 = v[0];
    int max2 = v[0];
    int min1 = v[0];
    int min2 = v[0];
    for (int i = 1; i < v.size(); i++)
    {
        max1 = max(max1 , v[i]+i);
        max2 = max(max2 , v[i]-i);
        min1 = min(min1 , v[i]+i);
        min2 = min(min2 , v[i]-i);
    }
    int ans = max(max1 - min1 , max2 - min2);
    return ans;
}

int Partitions(vector<int> v){
    int n = v.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
    }
    if (sum%3 != 0)
    {
        return 0;
    }
    sum /= 3;

    int s = 0;
    int count = 0;
    int left = 0;
    for (int i = 0; i < n; i++)
    {
        s += v[i];
        if (s == (2*sum))
        {
            count += left;
        }
        if (s == sum)
        {
            left++;
        }
    }
    return count;
}

vector<int> Flips(string s){
    int n = s.length();
    int curr = 0;
    int maxsofar = 0;

    int l = -1 , r = -1 , si = 0;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            curr++;
        }
        else
        {
            curr--;
        }

        if (curr > maxsofar)
        {
            maxsofar = curr;
            l = si;
            r = i;
        }
        if (curr < 0)
        {
            si = i+1;
            curr = 0;
        }
    }
    if (l == -1)
    {
        return {};
    }
    return {l+1 , r+1};
}

int sum_of_Max_Min_element(int arr[] , int n){
    int maxelement = INT_MIN;
    int minelement = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        maxelement = max(maxelement , arr[i]);
        minelement = min(minelement , arr[i]);
    }
    return (maxelement+minelement);
}

vector<vector<int>> MergeIntervals(vector<vector<int>> Intervals , vector<int> newIntervals){
    vector<vector<int>> ans;
    Intervals.push_back(newIntervals);
    sort(Intervals.begin() , Intervals.end());
    ans.push_back(Intervals[0]);
    for (int i = 1; i < Intervals.size(); i++)
    {
        if (ans[ans.size()-1][1] > Intervals[i][0])
        {
            ans[ans.size()-1][1] = max(ans[ans.size()-1][1] , Intervals[i][1]);
        }
        else
        {
            ans.push_back(Intervals[i]);
        }
    }
    return ans;
}

int PerfectPeakOfArray(int arr[] , int n){
    int left[n];
    left[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i-1] , arr[i]);
    }
    int right[n];
    right[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
    {
        right[i] = min(right[i+1] , arr[i]);
    }
    for (int i = 1; i < n-1; i++)
    {
        if (arr[i] > left[i-1] && arr[i] < right[i+1])
        {
            return 1;
        }
    }
    return 0;
}

vector<int> MoveZeros(vector<int> v){
    int j = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] != 0)
        {
            if (i != j)
            {
                swap(v[i] , v[j]);
            }
            j++;
        }
    }
    return v;
}

bool check(vector<int> v , int k , int tmp){
    for(auto it : v){
        if (it - k == tmp || it + k == tmp || it == tmp)
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int MakeEqualElements(vector<int> v , int k){
    int n = v.size();
    if (check(v , k , v[0]) || check(v , k , v[0]-k) || check(v , k , v[0]+k))
    {
        return 1;
    }
    else
    {
        return 0;
    }   
}

vector<int> segregrate01(vector<int> v){
    int j = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            if (i != j)
            {
                swap(v[i] , v[j]);
            }
            j++;
        }
    }
    return v;
}

vector<int> ArraySum(vector<int> A , vector<int> B){
    vector<int> ans;
    reverse(A.begin() , A.end());
    reverse(B.begin() , B.end());
    int carry = 0;
    int i = 0 , j = 0;
    int n = A.size() , m = B.size();
    while (i < n && j < m)
    {
        int sum = A[i++] + B[j++] + carry;
        ans.push_back(sum%10);
        carry = sum/10;
    }
    while (i < n)
    {
        int sum = A[i++] + carry;
        ans.push_back(sum%10);
        carry = sum/10;
    }
    while (j < m)
    {
        int sum = B[j++] + carry;
        ans.push_back(sum%10);
        carry = sum/10;
    }
    if (carry != 0)
    {
        ans.push_back(carry);
    }
    reverse(ans.begin() , ans.end());
    return ans;
}

vector<int> KthrowOfPascalsTriangle(int k){
    vector<vector<int>> ans(k+1);
    for (int i = 0; i <= k; i++)
    {
        ans[i].resize(i+1);
        ans[i][0] = ans[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
        }
    }
    return ans[k];
}

vector<vector<int>> SpiralOrderMatrix(int A){
    vector<vector<int>> a(A , vector<int>(A));
    int i, k = 0, l = 0;
    int c = 1;
    int m = A , n = A;
    while (k < m && l < n) {
        for (i = l; i < n; ++i) {
            a[k][i] = c;
            c++;
        }
        k++;
        for (i = k; i < m; ++i) {
            a[i][n-1] = c;
            c++;
        }
        n--;

        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                a[m-1][i] = c;
                c++;
            }
            m--;
        }

        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                a[i][l] = c;
                c++;
            }
            l++;
        }
    }
    return a;
}

vector<vector<int>> PascalsTriangle(int A){
    vector<vector<int>> v(A);
    for(int i=0;i<A;i++){
        v[i].resize(i+1);
        v[i][0] = v[i][i] = 1;
        for(int j = 1;j<i;j++){
            v[i][j] = v[i-1][j-1] + v[i-1][j];
        }
    }
    return v;
}

vector<vector<int>> Diagonals(vector<vector<int>> &A){
    int n = A.size(), d,i;
    vector<vector<int> > ret;
    if (n <= 0 || A[0].size() != n) {
        return ret;
    }
    vector<int> temp;
    for (d = 0; d < 2*n - 1; ++d) {
        temp.clear();
        for (i = 0; i <= d; ++i) {
            if (i < n && d-i < n) {
                temp.push_back(A[i][d-i]);
            }
        }
        if (temp.size() > 0) {
            ret.push_back(temp);
        }
    }
    return ret;
}

bool TripletWithSumbtwGivenRange(vector<string> v){
    int n = v.size();
    int i = 0;
    int j = n-1;
    sort(v.begin() , v.end());
    while ((j-i) >= 2)
    {
        int mid = (i+j)/2;
        double a = stof(v[i]);
        double b = stof(v[mid]);
        double c = stof(v[j]);
        double sum = a+b+c;
        if (sum > 2)
        {
            j--;
        }
        else if (sum < 1)
        {
            i++;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

int BalancedArray(int arr[] , int n){
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            sum1 += arr[i];
        }
        else
        {
            sum2 += arr[i];
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i%2 == 0)
        {
            sum1 -= arr[i];
            if (sum1 == sum2)
            {
                count++;
            }
            sum2 += arr[i];
        }
        else
        {
            sum2 -= arr[i];
            if (sum1 == sum2)
            {
                count++;
            }
            sum1 += arr[i];
        }
    }
    return count;
}

int FindDuplicate(int arr[] , int n){
    vector<bool> v(n+1 , false);
    for (int i = 0; i < n; i++)
    {
        int b = arr[i];
        if (v[b] == true)
        {
            return b;
        }
        v[b] = true;
    }
    return false;
}

int MaximumConsequtiveGap(int arr[] , int n){
    sort(arr , arr+n);
    int ans = 0;
    for (int i = 0; i < n-1; i++)
    {
        ans = max(ans , arr[i+1] - arr[i]);
    }
    return ans;
}

vector<int> SortWithSquares(vector<int> v){
    int n = v.size();
    int left = 0;
    int right = n-1;
    vector<int> ans(n);
    for (int i = n-1; i >= 0; i--)
    {
        if (abs(v[left]) > abs(v[right]))
        {
            ans[i] = (v[left]*v[left]);
            left++;
        }
        else
        {
            ans[i] = (v[right]*v[right]);
            right--;
        }
    }
    return ans;
}

bool static cmp(int a , int b){
    string a1 = to_string(a);
    string b1 = to_string(b);
    return a1+b1 > b1+a1;
}

string LargestNumber(vector<int> v){
    sort(v.begin() , v.end() , cmp);

    int c = 0;
    string a = "";
    for (int i = 0; i < v.size(); i++)
    {
        a += to_string(v[i]);
        if (v[i] == 0)
        {
            c++;
        }
    }
    if (c == v.size())
    {
        return "0";
    }
    return a;
}

void RotateMatrix(vector<vector<int>> v){
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < i; i++)
        {
            swap(v[i][j] , v[j][i]);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        reverse(v[i].begin() , v[i].end());
    }
}

vector<int> NextPermutation(vector<int> v){
    int k , l;
    int n = v.size();
    for (k = n-2; k >= 0; k--)
    {
        if (v[k] < v[k+1])
        {
            break;
        }
    }
    if (k < 0)
    {
        reverse(v.begin() , v.end());
        return v;
    }
    else
    {
        for (l = n-1; l >= k; l--)
        {
            if (v[l] > v[k])
            {
                break;
            }
            swap(v[l] , v[k]);
            reverse(v.begin()+k+1 , v.end());
        }
        return v;
    }
}

vector<int> FindPermutation(string A, int B) {
    int i=1, n=B;
    vector<int> ans;
    if(A[0]=='D')
        ans.push_back(n--);
    else
        ans.push_back(i++);
    if(B==2 || B==1)
        return ans;
    for(int j=0;j<B-2;j++)
    {
        if(A[j] == 'D' && A[j+1] == 'D')
            ans.push_back(n--);
        if(A[j] == 'D' && A[j+1] == 'I')
            ans.push_back(i++);
        if(A[j] == 'I' && A[j+1] == 'D')
            ans.push_back(n--);
        if(A[j] == 'I' && A[j+1] == 'I')
            ans.push_back(i++);
    }
    ans.push_back(i++);
    return ans;
}

int NobelInteger(vector<int> v){
    int n = v.size();
    sort(v.begin() , v.end());
    for (int i = 0; i < n; i++)
    {
        if (i+1 < n && v[i] != v[i+1] && v[i] == n-i-1)
        {
            return 1;
        }
        else if (i == n-1 && v[i] == 0)
        {
            return 1;
        }
    }
    return -1;
}

vector<int> WaveArray(vector<int> v){
    int n = v.size();
    sort(v.begin() , v.end());
    for (int i = 0; i < n; i += 2)
    {
        if (i == n-1)
        {
            break;
        }
        swap(v[i] , v[i+1]);
    }
    return v;
}

bool HotelBookingProblem(vector<int> arrive , vector<int> depart , int k){
    sort(arrive.begin() , arrive.end());
    sort(depart.begin() , depart.end());

    for (int i = k; i < arrive.size(); i++)
    {
        if (arrive[i] < depart[i-k])
        {
            return false;
        }
    }
    return true;
}

int MaximumDistance(vector<int> a){
    int n = a.size();
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({a[i] , i});
    }
    sort(v.begin() , v.end());
    int ans = 0;
    int rmax = v[n-1].second;
    for (int i = n-2; i >= 0; i--)
    {
        ans = max(ans , rmax-v[i].second);
        rmax = max(rmax , v[i].second);
    }
    return ans;
}

vector<int> MaximumUnsortedArray(vector<int> a){
    int n = a.size();
    int l = n , r = 0;
    int mn = INT_MAX , mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < mx)
        {
            r = i;
        }
        mx = max(mx , a[i]);
    }
    for (int i = n-1; i >= 0; i--)
    {
        if (a[i] > mn)
        {
            l = i;
        }
        mn = min(mn , a[i]);
    }
    if (l == n)
    {
        return {-1};
    }
    return {l , r};
}

void SetZeros(vector<vector<int>> &v){
    bool firstcol = false;
    bool firstrow = false;
    int n = v.size() , m = v[0].size();
    for (int i = 0; i < n; i++)
    {
        if (v[i][0] == 0)
        {
            firstcol = true;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (v[0][i] == 0)
        {
            firstrow = true;
            break;
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                v[i][0] = 0;
                v[0][j] = 0;
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (v[i][0] == 0 || v[0][j] == 0)
            {
                v[i][j] = 0;
            }
        }
    }
    if (firstrow)
    {
        for (int i = 0; i < m; i++)
        {
            v[0][i] = 0;
        }
    }
    if (firstcol)
    {
        for (int i = 0; i < n; i++)
        {
            v[i][0] = 0;
        }
    }
}

int FirstMissingInteger(vector<int> v){
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        if (v[i] > 0 && v[i] <= n)
        {
            int pos = v[i]-1;
            if (v[pos] != v[i])
            {
                swap(v[pos] , v[i]);
                i--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i] != i+1)
        {
            return i+1;
        }
    }
    return  n+1;
}

int MaximumSubMatrix(vector<vector<int> > &v, int k){
    int n = v.size();
    vector<vector<int>> s(n , vector<int>(n , 0));
    for (int i = 0; i < n; i++)
    {
        s[i][0] = v[i][0];
        for (int j = 1; j < n; j++)
        {
            s[i][j] = s[i][j-1] + v[i][j];
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            s[i][j] = s[i][j] + s[i-1][j];
        }
    }
    
    int sum = 0;
    for (int i = k-1; i < n; i++)
    {
        for (int j = k-1; j < n; j++)
        {
            if (i == k-1 && j == k-1)
            {
                sum = s[i][j];
            }
            else if (i == k-1)
            {
                sum = max(sum , s[i][j] - s[i][j-k]);
            }
            else if (j == k-1)
            {
                sum = max(sum , s[i][j] - s[i-k][j]);
            }
            else
            {
                sum = max(sum , s[i][j] - s[i-k][j] - s[i][j-k] - s[i-k][j-k]);
            }
        }
    }
    return sum;
}

vector<int> RepeatedAndMissingNo(vector<int> v){
    long long sum = 0;
    long long squaresum = 0;
    long long temp;
    for (int i = 0; i < v.size(); i++)
    {
        sum += v[i];
        sum -= (i+1);
        squaresum += (v[i]*v[i]);
        squaresum -= (i+1)*(i+1);
    }
    squaresum /= sum;
    int a = (sum+squaresum)/2;
    int b = squaresum-a;
    return {a,b};
}

int RepeatedNumberN3(vector<int> v){
    unordered_map<int,int> mp;
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        mp[v[i]]++;
    }
    
    for(auto it : mp){
        if (it.second > n/3)
        {
            return it.first;
        }
    }
    return -1;
}

int main(){

}