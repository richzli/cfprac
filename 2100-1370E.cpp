#include <bits/stdc++.h>
using namespace std;

int n;
string s, t;

int main() {
    cin >> n >> s >> t;

    int mx = 0, mn = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            switch (s[i]) {
                case '0':
                    --cur;
                    mn = min(mn, cur);
                    break;
                case '1':
                    ++cur;
                    mx = max(mx, cur);
                    break;
            }
        }
    }

    if (cur == 0) {
        cout << mx - mn;
    } else {
        cout << -1;
    }
}