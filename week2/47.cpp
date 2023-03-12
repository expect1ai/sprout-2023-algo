#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define maxn 100005
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    set<int> st;
    cin>>n;
    while(n--) {
        string op;
        int x;
        cin>>op>>x;
        if(op[0]=='i') {
            st.insert(x);
        }else if(op[0]=='d') {
            st.erase(x);
        }else {
            // if(x>*st.end()) {
            //     cout<<*st.end()<<endl;
            //     continue;
            // }
            // }else if(x<*st.begin()) {
            //     cout<<*st.begin()<<endl;
            //     continue;
            // }
            auto a=(st.lower_bound(x));
            auto b=prev(a,1);
            // if(a==st.begin()) {
            //     cout<<*a;
            //     continue;
            // }
            if(abs(*a-x)==abs(x-*b)) {
                if(*a!=*b) cout<<*b<<' '<<*a<<endl;
                else cout<<*b<<endl;
            }else if(abs(*a-x)<abs(x-*b)) {
                cout<<*a<<endl;
            }else if(abs(*a-x)>abs(x-*b)){
                cout<<*b<<endl;
            }
        }
    }
}