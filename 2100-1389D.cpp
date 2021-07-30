#include <bits/stdc++.h>
using namespace std;
typedef long long num;

num t, n, k, l1, r1, l2, r2;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (;t;--t) {
        cin >> n >> k >> l1 >> r1 >> l2 >> r2;
        if (l1 > l2) {
            swap(l1, l2);
            swap(r1, r2);
        }

        num a1, a2, s;
        if (r1 <= l2) {
            a1 = l2 - r1;
            a2 = r2 - l1;
            s = 0;
        } else {
            a1 = 0;
            if (r2 <= r1) {
                s = r2 - l2;
                a2 = r1 - l1 - s;
            } else {
                s = r1 - l2;
                a2 = r2 - l1 - s;
            }
        }

        num cnt = 0;
        k -= s * n;

        if (k > 0) {
            if (a2 == 0) {
                cnt += 2 * k;
            } else {
                num b = k / a2;
                if (b >= n) {
                    k -= n * a2;
                    cnt += n * (a1 + a2) + 2 * k;
                } else {
                    k -= b * a2;
                    if (b == 0) {
                        cnt += a1 + k;
                    } else {
                        cnt += b * (a1 + a2) + min(2 * k, a1 + k);
                    }
                }
            }
        }

        cout << cnt << "\n";
    }
}