#include<iostream>
#include<vector>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    vector<vector<int>> arr(n , vector<int>(3 , 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin>>arr[i][j];
        }
    }
    bool flag = true;
    for(int j=0;j<3;j++){
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += arr[i][j];
        }
        if(sum != 0){
            flag = false;
            break;
        }
    }
    if(flag){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}