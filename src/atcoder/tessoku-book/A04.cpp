#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repe(i, n) for (int i = 1; i <= (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
    int n;
    cin >> n;
    string ans(10, '0');

    rep(i, 10) {
        int p = pow(2, 9 - i);
        if (n >= p) {
            n -= p;
            ans[i] = '1';
        }
    }

    cout << ans << endl;
    return 0;
}
