#include<iostream>
#include<string>
using namespace std;

int main(){
    int n , s;
    cin>>n>>s;
    string str;
    cin>>str;
    for(int i=0;i<s;i++){
        int idx = n-1;
        while(idx >= 0){
            idx--;
            if(str[idx] == 'B' && str[idx+1] == 'G'){
                str[idx] = 'G';
                str[idx+1] = 'B';
                idx--;
            }
        }
    }
    cout<<str<<endl;
}