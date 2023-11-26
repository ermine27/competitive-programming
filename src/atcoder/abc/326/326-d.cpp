#ifdef INCLUDE_MAIN

// 3重ループをラムダ式の再帰で書き換える
int main2() {
    int n;
    string r, c;
    in(n, r, c);

    auto func = [&](auto self, char x, vector<vector<char>> g) -> bool {
        if (x == 'D') {
            string checkr = "", checkc = "";
            rep(i, n) {
                rep(j, n) {
                    if (g[i][j] == '.')
                        continue;
                    checkr += g[i][j];
                    break;
                }
            }
            rep(j, n) {
                rep(i, n) {
                    if (g[i][j] == '.')
                        continue;
                    checkc += g[i][j];
                    break;
                }
            }
            if (checkr == r && checkc == c) {
                cout << "Yes" << endl;
                rep(i, n) {
                    string s = "";
                    rep(j, n) s += g[i][j];
                    out(s);
                }
                return true;
            }
            return false;
        }

        vi ord(n);
        rep(i, n) ord[i] = i;
        do {
            vector<vector<char>> g2 = g;
            bool ok = true;
            rep(i, n) {
                if (g2[i][ord[i]] != '.')
                    ok = false;
                g2[i][ord[i]] = x;
            }
            if (ok) {
                if (self(self, x + 1, g2))
                    return true;
            }
        } while (next_permutation(all(ord)));

        return false;
    };

    vector<vector<char>> g(n, vector<char>(n, '.'));
    no(!func(func, 'A', g));
    return 0;
}

int main() {
    int n;
    string r, c;
    in(n, r, c);

    vector<vector<char>> d(n, vector<char>(n));

    vi orda(n), ordb(n), ordc(n);
    rep(i, n) { orda[i] = ordb[i] = ordc[i] = i; }

    do {
        do {
            do {
                bool ok = true;
                rep(i, n) {
                    if (orda[i] == ordb[i] || ordb[i] == ordc[i] || ordc[i] == orda[i]) {
                        ok = false;
                        break;
                    }
                }
                if (!ok)
                    continue;

                vector<vector<char>> ans(n, vector<char>(n, '.'));
                rep(i, n) {
                    ans[i][orda[i]] = 'A';
                    ans[i][ordb[i]] = 'B';
                    ans[i][ordc[i]] = 'C';
                }

                rep(i, n) {
                    rep(j, n) {
                        if (ans[i][j] == '.')
                            continue;
                        if (ans[i][j] == r[i])
                            break;
                        ok = false;
                    }
                }
                rep(j, n) {
                    rep(i, n) {
                        if (ans[i][j] == '.')
                            continue;
                        if (ans[i][j] == c[j])
                            break;
                        ok = false;
                    }
                }

                if (ok) {
                    cout << "Yes" << endl;
                    rep(i, n) {
                        string s = "";
                        rep(j, n) s += ans[i][j];
                        out(s);
                    }
                    return 0;
                }

            } while (next_permutation(all(ordc)));
        } while (next_permutation(all(ordb)));
    } while (next_permutation(all(orda)));

    cout << "No" << endl;
    return 0;
}

#else

#include <bits/stdc++.h>
using namespace std;

// clang-format off
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
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using mii = map<int,int>;
using mll = map<ll,ll>;
template<typename T> using priority_queue_asc = priority_queue<T, vector<T>, greater<T>>;
#define deg2rad(x) (x*M_PI/180.0)
#define rad2deg(x) (x*180.0/M_PI)
template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void invec(T &x){ rep(i, sz(x)) cin >> x[i]; }
template<typename T> void invec2(T &x){ rep(i, sz(x)) invec(x[i]); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<typename T> void outvec(const vector<T>& v, char d = '\n'){ rep(i,sz(v)) cout << v[i] << (i == sz(v)-1 ? '\n' : d);}
#define yesno(x) cout << ((x) ? "Yes" : "No") << endl;
#define yes(x) if(x){ cout << "Yes" << endl; exit(0); }
#define no(x) if(x){ cout << "No" << endl; exit(0); }
const int INF = 1.1e9;
const ll INFLL = 4.4e18;
const int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[] = {0, 1, 0, -1, 1, 1, -1, -1};

#ifdef LOCAL
#include "debug_print.hpp"
#define dbg(...) cerr << '(' << __LINE__ << ')' << endl; debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) (static_cast<void>(0))
#endif
// clang-format on

#define INCLUDE_MAIN
#include __FILE__

#endif
