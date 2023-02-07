#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    long long cnt = 0;
    cnt = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = max(1LL, i - k); j <= min(n, i + k); j++) {
            for (int l = max(1LL, j - k); l <= min(n, j + k); l++) {
                if (max({i, j, l}) - min({i, j, l}) < k)
                    cnt++;
            }
        }
    }
    cout << n * n * n - cnt << endl;
    return 0;
}
