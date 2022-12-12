/*
クーポンコレクター問題

期待値 E = n*Σ(1/k) = n(1/1+1/2+1/3+...+1/n) = n/1+n/2+n/3+...n/n
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    double ans = 0.0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        ans += 1.0 * n / i;
    }

    cout << setprecision(10) << ans << endl;
    return 0;
}
