#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, b, t;
    long long ans = 0;
    cin >> n;
    n--;
    vector<long long> a(n), c(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) c[i + 1] = c[i] + a[i];
    cin >> m >> b;
    t = b;
    for (int i = 1; i < m; i++) {
        cin >> b;
        ans += abs(c[b - 1] - c[t - 1]);
        t = b;
    }
    cout << ans << endl;
    return 0;
}
