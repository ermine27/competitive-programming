#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    n--;
    vector<int> b(n);
    for (int i = 0; i < n; i++) cin >> b[i];

    int ans = b[0] + b[n - 1];
    for (int i = 1; i < n; i++) {
        ans += min(b[i - 1], b[i]);
    }
    cout << ans << endl;
    return 0;
}
