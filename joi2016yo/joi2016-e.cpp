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
#define vvis(x,h,...) vector<vi>x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vector<vl>x(h,vl(__VA_ARGS__))
using pii = pair<int,int>;
using pil = pair<int,ll>;
using mii = map<int,int>;
using mil = map<int,ll>;

template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }

const ll INF = (1LL<<60);

int main(){
    int n, m, k, s, p, q;
    in(n, m, k, s, p, q);

    vvi g(n + 1);
    vis(zombie, n + 1);
    vis(danger, n + 1);
    queue<pii> que;

    // 1. ゾンビ村の情報を配列に格納する
    // 3-1. 後で使うBFSの初期データとしてキューに追加する
    rep(i, k) {
        int ki;
        in(ki);
        zombie[ki] = 1;
        que.push(make_pair(ki, 0));
    }

    // 2. グラフにルートを登録する
    rep(i, m) {
        int ai, bi;
        in(ai, bi);
        g[ai].push_back(bi);
        g[bi].push_back(ai);
    }

    // 3-2. 危険な町をBFSで探す
    while (!que.empty()) {
        int ki = que.front().first;
        int vv = que.front().second + 1;
        que.pop();

        if (vv > s) continue;

        fore(to, g[ki]) {
            if (danger[to]) continue;
            danger[to] = vv;
            que.push(make_pair(to, vv));
        }
    }

    // 4. 町ごとの宿泊費を配列に格納する
    vl price(n + 1);
    rep(i, 2, n) {
        price[i] = (danger[i] ? q : p);
    }

    // 5. ダイクストラ法で宿泊費の最小値を探す
    vls(ans, n + 1, INF);
    ans[0] = -1;
    ans[1] = 0;

    // queueを使った場合は実行時間が長くなるが、この問題の場合はACはできる
    priority_queue<pil, vector<pil>, greater<pil>> pq;
    pq.push(make_pair(1, 0));

    while (!pq.empty()) {
        int from = pq.top().first;
        ll cost = pq.top().second;
        pq.pop();

        if (ans[from] < cost) continue;

        fore(to, g[from]) {
            if (zombie[to]) continue;
            ll ncost = ans[from] + price[to];
            if (chmin(ans[to], ncost)) {
                pq.push(make_pair(to, ncost));
            }
        }
    }

    cout << ans[n] << endl;
    return 0;
}
