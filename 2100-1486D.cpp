#include <bits/stdc++.h>
using namespace std;
typedef int num;

num n, k, a;
vector<num> as, ps;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        as.emplace_back(a);
    }

    num l = 1, r = (num) 2e5;
    while (l <= r) {
        bool y = false;
        num m = (l + r) / 2;

        ps.clear();
        for (int i = 0; i < k; ++i) {
            if (as[i] < m) {
                ps.emplace_back(ps.empty() ? -1 : ps.back() - 1);
            } else {
                ps.emplace_back(ps.empty() ? 1 : ps.back() + 1);
            }
        }

        num mn = 0;
        if (ps.back() - mn > 0) {
            y = true;
        }
        for (int i = k; i < n; ++i) {
            if (as[i] < m) {
                ps.emplace_back(ps.empty() ? -1 : ps.back() - 1);
            } else {
                ps.emplace_back(ps.empty() ? 1 : ps.back() + 1);
            }
            mn = min(mn, ps[i-k]);
            if (ps.back() - mn > 0) {
                y = true;
            }
        }

        if (y) {
            l = m+1;
        } else {
            r = m-1;
        }
    }

    cout << r;
}