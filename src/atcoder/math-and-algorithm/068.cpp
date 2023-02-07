#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    int k;
    cin >> n >> k;
    vector<int> v(k);
    for (int i = 0; i < k; i++) cin >> v[i];
    long long ans = 0;

    for (int i = 1; i < (1 << k); i++) {
        bitset<10> bs(i);
        long long lc = 1;
        for (int j = 0; j < k; j++) {
            if (!bs[j])
                continue;
            lc = lcm(lc, v[j]);
        }

        long long cnt = n / lc;
        if (bs.count() % 2 == 0)
            ans -= cnt;
        else
            ans += cnt;
    }

    cout << ans << endl;
    return 0;
}
