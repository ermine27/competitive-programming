#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b, as = 0, bs = 0;
    double ans = 0.0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        as += a;
    }
    for (int i = 0; i < n; i++) {
        cin >> b;
        bs += b;
    }
    cout << setprecision(10) << 1.0 * as / 3 + 1.0 * bs * 2 / 3 << endl;
    return 0;
}
