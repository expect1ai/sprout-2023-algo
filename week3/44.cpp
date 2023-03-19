#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define fastio ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
struct node {
    node(int a, int b, int d):
        x{a}, y{b},dist{d} {}
    int x,y,dist;
};
signed main() {
    fastio;
    // cout<<"= =”"<<endl;
    int T;
    cin>>T;
    while(T--) {
        int n,m;
        cin>>n>>m;
        int graph[n+2][m+2]={{0}};
        node start(0,0,0);
        for(int i=1;i<=n;i++) {
            string s;
            cin>>s;
            for(int j=1;j<=m;j++) {
                if(s[j-1]=='K') {
                    graph[i][j]=1;
                    start.x=i;
                    start.y=j;
                    start.dist=0;
                }else if(s[j-1]=='.') {
                    graph[i][j]=2;
                }else if(s[j-1]=='@') {
                    graph[i][j]=3;
                }
            }
        }
        queue<node> q;
        q.push(start);
        int ans=0;
        bool pass=0;
        while(!q.empty()) {
            if(graph[q.front().x][q.front().y]) {
                if(graph[q.front().x][q.front().y]==3) {
                    ans=q.front().dist;
                    pass=1;
                    break;
                }
                int magic[5]={0,1,0,-1,0};
                graph[q.front().x][q.front().y]=0;
                for(int i=0;i<4;i++) {
                    q.push(node(q.front().x+magic[i],q.front().y+magic[i+1],q.front().dist+1));
                }
            }
            q.pop();
        }
        if(pass) {
            cout<<ans<<endl;
        }else {
            cout<<"= =\""<<endl;
        }
    }
}