#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = ((b)-1); i >= (a); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vi lis(vi a) {
    vi lens(sz(a)+1, 301);
    lens[0] = 0;
    vi ans(301);
    rep(i,0,sz(a)) {
        int x = upper_bound(all(lens), a[i]) - begin(lens);
        lens[x] = a[i];
        ans[a[i]] = max(ans[a[i]], x);
    }
    return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
    int n, t; cin >> n >> t;
    vi a(n);
    rep(i,0,n) {
        cin >> a[i];
    }

    if (t <= 2 * n) {
        vi b(n * t);
        rep(i,0,t) {
            rep(j,0,n) {
                b[n * i + j] = a[j];
            }
        }
        vi x = lis(b);
        cout << *max_element(all(x));
    } else {
        vi cnt(301);
        vi b(n * n);
        rep(i,0,n) {
            rep(j,0,n) {
                b[n * i + j] = a[j];
            }
            cnt[a[i]]++;
        }
        vi x = lis(b);
        rep(i,0,sz(b)) {
            b[i] = 301 - b[i];
        }
        reverse(all(b));
        vi y = lis(b);
        y.pb(0);
        reverse(all(y));
        int ans = 0;
        rep(i,1,301) {
            ans = max(ans, x[i] + y[i] + (t - 2 * n) * cnt[i]);
        }
        cout << ans;
    }

    /*
    vector<vi> g(301, vi(301));
    rep(i,0,n) {
        per(j,0,a[i]+1) {
            per(k,j,a[i]+1) {
                g[j][a[i]] = max(g[j][a[i]], g[j][k] + 1);
            }
        }
    }
    */

}