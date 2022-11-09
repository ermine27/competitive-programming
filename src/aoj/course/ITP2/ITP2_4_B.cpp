#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cin >> q;
    for (int i = 0; i < q; i++) {
        int b, m, e;
        cin >> b >> m >> e;

        rotate(a.begin() + b, a.begin() + m, a.begin() + e);
    }

    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ' ';
        cout << a[i];
    }
    cout << endl;

    return 0;
}
