#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cin >> q;
    for (int i = 0; i < q; i++) {
        // int k,l,u;
        // cin >> k;
        // l = lower_bound(a.begin(),a.end(), k) - a.begin();
        // u = upper_bound(a.begin(),a.end(), k) - a.begin();

        // equal_range関数を使って解く
        int k;
        cin >> k;
        auto [l, u] = equal_range(a.begin(), a.end(), k);
        cout << l - a.begin() << ' ' << u - a.begin() << endl;
    }

    return 0;
}
