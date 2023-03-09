#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    queue<int> q[n+1];
    while(m--) {
        string op;
        cin>>op;
        if(op[0]=='A') {
            int i,id;
            cin>>i>>id;
            q[i].push(id);
        }else if(op[0]=='L') {
            int i;
            cin>>i;
            if(q[i].empty()) {
                cout<<"queue "<<i<<" is empty!\n";
            }else {
                q[i].pop();
            }
        }else {
            int i,j;
            cin>>i>>j;
            while(!q[i].empty()) {
                int tmp=q[i].front();
                q[i].pop();
                q[j].push(tmp);
            }
        }
    }
    for(int i=1;i<=n;i++) {
        cout<<"queue "<<i<<": ";
        if(q[i].empty()) {
            cout<<"empty"<<endl;
        }else {
            while(q[i].size()!=1) {
                cout<<q[i].front()<<' ';
                q[i].pop();
            }
            cout<<q[i].front()<<endl;
        }
    }
}