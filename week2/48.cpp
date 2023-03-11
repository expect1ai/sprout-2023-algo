#pragma GCC optimize("O3,unroll-loops")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
struct node {
    int left=-1,right=-1,data;
};
vector<node> tree;
void add(int n,int from) {
    node newnode;
    newnode.data=n;
    if(tree.empty()) {
        tree.push_back(newnode);
    }else {
        if(n<tree[from].data) {
            if(tree[from].left==-1) {
                tree.push_back(newnode);
                tree[from].left=(int)tree.size()-1;
            }else {
                add(n,tree[from].left);
            }
        }else {
            if(tree[from].right==-1) {
                tree.push_back(newnode);
                tree[from].right=(int)tree.size()-1;
            }else {
                add(n,tree[from].right);
            }
        }
    }
}
void dfs(int idx) {
    if(tree[idx].left!=-1) {
        dfs(tree[idx].left);
    }
    if(tree[idx].right!=-1) {
        dfs(tree[idx].right);
    }
    cout<<tree[idx].data<<endl;
}
signed main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n;
    cin>>n;
    while(n--) {
        int x;
        cin>>x;
        add(x,0);
    }
    dfs(0);
}
