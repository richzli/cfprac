#include <bits/stdc++.h>
using namespace std;
typedef int num;

num n, m, k, a;
vector<num> ansdp;
vector<vector<num>> as, mxsm;
vector<vector<vector<num>>> asdp; // [row][nums used][mod]

void print_vector(vector<num> v) {
    for (num x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        as.emplace_back(vector<num>());
        for (int j = 0; j < m; ++j) {
            cin >> a;
            as.back().emplace_back(a);
        }
    }

    for (int i = 0; i < n; ++i) {
        asdp.emplace_back(vector<vector<num>>(m/2 + 1, vector<num>(k)));
        for (int c = 0; c < m; ++c) {
            num p = as[i][c];
            for (int j = min(m/2, c+1)-1; j >= 0; --j) {
                if (j == 0) {
                    asdp[i][1][p%k] = max(asdp[i][1][p%k], p);
                } else {
                    for (int b = 0; b < k; ++b) {
                        if (asdp[i][j][b] != 0) {
                            asdp[i][j+1][(b+p)%k] = max(asdp[i][j+1][(b+p)%k], asdp[i][j][b]+p);
                        }
                    }
                }
            }
        }
    }

    mxsm = vector<vector<num>>(n, vector<num>(k));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            num mx = 0;
            for (int b = 0; b <= m/2; ++b) {
                mx = max(mx, asdp[i][b][j]);
            }
            mxsm[i][j] = mx;
        }
        //print_vector(mxsm[i]);
    }

    //cout << endl;

    ansdp = vector<num>(k);
    for (int j = 0; j < k; ++j) {
        ansdp[j] = mxsm[0][j];
    }
    //print_vector(ansdp);
    for (int i = 1; i < n; ++i) {
        vector<num> nxt = ansdp;
        for (int j = 0; j < k; ++j) {
            for (int b = 0; b < k; ++b) {
                if (((j == 0) || (ansdp[j] != 0)) && (mxsm[i][b] != 0)) {
                    nxt[(j+mxsm[i][b])%k] = max(nxt[(j+mxsm[i][b])%k], ansdp[j] + mxsm[i][b]);
                }  
            }
        }
        ansdp = nxt;
        //print_vector(ansdp);
    }

    cout << ansdp[0];
}