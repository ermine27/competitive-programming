#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p, q;
    double ans = 0.0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> q;
        ans += 1.0 * q / p;
    }

    cout << setprecision(10) << ans << endl;
    return 0;
}
