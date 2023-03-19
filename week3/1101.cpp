#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#include <stdio.h>
#include <vector>
// #define int long long
// #define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
vector<int> adj[100000];
bool vis[100000],color[100000];
bool dfs(int idx, int type) {
    vis[idx]=1;
    color[idx]=type;
    for(auto k:adj[idx]) {
        if(vis[k]) {
            if(color[k]==type) return 0;
            else continue;
        }
        if(dfs(k,!type)==0) return 0;
    }
    return 1;
}
signed main() {
    // fastio;
    int t;
    scanf("%d",&t);
    while(t--) {
        int n, m;
        scanf("%d",&n);
        scanf("%d",&m);
        for(int i=0;i<n;i++) {
            adj[i].clear();
            vis[i]=0;
            color[i]=0;
        }
        for(int i=0 ; i<m ; i++) {
            int a, b;
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool ok=1;
        for(int i=0 ; i<n ; i++) {
            if(vis[i]==0) {
                if(dfs(i,0)==0) {
                    ok=0;
                    break;
                }
            }
        }
        if(ok) puts("NORMAL.");
        else puts("RAINBOW.");
    }
}