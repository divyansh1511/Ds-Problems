#include<iostream>
#include<string>
using namespace std;

int main(){
    string s;
    getline(cin , s);
    int i=0;
    int n = s.length();
    string ans = "";
    while (i < n)
    {
        if (s[i] == '.')
        {
            ans += "0";
        }
        else if (s[i] == '-' && s[i+1] == '.')
        {
            ans += "1";
            i++;
        }
        else
        {
            ans += "2";
            i++;
        }
        i++;
    }
    cout<<ans<<endl;
}