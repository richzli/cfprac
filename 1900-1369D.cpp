#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD ((int)(1e9 + 7))

ll t, n;
vector<vector<ll>> dp;

ll solve(ll x, ll y) {
    if (dp[x][y] == -1) {
        if (y == 1) {
            dp[x][y] = max(
                2 * solve(x-2, 1) + solve(x-1, 1),
                4 + 2 * solve(x-2, 0) + solve(x-1, 0)
            ) % MOD;
        } else {
            dp[x][y] = (2 * solve(x-2, 1) + solve(x-1, 1)) % MOD;
        }
    }
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp = vector<vector<ll>>((int)(2e6+5), vector<ll>(2, -1));
    dp[1][0] = dp[1][1] = dp[2][0] = dp[2][1] = dp[3][0] = 0;
    dp[3][1] = 4;

    for (int i = 4; i <= (int)(2e6); ++i) {
        solve(i, 0);
        solve(i, 1);
    }

    cin >> t;
    for (;t;--t) {
        cin >> n;

        cout << solve(n, 1) << "\n";
    }
}