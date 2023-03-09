#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define int long long
#define endl '\n'
using namespace std;
int n,t;
signed main(){
    fastio;
    cin>>t;
    while(t--){
        cin>>n;
        stack<int> s;
        
        int ans = 0,cnt[1000003];
        memset(cnt, 0, sizeof(cnt));
        while(n--){
            int k,top = s.size();cin>>k;
            
            while(!s.empty() && s.top()<k){
                cnt[top--] = 0;
                s.pop();
                ans++;
            }
            if(s.empty())s.push(k);
            else{
                if(s.top()==k && top>1){
                    cnt[top+1]+=cnt[top]+1;
                    ans+=cnt[top+1];
                }
                s.push(k);ans++;
            }
        }
        cout<<ans<<endl;
    }
}