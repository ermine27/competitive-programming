#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<double> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];

    double ans = 0.0;

    auto check = [&](double x, double y) -> bool {
        for (int i = 0; i < n; i++) {
            if (a[i] * x + b[i] * y > c[i])
                return false;
        }
        return true;
    };

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double x = (b[j] * c[i] - b[i] * c[j]) / (a[i] * b[j] - a[j] * b[i]);
            double y = (a[i] * c[j] - a[j] * c[i]) / (a[i] * b[j] - b[i] * a[j]);

            if (check(x, y)) {
                ans = max(ans, x + y);
            }
        }
    }

    cout << setprecision(10) << ans << endl;
    return 0;
}
