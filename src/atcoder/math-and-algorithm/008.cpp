#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, s, ans = 0;
    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i + j <= s)
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}

// 別解
int main2() {
    int n, s, ans = 0;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        // 次の内容と同値
        // ans += max(0, min(s-i,n));
        ans += clamp(s - i, 0, n);
    }
    cout << ans << endl;
    return 0;
}
