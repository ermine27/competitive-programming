#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> rl(n);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        rl[i] = make_pair(r, l);
    }
    sort(rl.begin(), rl.end());

    int ans = 0;
    int i = 0;
    int cur = -1;
    while (true) {
        while (rl[i].second < cur && i < n) i++;
        if (i == n)
            break;
        cur = rl[i].first;
        ans++;
    }

    cout << ans << endl;
    return 0;
}
