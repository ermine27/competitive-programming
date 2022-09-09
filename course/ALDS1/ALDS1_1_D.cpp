#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    int ans = -INT_MAX;
    int minv = r;

    for (int i = 1; i < n; ++i) {
        cin >> r;
        ans = max(ans, r - minv);
        minv = min(minv, r);
    }

    cout << ans << endl;
    return 0;
}
