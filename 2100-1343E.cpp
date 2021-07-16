#include <bits/stdc++.h>
using namespace std;
typedef long long num;
typedef pair<num, num> pii;

num t, n, m, a, b, c, p, u, v, mn;
vector<num> ps, psps, adist, bdist, cdist;
queue<pii> q;
vector<vector<num>> g;

void bfs(num o, vector<num>& dist) {
    q = queue<pii>();
    q.push(pii(o, 0));

    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        num node = cur.first, d = cur.second;
        if (dist[node] != -1) {
            continue;
        }
        dist[node] = d;
        
        for (num nxt : g[node]) {
            q.push(pii(nxt, d+1));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (;t;--t) {
        cin >> n >> m >> a >> b >> c;
        ps.clear();
        psps.clear();
        g.clear(); g = vector<vector<num>>(n+5);

        for (int i = 0; i < m; ++i) {
            cin >> p;
            ps.emplace_back(p);
        }
        sort(ps.begin(), ps.end());
        psps.emplace_back(0);
        for (int i = 0; i < m; ++i) {
            psps.emplace_back(psps.back() + ps[i]);
        }

        for (int i = 0; i < m; ++i) {
            cin >> u >> v;
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }

        cdist.clear(); cdist = vector<num>(n+5, -1); bfs(c, cdist);
        adist.clear(); adist = vector<num>(n+5, -1); bfs(a, adist);

        mn = ps.back() * m * 2;
        bdist.clear(); bdist = vector<num>(n+5, -1);
        q = queue<pii>();
        q.push(pii(b, 0));
        while (!q.empty()) {
            pii cur = q.front(); q.pop();
            num node = cur.first, d = cur.second;
            if (bdist[node] != -1) {
                continue;
            }
            bdist[node] = d;
            
            num tdist = adist[node] + cdist[node];
            if (d+tdist < psps.size()) {
                mn = min(mn, psps[d] + psps[d+tdist]);
            }

            for (num nxt : g[node]) {
                q.push(pii(nxt, d+1));
            }
        }

        cout << mn << "\n";
    }
}