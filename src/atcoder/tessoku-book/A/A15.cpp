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
    vector<pair<int, int>> ab(n);
    rep(i, n) {
        int a;
        cin >> a;
        ab[i] = make_pair(a, i);
    }
    sort(ab.begin(), ab.end());
    vi ans(n);
    int pre = 0;
    int c = 0;
    rep(i, n) {
        if (ab[i].first != pre) {
            c++;
            pre = ab[i].first;
        }
        ans[ab[i].second] = c;
    }

    rep(i, n) { cout << ans[i] << ' '; }
    cout << endl;
    return 0;
}
