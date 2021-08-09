#include <bits/stdc++.h>
using namespace std;
typedef int num;

num n, a;
vector<vector<vector<num>>> aij;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    
    map<set<num>, num> ids;
    for (int i = 1; i <= n; ++i) {
        set<num> x = { i };
        ids[x] = i;
    }
    vector<num> salaries = vector<num>(1), parents = vector<num>(n+1);

    for (int i = 0; i < n; ++i) {
        aij.emplace_back(vector<vector<num>>());
        for (int j = 0; j < n; ++j) {
            cin >> a;
            vector<num> p = { a, j+1 };
            aij[i].emplace_back(p);
            if (i == j) {
                salaries.emplace_back(a);
            }
        }
        sort(aij[i].begin(), aij[i].end());
    }

    num k = n;
    for (int i = 0; i < n; ++i) {
        set<num> cur = { i+1 };
        num curid = i+1;
        num idx = 1;
        while (idx < n) {
            num sal = aij[i][idx][0];
            cur.insert(aij[i][idx][1]);
            while (idx + 1 < n && aij[i][idx+1][0] == sal) {
                ++idx;
                cur.insert(aij[i][idx][1]);
            }
            if (ids.find(cur) == ids.end()) {
                ++k;
                ids[cur] = k;
                salaries.emplace_back(sal);
                parents.emplace_back(0);
                parents[curid] = k;
                curid = k;
            } else {
                num nid = ids[cur];
                parents[curid] = nid;
                curid = nid;
                break;
            }
            ++idx;
        }
    }

    set<num> head;
    for (int i = 1; i <= n; ++i) {
        head.insert(i);
    }
    num headid = ids[head];

    cout << k << "\n";
    for (int i = 1; i <= k; ++i) {
        cout << salaries[i] << " ";
    }
    cout << "\n";
    cout << headid << "\n";
    for (int i = 1; i <= k; ++i) {
        if (i != headid) {
            cout << i << " " << parents[i] << "\n";
        }
    }
}