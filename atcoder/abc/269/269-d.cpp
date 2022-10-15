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
using vvi = vector<vi>;
using vvl = vector<vl>;
using pii = pair<int,int>;
using pil = pair<int,ll>;
using mii = map<int,int>;
using mil = map<int,ll>;
#define vis(x,...) vi x(__VA_ARGS__)
#define vls(x,...) vl x(__VA_ARGS__)
#define vvis(x,h,...) vvi x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vvl x(h,vl(__VA_ARGS__))
template<typename... T> void in(T&... a){ (cin >> ... >> a); }
template<typename T> void out(T& a){ cout << a << '\n'; }
template<typename T, typename... T2> void out(T& a, T2&... b){ cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }

const int dx[] = {-1, -1, 0, 0, 1, 1};
const int dy[] = {-1, 0, -1, 1, 0, 1};
const int DMAX = 2000;
vvis(v, DMAX * 2 + 2, DMAX * 2 + 2);

int main() {
    int n;
    in(n);
    set<pii> s;

    rep(i, n) {
        int x, y;
        in(x, y);
        s.insert(make_pair(x, y));
    }

    int ans = 0;
    repe(i, -DMAX, DMAX) {
        repe(j, -DMAX, DMAX) {
            if (v[i + DMAX + 1][j + DMAX + 1]) continue;

            if (s.count(make_pair(i, j))) {
                ++ans;
                v[i + DMAX + 1][j + DMAX + 1] = 1;

                queue<pii> q;
                q.push(make_pair(i, j));

                while (!q.empty()) {
                    int x, y;
                    tie(x, y) = q.front();
                    q.pop();

                    rep(k, 6) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (abs(nx) <= DMAX && abs(ny) <= DMAX && !v[nx + DMAX + 1][ny + DMAX + 1] && s.count(make_pair(nx, ny))) {
                            v[nx + DMAX + 1][ny + DMAX + 1] = 1;
                            q.push(make_pair(nx, ny));
                        }
                    }
                }
            }
        }
    }

    out(ans);
    return 0;
}
