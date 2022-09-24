#include<bits/stdc++.h>
using namespace std;

int Numberof1Bits(int n){
    int count = 0;
    while (n)
    {
        if (n & 1)
        {
            count++;
        }
        n >>= 1;
    }
    return count;
}

int TrailingZeros(int n){
    int count = 0;
    while (n)
    {
        if (n & 1)
        {
            break;
        }
        count++;
        n >>= 1;
    }
    return count;
}

int reverseBits(int n){
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        ans <<= 1;
        ans |= (n&i);
        n >>= 1;
    }
    return ans;
}

int divide(int A, int B) {
    if(A==INT_MIN&&B==-1)
        return INT_MAX;
    long long int a=A,b=B;
    int sign = ((A < 0) ^ (B < 0)) ? -1 : 1;
    a=abs(a);b=abs(b);
    int ans=0;
    while(a>=b)
    { 
        a=a-b;
        ans++;
    }
    return ans*sign;
}

int MinXorValue(vector<int> v){
    int n = v.size();
    int ans = INT_MAX;
    sort(v.begin() , v.end());
    for (int i = 0; i < n-1; i++)
    {
        ans = min(ans , v[i] ^ v[i+1]);
    }
    return ans;
}

int CountTotalSetBits(int A) {
    if (A==0) return 0;
    int t=A+1;
    long long count =0;
    for ( int x=2;x<=2*(t-1);x=x*2)
    {
        count+=(t/x)*x/2;
         
        if ((t%x)>x/2)
        {
            count+=(t%x)-(x/2);
        }
    }
    return count%1000000007 ;
}

int SingleNumber(int arr[] , int n){
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= arr[i];
    }
    return ans;
}

int SingleNumberII(const vector<int> &A) {
    int ones = 0;
    int twos = 0;
    for(auto ele : A){
        ones = (ones^ele) & (~twos);
        twos = (twos^ele) & (~ones); 
    }
    return ones;
}


int main(){

}