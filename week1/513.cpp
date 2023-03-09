#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    vector<int> arr(n+2,0),l(n+2,0),r(n+2,0);
    for(int i=1;i<=n;i++) {
        cin>>arr[i];
    }
    stack<int> s;
    s.push(0);
    for(int i=1;i<=n;i++) {
        while(!s.empty() && arr[i]<=arr[s.top()]) s.pop();
        l[i]=i-s.top();
        s.push(i);
    }
    while(!s.empty()) s.pop();
    s.push(n+1);
    for(int i=n;i>=1;i--) {
        while(!s.empty()&& arr[i]<=arr[s.top()]) s.pop();
        r[i]=s.top()-i-1;
        s.push(i);
    }
    int ans[n+5];
    for(int i=1;i<=n;i++) {
        ans[i-1]=arr[i]*(l[i]+r[i]);
    }
    cout<<*max_element(ans,ans+n)<<'\n';
}