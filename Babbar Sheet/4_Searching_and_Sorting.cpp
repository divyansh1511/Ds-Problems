#include<bits/stdc++.h>
using namespace std;

int helper(int arr[] , int n , int x , bool flag){
    int i = 0 , j = n-1;
    int ans = -1;
    while (i <= j)
    {
        int mid = (i+j)/2;
        if (arr[mid] == x)
        {
            ans = mid;
            if (flag)
            {
                j = mid-1;
            }
            else
            {
                i = mid+1;
            }
            
        }
        else if (arr[mid] < x)
        {
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
    }
    return ans;
}

vector<int> FirstAndLastOccurence(int arr[] , int n , int x){
    int a = helper(arr , n , x , true);
    if (a == -1)
    {
        return {-1};
    }
    int b = helper(arr , n , x , false);
    return {a,b};
}

int valuetoIndex(int arr[] , int n){
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i+1)
        {
            return arr[i];
        }
    }
    return -1;
}

int SearchInRotatedSortedArray(vector<int> v , int key){
    int n = v.size();
    int i = 0 , j = n-1;
    while (i < j)
    {
        int mid = (i+j)/2;
        if (v[mid] > v[j])
        {
            i = mid+1;
        }
        else
        {
            j = mid;
        }
    }
    int rot = i;
    int lo = 0 , hi = n-1;
    while (lo <= hi)
    {
        int mid = (lo+hi)/2;
        int realmid = (mid+rot)%n;
        if(v[realmid] == key){
            return realmid;
        }
        else if (v[realmid] < key)
        {
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
        }
    }
    return -1;
}

int squareRoot(int n){
    int i = 0 , j = n;
    int ans = -1;
    while (i <= j)
    {
        int mid = (i+j)/2;
        if (mid*mid == n)
        {
            return mid;
        }
        else if (mid*mid < n)
        {
            ans = mid;
            i = mid+1;
        }
        else
        {
            j = mid-1;
        }
    }
    return ans;
}

vector<int> MissingAndRepeatingNumber(vector<int> v){
    int n = v.size();
    int sum = 0;
    int squaresum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += v[i];
        sum -= (i+1);
        squaresum += (v[i]*v[i]);
        squaresum -= ((i+1)*(i+1));
    }
    squaresum /= sum;
    int a = (sum+squaresum)/2;
    int b = squaresum - a;
    return {a,b};
}

int MajorityElement(int arr[] , int n){
    int count = 1;
    int ele = 0;
    int mxcount = 0;
    sort(arr , arr+n);
    int a = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] == a)
        {
            count++;
        }
        else
        {
            if (count > mxcount)
            {
                mxcount = count;
                ele = arr[i-1];
            }
            count = 1;
        }
    }
    return ele;
}

int SearchInArray(int arr[] , int n , int x , int k){
    int i = 0;
    while (i < n)
    {
        if (arr[i] == x)
        {
            return i;
        }
        i += max(1 , abs(arr[i]-x)/k);
    }
    return -1;
}

bool FindPairWithGivenDiff(int arr[] , int n , int diff){
    sort(arr , arr+n);
    int i = 0 , j = 1;
    while (i < n && j < n)
    {
        if ((arr[j] - arr[i]) == n && i != j)
        {
            return true;
        }
        else if ((arr[j]-arr[i]) < n || i == j)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    return false;
}

vector<vector<int> > fourSum(vector<int> &arr, int k) {
    sort(arr.begin(), arr.end());
    set<vector<int>>s;
    vector<vector<int>>ans;
    for(int i=0; i<arr.size()-3; i++)
    {       
        for(int j=i+1; j<arr.size()-2; j++)
        {       
            int k1=j+1;
            int k2=arr.size()-1;
            while(k1<k2)
            {
                if((arr[i]+arr[j]+arr[k1]+arr[k2]) < k)
                    k1++;
                else if((arr[i]+arr[j]+arr[k1]+arr[k2]) > k)
                    k2--;
                else if((arr[i]+arr[j]+arr[k1]+arr[k2]) == k)
                {
                    s.insert({arr[i], arr[j], arr[k1],arr[k2]});
                    k1++; k2--;
                }   
            }
        }
    }
   for(auto i:s)
    {
        ans.push_back(i);
    }
    return ans;
}

int MaxSumNoadjacent(int arr[] , int n){
    int a = arr[0];
    int b = 0;
    int temp = 0;
    for(int i=1;i<n;i++){
        temp = (a > b) ? a : b;
        a = b+arr[i];
        b = temp;
    }
    return (a > b) ? a : b;
}

int countTriplets(int arr[] , int n , int sum){
    sort(arr , arr+n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i+1 , k = n-1;
        while (j < k)
        {
            int a = arr[i]+arr[j]+arr[k];
            if (a < sum)
            {
                ans += (k-j);
                j++;
            }
            else
            {
                k--;
            }
        }
    }
    return ans;
}

void merge2SortedArr(int arr1[] , int arr2[] , int n , int m){
    int i = 0 , j = 0 , k = n-1;
    while (i <= k && j < m)
    {
        if (arr1[i] > arr2[j])
        {
            swap(arr1[k] , arr2[j]);
            k--;
        }
        else
        {
            i++;
        }
    }
    sort(arr1 , arr1+n);
    sort(arr2 , arr2+m);
}

int CountSubarrWithSumZero(int arr[] , int n){
    int c = 0;
    unordered_map<int,int> mp;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            c++;
        }
        if (mp.find(arr[i]) != mp.end())
        {
            c += mp[sum];
        }
        mp[sum]++;
    }
    return c;
}

vector<int> ProductExceptItself(int arr[] , int n){
    vector<int> ans(n , 0);
    int flag = 0;
    int pro = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            pro *= arr[i];
        }
        else
        {
            flag++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (flag == 1)
        {
            if (arr[i] != 0)
            {
                ans[i] = pro;
            }
            else
            {
                ans[i] = 0;
            }
        }
        else if (flag == 0)
        {
            ans[i] = pro/arr[i];
        }
        else
        {
            break;
        }
    }
    return ans;
}

//-----Learn About Stable sort-----//

int MinSwapsToSortArray(vector<int> v){
    int n = v.size();
    vector<int> tmp = v;
    sort(v.begin() , v.end());
    unordered_map<int,int> mp;
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        mp[v[i]] = i;
    }
    for (int i = 0; i < n;)
    {
        if (mp[v[i]] != i)
        {
            swap(v[i] , v[mp[v[i]]]);
            c++;
        }
        else
        {
            i++;
        }
    }
    return c;
}

int kthElement(int arr1[], int arr2[], int end1, int end2, int k)
{
    int i = 0 , j = 0;
    while(i < end1 && j<end2 && k >= 0){
        if(k == 1){
            return min(arr1[i] , arr2[j]);
        }
        if(arr1[i] < arr2[j]){
            i++;
        }
        else{
            j++;
        }
        k--;
    }
    while(i < end1 && k >= 0){
        if(k == 1){
            return arr1[i];
        }
        k--;
        i++;
    }
    while(j < end2 && k >= 0){
        if(k == 1){
            return arr2[j];
        }
        k--;
        j++;
    }
    return -1;
}

bool isPossible(int A[] , int n , int m , int mid){
    int pages = 0;
    int s = 1;
    for(int i=0;i<n;i++){
        if(pages+A[i] <= mid){
            pages += A[i];
        }
        else{
            s++;
            if(s > m || A[i] > mid){
                return false;
            }
            pages = A[i];
        }
    }
    return true;
}
    
int BookAllocationProblem(int A[], int N, int M) 
{
    int sum = 0;
    for(int i=0;i<N;i++){
        sum += A[i];
    }
    int s = 0 , e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e){
        if(isPossible(A , N , M , mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int ArthematicNumber(int A, int B, int C){
    if(C==0)
        return A==B;
    int n = ((B-A)/C) + 1;
    int x = A + (n-1)*C;
    if(n<=0)
        return 0;
    else
        return x==B;
}

bool isFact(int mid, int n){
    int ans = 0;
    for(int i = 5; i<=mid; i *= 5){
        ans += mid/i;
    }
    if(ans >= n) return true;
    else return false;
}

int findNum(int n)
{
    int low = 0;
    int high = 1e9;
    int ans  = -1;
    while(low <= high){
        int mid = low + (high - low)/2;        
        if(isFact(mid, n)){
            ans = mid;
            high = mid - 1;
        }
        else 
            low = mid + 1;
    }        
    return ans;
}



int main(){

}