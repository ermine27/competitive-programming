#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, x, t, d, ans;
    cin >> n >> m >> x >> t >> d;

    if (m >= x) {
        ans = t;
    } else {
        ans = t - (x - m) * d;
    }

    cout << ans;
    return 0;
}
