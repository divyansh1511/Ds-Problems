#include<bits/stdc++.h>
using namespace std;

string FractionToDecimal(int numerator , int denominator){
    if (numerator == 0)
    {
        return "0";
    }
    string ans = "";
    ans += (numerator < 0) ^ (denominator < 0) ? "-" : "";
    
    long n = abs(numerator) , d = abs(denominator);

    ans += to_string(n/d);
    n = n%d;
    if (!n)
    {
        return ans;
    }
    
    ans += ".";
    unordered_map<long , int> mp;
    mp[n] = ans.size();
    while (n)
    {
        n *= 10;
        ans += to_string(n/d);
        n = n%d;
        if (mp[n])
        {
            ans.insert(mp[n] , "(");
            ans += ")";
            break;
        }
        mp[n] = ans.size();
    }
    return ans;
}

int main(){

}