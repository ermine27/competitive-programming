#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cin >> q;
    for (int i = 0; i < q; i++) {
        int b, e, k;
        cin >> b >> e >> k;
        cout << count(a.begin() + b, a.begin() + e, k) << endl;
    }

    return 0;
}
