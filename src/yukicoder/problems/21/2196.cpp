#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(2 * n), b(2 * n), x(n), y(n);
    for (int i = 0; i < 2 * n; i++) cin >> a[i];
    for (int i = 0; i < 2 * n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        vector<long long> p(4);
        p[0] = a[2 * i] + a[2 * i + 1] + x[i];
        p[1] = a[2 * i] + b[2 * i + 1] + y[i];
        p[2] = b[2 * i] + a[2 * i + 1] + y[i];
        p[3] = b[2 * i] + b[2 * i + 1] + x[i];
        ans += *max_element(p.begin(), p.end());
    }

    cout << ans << endl;
    return 0;
}
