#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
signed main() {
    fastio;
    int t;cin>>t;
    stack<int> stk;
    while(t--) {
        int op;
        cin>>op;
        if(op==1) {
            int n;
            cin>>n;
            stk.push(n);
        }else {
            if(!stk.empty()) {
                cout<<stk.top()<<endl;
                stk.pop();
            }else {
                cout<<"empty!"<<endl;
            }
        }
    }
}