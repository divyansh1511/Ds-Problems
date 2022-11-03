#include<iostream>
using namespace std;
 
bool helper(int n){
    int a = n%10;
    n = n/10;
    int b = n%10;
    if(a == b){
        return false;
    }
    n = n/10;
    int c = n%10;
    if(b == c || a == c){
        return false;
    }
    n = n/10;
    int d = n%10;
    if(d == a || d == b || d == c){
        return false;
    }
    return true;
}
 
int main(){
    int n;
    cin>>n;
    while(!helper(n)){
        n++;
    }
    cout<<n<<endl;
}