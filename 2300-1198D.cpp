#include <bits/stdc++.h>
using namespace std;
typedef int num;

num n;
string s;
vector<vector<num>> ss, ssps;

num sum(int x1, int x2, int y1, int y2) {
    return ssps[x2][y2] - ssps[x1][y2] - ssps[x2][y1] + ssps[x1][y1];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    ssps.emplace_back(vector<num>(n+1, 0));
    for (int i = 0; i < n; ++i) {
        cin >> s;
        ss.emplace_back(vector<num>());
        ssps.emplace_back(vector<num>(1, 0));
        for (int j = 0; j < n; ++j) {
            char c = s[j];
            if (c == '#') {
                ss.back().emplace_back(1);
            } else {
                ss.back().emplace_back(0);
            }
            ssps.back().emplace_back(ssps[i][j+1] + ssps[i+1][j] - ssps[i][j] + ss.back().back());
        }
    }

    vector<vector<vector<vector<num>>>> dp(n+1,
        vector<vector<vector<num>>>(n+1,
            vector<vector<num>>(n+1,
                vector<num>(n+1, 0)
            )
        )
    );

    for (int x1 = 0; x1 < n; ++x1) {
        for (int x2 = x1+1; x2 <= n; ++x2) {
            for (int y1 = 0; y1 < n; ++y1) {
                for (int y2 = y1+1; y2 <= n; ++y2) {
                    if (sum(x1, x2, y1, y2) != 0) {
                        dp[x1][x2][y1][y2] = max(x2-x1, y2-y1);
                    }
                }
            }
        }
    }

    for (int dx = 1; dx <= n; ++dx) {
        for (int dy = 1; dy <= n; ++dy) {
            for (int x = 0; x + dx <= n; ++x) {
                for (int y = 0; y + dy <= n; ++y) {
                    for (int sx = 1; sx < dx; ++sx) {
                        dp[x][x+dx][y][y+dy] = min(dp[x][x+dx][y][y+dy], dp[x][x+sx][y][y+dy] + dp[x+sx][x+dx][y][y+dy]);
                    }
                    for (int sy = 1; sy < dy; ++sy) {
                        dp[x][x+dx][y][y+dy] = min(dp[x][x+dx][y][y+dy], dp[x][x+dx][y][y+sy] + dp[x][x+dx][y+sy][y+dy]);
                    }
                }
            }
        }
    }

    cout << dp[0][n][0][n];
}