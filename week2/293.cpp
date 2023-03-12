#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define maxn 100005
using namespace std;
// int t,n;
// vector<int> adj[maxn];
// int subtree_size[maxn];
// int dfs(int cur,int pre=-1) {
//     int &res=subtree_size[cur];
//     res=1;
//     for(auto i:adj[cur]) {
//         if(i!=pre) {
//             res+=dfs(i,cur);
//         }
//     }
//     return res;
// }
// int find(int cur,int pre=-1) {
//     for(auto i:adj[cur]) {
//         if(i!=pre && subtree_size[i]*2>n) {
//             return find(i,cur);
//         }
//     }
//     return cur;
// }
int t,n;
vector<int> adj[maxn];
vector<int> loss(maxn);
int dfs(int cur,int pre) {
    int tot=1,ret=0;
    for(auto i:adj[cur]) {
        if(i==pre) continue;
        ret=dfs(i,cur);
        tot+=ret;
        loss[cur]=max(loss[cur],ret);
    }
    loss[cur]=max(loss[cur],n-tot);
    return tot;
}
signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    // int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=0;i<n;i++) {
            adj[i].clear();
            loss[i]=0;
        }
        for(int i=0;i<n-1;i++) {
            int a,b;
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        dfs(0,-1);
        int mn=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++) {
            if(loss[i]<mn) {
                mn=loss[i];
                ans=i;
            }
        }
        cout<<ans<<endl;
        // cout<<find(0)<<endl;
    }
}