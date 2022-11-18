#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
    int n; cin >> n;

    vector<double> p(n);
    rep(i,0,n) cin >> p[i];

    vector<vi> g(n);
    rep(i,1,n) {
        int a, b;
        cin >> a >> b;
        g[a].pb(b);
        g[b].pb(a);
    }

    // arbitrarily root at 0
    vi parent(n), visited(n);
    function<void(int, int)> dfs = [&](int x, int w) {
        if (visited[x]) return;
        visited[x] = 1;
        parent[x] = w;
        for (int y : g[x]) {
            dfs(y, x);
        }
    };
    dfs(0, -1);

    // store sums of children for easy processing
    vector<double> c(n);
    rep(i,1,n) {
        c[parent[i]] += 1 - p[i];
    }

    // calculate the initial answer
    double ans = 1 - p[0];
    rep(i,0,n) {
        ans += p[i] * c[i];
    }

    // update for each query
    int q; cin >> q;
    rep(i,0,q) {
        int v; double w; cin >> v >> w;

        if (v == 0) {
            ans += p[0] - w;
            ans += (w - p[0]) * c[0];
        } else {
            ans += (w - p[v]) * c[v];
            ans += p[parent[v]] * ((1 - w) - (1 - p[v]));
            c[parent[v]] += (1 - w) - (1 - p[v]);
        }
        p[v] = w;

        cout << setprecision(8) << fixed << ans << "\n";
    }
}