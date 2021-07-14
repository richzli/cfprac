#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a;
vector<ll> as;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        as.emplace_back(a);
    }

    if (n == 1) {
        cout << as[0];
    } else if (n == 2) {
        cout << (as[0] | as[1]);
    } else {
        ll mx = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i+1; j < n; ++j) {
                for (int k = j+1; k < n; ++k) {
                    mx = max(mx, as[i] | as[j] | as[k]);
                }
            }
        }
        cout << mx;
    }
}