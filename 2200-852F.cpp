#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll modpow(ll x, ll p, ll mod) {
    ll ans = 1, c = x;
    while (p > 0) {
        if (p & 1) {
            ans *= c;
            ans %= mod;
        }
        c *= c;
        c %= mod;
        p >>= 1;
    }
    return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
    ll n, m, a, q;
    cin >> n >> m >> a >> q;

    // calculate the order of a mod q, < 10^6
    ll o = 1;
    for (ll x = a; x != 1; (x *= a) %= q, ++o);

    // calculate modular inverses mod o
    ll* inv = new ll[o] - 1; inv[1] = 1;
    rep(i,2,o) inv[i] = o - (o / i) * inv[o % i] % o;

    vector<ll> ans(n);
    ll cur = 1, p = 1;
    int i = 1;
    ans[n-1] = a;
    for (; i <= min(n-1, m); ++i) {
        cur *= (m-i+1);
        cur %= o;
        cur *= inv[i];
        cur %= o;
        p += cur;
        p %= o;

        ans[n-1-i] = modpow(a, p, q);
    }

    rep(j,i,n) {
        ans[n-1-j] = ans[n-i];
    }

    rep(j,0,n) {
        cout << ans[j] << ' ';
    }
}