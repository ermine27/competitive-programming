#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f

#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define _repe1(i,n) for(int i = 1; i <= (int)(n); ++i)
#define _repe2(i,s,n) for(int i = (int)(s); i <= (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define repe(...) _overload3(__VA_ARGS__, _repe2, _repe1)(__VA_ARGS__)

#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;

int main() {
    int h1, h2, w1, w2;
    cin >> h1 >> w1;
    vvi a(h1, vi(w1));
    rep(i, h1) rep(j, w1) cin >> a[i][j];
    cin >> h2 >> w2;
    vvi b(h2, vi(w2));
    rep(i, h2) rep(j, w2) cin >> b[i][j];

    vi ph(h1), pw(w1);
    rep(i, h2) ph[h1 - i - 1] = 1;
    rep(i, w2) pw[w1 - i - 1] = 1;

    do {
        do {
            vvi c(h2, vi(w2));
            int h = 0;
            rep(i, h1) {
                int w = 0;
                rep(j, w1) {
                    if (ph[i] && pw[j]) {
                        c[h][w] = a[i][j];
                        ++w;
                    }
                }
                if (w == w2) {
                    ++h;
                }
            }

            if (c == b) {
                cout << "Yes";
                return 0;
            }

        } while (next_permutation(all(pw)));
    } while (next_permutation(all(ph)));

    cout << "No";
    return 0;
}
