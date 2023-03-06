#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int mnm = 1; mnm <= t; mnm++) {
        cout << "Line #" << mnm << endl;
        int n;
        cin >> n;
        short group[1000000] = {0};
        for (int i = 1; i <= n; i++) {
            int k;
            cin >> k;
            for (int j = 0; j < k; j++) {
                int in;
                cin >> in;
                group[in] = i;
            }
        }
        vector<queue<int> > line;
        int loc[1005] = {0};
        int m;
        cin >> m;
        int total = 1;
        int del = 0;
        for (int p = 0; p < m; p++) {
            string c;
            cin >> c;
            if (c[0]=='D') {
                int it;
                cout << line[del].front() << endl;
                it = group[line[del].front()];
                line[del].pop();
                if (line[del].empty()) {
                    loc[it] = 0;
                    del++;
                }
            } else {
                int num;
                cin >> num;
                if (group[num] == 0) {
                    queue<int> tmp;
                    tmp.push(num);
                    line.push_back(tmp);
                    total++;
                } else {
                    if (loc[group[num]] == 0) {
                        queue<int> tmp;
                        tmp.push(num);
                        line.push_back(tmp);
                        loc[group[num]] = total;
                        total++;
                    } else {
                        line[loc[group[num]] - 1].push(num);
                    }
                }
            }
        }
    }
}