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


// #include<bits/stdc++.h>
// using namespace std;

// void dfs(int node, int dest, vector<int> adj[], vector<int> &vis, int &count)
// {
//     if (node == dest){
//         count += 1;
//     }
//     vis[node] = 1;
//     for (auto it : adj[node])
//     {
//         if (!vis[it]){
//             dfs(it, dest, adj, vis, count);
//         }
//     }
//     vis[node] = 0;
// }

// int countPaths(int V, vector<int> adj[], int source, int destination)
// {
//     vector<int> vis(V, 0);
//     int count = 0;
//     dfs(source, destination, adj, vis, count);
//     return count;
// }

// int main()
// {
//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, e;
//         cin >> n >> e;
//         vector<int> mat[n];
//         for (int i = 0; i < e; i++)
//         {
//             int u,v;
//             cin>>u>>v;
//             mat[u].push_back(v);
//         }
//         int a, b, c;
//         cin >> a >> b >> c;
//         int ans = countPaths(n , mat , a , b);
//         // cout<<ans<<endl;
//         if (ans == c)
//         {
//             cout<<"YES"<<endl;
//         }
//         else
//         {
//             cout<<"NO"<<endl;
//         }
//     }
// }