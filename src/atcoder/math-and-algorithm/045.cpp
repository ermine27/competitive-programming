#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b, ans = 0;
    cin >> n >> m;

    vector<int> cnt(n);
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        --a;
        --b;
        if (a < b)
            swap(a, b);
        cnt[a]++;
    }

    for (int i = 0; i < n; i++) {
        if (cnt[i] == 1)
            ans++;
    }

    cout << ans << endl;
    return 0;
}
