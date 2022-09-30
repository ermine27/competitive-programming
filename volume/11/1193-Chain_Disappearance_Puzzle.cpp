#include <bits/stdc++.h>
using namespace std;

#define _overload2(a,b,f,...) f
#define _overload3(a,b,c,f,...) f
#define _rep1(i,n) for(int i = 0; i < (int)(n); ++i)
#define _rep2(i,s,n) for(int i = (int)(s); i < (int)(n); ++i)
#define rep(...) _overload3(__VA_ARGS__, _rep2, _rep1)(__VA_ARGS__)
#define _repe1(i,n) for(int i = 1; i <= (int)(n); ++i)
#define _repe2(i,s,n) for(int i = (int)(s); i <= (int)(n); ++i)
#define repe(...) _overload3(__VA_ARGS__, _repe2, _repe1)(__VA_ARGS__)
#define _fore1(x,a) for(auto& x:a)
#define _fore2(k,v,a) for(auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)
#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

int main() {
    const int EMPTY = -1;

    int h;
    vvi s;

    while (true) {
        in(h);
        if (h == 0) break;

        int score = 0;
        s.assign(h + 1, vi(5, -1));
        repe(i, h) rep(j, 5) in(s[i][j]);

        while (true) {
            bool check = false;
            repe(i, h) {
                if (s[i][0] != EMPTY && s[i][0] == s[i][1] && s[i][1] == s[i][2] && s[i][2] == s[i][3] && s[i][3] == s[i][4]) {
                    score += 5 * s[i][0];
                    rep(j, 5) s[i][j] = EMPTY;
                    check = true;
                    break;
                }

                rep(j, 2) {
                    if (s[i][j] != EMPTY && s[i][j] == s[i][j + 1] && s[i][j + 1] == s[i][j + 2] && s[i][j + 2] == s[i][j + 3]) {
                        score += 4 * s[i][j];
                        rep(k, j, j + 4) s[i][k] = EMPTY;
                        check = true;
                        break;
                    }
                }

                rep(j, 3) {
                    if (s[i][j] != EMPTY && s[i][j] == s[i][j + 1] && s[i][j + 1] == s[i][j + 2]) {
                        score += 3 * s[i][j];
                        rep(k, j, j + 3) s[i][k] = EMPTY;
                        check = true;
                        break;
                    }
                }
            }

            if (check) {
                rep(j, 5) {
                    int i = h;
                    while (i >= 1) {
                        if (s[i][j] == EMPTY) {
                            bool rest = false;
                            for (int k = i; k > 0; --k) {
                                s[k][j] = s[k - 1][j];
                                if (s[k][j] != EMPTY) rest = true;
                            }
                            if (rest == false) break;
                        } else {
                            --i;
                        }
                    }
                }
            } else {
                break;
            }
        }

        out(score);
    }

    return 0;
}
