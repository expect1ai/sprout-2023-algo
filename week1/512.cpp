#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    stack<int> s;
    bool ok=1;
    while(n--) {
        int a;
        cin>>a;
        if(a>0) {
            s.push(a);
        }else {
            if(s.empty()) {
                ok=0;
                break;
            }else {
                if(s.top()+a==0) {
                    s.pop();
                }else {
                    ok=0;
                    break;
                }
            }
        }
    }
    if(ok&&s.empty()) cout<<"weed\n";
    else cout<<"lose light light\n";
}