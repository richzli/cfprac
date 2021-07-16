#include <bits/stdc++.h>
using namespace std;
typedef long long num;

num t, n, m;
string a;
vector<num> rem;

num bstoa(string s) {
    num val = 0;
    num place = 1LL;
    while (s != "") {
        if (s.back() == '1') {
            val += place;
        }
        place <<= 1;
        s.erase(s.end()-1);
    }
    return val;
}

string atobs(num x) {
    string s = "";
    num place = 1LL << (m-1);
    while (place > 0) {
        if (x >= place) {
            s.append("1");
            x -= place;
        } else {
            s.append("0");
        }
        place >>= 1;
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (;t;--t) {
        cin >> n >> m;
        rem.clear();
        for (int i = 0; i < n; ++i) {
            cin >> a;
            rem.emplace_back(bstoa(a));
        }
        sort(rem.begin(), rem.end());

        num l = 0, r = (1LL << m) - 1;
        while (l <= r) {
            num med = (l + r) / 2;

            num toleft = med + 1, toright = (1LL << m) - med - 1;
            num pos = 0;
            while ((pos < rem.size()) && (rem[pos] <= med)) {
                ++pos;
            }

            toleft -= pos;
            toright -= rem.size() - pos;

            if (!(n % 2) && (toleft == toright)) {
                if ((pos > 0) && (pos <= rem.size()) && (med == rem[pos-1])) {
                    
                } else {
                    r = med;
                    break;
                }
            } else if ((n % 2) && (toleft - 1 == toright)) {
                if ((pos > 0) && (pos <= rem.size()) && (med == rem[pos-1])) {
                    
                } else {
                    r = med;
                    break;
                }
            }

            if (n % 2) {
                if (toleft - 1 >= toright) {
                    r = med-1;
                } else {
                    l = med+1;
                }
            } else {
                if (toleft >= toright) {
                    r = med-1;
                } else {
                    l = med+1;
                }
            }
        }

        cout << atobs(r) << "\n";
    }
}