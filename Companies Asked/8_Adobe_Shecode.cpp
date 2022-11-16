#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int arr1[6];
        int arr2[6];
        for (int i = 0; i < 6; i++)
        {
            cin>>arr1[i];
        }
        for (int i = 0; i < 6; i++)
        {
            cin>>arr2[i];
        }
        // double bobwins = 0.0;
        // double total = 0.0;
        // for (int i = 0; i < 6; i++)
        // {
        //     if (arr1[i] == arr2[i])
        //     {
        //         continue;
        //     }
        //     if (arr1[i] > arr2[i])
        //     {
        //         bobwins++;
        //     }
        //     total++;
        // }
        // // cout<<bobwins << " " << total <<endl;
        // double ans = bobwins/total;
        // cout << fixed << setprecision(6) << ans << endl;
        double a = 0.0 , tot = 0.0;
        for (int i = 0; i < 6; i++)
        {
            for (int j = 0; j < 6; j++)
            {
                if (arr1[i] == arr2[j])
                {
                    continue;
                }
                if (arr1[i] > arr2[j])
                {
                    a++;
                }
                tot++;
            }
        }
        double ans = a/tot;
        cout<< fixed << setprecision(6) << ans <<endl;
    }
}
