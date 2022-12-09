#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, ans = 0;
    cin >> n >> x >> y;
    for (int i = 1; i <= n; ++i) {
        if (i % x == 0 || i % y == 0)
            ans++;
    }
    cout << ans << endl;
    return 0;
}

// 別解
int main2() {
    long long n, x, y;
    cin >> n >> x >> y;
    cout << n / x + n / y - n / lcm(x, y) << endl;
    return 0;
}
