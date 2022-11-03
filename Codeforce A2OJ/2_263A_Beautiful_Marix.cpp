#include<iostream>
using namespace std;
 
int main(){
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            int a;
            cin>>a;
            if(a){
                cout<<abs(i-3) + abs(j-3)<<endl;
                return 0;
            }
        }
    }
}
