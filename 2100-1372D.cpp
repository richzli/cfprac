#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a;
vector<ll> as, ss;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        as.emplace_back(a);
        if (i > 1) {
            ss.emplace_back(a + ss[i-2]);
        } else {
            ss.emplace_back(a);
        }
    }
    for (int i = 0; i < n; ++i) {
        ss.emplace_back(as[i] + ss[n+i-2]);
    }

    ll mx = 0;
    for (int i = 0; i < n; ++i) {
        mx = max(mx, ss[i+n-1] - ss[i] + as[i]);
    }

    cout << mx;
}