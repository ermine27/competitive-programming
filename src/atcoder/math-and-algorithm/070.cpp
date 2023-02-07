#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> x(n), y(n);
    long long ans = 4e18;
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++) {
            for (int c = 0; c < n; c++) {
                for (int d = 0; d < n; d++) {
                    int cnt = 0;
                    for (int e = 0; e < n; e++) {
                        if (x[a] <= x[e] && x[e] <= x[b] && y[c] <= y[e] && y[e] <= y[d])
                            cnt++;
                    }
                    if (cnt >= k) {
                        ans = min(ans, (x[b] - x[a]) * (y[d] - y[c]));
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
