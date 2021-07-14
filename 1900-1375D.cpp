#include <bits/stdc++.h>
using namespace std;

int t, n, a;
vector<int> as;
map<int, int> as_set;

int mex() {
    for (int i = 0; i <= n; ++i) {
        if (as_set[i] == 0) {
            return i;
        }
    }
}

bool ordered() {
    for (int i = 1; i < n; ++i) {
        if (as[i] < as[i-1]) return false;
    }
    return true;
}

void update(int pos, int val) {
    --as_set[as[pos]];
    ++as_set[val];
    as[pos] = val;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    for (;t;--t) {
        cin >> n;
        as.clear();
        as_set.clear();
        for (int i = 0; i <= n; ++i) {
            as_set[i] = 0;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a;
            as.emplace_back(a);
            ++as_set[a];
        }

        vector<int> sol;
        while (!ordered()) {
            int m = mex();
            if (m == n) {
                sol.push_back(m-1);
                update(m-1, m);
                --n;
            } else {
                sol.push_back(m);
                update(m, m);
            }
        }

        cout << sol.size() << "\n";
        for (int s : sol) {
            cout << s+1 << " ";
        }
        cout << "\n";
    }
}