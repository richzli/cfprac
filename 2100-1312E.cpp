#include <bits/stdc++.h>
using namespace std;
typedef int num;

num n, a;
vector<num> as, dp2;
vector<vector<num>> dp;

num get(int l, int r) {
    if (dp[l][r] != 0) {
        return dp[l][r];
    }

    for (int k = l+1; k < r; ++k) {
        if ((get(l, k) == get(k, r)) && (get(l, k) != -1) && (get(k, r) != -1)) {
            dp[l][r] = get(l, k) + 1;
        }
    }

    if (dp[l][r] == 0) {
        dp[l][r] = -1;
    }

    return dp[l][r];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    dp = vector<vector<num>>(n+5, vector<num>(n+5));
    dp2.emplace_back(0);
    for (int i = 0; i < n; ++i) {
        cin >> a;
        as.emplace_back(a);
        dp[i][i+1] = a;
        dp2.emplace_back(i+1);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j <= n; ++j) {
            if (get(i, j) != -1) {
                dp2[j] = min(dp2[j], dp2[i]+1);
            }
        }
    }

    cout << dp2[n];
}