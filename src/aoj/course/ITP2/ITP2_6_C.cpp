#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cin >> q;
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        cout << lower_bound(a.begin(), a.end(), k) - a.begin() << endl;
    }

    return 0;
}
