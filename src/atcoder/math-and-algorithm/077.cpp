#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> x(n), y(n), bx(n + 1), by(n + 1);
    vector<pair<long long, long long>> xy(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    for (int i = 0; i < n; i++) {
        bx[i + 1] = bx[i] + x[i];
        by[i + 1] = by[i] + y[i];
    }

    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += (bx[n] - bx[i + 1]) - (n - i - 1) * x[i];
        ans += (by[n] - by[i + 1]) - (n - i - 1) * y[i];
    }

    cout << ans << endl;
    return 0;
}
