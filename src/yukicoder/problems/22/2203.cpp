#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(9);
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        a[ai]++;
    }

    long long ans = 0LL;
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            long long t = pow(i, j);
            ans += a[i] * a[j] * t;
        }
    }

    cout << ans << endl;
    return 0;
}
