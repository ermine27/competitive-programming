#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, ans = 0, gcd = 0;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 2; i <= 1000; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] % i == 0)
                cnt++;
        }
        if (cnt > gcd) {
            ans = i;
            gcd = cnt;
        }
    }

    cout << ans << endl;
    return 0;
}
