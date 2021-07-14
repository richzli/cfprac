#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, a;
ll ans;
vector<int> as;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (;t;--t) {
        cin >> n;
        ans = 0;
        as.clear();
        map<int, vector<int>> diff;
        for (int i = 1; i <= n; ++i) {
            cin >> a;
            as.emplace_back(a);
            if (diff.find(a) == diff.end()) {
                diff[a] = vector<int>(i, 0);
            }

            for (auto& e : diff) {
                if (e.first == a) {
                    e.second.emplace_back(e.second.back()+1);
                } else {
                    e.second.emplace_back(e.second.back());
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            ll rs = 0;
            for (int j = i+1; j < n; ++j) {
                if (as[i] == as[j]) {
                    ans += rs;
                }
                rs += diff[as[j]][i];
            }
        }

        cout << ans << "\n";
    }
}