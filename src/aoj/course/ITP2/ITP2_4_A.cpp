#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cin >> q;
    for (int i = 0; i < q; i++) {
        int b, e;
        cin >> b >> e;

        reverse(a.begin() + b, a.begin() + e);
    }

    for (int i = 0; i < n; ++i) {
        if (i != 0) cout << ' ';
        cout << a[i];
    }
    cout << endl;

    return 0;
}
