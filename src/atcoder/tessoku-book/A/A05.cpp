#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repe(i, n) for (int i = 1; i <= (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
    int n, k, ans = 0;
    cin >> n >> k;

    repe(i, n) {
        repe(j, n) {
            if (i + j < k && k - (i + j) <= n)
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}
