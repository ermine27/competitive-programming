#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    map<int, long long> c;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        c[a]++;
    }

    for (auto &[key, val] : c) {
        if (key >= 50000)
            break;
        ans += val * c[100000 - key];
    }
    ans += c[50000] * (c[50000] - 1) / 2;

    cout << ans << endl;
    return 0;
}
