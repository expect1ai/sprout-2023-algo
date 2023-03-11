#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define f first
#define s second
#define pii pair<int,int>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,m,q;
        cin>>n>>m;
        vector<pii> v(n+1,{1,-1});
        for(int i=0;i<m;i++) {
            int a,b,now;
            cin>>a>>b;
            v[b].s=a;
            now=a;
            while(v[now].s!=-1) {
                v[now].f+=v[b].f;
                now=v[now].s;
            }
            v[now].f+=v[b].f;
        }
        cin>>q;
        while(q--) {
            int x;
            cin>>x;
            cout<<v[x].f<<endl;
        }
    }
    return 0;
}