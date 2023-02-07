#include <bits/stdc++.h>
using namespace std;

int main() {
    long long h, w, ans;
    cin >> h >> w;
    if (h == 1 || w == 1) {
        cout << 1 << endl;
        return 0;
    }
    ans = h * w;
    if (h * w % 2 == 1)
        ans++;
    cout << ans / 2 << endl;
    return 0;
}
