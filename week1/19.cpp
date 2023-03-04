#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
signed main() {
    fastio;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> stk;
        queue<int> q;
        for(int i=0;i<n;i++) {
            int x;
            cin>>x;
            q.push(x);
        }
        for(int i=1;i<=n;i++) {
            stk.push_back(i);
            while(!stk.empty() && !q.empty() && q.front()==stk.back()) {
                stk.pop_back();
                q.pop();
            }
        }
        if(stk.empty() && q.empty()) puts("Yes");
        else puts("No");
    }
}