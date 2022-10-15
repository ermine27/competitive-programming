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
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

int main() {
    int a = 0, b = 10, c = 0, d = 10;
    vector<string> s(10);
    rep(i, 10) in(s[i]);

    int find = 0;
    rep(i, 10) {
        rep(j, 10) {
            if (s[i][j] == '#') {
                find = 1;
                a = i;
                c = j;
                break;
            }
        }
        if (find) break;
    }

    rep(i, c, 10) {
        if (s[a][i] == '.') {
            d = i;
            break;
        }
    }

    rep(j, a, 10) {
        if (s[j][c] == '.') {
            b = j;
            break;
        }
    }

    ++a;
    ++c;

    out(a, b);
    out(c, d);

    return 0;
}
