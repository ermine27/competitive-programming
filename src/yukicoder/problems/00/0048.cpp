#include <bits/stdc++.h>
using namespace std;

int main() {
    int x, y, l, ans = 0;
    cin >> x >> y >> l;

    ans += abs(x) / l;
    if (x % l)
        ans++;
    ans += abs(y) / l;
    if (y % l)
        ans++;

    if (x == 0) {
        if (y < 0)
            ans += 2;
    } else {
        ans++;
        if (y < 0)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
