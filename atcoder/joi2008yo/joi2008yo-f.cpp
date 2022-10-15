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

const int INF = 2e9;

int main(){
    int n, k;
    cin >> n >> k;

    vector<vector<pii>> g(n);
    rep(i,k){
        int x,a,b,c,d,e;
        in(x);
        if(x==0){
            in(a,b);
            --a; --b;

            vis(cost, n, INF);
            cost[a] = 0;
            priority_queue<pii, vector<pii>, greater<pii>> q;
            q.push(make_pair(a, 0));
            while (!q.empty()) {
                int from = q.top().first;
                int fcost = q.top().second;
                q.pop();
                fore(to, co, g[from]) {
                    if (chmin(cost[to], fcost + co)) {
                        q.push(make_pair(to, cost[to]));
                    }
                }
            }
            cout << (cost[b] == INF ? -1 : cost[b]) << endl;
        } else {
            in(c, d, e);
            g[c - 1].push_back(make_pair(d - 1, e));
            g[d - 1].push_back(make_pair(c - 1, e));
        }
    }

    return 0;
}
