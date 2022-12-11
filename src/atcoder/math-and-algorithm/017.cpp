#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    long long a, ans = 1LL;
    cin >> n;

    // ユークリッドの互除法
    auto euclidean = [](long long a, long long b) {
        if (a < b)
            swap(a, b);

        while (a % b != 0) {
            long long m = a % b;
            a = b;
            b = m;
        }
        return b;
    };

    for (int i = 0; i < n; i++) {
        cin >> a;
        // LCM(a,b) = a*b / GCD(a,b)
        // 先に掛け算をするとオーバーフローの恐れがある
        // GCDで割り切れるので先に割り算をしても問題ない
        ans = ans / euclidean(ans, a) * a;
    }

    cout << ans << endl;
    return 0;
}

// 別解：lcm関数を使って解く
int main() {
    int n;
    long long a, ans = 1LL;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ans = lcm(ans, a);
    }
    cout << ans << endl;
    return 0;
}
