#include<iostream>
#include<vector>
using namespace std;

int main(){
    int a = 3;
    vector<vector<int>> v(a , vector<int>(a , 0));
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cin>>v[i][j];
            if(i > 0){
                v[i-1][j] += v[i][j];
            }
            if(j > 0){
                v[i][j-1] += v[i][j];
            }
            if(i < a-1){
                v[i+1][j] += v[i][j];
            }
            if(j < a-1){
                v[i][j+1] += v[i][j];
            }
        }
    }
    
    for(int i=0;i<a;i++){
        for(int j=0;j<a;j++){
            cout<<(1+v[i][j])%2;
        }
        cout<<endl;
    }
}