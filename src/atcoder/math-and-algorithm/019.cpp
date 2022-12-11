#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    long long ans = 0;
    cin >> n;
    vector<int> c(3);
    for (int i = 0; i < n; i++) {
        cin >> a;
        c[a - 1]++;
    }

    for (int i = 0; i < 3; i++) {
        if (c[i] >= 2) {
            ans += 1LL * c[i] * (c[i] - 1) / 2;
        }
    }

    cout << ans << endl;
    return 0;
}
