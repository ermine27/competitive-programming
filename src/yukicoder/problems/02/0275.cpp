#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    double ans;
    if (n % 2 == 1) {
        ans = a[n / 2];
    } else {
        ans = (a[n / 2] + a[n / 2 - 1]) / 2.0;
    }

    cout << ans << endl;
    return 0;
}
