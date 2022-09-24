#include<bits/stdc++.h>
using namespace std;

int PairWithGivenDifference(vector<int> v , int k){
    sort(v.begin() , v.end());
    int n = v.size();
    int i = 0 , j = 1;
    while (i < n && j < n)
    {
        if ((v[j] - v[i]) == k && i != j)
        {
            return 1;
        }
        else if ((v[j] - v[i]) > k)
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return 0;
}

int DiffPossible(vector<int> v , int k){
    int n = v.size();
    if (n < 2)
    {
        return 0;
    }
    int i = 0 , j = 1;
    while (i < n && j < n)
    {
        int diff = v[j] - v[i];
        if (diff == k)
        {
            return 1;
        }
        else if (diff > k)
        {
            i++;
            if (i == j)
            {
                j++;
            }
        }
        else
        {
            j++;
        }
    }
    return 0;
}

int MaximumOnesAfterModification(vector<int> A , int K){
    int i = 0, j;
    for (j = 0; j < A.size(); ++j) {
        if (A[j] == 0) K--;
        if (K < 0 && A[i++] == 0) K++;
    }
    return j - i;
}

int CountingSubarr(vector<int> A , int B){
    int n = A.size();
    int ans = 0;
    int i = 0 , j = 0;
    int sum = 0;
    while(i<n){
        sum += A[i];
        while(sum >= B){
            sum -= A[j];
            j++;
        }
        ans += (i-j+1);
        i++;
    }
    return ans;
}

int maxArea(vector<int> &A) {
    int n = A.size();
    int i = 0 , j = n-1;
    int ans = 0;
    while(i<j){
        int mini = min(A[i] , A[j]);
        int area = mini*(j-i);
        ans = max(ans , area);
        if(mini == A[i]){
            i++;
        }
        else{
            j--;
        }
    }
    return ans;
}

vector<int> intersectionOfArray(const vector<int> &A, const vector<int> &B) {
    vector<int> ans;
    int i = 0 , j = 0;
    int n = A.size() , m = B.size();
    while(i<n && j<m){
        if(A[i] == B[j]){
            ans.push_back(A[i]);
            i++;
            j++;
        }
        else if(A[i] > B[j]){
            j++;
        }
        else{
            i++;
        }
    }
    return ans;
}

int removeDuplicates(vector<int> &A) {
    int n = A.size();
    vector<int> v;
    v.push_back(A[0]);
    for(int i=1;i<n;i++){
        if(v[v.size() - 1] != A[i]){
            v.push_back(A[i]);
        }
    }
    A = v;
    return A.size();
}

void sortColors(vector<int> &A) {
    int count0 = 0 , count1 = 0 , count2 = 0;
    int n = A.size();
    for(int i=0;i<n;i++){
        if(A[i] == 0){
            count0++;
        }
        else if(A[i] == 1){
            count1++;
        }
        else{
            count2++;
        }
    }
    for(int i=0;i<count0;i++){
        A[i] = 0;
    }
    for(int i=count0;i<(count0+count1);i++){
        A[i] = 1;
    }
    for(int i=(count0+count1);i<n;i++){
        A[i] = 2;
    }
}

int main(){

}