#include <bits/stdc++.h>
using namespace std;

int main() {
    long long l, r;
    cin >> l >> r;
    vector<bool> c(r - l + 1, true);

    for (long long i = 2; i * i <= r; i++) {
        long long k = (l + i - 1) / i * i;
        if (k == i)
            k += i;

        for (long long j = k; j <= r; j += i) {
            c[j - l] = false;
        }
    }

    int ans = 0;
    for (int i = 0; i < r - l + 1; i++) {
        if (c[i])
            ans++;
    }
    if (l == 1)
        ans--;
    cout << ans << endl;
    return 0;
}
