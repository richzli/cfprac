#include <bits/stdc++.h>
using namespace std;
typedef long long num;

num n, p, kay, a, s;
vector<num> odp, ndp;
vector<vector<num>> as;

num bitcount(num k) {
    num c = 0;
    while (k > 0) {
        c += k & 1;
        k >>= 1;
    }
    return c;
}

int main() {
    cin >> n >> p >> kay;
    num mx = (1<<p)-1;
    odp = vector<num>(mx+13, -1);
    odp[0] = 0;

    for (int i = 0; i < n; ++i) {
        cin >> a;
        as.emplace_back(vector<num>(1, a));
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < p; ++j) {
            cin >> s;
            as[i].emplace_back(s);
        }
    }
    sort(as.begin(), as.end(), greater<vector<num>>());
    for (int i = 0; i < n; ++i) {
        ndp = odp;
        for (int k = 0; k <= mx; ++k) {
            if (odp[k] != -1 && (i-bitcount(k)) < kay) {
                ndp[k] = max(ndp[k], odp[k] + as[i][0]);
            }
        }
        for (int j = 0; j < p; ++j) {
            for (int k = 0; k <= mx; ++k) {
                if (odp[k] != -1 && (k & (1 << j)) == 0) {
                    ndp[k | (1 << j)] = max(ndp[k | (1 << j)], odp[k] + as[i][j+1]);
                }
            }
        }
        odp = ndp;
    }

    cout << ndp[mx];
}