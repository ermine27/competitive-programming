/*
単一始点最短経路　（ベルマンフォード法）
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

template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }

struct Edge{
    int from;
    int to;
    int cost;
};

int main(){
    int v, e, r;
    in(v, e, r);
    vector<Edge> edges(e);
    rep(i,e){
        in(edges[i].from, edges[i].to, edges[i].cost);
    }

    vis(d, v, INT_MAX);
    d[r] = 0;
    rep(i, v) {
        rep(j, sz(edges)) {
            Edge et = edges[j];
            if (d[et.from] != INT_MAX && d[et.to] > d[et.from] + et.cost) {
                d[et.to] = d[et.from] + et.cost;
                if (i == v - 1) {
                    cout << "NEGATIVE CYCLE" << endl;
                    return 0;
                }
            }
        }
    }

    rep(i,v){
        if(d[i] == INT_MAX) cout << "INF";
        else cout << d[i];
        cout << endl;
    }
    return 0;
}
