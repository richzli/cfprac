#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, x, d;
vector<ll> ds, yr;

ll tot(ll t) {
    return (t * (t+1))/2;
}

ll rem(ll t, ll r) {
    return ((t * (t+1)) - ((t-r) * (t-r+1)))/2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> x;
    for (int i = 0; i < n; ++i) {
        cin >> d;
        ds.emplace_back(d);
        yr.emplace_back(d);
    }
    yr.insert(yr.end(), ds.begin(), ds.end());
    
    ll maxhugs = 0;
    ll currdays = 0, currhugs = 0;
    int l = 0, r = 0;
    while (currdays + yr[r] < x) {
        currhugs += tot(yr[r]);
        currdays += yr[r];
        ++r;
    }
    maxhugs = currhugs;

    while (r < yr.size()) {
        currdays += yr[r];
        currhugs += tot(yr[r]);
        ++r;

        while (currdays > x) {
            currdays -= yr[l];
            currhugs -= tot(yr[l]);
            ++l;
        }
        
        maxhugs = max(maxhugs, currhugs + rem(yr[l-1], x-currdays));
    }

    cout << maxhugs;
}