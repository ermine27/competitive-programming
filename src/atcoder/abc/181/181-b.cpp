#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        ans += b * (b + 1) / 2 - (a - 1) * a / 2;
    }
    cout << ans << endl;
    return 0;
}
