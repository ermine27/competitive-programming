/*
全点対間最短経路　（ワーシャルフロイド法）
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
#define vvis(x,h,...) vvi x(h,vi(__VA_ARGS__))
#define vvls(x,h,...) vvl x(h,vl(__VA_ARGS__))
using pii = pair<int,int>;
using pil = pair<int,ll>;
using mii = map<int,int>;
using mil = map<int,ll>;

template<typename T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<typename T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
template<typename... T> void in(T&... a){ (cin >> ... >> a); }


int main(){
    const ll INF = 2e9;

    int v, e;
    in(v, e);
    vvls(dp, v, v, INF);
    rep(i, v) dp[i][i] = 0;
    rep(i, e) {
        int s, t, d;
        in(s, t, d);
        dp[s][t] = d;
    }

    rep(k, v) {
        rep(i, v) {
            if (dp[i][k] == INF) continue;
            rep(j, v) {
                if (dp[k][j] == INF) continue;
                chmin(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }

    // ある頂点viからviへの最短距離が負である　→　負の閉路が存在する
    rep(i,v){
        if(dp[i][i]<0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }

    rep(i, v) {
        rep(j, v) {
            if (j > 0) cout << ' ';
            if (dp[i][j] >= INF) {
                cout << "INF";
            } else {
                cout << dp[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
