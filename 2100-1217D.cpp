#include <bits/stdc++.h>
using namespace std;
typedef int num;
typedef pair<num, num> pii;

num n, m, u, v, mx;
vector<num> vst, clr;
vector<vector<pii>> g;

void dfs(num x) {
    if (vst[x] == 0) {
        vst[x] = 1;
        for (auto c : g[x]) {
            if (clr[c.second] == 0) {
                if (vst[c.first] == 1) {
                    clr[c.second] = 2;
                    mx = 2;
                } else {
                    clr[c.second] = 1;
                    dfs(c.first);
                } 
            }
        }
        vst[x] = 2;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vst = vector<num>(n+5); clr = vector<num>(m);
    g = vector<vector<pii>>(n+5);
    mx = 1;
    for (int i = 0; i < m; ++i) {
        cin >> u >> v;
        g[u].emplace_back(pii(v, i));
    }

    for (int i = 1; i <= n; ++i) {
        if (vst[i] == 0) {
            dfs(i);
        }
    }

    cout << mx << "\n";
    for (int i = 0; i < m; ++i) {
        cout << clr[i] << " ";
    }
}