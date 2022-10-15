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
template<typename... T> int in(T&... a){ (cin >> ... >> a); return 1; }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

int main() {
    const int EMPTY = -1;

    int h;
    vvi s;

    while (in(h) && h != 0) {
        int score = 0;
        s.assign(h + 1, vi(5, -1));
        repe(i, h) rep(j, 5) in(s[i][j]);

        bool check = true;
        while (check) {
            check = false;
            repe(i, h) {
                rep(j, 3) {
                    if (s[i][j] != EMPTY && s[i][j] == s[i][j + 1] && s[i][j + 1] == s[i][j + 2]) {
                        int con = 3;
                        for (int k = j + 3; s[i][j] == s[i][k] && k < 5; ++k)
                            ++con;
                        score += con * s[i][j];

                        rep(k, j, j + con) s[i][k] = EMPTY;
                        check = true;
                        break;
                    }
                }
            }

            rep(j, 5) {
                for (int i = h; i > 1; --i) {
                    for (int k = h; k > 0; --k) {
                        if (s[k][j] == EMPTY) swap(s[k][j], s[k - 1][j]);
                    }
                }
            }
        }

        out(score);
    }

    return 0;
}
