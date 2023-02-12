#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n), b(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        b[i + 1] = b[i] + a[i];
    }

    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += (b[n] - b[i + 1]) - (n - i - 1) * a[i];
    }

    cout << ans << endl;
    return 0;
}
