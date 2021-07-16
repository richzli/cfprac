#include <bits/stdc++.h>
using namespace std;
typedef long long num;
typedef pair<num, num> pii;

num t, c, d, x, ans;
vector<num> sieve, pfnum;

void fill_sieve() {
    sieve = vector<num>((int)(2e7+5));
    pfnum = vector<num>((int)(2e7+5));

    for (num i = 2; i < sieve.size(); ++i) {    
        if (sieve[i] == 0) {
            sieve[i] = i;
            num j = 1;
            for ( ; j < i && i*j < sieve.size(); ++j) {
                ++pfnum[i*j];
            }
            for ( ; i*j < sieve.size(); ++j) {
                if (sieve[i*j] == 0) {
                    sieve[i*j] = i;
                }
                ++pfnum[i*j];
            }
        }
    }
}

vector<pii> factor(num x) {
    vector<pii> ret;
    num cur = sieve[x];
    while (cur != 0) {
        if (ret.empty() || ret.back().first != cur) {
            ret.emplace_back(pii(sieve[x], 1));
        } else {
            ++ret.back().second;
        }
        x /= sieve[x];
        cur = sieve[x];
    }
    return ret;
}

num fpow(num base, num exponent) {
    num ret = 1, cur = base;
    while (exponent > 0) {
        if (exponent % 2) {
            ret *= cur;
        }
        cur *= cur;
        exponent >>= 1;
    }

    return ret;
}

void solve(num val, num z, vector<pii> factors) {
    if (factors.empty()) {
        // c * y * val - d * val = z * val = x
        // c * y = z + d
        if ((z+d) % c == 0) {
            num y = (z+d)/c;
            ans += 1LL << pfnum[y];
        }
    } else {
        pii cur = factors.back();
        factors.pop_back();
        for (int i = 0; i <= cur.second; ++i) {
            solve(val * fpow(cur.first, i), z * fpow(cur.first, cur.second - i), factors);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
 
    fill_sieve();

    cin >> t;
    for (;t;--t) {
        cin >> c >> d >> x;

        ans = 0;
        solve(1, 1, factor(x));

        cout << ans << "\n";
    }
}