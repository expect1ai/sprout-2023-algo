#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
using namespace std;
int a, b, c, d, m, s, t;
int f(int time) {
    int res=0;
    for(int i=0;i<=time;i++) {
        int totq = m+d*i;
        int forwardt = min(totq/c, time-i);
        res = max(res, a*(time-i-forwardt)+b*forwardt);
    }
    return res;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b >> c >> d >> m >> s >> t;
    int maxdis = f(t);
    if (s >= maxdis) {
        puts("No");
        cout << maxdis << '\n';
    }else {
        int r=t+1, l=0;
        while(r-l>1) {
            int mid = (l+r)/2;
            if(f(mid)>=s) {
                r=mid;
            }else {
                l=mid;
            }
        }
        puts("Yes");
        cout << r << '\n';
    }
}