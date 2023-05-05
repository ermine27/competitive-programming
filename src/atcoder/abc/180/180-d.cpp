#include <bits/stdc++.h>
using namespace std;

int main() {
    long long x, y, a, b, i, ans = 0;
    cin >> x >> y >> a >> b;
    i = x;
    while ((double)i * a < 9e18 && i * a < y && i * a < b) {
        i *= a;
        ans++;
    }

    ans += (y - i - 1) / b;
    cout << ans << endl;
    return 0;
}
