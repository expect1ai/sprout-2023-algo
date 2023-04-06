#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m;
vector<int> v(100005);
bool check(int x) {
    int sum = 0,ans = 1;
    for(int i=0;i<n;i++){
        if(v[i]>x)return 0;
        sum += v[i];
        if(sum+v[i+1] > x){
            sum = 0;
            ans++;
        }
    }
    if(ans>m)return 0;
    else return 1;
}
signed main() {
    cin>>t;
    while(t--) {
        cin>>n>>m;
        for(int i=0;i<n;i++) cin>>v[i];
        v[n+1]=-INT_MAX;
        int r=1000000001,l=0;
        while(r-l>1) {
            int mid=(l+r)/2;
            if(check(mid)) r=mid;
            else l=mid;
        }
        if(r==1000000001) cout<<1000000000<<'\n';
        else cout<<r<<'\n';
    }
}