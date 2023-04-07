#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t,n;
    cin >> t;
    while(t--) {
        cin >> n;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i=0; i<n; i++) {
            int x;
            cin >> x;
            pq.push(x);
        }
        int ans = 0;
        while(pq.size()!=1) {
            int a, b;
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            pq.push(a+b);
            ans += a+b;        
        }
        cout << ans << endl;
    }
}