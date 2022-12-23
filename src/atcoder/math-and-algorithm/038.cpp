#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q, l, r;
    cin >> n >> q;
    vector<int> a(n), c(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) c[i + 1] = c[i] + a[i];
    for (int i = 0; i < q; i++) {
        cin >> l >> r;
        cout << c[r] - c[l - 1] << endl;
    }
    return 0;
}
