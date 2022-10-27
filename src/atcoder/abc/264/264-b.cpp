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
    int r, c;
    cin >> r >> c;
    --r;
    --c;

    const int GMAX = 15;
    vvi g(GMAX, vi(GMAX));

    for (int i = 0; i < 7; i += 2) {
        rep(j, i, GMAX - i) {
            g[i][j] = 1;
            g[GMAX - i - 1][j] = 1;
        }
    }

    for (int j = 0; j < 7; j += 2) {
        rep(i, j, GMAX - j) {
            g[i][j] = 1;
            g[i][GMAX - j - 1] = 1;
        }
    }

    cout << (g[r][c] ? "black" : "white") << endl;
    return 0;
}
