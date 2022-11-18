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
	
    ll n, a, cf, cm, m; cin >> n >> a >> cf >> cm >> m;
    vector<pair<ll, int>> skills(n);
    rep(i,0,n) {
        cin >> skills[i].first;
        skills[i].second = i;
    }
    sort(all(skills));

    vector<ll> perfect(n+1);
    rep(i,0,n) {
        perfect[i+1] = perfect[i] + a - skills[n-1-i].first;
    }

    int r = upper_bound(all(perfect), m) - perfect.begin() - 1;
    ll leftover = m - perfect[r];
    ll ans = -1, ind = -1, indl = -1, curl = -1;
    ll sum = 0, l = 0;
    do {
        while (l + 1 < n - r) {
            if (sum + (l + 1) * (skills[l + 1].first - skills[l].first) <= leftover) {
                sum += (l + 1) * (skills[l + 1].first - skills[l].first);
                l++;
            } else {
                break;
            }
        }

        ll cur = min(a, (leftover - sum) / (l + 1) + skills[l].first);
        if (l >= n - r) {
            cur = a;
        }
        if (cur * cm + r * cf > ans) {
            ans = cur * cm + r * cf;
            ind = r;
            indl = l;
            curl = cur;
        }

        --r;
        leftover = m - perfect[r];
    } while (r >= 0);

    cout << ans << '\n';

    rep(i,0,n) {
        if (i <= indl) {
            skills[i].first = curl;
        }
        if (i >= n - ind) {
            skills[i].first = a;
        }
    }
    sort(all(skills), [&](pair<ll, int> a, pair<ll, int> b){ return a.second < b.second; });
    rep(i,0,n) {
        cout << skills[i].first << ' ';
    }
}