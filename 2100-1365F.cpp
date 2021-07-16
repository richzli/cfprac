#include <bits/stdc++.h>
using namespace std;
typedef int num;
typedef pair<num, num> pii;

num t, n, a, b;
vector<num> as, bs;
multiset<pii> aas, bbs;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> t;

    for (;t;--t) {
        cin >> n;
        as.clear();
        bs.clear();
        aas.clear();
        bbs.clear();
        for (int i = 0; i < n; ++i) {
            cin >> a;
            as.emplace_back(a);
        }
        for (int i = 0; i < n; ++i) {
            cin >> b;
            bs.emplace_back(b);
        }

        for (int i = 0; i < n/2; ++i) {
            aas.emplace(pii(min(as[i], as[n-1-i]), max(as[i], as[n-1-i])));
            bbs.emplace(pii(min(bs[i], bs[n-1-i]), max(bs[i], bs[n-1-i])));
        }

        if (n % 2) {
            if (as[n/2] == bs[n/2]) {
                cout << (aas == bbs ? "yes\n" : "no\n");
            } else {
                cout << "no\n";
            }
        } else {
            cout << (aas == bbs ? "yes\n" : "no\n");
        }
    }
}