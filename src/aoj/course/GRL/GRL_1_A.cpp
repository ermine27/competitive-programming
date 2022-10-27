/*
単一始点最短経路　（ダイクストラ法）
*/

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
#define per(i,n) for(int i = (int)(n)-1; i >= 0; --i)
#define perf(i,n) for(int i = (int)(n); i >= 1; --i)
#define _fore1(x,a) for(auto& x:a)
#define _fore2(k,v,a) for(auto& [k,v] : a)
#define fore(...) _overload3(__VA_ARGS__, _fore2, _fore1)(__VA_ARGS__)

#define all(v) v.begin(), v.end()
#define sz(x) ((int)(x).size())
using ll = long long;
using vi = vector<int>;
using vl = vector<long long>;
using vvi = vector<vi>;
using vvl = vector<vl>;
#define vis(x,...) vector<int>x(__VA_ARGS__)
#define vls(x,...) vector<ll>x(__VA_ARGS__)
using pii = pair<int,int>;
using pil = pair<int,ll>;
using mii = map<int,int>;
using mil = map<int,ll>;

template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }

int main() {
    int v, e, r;
    in(v, e, r);

    vector<vector<pii>> st(v);
    rep(i, e) {
        int si, ti, di;
        in(si, ti, di);
        st[si].push_back(make_pair(ti, di));
    }

    vis(d, v, INT_MAX);
    d[r] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push(make_pair(r, 0));

    while (!q.empty()) {
        int pi = q.top().first;
        int di = q.top().second;
        q.pop();
        fore(tt, dd, st[pi]) {
            if (chmin(d[tt], di + dd)) {
                q.push(make_pair(tt, d[tt]));
            }
        }
    }

    rep(i, v) {
        if (d[i] == INT_MAX) cout << "INF";
        else cout << d[i];
        cout << endl;
    }
    return 0;
}
