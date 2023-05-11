#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define repe(i, n) for (int i = 1; i <= (int)(n); ++i)
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

int main() {
    int n, d;
    cin >> n;
    vector<vi> c(101);
    rep(i, n) {
        int a;
        cin >> a;
        c[a].push_back(i);
    }

    cin >> d;
    rep(i, d) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        for (int j = 100; j > 0; j--) {
            if (c[j].size() > 0 && (*c[j].begin() < l || *c[j].rbegin() > r)) {
                cout << j << endl;
                break;
            }
        }
    }

    return 0;
}
