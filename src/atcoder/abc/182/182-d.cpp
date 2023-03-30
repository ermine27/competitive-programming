#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> c(n + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c[i + 1] = c[i] + a;
    }

    long long ans = 0, ci = 0, m = 0;
    for (int i = 1; i <= n; i++) {
        m = max(m, c[i]);
        ans = max(ans, ci + m);
        ci += c[i];
    }

    cout << ans << endl;
    return 0;
}
